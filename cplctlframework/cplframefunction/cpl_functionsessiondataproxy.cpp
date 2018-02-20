#include "cpl_functionframeincludes.h"
#include "cpl_functionserialdatacoder.h"
#include "cpl_functionsessiondataproxy.h"

//------------------------------------------------------------------------
// class cpl_FunctionSessionDataProxy
//------------------------------------------------------------------------
//
//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
cpl_FunctionSessionDataProxy* cpl_FunctionSessionDataProxy::New() {
    return new cpl_FunctionSessionDataProxy;
}

//------------------------------------------------------------------------
void cpl_FunctionSessionDataProxy::Delete() { 
    delete this; 
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
void cpl_FunctionSessionDataProxy::SetFunctionParamManager(cpl_ParameterEngineManager* paramMan) {
    //@@preconditions
    //@@end preconditions

    this->uParamMan = paramMan;
}

//------------------------------------------------------------------------
char* cpl_FunctionSessionDataProxy::SegmentParameterString(char* paramStr) {
    //@@preconditions
    assert(paramStr != NULL);
    //@@end preconditions

    int nCharLimit = 80;

    int slen = (int)strlen(paramStr);
    assert(slen > 0);

    if (slen > nCharLimit) {
        if (this->parStringBuf != NULL) {
            delete[] this->parStringBuf;
            this->parStringBuf = NULL;
        }

        int tmpStrLen      = slen+slen/nCharLimit+64;
        this->parStringBuf = new char[tmpStrLen+1];

        char devidedChar  = '\n';
        char forceEndChar = ',';
        int charCount     = 0;
        int segCharCount  = 0;
        for (int i = 0; i < slen; i++) {
            if (segCharCount >= nCharLimit && paramStr[i] == forceEndChar) {
                this->parStringBuf[charCount++] = paramStr[i];
                this->parStringBuf[charCount++] = devidedChar;
                segCharCount = 0;
                continue;
            }

            this->parStringBuf[charCount++] = paramStr[i];
            segCharCount++;
        }
        assert(charCount <= tmpStrLen);
        this->parStringBuf[charCount] = '\0';

        return this->parStringBuf;
    }
    
    return paramStr;
}

//------------------------------------------------------------------------
int cpl_FunctionSessionDataProxy::ApplyFunctionParameter(cpl_ParameterBuffer* params) {
    //@@preconditions
    assert(params != NULL);
    assert(this->uParamMan != NULL);
    assert(this->uParamMan->GetInputWriteRight() != NULL);
    //@@end preconditions

    this->uParamMan->GetInputWriteRight()->Clear();
    this->uParamMan->GetInputWriteRight()->PrepareWrite();

    int nparams = 0;
    params->GetNumber(nparams);

    for (int i = 0; i < nparams; i++) {
        AtomDataTypeEnum parType = AtomINVALID;
        params->GetType(i, parType);

        void* vdata = NULL;
        int dataLen = 0;
        params->GetParameter(i, vdata, dataLen, parType);
        assert(vdata != NULL && dataLen > 0);

        if (parType == AtomINTEGER) {
            int* idata = (int*)vdata;
            this->uParamMan->GetInputWriteRight()->SetParamAsINT(i, idata[0]);
        }
        if (parType == AtomINTEGERArray) {
            this->uParamMan->GetInputWriteRight()->SetParamAsINTArray(i, (int*)vdata, dataLen);
        }
        if (parType == AtomIDArray) {
            this->uParamMan->GetInputWriteRight()->SetParamAsINTArray(i, (int*)vdata, dataLen);
        }
        if (parType == AtomFLOAT) {
            float* fdata = (float*)vdata;
            this->uParamMan->GetInputWriteRight()->SetParamAsREAL(i, fdata[0]);
        }
        if (parType == AtomFLOATArray) {
            this->uParamMan->GetInputWriteRight()->SetParamAsREALArray(i, (float*)vdata, dataLen);
        }
        if (parType == AtomSTRING) {
            char** sdata = (char**)vdata;
            this->uParamMan->GetInputWriteRight()->SetParamAsSTRING(i, sdata[0]);
        }
    }

    this->uParamMan->GetInputWriteRight()->EndWrite();

    return 1;
}

//------------------------------------------------------------------------
int cpl_FunctionSessionDataProxy::ApplyFunctionCommandParameter(cpl_StylerFunction* uFunc, cpl_ParameterBuffer* params) {
    //@@preconditions
    assert(uFunc  != NULL);
    assert(params != NULL);
    //@@end preconditions

    IFunctionExecuteInvoker* funcExeImp = uFunc->GetFunctionExecuteImp();
    assert(funcExeImp != NULL);

    int nparams = 0;
    params->GetNumber(nparams);

    for (int i = 0; i < nparams; i++) {
        AtomDataTypeEnum parType = AtomINVALID;
        params->GetType(i, parType);

        void* vdata = NULL;
        int dataLen = 0;
        params->GetParameter(i, vdata, dataLen, parType);
        assert(vdata != NULL && dataLen > 0);

        if (parType == AtomINTEGER) {
            int* idata = (int*)vdata;
            funcExeImp->SetInputAsINT(i, idata[0]);
        }
        if (parType == AtomINTEGERArray) {
            funcExeImp->SetInputAsINTArray(i, (int*)vdata, dataLen);
        }
        if (parType == AtomIDArray) {
            funcExeImp->SetInputAsIDArray(i, (int*)vdata, dataLen);
        }
        if (parType == AtomFLOAT) {
            float* fdata = (float*)vdata;
            funcExeImp->SetInputAsREAL(i, fdata[0]);
        }
        if (parType == AtomFLOATArray) {
            funcExeImp->SetInputAsREALArray(i, (float*)vdata, dataLen);
        }
        if (parType == AtomSTRING) {
            char** sdata = (char**)vdata;
            funcExeImp->SetInputAsSTRING(i, sdata[0]);
        }
    }

    return 1;
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
cpl_FunctionSessionDataProxy::cpl_FunctionSessionDataProxy() {
    this->uParamMan    = NULL;
    this->parStringBuf = NULL;
}

//------------------------------------------------------------------------
cpl_FunctionSessionDataProxy::~cpl_FunctionSessionDataProxy() {
    if (this->parStringBuf != NULL) {
        delete[] this->parStringBuf;
        this->parStringBuf = NULL;
    }
}
