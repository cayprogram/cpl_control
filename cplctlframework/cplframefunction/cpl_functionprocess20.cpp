#include "cpl_functionframeincludes.h"
#include "cpl_functionsessiondataproxy.h"

//------------------------------------------------------------------------
// class cpl_FunctionProcess20
//------------------------------------------------------------------------
//
//------------------------------------------------------------------------
int cpl_FunctionProcess20::ExecuteFunction(char* string) {
    //@@preconditions
    assert(string != NULL);
    assert(this->functionParameter != NULL);
    //@@end preconditions

    int ret = 0;
    if (this->funcExecuteStatus == 1) {
        if (this->IsRecordSessionForFunction(string) == 1) {
            this->RecordSessionFunction(string);
        }
        ret = cpl_FunctionProcess15::ExecuteFunction(string);
    }

    if (this->funcExecuteStatus == 0) {
        if (this->IsRecordSessionForFunction(string) == 1) {
            this->RecordSessionFunction(string);
        }
        this->funcExecuteStatus = 1;
        ret = cpl_FunctionProcess15::ExecuteFunction(string);
        this->funcExecuteStatus = 0;
    }

    //clear input parameters.
    this->functionParameter->GetParamEngine()->GetInputReadRight()->Clear();
    return ret;
}

//------------------------------------------------------------------------
int cpl_FunctionProcess20::IsRecordSessionForFunction(char* funcName) {
    //@@preconditions
    assert(funcName != NULL);
    assert(this->pSessionProxy != NULL);
    //@@end preconditions

    if (this->pSessionProxy->IsValidRecordSession() == 0) {
        return 0;
    }
    if (this->pSessionProxy->IsSkipRecordFunction(funcName) == 1) {
        return 0;
    }
    if (this->pSessionProxy->IsRunningSession() == 1) {
        return 0;
    }
    if (this->pSessionProxy->IsRecordSessionEnabled() == 0) {
        return 0;
    }

    cpl_Function* uFunc = NULL;
    this->FindFunction(funcName, uFunc);
    if (uFunc == NULL || uFunc->IsValidRecordSession() == 0) {
        return 0;
    }
    if (this->funcExecuteStatus == 1 && uFunc->IsValidRecordSession() != 2) {
        return 0;
    }
    return 1;
}

//------------------------------------------------------------------------
int cpl_FunctionProcess20::RecordSessionFunction(char* funcName) {
    //@@preconditions
    assert(funcName != NULL);
    assert(this->pSessionProxy != NULL);
    //@@end preconditions

    cpl_CtlDataTextFormatter* textFormater = cpl_CtlDataTextFormatter::New();

    char* sessionStr = NULL;
    textFormater->FormatCtlActionText(funcName, this->functionParameter->GetParamEngine()->GetInputParamBuffer(), sessionStr);
    assert(sessionStr != NULL);

    char* modSessionStr = this->funcSessionData->SegmentParameterString(sessionStr);
    assert(modSessionStr != NULL);

    this->pSessionProxy->WriteFunctionSession(modSessionStr);

    textFormater->Delete();

    return 1;
}

//------------------------------------------------------------------------
cpl_FunctionProcess20::cpl_FunctionProcess20() {
    this->pSessionProxy = NULL;
    this->funcExecuteStatus = 0;
    this->funcSessionData = cpl_FunctionSessionDataProxy::New();
}

//------------------------------------------------------------------------
cpl_FunctionProcess20::~cpl_FunctionProcess20() {
    if (this->funcSessionData != NULL) {
        this->funcSessionData->Delete();
        this->funcSessionData = NULL;
    }
}
