#include "cpl_functionframeincludes.h"
#include "cpl_functionserialdata.h"
#include "cpl_functionserialdatacoder.h"
#include "cpl_functionserialdataproxy.h"

//------------------------------------------------------------------------
// class cpl_FunctionSerialDataProxy
//------------------------------------------------------------------------
//
//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
cpl_FunctionSerialDataProxy* cpl_FunctionSerialDataProxy::New() {
    return new cpl_FunctionSerialDataProxy;
}

//------------------------------------------------------------------------
void cpl_FunctionSerialDataProxy::Delete() { 
    delete this; 
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
void cpl_FunctionSerialDataProxy::SetCommandProxy(cpl_FunctionCommandProxy* proxy) {
    //@@preconditions
    assert(proxy != NULL);
    //@@end preconditions

    this->cmdProxy = proxy;
}

//------------------------------------------------------------------------
void cpl_FunctionSerialDataProxy::AllocateFuncSerialData(int sz, int ext) {
    //@@preconditions
    assert(sz  > 0);
    assert(ext > 0);
    assert(this->serialDat != NULL);
    //@@end preconditions

    this->serialDat->Allocate(sz, ext);
}

//------------------------------------------------------------------------
void cpl_FunctionSerialDataProxy::ResetFuncSerialData() {
    //@@preconditions
    assert(this->serialDat != NULL);
    //@@end preconditions

    this->serialDat->Reset();
}

//------------------------------------------------------------------------
int  cpl_FunctionSerialDataProxy::GetFuncSerialDataNumber() {
    //@@preconditions
    assert(this->serialDat != NULL);
    //@@end preconditions

    return this->serialDat->GetFuncSerialDataNumber();
}

//------------------------------------------------------------------------
int  cpl_FunctionSerialDataProxy::InsertFuncSerialData(char* datName, char* datVal) {
    //@@preconditions
    assert(datName != NULL);
    assert(datVal  != NULL);
    assert(this->serialDat != NULL);
    //@@end precondition

    return this->serialDat->InsertNextFuncSerialData(datName, datVal);
}

//------------------------------------------------------------------------
void cpl_FunctionSerialDataProxy::GetFuncSerialData(int datid, char*& datName, char*& datVal) {
    //@@preconditions
    assert(datid   >= 0);
    assert(datName == NULL);
    assert(datVal  == NULL);
    assert(this->serialDat != NULL);
    //@@end precondition

    datName = this->serialDat->GetFuncSerialDataName(datid);
    datVal  = this->serialDat->GetFuncSerialDataValue(datid);
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
char* cpl_FunctionSerialDataProxy::EncodeFuncSerialData(int num, int* iarray) {
    //@@preconditions
    assert(this->serialDatCoder != NULL);
    //@@end preconditions

    return this->serialDatCoder->EncodeFuncSerialData(num, iarray);
}

//------------------------------------------------------------------------
char* cpl_FunctionSerialDataProxy::EncodeFuncSerialData(int num, float* farray) {
    //@@preconditions
    assert(this->serialDatCoder != NULL);
    //@@end preconditions

    return this->serialDatCoder->EncodeFuncSerialData(num, farray);
}

//------------------------------------------------------------------------
int cpl_FunctionSerialDataProxy::ParseFuncSerialData(char* dataStr, int& num, int*& iarray) {
    //@@preconditions
    assert(this->serialDatCoder != NULL);
    //@@end preconditions

    if (strncmp(dataStr, "@CMD_", 5) == 0) {
        if (this->GetFuncSerialDataFromCommand(0, &dataStr[5]) == 1) {
            assert(this->idatArray != NULL && this->idatArray->GetMaxId() >= 0);
            num    = this->idatArray->GetMaxId()+1;
            iarray = this->idatArray->GetPointer(0);
            return 1;
        }
        return 0;
    }

    return this->serialDatCoder->ParseFuncSerialData(dataStr, num, iarray);
}

//------------------------------------------------------------------------
int cpl_FunctionSerialDataProxy::ParseFuncSerialData(char* dataStr, int& num, float*& farray) {
    //@@preconditions
    assert(this->serialDatCoder != NULL);
    //@@end preconditions

    if (strncmp(dataStr, "@CMD_", 5) == 0) {
        if (this->GetFuncSerialDataFromCommand(1, &dataStr[5]) == 1) {
            assert(this->fdatArray != NULL && this->fdatArray->GetMaxId() >= 0);
            num    = this->fdatArray->GetMaxId()+1;
            farray = this->fdatArray->GetPointer(0);
            return 1;
        }
        return 0;
    }

    return this->serialDatCoder->ParseFuncSerialData(dataStr, num, farray);
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
int cpl_FunctionSerialDataProxy::GetFuncSerialDataFromCommand(int runTyp, char* dataStr) {
    //@@preconditions
    assert(runTyp == 0 || runTyp == 1);
    assert(dataStr != NULL);
    assert(this->cmdProxy != NULL);
    assert(this->serialDatCoder != NULL);
    //@@end preconditions

    this->idatArray->Reset();
    this->fdatArray->Reset();

    char* cmdStr = NULL;
    cpl_ParameterBuffer* cmdPar = NULL;
    if (this->serialDatCoder->ParseFuncCmdSerialData(dataStr, cmdStr, cmdPar) == 0) {
        return 0;
    }

    assert(cmdStr != NULL);
    assert(cmdPar != NULL);

    int inputParNum = 0;
    cmdPar->GetNumber(inputParNum);
    if (inputParNum > 0) {
        for (int i = 0; i < inputParNum; i++) {
            AtomDataTypeEnum parType = AtomINVALID;
            cmdPar->GetType(i, parType);

            void* vdata = NULL;
            int dataLen = 0;
            cmdPar->GetParameter(i, vdata, dataLen, parType);
            assert(vdata != NULL && dataLen > 0);

            if (parType == AtomINTEGER) {
                int* idata = (int*)vdata;
                this->cmdProxy->SetParamAsINT(i, idata[0]);
            }
            if (parType == AtomINTEGERArray) {
                this->cmdProxy->SetParamAsINTArray(i, (int*)vdata, dataLen);
            }
            if (parType == AtomFLOAT) {
                float* fdata = (float*)vdata;
                this->cmdProxy->SetParamAsREAL(i, fdata[0]);
            }
            if (parType == AtomFLOATArray) {
                this->cmdProxy->SetParamAsREALArray(i, (float*)vdata, dataLen);
            }
            if (parType == AtomSTRING) {
                char** sdata = (char**)vdata;
                this->cmdProxy->SetParamAsSTRING(i, sdata[0]);
            }
        }
    }

    this->cmdProxy->ExecuteCommand(cmdStr);

    int outputParNum = this->cmdProxy->GetParamNumber();
    if (outputParNum == 0) {
        return 0;
    }

    if (runTyp == 0) {
        int  num = 0;
        int* iarray = NULL;
        if (this->cmdProxy->GetParamAsINTArray(0, iarray, num) == 0) {
            return 0;
        }
        assert(num > 0 && iarray != NULL);

        this->idatArray->Reset();
        for (int i = 0; i < num; i++) {
            this->idatArray->InsertNextValue(iarray[i]);
        }
        return 1;
    }

    if (runTyp == 1) {
        int  num = 0;
        int* farray = NULL;
        if (this->cmdProxy->GetParamAsINTArray(0, farray, num) == 0) {
            return 0;
        }
        assert(num > 0 && farray != NULL);

        this->fdatArray->Reset();
        for (int i = 0; i < num; i++) {
            this->fdatArray->InsertNextValue(farray[i]);
        }
        return 1;
    }

    return 0;
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
cpl_FunctionSerialDataProxy::cpl_FunctionSerialDataProxy() {
    this->serialDat      = cpl_FunctionSerialData::New();
    this->serialDatCoder = cpl_FunctionSerialDataCoder::New();
    this->cmdProxy       = NULL;
    this->idatArray      = cpl_IntArray::New();
    this->fdatArray      = cpl_FloatArray::New();
    this->idatArray->Allocate(100, 100);
    this->fdatArray->Allocate(100, 100);
}

//------------------------------------------------------------------------
cpl_FunctionSerialDataProxy::~cpl_FunctionSerialDataProxy() {
    if (this->serialDat != NULL) {
        this->serialDat->Delete();
        this->serialDat = NULL;
    }
    if (this->serialDatCoder != NULL) {
        this->serialDatCoder->Delete();
        this->serialDatCoder = NULL;
    }
    if (this->idatArray != NULL) {
        this->idatArray->Delete();
        this->idatArray = NULL;
    }
    if (this->fdatArray != NULL) {
        this->fdatArray->Delete();
        this->fdatArray = NULL;
    }
}
