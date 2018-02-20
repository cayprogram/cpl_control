#ifndef CPL_HASHTABLEFUNCTION_H
#define CPL_HASHTABLEFUNCTION_H

/** implementation dependent declarations */
typedef int FuncIdHashIndexType;

typedef struct FuncIdKeyTypeTag{
    char id[64];
}
FuncIdKeyType;

/** user data stored in hash table */
typedef struct FuncIdRecTypeTag {
    cpl_Function * stuff;
    FuncIdKeyType inkey;
}
FuncIdRecType;

/** implementation independent declarations */
typedef enum FuncIdStatusEnumTag{
    FUNC_STATUS_OK, FUNC_STATUS_MEM_EXHAUSTED, FUNC_STATUS_KEY_NOT_FOUND
}
FuncIdStatusEnum;

typedef struct FuncIdNodeTag {
    struct FuncIdNodeTag * next; // next node
    FuncIdKeyType key; // key
    FuncIdRecType rec; // user data
}
FuncIdNodeType;

typedef FuncIdNodeType * FuncIdNodeTypeP;

//-----------------------------------------------------------------------------
class cpl_HashTableFuncOneKey {

public:
    /** hash function */
    FuncIdHashIndexType FuncIdHashFunction(FuncIdKeyType key);

    /** insert */
    FuncIdStatusEnum FuncIdInsert(FuncIdKeyType key, FuncIdRecType * rec);

    /** delete */
    FuncIdStatusEnum FuncIdDelete(FuncIdKeyType key);

    /** find */
    FuncIdStatusEnum FuncIdFind(FuncIdKeyType key, FuncIdRecType * rec);

    /** initial */
    FuncIdStatusEnum FuncIdHashInit(int TableSize = 0);

    /** cleanup */
    FuncIdStatusEnum FuncIdHashClean();
    
    /** init traversal hash table*/
    FuncIdStatusEnum InitTraversal();

    /** get first node in hash table*/
    FuncIdStatusEnum GetFirstItemDetail(FuncIdRecType * rec);

    /** get hash table node */
    FuncIdStatusEnum GetNextItemDetail(FuncIdRecType * rec);

public:
    //constructor
    cpl_HashTableFuncOneKey(int tablesize = 1000) {
        this->FuncIdHashTable = NULL;
        this->FuncIdHashTableSize = tablesize;
        FuncIdHashInit(tablesize);
        this->FuncIdNode = NULL;
        this->iHashTableNum = 0;
    }

    //destructor
    virtual ~cpl_HashTableFuncOneKey() {
        FuncIdHashClean();
    }

protected:
    //variables
    FuncIdNodeType * * FuncIdHashTable;
    int FuncIdHashTableSize;

protected:
    //variables for traversal
    FuncIdNodeType * FuncIdNode;
    int iHashTableNum;
};

//-----------------------------------------------------------------------------
inline int compEQ(FuncIdKeyType key1, FuncIdKeyType key2) {
    if (strcmp(key1.id, key2.id) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
inline FuncIdHashIndexType cpl_HashTableFuncOneKey::FuncIdHashFunction(FuncIdKeyType key) {
    FuncIdHashIndexType h = 0;
    char * str = key.id;
    while (* str) {
        h += * str++;
    }
    return h % FuncIdHashTableSize;
}

//-----------------------------------------------------------------------------
inline FuncIdStatusEnum cpl_HashTableFuncOneKey::FuncIdInsert(FuncIdKeyType key, FuncIdRecType * rec) {
    FuncIdNodeType * p, * p0;
    FuncIdHashIndexType bucket;

    bucket = FuncIdHashFunction(key);
    p = new FuncIdNodeType;
    if (p == NULL) {
        return FUNC_STATUS_MEM_EXHAUSTED;
    }
    p0 = FuncIdHashTable[bucket];
    FuncIdHashTable[bucket] = p;
    p->next = p0;
    strcpy(p->key.id, key.id);
    p->rec.stuff = rec->stuff;
    strcpy(p->rec.inkey.id, rec->inkey.id);
    return FUNC_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline FuncIdStatusEnum cpl_HashTableFuncOneKey::FuncIdDelete(FuncIdKeyType key) {
    FuncIdNodeType * p0, * p;
    FuncIdHashIndexType bucket;

    p0 = 0;
    bucket = FuncIdHashFunction(key);
    p = FuncIdHashTable[bucket];
    while (p && !compEQ(p->rec.inkey, key)) {
        p0 = p;
        p = p->next;
    }

    if (!p) {
        return FUNC_STATUS_KEY_NOT_FOUND;
    }

    if (p0) {
        p0->next = p->next;
    }
    else {
        FuncIdHashTable[bucket] = p->next;
    }

    delete(p);
    return FUNC_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline FuncIdStatusEnum cpl_HashTableFuncOneKey::FuncIdFind(FuncIdKeyType key, FuncIdRecType * rec) {
    FuncIdNodeType * p;

    p = FuncIdHashTable[FuncIdHashFunction(key)];
    while (p && !compEQ(p->rec.inkey, key)) {
        p = p->next;
    }
    if (!p) {
        return FUNC_STATUS_KEY_NOT_FOUND;
    }
    * rec = p->rec;
    return FUNC_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline FuncIdStatusEnum cpl_HashTableFuncOneKey::FuncIdHashInit(int TableSize) {
    //@@preconditions
    assert(TableSize > 0);
    //@@end preconditions

    int i;

    if (TableSize > 0) {
        FuncIdHashTableSize = TableSize;
    }
    FuncIdHashTable = new FuncIdNodeTypeP[FuncIdHashTableSize];
    if (FuncIdHashTable == NULL) {
        return FUNC_STATUS_MEM_EXHAUSTED;
    }

    for (i = 0; i < FuncIdHashTableSize; i++) {
        FuncIdHashTable[i] = NULL;
    }

    return FUNC_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline FuncIdStatusEnum cpl_HashTableFuncOneKey::FuncIdHashClean() {
    FuncIdNodeType * p0, * p;
    int i = 0;
    for (i = 0; i < FuncIdHashTableSize; i++) {
        p = FuncIdHashTable[i];
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
    if (FuncIdHashTable) {
        delete[] FuncIdHashTable;
    }
    FuncIdHashTable = NULL;

    return FUNC_STATUS_OK;
}

//-----------------------------------------------------------------------------
inline FuncIdStatusEnum cpl_HashTableFuncOneKey::InitTraversal() {
    FuncIdNodeType* p = NULL;
    int i = 0;
    for (i = 0; i < FuncIdHashTableSize; i++) {
        p = FuncIdHashTable[i];
        this->iHashTableNum = i;
        if (p != NULL)
            break;
    }

    this->FuncIdNode = p;
    if (this->FuncIdNode != NULL){
        return FUNC_STATUS_OK;
    }

    return FUNC_STATUS_KEY_NOT_FOUND;
}

//-----------------------------------------------------------------------------
inline FuncIdStatusEnum cpl_HashTableFuncOneKey::GetFirstItemDetail(FuncIdRecType * rec) {
    *rec = this->FuncIdNode->rec;
    if (this->FuncIdNode != NULL) {
        return FUNC_STATUS_OK;
    }
    
    return FUNC_STATUS_KEY_NOT_FOUND;
}

//-----------------------------------------------------------------------------
inline FuncIdStatusEnum cpl_HashTableFuncOneKey::GetNextItemDetail(FuncIdRecType * rec) {
    if (this->FuncIdNode == NULL) {
        return FUNC_STATUS_KEY_NOT_FOUND;
    }else if (this->FuncIdNode->next != NULL) {
        this->FuncIdNode = this->FuncIdNode->next;
    }else {
        for (int i = this->iHashTableNum + 1; i < FuncIdHashTableSize; i++) {
            this->FuncIdNode = FuncIdHashTable[i];
            if (this->FuncIdNode != NULL) {
                this->iHashTableNum = i;
                break;
            }
        }
    }
    if (this->FuncIdNode != NULL) {
        *rec = this->FuncIdNode->rec;
        return FUNC_STATUS_OK;
    }

    return FUNC_STATUS_KEY_NOT_FOUND;
}

#endif //CPL_HASHTABLEFUNCTION_H
