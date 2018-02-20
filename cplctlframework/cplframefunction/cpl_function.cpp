#include "cpl_functionframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_Function
//------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------
void cpl_Function::Execute() {
    //@@preconditions
    assert(this->functionData.paramPoxy != NULL);
    //@@end preconditions

    //clear output buffer.
    this->functionData.paramPoxy->ClearOutputParameter();

    //execute direct.
    this->EnterExecuteDirect();
    this->ExecuteDirect();
    this->LeaveExecuteDirect();

    this->functionData.paramPoxy->ClearInputParameter();    
}

//------------------------------------------------------------------------------
int cpl_Function::DoCommandId(int cmdId) {
    //@@preconditions
    assert(this->functionData.process != NULL);
    //@@end preconditions

    this->functionData.process->EnterProcess();
    this->DoCommandDirect(cmdId);
    this->functionData.process->LeaveProcess();

    return 1;
}

//------------------------------------------------------------------------
void cpl_Function::SetParameterProxy(cpl_FunctionParameterProxy* proxy) {
    //@@preconditions
    //@@end preconditions
    
    this->functionData.paramPoxy = proxy;      
}

//-----------------------------------------------------------------------
cpl_FunctionParameterProxy* cpl_Function::GetParamterProxy() {
    return this->functionData.paramPoxy;
}

//-----------------------------------------------------------------------
void cpl_Function::SetFunctionProcess(cpl_FunctionProcess* process) {
    //@@preconditions
    assert(process != NULL);
    //@@end preconditions

    this->functionData.process = process;
}

//-----------------------------------------------------------------------
cpl_FunctionProcess* cpl_Function::GetFunctionProcess() {
    return this->functionData.process;
}

//-----------------------------------------------------------------------
void cpl_Function::SetCommandProxy(cpl_FunctionCommandProxy* proxy) {
    //@@preconditions
    assert(proxy != NULL);
    //@@end preconditions

    this->functionData.cmdProxy = proxy;
    this->serialDatProxy->SetCommandProxy(proxy);
}

//-----------------------------------------------------------------------
cpl_FunctionCommandProxy* cpl_Function::GetCommandProxy() {
    //@@preconditions
    //@@end preconditions
    
    return this->functionData.cmdProxy;
}

//-----------------------------------------------------------------------
void cpl_Function::SetContextProxy(cpl_FunctionContextProxy* proxy) {
    //@@preconditions
    assert(proxy != NULL);
    //@@end preconditions
    
    this->functionData.ctxProxy = proxy;
}

//-----------------------------------------------------------------------
cpl_FunctionContextProxy* cpl_Function::GetContextProxy() {
    return this->functionData.ctxProxy;
}

//-----------------------------------------------------------------------
cpl_FunctionSerialDataProxy* cpl_Function::GetFuncSerialDataProxy() {
    //@@preconditions
    assert(this->serialDatProxy != NULL);
    //@@end preconditions

    return this->serialDatProxy;
}

//------------------------------------------------------------------------
void cpl_Function::SetLocalStatus(int status) {
    this->functionData.lockStatus = status;
}

//------------------------------------------------------------------------
int  cpl_Function::GetLocalStatus() {
    return this->functionData.lockStatus;
}

//------------------------------------------------------------------------
void cpl_Function::SetProcessFunctionLockStatus(int status) {
    //@@preconditions
    assert(this->functionData.process != NULL);
    //@@end preconditions

    this->functionData.process->SetLocalStatus(status);
}

//------------------------------------------------------------------------
int  cpl_Function::GetProcessFunctionLockStatus() {
    //@@preconditions
    assert(this->functionData.process != NULL);
    //@@end preconditions

    return this->functionData.process->GetLocalStatus();
}

//------------------------------------------------------------------------
void cpl_Function::SynchronizeFunctionOnStack() {
    //@@preconditions
    assert(this->functionData.process != NULL);
    //@@end preconditions

    this->functionData.process->SynchronizeFunctionOnStack();
}

//------------------------------------------------------------------------
int cpl_Function::IsAsyncCommand(int id) {
    //@@preconditions
    //@@end preconditions

    return 0;
}

//------------------------------------------------------------------------
int cpl_Function::GetCommandNameFromID(int id, const char*& name) {
    //@@preconditions
    //@@end preconditions

    return 0;
}

//------------------------------------------------------------------------
int cpl_Function::GetCommandIDFromName(const char* name, int& id) {
    //@@preconditions
    //@@end preconditions

    return 0;
}

//------------------------------------------------------------------------
int cpl_Function::GetCommandNeedRecord(int id) {
    //@@preconditions
    //@@end preconditions

    return 1;
}

//------------------------------------------------------------------------
int cpl_Function::GetCommandNeedRefreshGUI(int id) {
    //@@preconditions
    //@@end preconditions

    return 0;
}

//-----------------------------------------------------------------------
int cpl_Function::GetWindowId() {
    return this->functionData.process->GetGraphicWindow();
}

//------------------------------------------------------------------------
cpl_Function::cpl_Function() {
    this->functionData.text[0]         ='\0';
    this->functionData.funcid          = 0;
    this->functionData.type            = 0;
    this->functionData.lockStatus      = 0;
    this->functionData.lockfuncdata    = 0;
    this->functionData.process         = NULL;
    this->functionData.paramPoxy       = NULL;
    this->functionData.cmdProxy        = NULL;
    this->functionData.ctxProxy        = NULL;
    this->serialDatProxy               = cpl_FunctionSerialDataProxy::New();
}

//------------------------------------------------------------------------
cpl_Function::~cpl_Function() {
    if (this->serialDatProxy != NULL) {
        this->serialDatProxy->Delete();
        this->serialDatProxy = NULL;
    }
}
