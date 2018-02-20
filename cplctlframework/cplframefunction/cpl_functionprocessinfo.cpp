#include "cpl_functionframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_FunctionProcessInfo
//-----------------------------------------------------------------------------
//
cpl_FunctionProcessInfo* cpl_FunctionProcessInfo::New() {
    return new cpl_FunctionProcessInfo;
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcessInfo::SetFunctionProcessDescription(char* processDesp) {
    //@@preconditions
    assert(processDesp != NULL);
    //@@end preconditions

    if (this->processInfo.processDesp != NULL) {
        delete[] this->processInfo.processDesp;
        this->processInfo.processDesp = NULL;
    }
    
    int slen = strlen(processDesp);
    this->processInfo.processDesp = new char[slen+1];
    strncpy(this->processInfo.processDesp, processDesp, slen);
    this->processInfo.processDesp[slen] = '\0';
}

//-----------------------------------------------------------------------------
char* cpl_FunctionProcessInfo::GetFunctionProcessDescription() {
    //@@preconditions
    assert(this->processInfo.processDesp != NULL);
    //@@end preconditions

    return this->processInfo.processDesp;
}

//-----------------------------------------------------------------------------
cpl_FunctionProcessInfo::cpl_FunctionProcessInfo() {
    this->processInfo.processDesp = NULL;
}

//-----------------------------------------------------------------------------
cpl_FunctionProcessInfo::~cpl_FunctionProcessInfo() {
    if (this->processInfo.processDesp != NULL) {
        delete[] this->processInfo.processDesp;
        this->processInfo.processDesp = NULL;
    }
}
