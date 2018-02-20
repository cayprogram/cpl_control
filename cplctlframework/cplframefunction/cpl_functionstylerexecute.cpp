#include "cpl_functionframeincludes.h"
#include "cpl_functionstylerexecute.h"

//-----------------------------------------------------------------------------
// class cpl_FunctionExecuteImp
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
IParameterEngineWriteRight* cpl_FunctionExecuteImp::GetInputWriteRight() {
    //@@preconditions
    assert(this->pDDX != NULL);
    assert(this->pDDX->GetParamEngine() != NULL);
    //@@end preconditions

    return this->pDDX->GetParamEngine()->GetInputWriteRight();
}

//-----------------------------------------------------------------------------
IParameterEngineReadRight* cpl_FunctionExecuteImp::GetOutputReadRight() {
    //@@preconditions
    assert(this->pDDX != NULL);
    assert(this->pDDX->GetParamEngine() != NULL);
    //@@end preconditions
    
    return this->pDDX->GetParamEngine()->GetOutputReadRight();
}

//-----------------------------------------------------------------------------
int cpl_FunctionExecuteImp::DoCommandId(int cmdId) {
    //@@preconditions
    assert(this->Owner != NULL);
    //@@end preconditions

    return this->Owner->DoCommandId(cmdId);
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteImp::SetDataExchange(cpl_FunctionParameter* pDataX) {
    //@@preconditions
    //@@end preconditions

    this->pDDX = pDataX;
}

//-----------------------------------------------------------------------------
cpl_FunctionExecuteImp::cpl_FunctionExecuteImp(cpl_StylerFunction* pOwner) {
    this->Owner = pOwner;
    this->pDDX  = NULL;
}

//-----------------------------------------------------------------------------
cpl_FunctionExecuteImp::~cpl_FunctionExecuteImp() {
}
