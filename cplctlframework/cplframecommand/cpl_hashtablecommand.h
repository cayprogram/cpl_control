#ifndef CPL_HASHTABLECOMMAND_H
#define CPL_HASHTABLECOMMAND_H

/** implementation dependent declarations */
class cpl_Command;
typedef int CmdIdHashIndexType;

typedef struct CmdIdKeyTypeTag{
    char id[64];
}
CmdIdKeyType;

/** user data stored in hash table */
typedef struct CmdIdRecTypeTag {
    cpl_Command * stuff;
    CmdIdKeyType inkey;
}
CmdIdRecType;

/** implementation independent declarations */
typedef enum CmdIdStatusEnumTag{
    CMD_STATUS_OK, CMD_STATUS_MEM_EXHAUSTED, CMD_STATUS_KEY_NOT_FOUND
}
CmdIdStatusEnum;

typedef struct CmdIdNodeTag {
    struct CmdIdNodeTag * next; // next node
    CmdIdKeyType key; // key
    CmdIdRecType rec; // user data
}
CmdIdNodeType;

typedef CmdIdNodeType * CmdIdNodeTypeP;

//-----------------------------------------------------------------------------
class cpl_HashTableCmdOneKey {

public:
    /** hash command */
    CmdIdHashIndexType CmdIdHashCmdtion(CmdIdKeyType key);

    /** insert */
    CmdIdStatusEnum CmdIdInsert(CmdIdKeyType key, CmdIdRecType * rec);

    /** delete */
    CmdIdStatusEnum CmdIdDelete(CmdIdKeyType key);

    /** find */
    CmdIdStatusEnum CmdIdFind(CmdIdKeyType key, CmdIdRecType * rec);

    /** initial */
    CmdIdStatusEnum CmdIdHashInit(int TableSize = 0);

    /** cleanup */
    CmdIdStatusEnum CmdIdHashClean();

protected:
    int compEQ(CmdIdKeyType key1, CmdIdKeyType key2);

public:
    //constructor
    cpl_HashTableCmdOneKey(int tablesize = 1000) {
        this->CmdIdHashTable = NULL;
        this->CmdIdHashTableSize = tablesize;
        CmdIdHashInit(tablesize);
    }

    //destructor
    virtual ~cpl_HashTableCmdOneKey() {
        CmdIdHashClean();
    }

protected:

    //variables
    CmdIdNodeType * * CmdIdHashTable;
    int CmdIdHashTableSize;
};

//-----------------------------------------------------------------------------
inline int cpl_HashTableCmdOneKey::compEQ(CmdIdKeyType key1, CmdIdKeyType key2) {
    if (strcmp(key1.id, key2.id) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
inline CmdIdHashIndexType cpl_HashTableCmdOneKey::CmdIdHashCmdtion(CmdIdKeyType key) {
    CmdIdHashIndexType h = 0;
    char * str = key.id;
    while (* str) {
        h += * str++;
    }
    return h % CmdIdHashTableSize;
}

//-----------------------------------------------------------------------------
inline CmdIdStatusEnum cpl_HashTableCmdOneKey::CmdIdInsert(CmdIdKeyType key, CmdIdRecType * rec) {
    CmdIdNodeType * p, * p0;
    CmdIdHashIndexType bucket;

    bucket = CmdIdHashCmdtion(key);
    p = new CmdIdNodeType;
    if (p == NULL) {
        return CMD_STATUS_MEM_EXHAUSTED;
    }
    p0 = CmdIdHashTable[bucket];
    CmdIdHashTable[bucket] = p;
    p->next = p0;
    strcpy(p->key.id, key.id);
    p->rec.stuff = rec->stuff;
    strcpy(p->rec.inkey.id, rec->inkey.id);
    return CMD_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline CmdIdStatusEnum cpl_HashTableCmdOneKey::CmdIdDelete(CmdIdKeyType key) {
    CmdIdNodeType * p0, * p;
    CmdIdHashIndexType bucket;

    p0 = 0;
    bucket = CmdIdHashCmdtion(key);
    p = CmdIdHashTable[bucket];
    while (p && !this->compEQ(p->rec.inkey, key)) {
        p0 = p;
        p = p->next;
    }

    if (!p) {
        return CMD_STATUS_KEY_NOT_FOUND;
    }

    if (p0) {
        p0->next = p->next;
    }
    else {
        CmdIdHashTable[bucket] = p->next;
    }

    delete(p);
    return CMD_STATUS_OK;
}

inline CmdIdStatusEnum cpl_HashTableCmdOneKey::CmdIdFind(CmdIdKeyType key, CmdIdRecType * rec) {
    CmdIdNodeType * p;

    p = CmdIdHashTable[CmdIdHashCmdtion(key)];
    while (p && !this->compEQ(p->rec.inkey, key)) {
        p = p->next;
    }
    if (!p) {
        return CMD_STATUS_KEY_NOT_FOUND;
    }
    * rec = p->rec;
    return CMD_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline CmdIdStatusEnum cpl_HashTableCmdOneKey::CmdIdHashInit(int TableSize) {
    //@@preconditions
    assert(TableSize > 0);
    //@@end preconditions

    int i;

    if (TableSize > 0) {
        CmdIdHashTableSize = TableSize;
    }
    CmdIdHashTable = new CmdIdNodeTypeP[CmdIdHashTableSize];
    if (CmdIdHashTable == NULL) {
        return CMD_STATUS_MEM_EXHAUSTED;
    }

    for (i = 0; i < CmdIdHashTableSize; i++) {
        CmdIdHashTable[i] = NULL;
    }

    return CMD_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline CmdIdStatusEnum cpl_HashTableCmdOneKey::CmdIdHashClean() {
    CmdIdNodeType * p0, * p;
    int i = 0;
    for (i = 0; i < CmdIdHashTableSize; i++) {
        p = CmdIdHashTable[i];
        while (p) {
            p0 = p;
            p = p->next;
            if (p0) {
                p0->rec.stuff->Delete();
                delete(p0);
                p0 = NULL;
            }
        }
    }
    if (CmdIdHashTable) {
        delete[] CmdIdHashTable;
    }
    CmdIdHashTable = NULL;

    return CMD_STATUS_OK;
}

#endif //CPL_HASHTABLECOMMAND_H
