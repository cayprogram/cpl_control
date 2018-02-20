#include "cpl_functionframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_FunctionCommandProxy.
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
void cpl_FunctionCommandProxy::DoInitialization(char* cmdType) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    //@@end preconditions

    this->uCmdManager->DoInitialization(cmdType);
}

//-----------------------------------------------------------------------------
void cpl_FunctionCommandProxy::DoCleanup() {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    //@@end preconditions

    this->uCmdManager->DoCleanup();
}

//-----------------------------------------------------------------------------
void cpl_FunctionCommandProxy::DoDefaultSetting() {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    //@@end preconditions

    this->uCmdManager->DoDefaultSetting();
}

//-----------------------------------------------------------------------------
void cpl_FunctionCommandProxy::SetRuntimeContext(int domainHaandle, int graphicHandle) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    //@@end preconditions

    this->uCmdManager->SetRuntimeContext(domainHaandle, graphicHandle);
}

//////////////////////////////////////////////////////////////////////////
//set parameter functions.
//////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::SetParamAsINT(int index, int data) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetInputParamWriter()->SetParamAsINT(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::SetParamAsREAL(int index, float data) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetInputParamWriter()->SetParamAsREAL(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::SetParamAsVOID(int index,  void *  data) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetInputParamWriter()->SetParamAsVOID(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::SetParamAsSTRING(int index,  char *  data) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetInputParamWriter()->SetParamAsSTRING(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::SetParamAsINTArray(int index,  int *  data, int num) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetInputParamWriter()->SetParamAsINTArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::SetParamAsIDArray(int index,  int *  data, int num) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetInputParamWriter()->SetParamAsIDArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::SetParamAsREALArray(int index,  float *  data, int num) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetInputParamWriter()->SetParamAsREALArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::SetParamAsSTRINGArray(int index,  char **data, int num) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetInputParamWriter()->SetParamAsSTRINGArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::SetParamAsFUNC(int index, ParamFunc data) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions
    
    return this->uCmdManager->GetInputParamWriter()->SetParamAsFUNC(index, data);
}

//////////////////////////////////////////////////////////////////////////
//get parameter functions.
//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
int cpl_FunctionCommandProxy::GetParamNumber() {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    //@@end preconditions

    int num = 0;
    this->uCmdManager->GetOutputParamChecker()->GetParamNumber(num);
    return num;
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::GetParamAsINT(int index, int&  data) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetOutputParamReader()->GetParamAsINT(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::GetParamAsREAL(int index, float & data) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetOutputParamReader()->GetParamAsREAL(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::GetParamAsVOID(int index,  void *& data) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetOutputParamReader()->GetParamAsVOID(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::GetParamAsSTRING(int index,  char *& data) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetOutputParamReader()->GetParamAsSTRING(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::GetParamAsINTArray(int index,  int *& data, int& num) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetOutputParamReader()->GetParamAsINTArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::GetParamAsIDArray(int index,  int *& data, int& num) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetOutputParamReader()->GetParamAsIDArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::GetParamAsREALArray(int index,  float *& data, int &num) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetOutputParamReader()->GetParamAsREALArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::GetParamAsSTRINGArray(int index,  char **& data, int &num) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetOutputParamReader()->GetParamAsSTRINGArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::GetParamAsFUNC(int index, ParamFunc& data) {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    return this->uCmdManager->GetOutputParamReader()->GetParamAsFUNC(index, data);
}

//-----------------------------------------------------------------------------
cpl_ParameterBuffer* cpl_FunctionCommandProxy::GetOutputParamBuffer() {
    //@@preconditions
    assert(this->uCmdManager != NULL);
    //@@end precondition

    return this->uCmdManager->GetOutputParamBuffer();
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::ExecuteCommand(char* string) {
    //@@preconditions
    assert(string != NULL);
    assert(this->uCmdManager != NULL);
    assert(this->uFunProcess != NULL);
    //@@end preconditions

    this->uFunProcess->EnterProcess();
    int ret = this->uCmdManager->ExecuteCommand(string);
    this->uFunProcess->LeaveProcess();
    return ret;
}

//-----------------------------------------------------------------------------
int cpl_FunctionCommandProxy::ExecuteCommandFormatted(char* string, cpl_ParameterBuffer*& outParams) {
    //@@preconditions
    assert(string != NULL);
    //@@end preconditions

    cpl_CtlDataTextFormatter* uTextFormater = cpl_CtlDataTextFormatter::New();

    char* cmdName              = NULL;
    cpl_ParameterBuffer* cmdParams = NULL;
    if (uTextFormater->ParseCtlActionText(string, cmdName, cmdParams) == 0) {
        uTextFormater->Delete();
        return 0;
    }

    assert(cmdName   != NULL);
    assert(cmdParams != NULL);

    int inputParNum = 0;
    cmdParams->GetNumber(inputParNum);
    if (inputParNum > 0) {
        for (int i = 0; i < inputParNum; i++) {
            AtomDataTypeEnum parType = AtomINVALID;
            cmdParams->GetType(i, parType);

            void* vdata = NULL;
            int dataLen = 0;
            cmdParams->GetParameter(i, vdata, dataLen, parType);
            assert(vdata != NULL && dataLen > 0);

            if (parType == AtomINTEGER) {
                int* idata = (int*)vdata;
                this->SetParamAsINT(i, idata[0]);
            }
            if (parType == AtomINTEGERArray) {
                this->SetParamAsINTArray(i, (int*)vdata, dataLen);
            }
            if (parType == AtomFLOAT) {
                float* fdata = (float*)vdata;
                this->SetParamAsREAL(i, fdata[0]);
            }
            if (parType == AtomFLOATArray) {
                this->SetParamAsREALArray(i, (float*)vdata, dataLen);
            }
            if (parType == AtomSTRING) {
                char** sdata = (char**)vdata;
                this->SetParamAsSTRING(i, sdata[0]);
            }
        }
    }

    int ret = this->ExecuteCommand(cmdName);
    uTextFormater->Delete();

    outParams = this->uCmdManager->GetOutputParamBuffer();
    assert(outParams != NULL);

    return ret;
}

//-----------------------------------------------------------------------------
cpl_FunctionCommandProxy::cpl_FunctionCommandProxy(cpl_FunctionProcess* funProcess) {
    //@@preconditions
    assert(funProcess != NULL);
    //@@end preconditions

    this->uCmdManager = cpl_CommandsManager::New();
    this->uFunProcess = funProcess;
}

//-----------------------------------------------------------------------------
cpl_FunctionCommandProxy::~cpl_FunctionCommandProxy() {
    if (this->uCmdManager != NULL) {
        this->uCmdManager->Delete();
        this->uCmdManager = NULL;
    }
}
