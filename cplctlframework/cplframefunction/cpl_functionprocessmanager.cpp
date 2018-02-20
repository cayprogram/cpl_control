#include "cpl_functionframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_FunctionProcessManager
//------------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
int cpl_FunctionProcessManager::SetFunctionManager(cpl_FunctionsManager* functionManager) {
    //@@preconditions
    assert(functionManager != NULL);
    //@@end preconditions

    this->uFuncManager = functionManager;
    return 1;
}

//-----------------------------------------------------------------------------
cpl_FunctionsManager* cpl_FunctionProcessManager::GetFunctionManager() {
    //@@postconditions
    assert(this->uFuncManager != NULL);
    //@@end postconditions

    return this->uFuncManager;
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessManager::GetFunctionProcessNumber() {
    //@@preconditions
    assert(this->uFuncProcessSet != NULL);
    //@@end preconditions

    return this->uFuncProcessSet->GetNumberOfItems();
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessManager::DeleteFunctionProcess(int processId) {
    //@@preconditions
    assert(processId > 0);
    assert(this->uFuncProcessSet != NULL);
    //@@end preconditions

    cpl_FunctionProcess* uFuncProcess = this->GetFunctionProcess(processId);
    if (uFuncProcess != NULL) {
        uFuncProcess->StopProcess();
        this->uFuncProcessSet->RemoveFunctionProcess(uFuncProcess);
        return 1;
    }
    return 0;
}

//-----------------------------------------------------------------------------
cpl_FunctionProcess* cpl_FunctionProcessManager::GetFunctionProcess(int processId) {
    //@@preconditions
    assert(processId > 0);
    assert(this->uFuncProcessSet != NULL);
    //@@end preconditions
    
    int index = this->FindFunctionProcess(processId);  
    if (index >= 0) {
        return this->uFuncProcessSet->GetFunctionProcessByIndex(index);
    }    
    return NULL;
}

//-----------------------------------------------------------------------------
cpl_FunctionProcess* cpl_FunctionProcessManager::GetFunctionProcess(char* processName) {
    //@@preconditions
    assert(processName != NULL);
    assert(this->uFuncProcessSet != NULL);
    //@@end preconditions

    int index = this->FindFunctionProcess(processName);  
    if (index >= 0) {
        return this->uFuncProcessSet->GetFunctionProcessByIndex(index);
    }    
    return NULL;
}

//------------------------------------------------------------------------------
int cpl_FunctionProcessManager::FindFunctionProcess(int processId) {
    //@@preconditions
    assert(processId > 0);
    assert(this->uFuncProcessSet != NULL);
    //@@end preconditions
    
    int index = -1;
    for (int i = 0; i < this->uFuncProcessSet->GetNumberOfItems(); i++) {
        cpl_FunctionProcess* funcProcess = this->uFuncProcessSet->GetFunctionProcessByIndex(i);
        assert(funcProcess != NULL);
        if (funcProcess->GetProcessId() == processId) {
            index = i;
            break;
        }
    }
    return index;
}

//------------------------------------------------------------------------------
int cpl_FunctionProcessManager::FindFunctionProcess(char* processName) {
    //@@preconditions
    assert(processName != NULL);
    //@@end preconditions

    int slen = (int)strlen(processName);

    int index = -1;
    for (int i = 0; i < this->uFuncProcessSet->GetNumberOfItems(); i++) {
        cpl_FunctionProcess* funcProcess = this->uFuncProcessSet->GetFunctionProcessByIndex(i);
        assert(funcProcess != NULL);
        char* pName = funcProcess->GetProcessName();
        int plen    = (int)strlen(pName);
        if (slen == plen && strcmp(processName, pName) == NULL) {
            index = i;
            break;
        }
    }
    return index;
}

//-----------------------------------------------------------------------------
cpl_FunctionProcess* cpl_FunctionProcessManager::GetFunctionProcessByIndex(int idx) {
    //@@preconditions
    assert(this->uFuncProcessSet != NULL);
    assert(idx >= 0 && idx < this->uFuncProcessSet->GetNumberOfItems());
    //@@end preconditions
    
    return this->uFuncProcessSet->GetFunctionProcessByIndex(idx);
}

//-----------------------------------------------------------------------------
cpl_FunctionProcess* cpl_FunctionProcessManager::GetActiveWinFunctionProcess(int& processId) {
    //@@preconditions
    assert(processId == -1);
    assert(this->uFuncManager != NULL);
    //@@end preconditions

    return this->uFuncManager->GetActiveWinFunctionProcess(processId);
}

//-----------------------------------------------------------------------------
cpl_FunctionProcessManager::cpl_FunctionProcessManager() { 
    this->uFuncManager = NULL;
    this->uFuncProcessSet = cpl_FunctionProcessArray::New();
    this->uFuncProcessSet->Allocate(10, 10);
}

//------------------------------------------------------------------------------
cpl_FunctionProcessManager::~cpl_FunctionProcessManager() {
    if (this->uFuncProcessSet != NULL) {
        this->uFuncProcessSet->Delete();
        this->uFuncProcessSet = NULL;
    }
}
