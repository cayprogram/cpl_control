#include "cpl_functionframeincludes.h"
#include "cpl_functioncollection.h"

//------------------------------------------------------------------------------
// class cpl_FunctionsManager
//------------------------------------------------------------------------------
//
cpl_FunctionsManager * cpl_FunctionsManager::instance = NULL;

//-----------------------------------------------------------------------------
cpl_FunctionsManager * cpl_FunctionsManager::Instance() {
    return cpl_FunctionsManager::instance;
}

//-----------------------------------------------------------------------------
void cpl_FunctionsManager::SetFactory(cpl_FunctionsManager* uInstance) {
    cpl_FunctionsManager::instance = uInstance;
}

//-----------------------------------------------------------------------------
int cpl_FunctionsManager::IsContextValid(char* funcName) {
    //@@preconditions
    assert(funcName != NULL);
    assert(funcName[0] != '\0');
    //@@end preconditions
    
    int nprocess = 0;  cpl_FunctionProcess** processes = NULL;
    this->GetActiveFunctionProcesses(funcName, nprocess, processes);
    
    int executed = 0;
    for (int i = 0; i < nprocess; i++) {
        cpl_FunctionProcess* uFuncProcess = processes[i];
        assert(uFuncProcess != NULL);
        
        uFuncProcess->EnterProcess();
        if (uFuncProcess->IsContextValid(funcName) == 1) {
            executed = 1;
        }
        uFuncProcess->LeaveProcess();
    }    
    if (processes != NULL) {
        delete[] processes;
    }
    return executed;    
}

//-----------------------------------------------------------------------------
int cpl_FunctionsManager::FindFunction(char* funcName, cpl_Function*& funcObj) {
    //@@preconditions
    assert(funcName != NULL);
    assert(funcName[0] != '\0');
    //@@end preconditions

    int nprocess = 0;  cpl_FunctionProcess** processes = NULL;
    this->GetActiveFunctionProcesses(funcName, nprocess, processes);

    int ret = 0;
    for (int i = 0; i < nprocess; i++) {
        cpl_FunctionProcess* uFuncProcess = processes[i];
        assert(uFuncProcess != NULL);

        if (uFuncProcess->FindFunction(funcName, funcObj) == 1) {
            assert(funcObj != NULL);
            ret = 1;
            break;
        }
    }

    if (processes != NULL) {
        delete[] processes;
    }
    return ret;
}

//-----------------------------------------------------------------------------
int  cpl_FunctionsManager::ExecuteFunction(char* funcName) {
    //@@precondition
    assert(funcName != NULL);
    assert(strlen(funcName) > 0);
    assert(this->funcProcessMan != NULL);
    assert(this->paramHandler   != NULL);
    //@@end preconditions
    
    int nprocess = 0;  cpl_FunctionProcess** processes = NULL;
    this->GetActiveFunctionProcesses(funcName, nprocess, processes);
    
    int executed = 0;
    for (int i = 0; i < nprocess; i++) {
        cpl_FunctionProcess* uFuncProcess = processes[i];
        assert(uFuncProcess != NULL);

        int ret = this->ExecuteFunction(funcName, uFuncProcess);
        if (ret == 1) {
            executed = 1;
        }
    }

    if (processes != NULL) {
        delete[] processes;
    }
    return executed;
}

//-----------------------------------------------------------------------------
int cpl_FunctionsManager::ExecuteFunction(char* funcName, cpl_FunctionProcess* funcProcess) {
    //@@preconditions
    assert(funcName != NULL);
    assert(funcProcess != NULL);
    //@@end preconditions

    cpl_Function* uFunction = NULL;
    if (funcProcess->FindFunction(funcName, uFunction) == 0) {
        return 0;
    }

    int executed = 0;
    funcProcess->EnterProcess();
    if (funcProcess->IsContextValid(funcName) == 1) {
        funcProcess->EnterFunctionScope();
        this->paramHandler->ExechangeInputParameter(funcProcess);
        executed = funcProcess->ExecuteFunction(funcName);
        this->paramHandler->ExechangeOutputParameter(funcProcess);
        funcProcess->LeaveFunctionScope();
    }
    funcProcess->LeaveProcess();

    return executed;
}

//-----------------------------------------------------------------------------
cpl_FunctionProcessManager* cpl_FunctionsManager::GetFunctionProcessManager() {
    //@@preconditions
    assert(this->funcProcessMan != NULL);
    //@@end preconditions

    return this->funcProcessMan;
}

//-----------------------------------------------------------------------------
cpl_FunctionProcess* cpl_FunctionsManager::GetActiveWinFunctionProcess(int& processId) {
    //@@preconditions
    //@@end preconditions
    assert(0);
    return NULL;
}

//-----------------------------------------------------------------------------
cpl_FunctionProcessParameter* cpl_FunctionsManager::GetParamBufferIO() {
    //@@preconditions
    assert(this->paramHandler != NULL);
    //@@end preconditions

    return this->paramHandler;
}

//-----------------------------------------------------------------------------
cpl_FunctionsManager::cpl_FunctionsManager() { 
    this->paramHandler     = cpl_FunctionProcessParameter::New();
    this->funcProcessMan   = NULL;
}

//------------------------------------------------------------------------------
cpl_FunctionsManager::~cpl_FunctionsManager() {
    if (this->paramHandler != NULL) {
        this->paramHandler->Delete();
        this->paramHandler = NULL;
    }
    if (this->funcProcessMan != NULL) {
        this->funcProcessMan->Delete();
        this->funcProcessMan = NULL;
    }
}
