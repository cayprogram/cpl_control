#include "cpl_functionframeincludes.h"
#include "cpl_hashtablefunction.h"

//------------------------------------------------------------------------------
// class cpl_FunctionProcess15
//------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------
cpl_FunctionProcess15::cpl_FunctionProcess15() {
    this->hashFuncStringKey = new cpl_HashTableFuncOneKey;
}

//------------------------------------------------------------------------------
cpl_FunctionProcess15::~cpl_FunctionProcess15() {
    if (this->hashFuncStringKey) {
        delete this->hashFuncStringKey;
        this->hashFuncStringKey = NULL;
    }
}

//------------------------------------------------------------------------------
int cpl_FunctionProcess15::InsertFunction(cpl_Function * cmdObject) {
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

//------------------------------------------------------------------------------
int cpl_FunctionProcess15::ExecuteFunction(char* string) {
    //@@preconditions.
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

    //execute.
    return this->ExecuteFunctionDirect(stringRec.stuff);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcess15::IsFunctionExist(char * string) {
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
int cpl_FunctionProcess15::FindFunction(char* string, cpl_Function * & funcObject) {
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
int cpl_FunctionProcess15::IsContextValid(char* string) {
    //@@preconditions
    assert(string != NULL);
    assert(strlen(string) > 0);
    //@@end preconditions

    cpl_Function* func = NULL;
    this->FindFunction(string, func);
    if (func == NULL) {
        return 0;
    }
    return func->IsValidContext();
}

//------------------------------------------------------------------------------
int cpl_FunctionProcess15::InitTraversal() {
    //@@postconditions
    assert(this->hashFuncStringKey != NULL);
    //@@end postconditions

    FuncIdStatusEnum stat = this->hashFuncStringKey->InitTraversal();
    if (stat == FUNC_STATUS_KEY_NOT_FOUND) {
        return 0;
    }

    return 1;
}
//------------------------------------------------------------------------------
int cpl_FunctionProcess15::GetFirstItemDetail(cpl_Function * & funcObject) {
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
int cpl_FunctionProcess15::GetNextItemDetail(cpl_Function * & funcObject) {
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
