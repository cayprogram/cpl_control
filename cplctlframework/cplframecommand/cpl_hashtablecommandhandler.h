#ifndef CPL_HASHTABLECOMMANDHANDLER_H
#define CPL_HASHTABLECOMMANDHANDLER_H

/** implementation dependent declarations */
class cpl_CommandHandler;
typedef int CmdHandlerIdHashIndexType;

typedef struct CmdHandlerIdKeyTypeTag{
    char id[64];
}
CmdHandlerIdKeyType;

/** user data stored in hash table */
typedef struct CmdHandlerIdRecTypeTag {
    cpl_CommandHandler * stuff;
    CmdHandlerIdKeyType inkey;
}
CmdHandlerIdRecType;

/** implementation independent declarations */
typedef enum CmdHandlerIdStatusEnumTag{
    CMDHND_STATUS_OK, CMDHND_STATUS_MEM_EXHAUSTED, CMDHND_STATUS_KEY_NOT_FOUND
}
CmdHandlerIdStatusEnum;

typedef struct CmdHandlerIdNodeTag {
    struct CmdHandlerIdNodeTag * next; // next node
    CmdHandlerIdKeyType key; // key
    CmdHandlerIdRecType rec; // user data
}
CmdHandlerIdNodeType;

typedef CmdHandlerIdNodeType * CmdHandlerIdNodeTypeP;

//-----------------------------------------------------------------------------
class cpl_HashTableCmdHandlerOneKey {

public:
    /** hash command */
    CmdHandlerIdHashIndexType CmdHandlerIdHashCmdHandlertion(CmdHandlerIdKeyType key);

    /** insert */
    CmdHandlerIdStatusEnum CmdHandlerIdInsert(CmdHandlerIdKeyType key, CmdHandlerIdRecType * rec);

    /** delete */
    CmdHandlerIdStatusEnum CmdHandlerIdDelete(CmdHandlerIdKeyType key);

    /** find */
    CmdHandlerIdStatusEnum CmdHandlerIdFind(CmdHandlerIdKeyType key, CmdHandlerIdRecType * rec);

    /** initial */
    CmdHandlerIdStatusEnum CmdHandlerIdHashInit(int TableSize = 0);

    /** cleanup */
    CmdHandlerIdStatusEnum CmdHandlerIdHashClean();

protected:
    int compEQ(CmdHandlerIdKeyType key1, CmdHandlerIdKeyType key2);

public:
    //constructor
    cpl_HashTableCmdHandlerOneKey(int tablesize = 1000) {
        this->CmdHandlerIdHashTable = NULL;
        this->CmdHandlerIdHashTableSize = tablesize;
        CmdHandlerIdHashInit(tablesize);
    }

    //destructor
    virtual ~cpl_HashTableCmdHandlerOneKey() {
        CmdHandlerIdHashClean();
    }

protected:

    //variables
    CmdHandlerIdNodeType * * CmdHandlerIdHashTable;
    int CmdHandlerIdHashTableSize;
};

//-----------------------------------------------------------------------------
inline int cpl_HashTableCmdHandlerOneKey::compEQ(CmdHandlerIdKeyType key1, CmdHandlerIdKeyType key2) {
    if (strcmp(key1.id, key2.id) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
inline CmdHandlerIdHashIndexType cpl_HashTableCmdHandlerOneKey::CmdHandlerIdHashCmdHandlertion(CmdHandlerIdKeyType key) {
    CmdHandlerIdHashIndexType h = 0;
    char * str = key.id;
    while (* str) {
        h += * str++;
    }
    return h % CmdHandlerIdHashTableSize;
}

//-----------------------------------------------------------------------------
inline CmdHandlerIdStatusEnum cpl_HashTableCmdHandlerOneKey::CmdHandlerIdInsert(CmdHandlerIdKeyType key, CmdHandlerIdRecType * rec) {
    CmdHandlerIdNodeType * p, * p0;
    CmdHandlerIdHashIndexType bucket;

    bucket = CmdHandlerIdHashCmdHandlertion(key);
    p = new CmdHandlerIdNodeType;
    if (p == NULL) {
        return CMDHND_STATUS_MEM_EXHAUSTED;
    }
    p0 = CmdHandlerIdHashTable[bucket];
    CmdHandlerIdHashTable[bucket] = p;
    p->next = p0;
    strcpy(p->key.id, key.id);
    p->rec.stuff = rec->stuff;
    strcpy(p->rec.inkey.id, rec->inkey.id);
    return CMDHND_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline CmdHandlerIdStatusEnum cpl_HashTableCmdHandlerOneKey::CmdHandlerIdDelete(CmdHandlerIdKeyType key) {
    CmdHandlerIdNodeType * p0, * p;
    CmdHandlerIdHashIndexType bucket;

    p0 = 0;
    bucket = CmdHandlerIdHashCmdHandlertion(key);
    p = CmdHandlerIdHashTable[bucket];
    while (p && !this->compEQ(p->rec.inkey, key)) {
        p0 = p;
        p = p->next;
    }

    if (!p) {
        return CMDHND_STATUS_KEY_NOT_FOUND;
    }

    if (p0) {
        p0->next = p->next;
    }
    else {
        CmdHandlerIdHashTable[bucket] = p->next;
    }

    delete(p);
    return CMDHND_STATUS_OK;
}

inline CmdHandlerIdStatusEnum cpl_HashTableCmdHandlerOneKey::CmdHandlerIdFind(CmdHandlerIdKeyType key, CmdHandlerIdRecType * rec) {
    CmdHandlerIdNodeType * p;

    p = CmdHandlerIdHashTable[CmdHandlerIdHashCmdHandlertion(key)];
    while (p && !this->compEQ(p->rec.inkey, key)) {
        p = p->next;
    }
    if (!p) {
        return CMDHND_STATUS_KEY_NOT_FOUND;
    }
    * rec = p->rec;
    return CMDHND_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline CmdHandlerIdStatusEnum cpl_HashTableCmdHandlerOneKey::CmdHandlerIdHashInit(int TableSize) {
    //@@preconditions
    assert(TableSize > 0);
    //@@end preconditions

    int i;

    if (TableSize > 0) {
        CmdHandlerIdHashTableSize = TableSize;
    }
    CmdHandlerIdHashTable = new CmdHandlerIdNodeTypeP[CmdHandlerIdHashTableSize];
    if (CmdHandlerIdHashTable == NULL) {
        return CMDHND_STATUS_MEM_EXHAUSTED;
    }

    for (i = 0; i < CmdHandlerIdHashTableSize; i++) {
        CmdHandlerIdHashTable[i] = NULL;
    }

    return CMDHND_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline CmdHandlerIdStatusEnum cpl_HashTableCmdHandlerOneKey::CmdHandlerIdHashClean() {
    CmdHandlerIdNodeType * p0, * p;
    int i = 0;
    for (i = 0; i < CmdHandlerIdHashTableSize; i++) {
        p = CmdHandlerIdHashTable[i];
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
    if (CmdHandlerIdHashTable) {
        delete[] CmdHandlerIdHashTable;
    }
    CmdHandlerIdHashTable = NULL;

    return CMDHND_STATUS_OK;
}

#endif //CPL_HASHTABLECOMMANDHANDLER_H
