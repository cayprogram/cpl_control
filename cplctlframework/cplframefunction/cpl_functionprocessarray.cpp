#include "cpl_functionframeincludes.h"

//-------------------------------------------------------------------------
// class cpl_FunctionProcessArray
//-------------------------------------------------------------------------
//

cpl_FunctionProcessArray* cpl_FunctionProcessArray::New() {
    return new cpl_FunctionProcessArray;
}

//-------------------------------------------------------------------------
int cpl_FunctionProcessArray::InsertNextFunctionProcess(cpl_FunctionProcess* funcProcess) {    
    //@@preconditions
    assert(funcProcess != NULL);
    //@@end preconditions

    return this->InsertNextItem(funcProcess);
}

//-------------------------------------------------------------------------
int cpl_FunctionProcessArray::RemoveFunctionProcess(cpl_FunctionProcess* funcProcess) {
    //@@preconditions
    assert(funcProcess != NULL);
    //@@end preconditions

    return this->RemoveItem(funcProcess);
}

//-------------------------------------------------------------------------
cpl_FunctionProcess* cpl_FunctionProcessArray::GetFunctionProcessByIndex(int idx) {
    //@@preconditions
    assert(idx >= 0 && idx < this->GetNumberOfItems());
    //@@end preconditions

    return (cpl_FunctionProcess*) this->GetItem(idx);
}

//-------------------------------------------------------------------------
cpl_FunctionProcessArray::cpl_FunctionProcessArray() {
}

//-------------------------------------------------------------------------
cpl_FunctionProcessArray::~cpl_FunctionProcessArray() {
}
