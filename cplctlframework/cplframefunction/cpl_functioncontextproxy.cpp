#include "cpl_functionframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_FunctionContextProxy.
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
void cpl_FunctionContextProxy::SetFunctionKeyString(char* funString) {
    //@@preconditions
    //@@end preconditions

    if (this->funcContextData.keyString != NULL) {
        delete[] this->funcContextData.keyString;
        this->funcContextData.keyString = NULL;
    }

    if (funString != NULL) {
        int slen = (int)strlen(funString);
        assert(slen > 0);

        this->funcContextData.keyString = new char[slen+1];
        sprintf(this->funcContextData.keyString, "%s", funString);
    }
}

//-----------------------------------------------------------------------------
char* cpl_FunctionContextProxy::GetFunctionKeyString() {
    //@@preconditions
    //@@end preconditions

    return this->funcContextData.keyString;
}

//////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
cpl_FunctionContextProxy::cpl_FunctionContextProxy() {
    //@@preconditions
    //@@end preconditions

    this->funcContextData.keyString = NULL;
}

//-----------------------------------------------------------------------------
cpl_FunctionContextProxy::~cpl_FunctionContextProxy() {
    if (this->funcContextData.keyString != NULL) {
        delete[] this->funcContextData.keyString;
        this->funcContextData.keyString = NULL;
    }
}
