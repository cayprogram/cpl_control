#include "cpl_functionframeincludes.h"
#include "cpl_hashtablefunction.h"
#include "cpl_functioncollection.h"

//------------------------------------------------------------------------------
// class cpl_FunctionCollection
//------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------
int cpl_FunctionCollection::InsertFunction(cpl_Function * cmdObject) {
    //@@preconditions
    assert(cmdObject != NULL);
    //@@end preconditions
    
    FuncIdRecType stringRec;
    const char * stringFunc = cmdObject->GetStringId();
    assert(stringFunc != NULL);
    
    FuncIdKeyType stringKey;    
    strcpy(stringKey.id, stringFunc);
    
    FuncIdStatusEnum stat = this->hashFuncStringKey->FuncIdFind(stringKey, & stringRec);
    if (stat == FUNC_STATUS_OK) {
        assert(0);
        return 0;
    }
    
    strcpy(stringRec.inkey.id, stringFunc);
    stringRec.stuff = cmdObject;
    this->hashFuncStringKey->FuncIdInsert(stringRec.inkey, & stringRec);
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_FunctionCollection::IsFunctionExist(char * string) {
    //@@preconditions
    assert(string != NULL);
    assert(strlen(string) > 0);
    assert(this->hashFuncStringKey != NULL);
    //@@end preconditions
    
    FuncIdRecType stringRec;
    FuncIdKeyType stringKey;
    
    strcpy(stringKey.id, string);
    stringRec.stuff = NULL;
    FuncIdStatusEnum stat = this->hashFuncStringKey->FuncIdFind(stringKey, & stringRec);
    if (stat == FUNC_STATUS_KEY_NOT_FOUND) {
        return 0;
    }
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_FunctionCollection::FindFunction(char* string, cpl_Function * & funcObject) {
    //@@preconditions
    assert(funcObject == NULL);
    assert(string != NULL);
    assert(strlen(string) > 0);
    assert(this->hashFuncStringKey != NULL);
    //@@end preconditions
    
    FuncIdRecType stringRec;
    FuncIdKeyType stringKey;
    
    strcpy(stringKey.id, string);
    
    stringRec.stuff = NULL;
    FuncIdStatusEnum stat = this->hashFuncStringKey->FuncIdFind(stringKey, & stringRec);
    if (stat == FUNC_STATUS_KEY_NOT_FOUND) {
        return 0;
    }
    funcObject = stringRec.stuff;
    
    //@@postconditions
    assert(funcObject != NULL);
    //@@end postconditions
    
    return 1;
}


//------------------------------------------------------------------------------
int cpl_FunctionCollection::InitTraversal() {
    //@@preconditions
    assert(this->hashFuncStringKey != NULL);
    //@@end preconditions

    FuncIdStatusEnum status = this->hashFuncStringKey->InitTraversal();
    if (status == FUNC_STATUS_OK) {
        return 1;
    }
    return 0;
}

//------------------------------------------------------------------------------
int cpl_FunctionCollection::GetFirstItem(cpl_Function * & funcObject) {
    //@@postconditions
    assert(this->hashFuncStringKey != NULL);
    //@@end postconditions

    FuncIdRecType stringRec;
    stringRec.stuff = NULL;

    FuncIdStatusEnum stat = this->hashFuncStringKey->GetFirstItemDetail(&stringRec);
    if (stat == FUNC_STATUS_KEY_NOT_FOUND) {
        funcObject = NULL;
        return 0;
    }
    funcObject = stringRec.stuff;
    return 1;
}

//------------------------------------------------------------------------------
int cpl_FunctionCollection::GetNextItem(cpl_Function * & funcObject) {
    //@@postconditions
    assert(this->hashFuncStringKey != NULL);
    //@@end postconditions

    FuncIdRecType stringRec;
    stringRec.stuff = NULL;

    FuncIdStatusEnum stat = this->hashFuncStringKey->GetNextItemDetail(&stringRec);
    if (stat == FUNC_STATUS_KEY_NOT_FOUND) {
        funcObject = NULL;
        return 0;
    }
    funcObject = stringRec.stuff;
    return 1;
}

//------------------------------------------------------------------------------
cpl_FunctionCollection::cpl_FunctionCollection() {
    this->hashFuncStringKey = new cpl_HashTableFuncOneKey;
}

//------------------------------------------------------------------------------
cpl_FunctionCollection::~cpl_FunctionCollection() {
    if (this->hashFuncStringKey) {
        delete this->hashFuncStringKey;
        this->hashFuncStringKey = NULL;
    }
}
