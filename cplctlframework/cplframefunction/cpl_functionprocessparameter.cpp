#include "cpl_functionframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_FunctionProcessParameter
//-----------------------------------------------------------------------------
//
cpl_FunctionProcessParameter* cpl_FunctionProcessParameter::New() {
    return new cpl_FunctionProcessParameter;
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::SetParamAsINT(int index, int data) {
    //@@preconditions
    assert(index >= 0);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->EncloseReadProcess();
    this->TryToWriteParameter();

    IParameterEngineWriteRight* pWriter = this->paramMan->GetInputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsINT(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::SetParamAsREAL(int index, float data) {
    //@@preconditions
    assert(index >= 0);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->EncloseReadProcess();
    this->TryToWriteParameter();

    IParameterEngineWriteRight* pWriter = this->paramMan->GetInputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsREAL(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::SetParamAsVOID(int index,  void * data) {
    //@@preconditions
    assert(index >= 0);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->EncloseReadProcess();
    this->TryToWriteParameter();

    IParameterEngineWriteRight* pWriter = this->paramMan->GetInputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsVOID(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::SetParamAsSTRING(int index,  char *  data) {
    //@@preconditions
    assert(index >= 0);
    assert(data != NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->EncloseReadProcess();
    this->TryToWriteParameter();

    IParameterEngineWriteRight* pWriter = this->paramMan->GetInputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsSTRING(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::SetParamAsINTArray(int index,  int * data, int num) {
    //@@preconditions
    assert(index >= 0);
    assert(data != NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->EncloseReadProcess();
    this->TryToWriteParameter();

    IParameterEngineWriteRight* pWriter = this->paramMan->GetInputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsINTArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::SetParamAsIDArray(int index,  int * data, int num) {
    //@@preconditions
    assert(index >= 0);
    assert(data != NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions

    this->EncloseReadProcess();
    this->TryToWriteParameter();

    IParameterEngineWriteRight* pWriter = this->paramMan->GetInputWriteRight();
    assert(pWriter != NULL);

    return pWriter->SetParamAsIDArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::SetParamAsREALArray(int index,  float *  data, int num) {
    //@@preconditions
    assert(index >= 0);
    assert(data != NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->EncloseReadProcess();
    this->TryToWriteParameter();

    IParameterEngineWriteRight* pWriter = this->paramMan->GetInputWriteRight();
    assert(pWriter != NULL);
   
    return pWriter->SetParamAsREALArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::SetParamAsSTRINGArray(int index,  char **data, int num) {
    //@@preconditions
    assert(index >= 0);
    assert(data != NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->EncloseReadProcess();
    this->TryToWriteParameter();

    IParameterEngineWriteRight* pWriter = this->paramMan->GetInputWriteRight();
    assert(pWriter != NULL);
   
    return pWriter->SetParamAsSTRINGArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::SetParamAsFUNC(int index, ParamFunc data) {
    //@@preconditions
    assert(index >= 0);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->EncloseReadProcess();
    this->TryToWriteParameter();

    IParameterEngineWriteRight* pWriter =this->paramMan->GetInputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsFUNC(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::GetParamAsINT(int index, int&  data) {
    //@@preconditions
    assert(index >= 0);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->TryToReadParameter();

    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);

    return pReader->GetParamAsINT(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::GetParamAsREAL(int index, float & data) {
    //@@preconditions
    assert(index >= 0);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->TryToReadParameter();

    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsREAL(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::GetParamAsVOID(int index,  void *& data) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions

    this->TryToReadParameter();
    
    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsVOID(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::GetParamAsSTRING(int index,  char *& data) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->TryToReadParameter();

    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsSTRING(index, data);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::GetParamAsINTArray(int index,  int *& data, int& num) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->TryToReadParameter();

    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsINTArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::GetParamAsIDArray(int index,  int *& data, int& num) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions

    this->TryToReadParameter();

    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);

    return pReader->GetParamAsIDArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::GetParamAsREALArray(int index,  float *& data, int &num) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->TryToReadParameter();

    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsREALArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::GetParamAsSTRINGArray(int index,  char **& data, int &num) {
    //@@preconditions
    assert(index >= 0);
    assert(data == NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->TryToReadParameter();

    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsSTRINGArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcessParameter::GetParamAsFUNC(int index, ParamFunc& data) {
    //@@preconditions
    assert(index >= 0);
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    this->TryToReadParameter();

    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsFUNC(index, data);
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcessParameter::ExechangeInputParameter(cpl_FunctionProcess* uFuncProcess) {
    //@@preconditions
    assert(uFuncProcess   != NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions

    //enclose output read process.
    this->EncloseReadProcess();

    //enclose input write process.
    this->EncloseWriteProcess();

    IParameterEngineCheckRight* pChecker = this->paramMan->GetInputCheckRight();
    assert(pChecker != NULL);
    
    IParameterEngineReadRight* pReader = this->paramMan->GetInputReadRight();
    assert(pReader != NULL);

    IParameterEngineWriteRight* uWriter = uFuncProcess->GetInputParamWriter();
    assert(uWriter != NULL);
    
    pReader->PrepareRead();

    int num = 0; pChecker->GetParamNumber(num);
    for (int i = 0; i < num; i++) {                
        int type = pChecker->GetParamType(i);
        switch (type) {
        case AtomFLOAT: {
                float data = 0;
                pReader->GetParamAsREAL(i, data);
                uWriter->SetParamAsREAL(i, data);
            }
            break;
        case AtomFLOATArray: {
                int num = 0; float* data = 0;
                pReader->GetParamAsREALArray(i, data, num);
                uWriter->SetParamAsREALArray(i, data, num);
            }
            break;
        case AtomINTEGER: {
                int data = 0;
                pReader->GetParamAsINT(i, data);
                uWriter->SetParamAsINT(i, data);
            }
            break;
        case AtomIDArray:
        case AtomINTEGERArray: {
                int num = 0; int* data = 0;
                pReader->GetParamAsINTArray(i, data, num);
                uWriter->SetParamAsINTArray(i, data, num);
            }
            break;
        case AtomSTRING: {
                char* data = 0;
                pReader->GetParamAsSTRING(i, data);
                uWriter->SetParamAsSTRING(i, data);
            }
            break;
        case AtomVOID: {
                void* data = 0;
                pReader->GetParamAsVOID(i, data);
                uWriter->SetParamAsVOID(i, data);
            }
            break;
        case AtomFUNC: {
                ParamFunc data1;
                ParamFunc data2;
                pReader->GetParamAsFUNC(i, data1);
                data2.Func = data1.Func;
                uWriter->SetParamAsFUNC(i, data2);
            }
            break;
        default:
            assert(0);
            break;
        }
    }
    pReader->EndRead();
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcessParameter::ExechangeOutputParameter(cpl_FunctionProcess* uFuncProcess) {
    //@@preconditions
    assert(uFuncProcess   != NULL);
    assert(this->paramMan != NULL);
    //@@end preconditions

    //The input parameter should be cleared after execute function for avoid mess up session record.
    //Clear input parameters.
    this->paramMan->GetInputReadRight()->Clear();

    //It is possible nested call functions and set/get function manager parameter from outer when execute a function.
    //For example run macro may call pl_ExecuteScript PSFuncServerGetXXX from outer.
    //So we need to clear some status in here.
    this->EncloseReadProcess();

    IParameterEngineWriteRight* pWriter = this->paramMan->GetOutputWriteRight();
    assert(pWriter != NULL);

    IParameterEngineReadRight* uReader = uFuncProcess->GetOutputParamReader();
    assert(uReader != NULL);

    IParameterEngineCheckRight* uChecker = uFuncProcess->GetOutputParamChecker();
    assert(uChecker != NULL);
    
    pWriter->Clear();
    pWriter->PrepareWrite();
    
    int num = 0; uChecker->GetParamNumber(num);
    for (int i = 0; i < num; i++) {
        int type = uChecker->GetParamType(i);
        switch (type) {
        case AtomFLOAT: {
                float data = 0;
                uReader->GetParamAsREAL(i, data);
                pWriter->SetParamAsREAL(i, data);
            }
            break;
        case AtomFLOATArray: {
                int num = 0; float* data = 0;
                uReader->GetParamAsREALArray(i, data, num);
                pWriter->SetParamAsREALArray(i, data, num);
            }
            break;
        case AtomINTEGER: {
                int data = 0;
                uReader->GetParamAsINT(i, data);
                pWriter->SetParamAsINT(i, data);
            }
            break;
        case AtomIDArray:
        case AtomINTEGERArray: {
                int num = 0; int* data = 0;
                uReader->GetParamAsINTArray(i, data, num);
                pWriter->SetParamAsINTArray(i, data, num);
            }
            break;
        case AtomSTRING: {
                char* data = 0;
                uReader->GetParamAsSTRING(i, data);
                pWriter->SetParamAsSTRING(i, data);
            }
            break;
        case AtomSTRINGArray: 
            {
                int num = 0;
                char** data = 0;
                uReader->GetParamAsSTRINGArray(i, data, num);
                pWriter->SetParamAsSTRINGArray(i, data, num);
            }
            break;
        case AtomVOID: {
                void* data = 0;
                uReader->GetParamAsVOID(i, data);
                pWriter->SetParamAsVOID(i, data);
            }
            break;
        case AtomFUNC: {
                ParamFunc data1; ParamFunc data2;
                uReader->GetParamAsFUNC(i, data2);
                data1.Func = data2.Func;
                pWriter->SetParamAsFUNC(i, data1);
            }
            break;
        default:
            assert(0);
            break;
        }
    }  
    pWriter->EndWrite();
}

//-----------------------------------------------------------------------------
cpl_ParameterEngineManager* cpl_FunctionProcessParameter::GetParamManager() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions

    return this->paramMan;
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcessParameter::EncloseReadProcess() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);
    
    if (this->readRight == 1) {
        pReader->EndRead();
        this->readRight = 0;
    }
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcessParameter::EncloseWriteProcess() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    IParameterEngineWriteRight* pInputWriter = this->paramMan->GetInputWriteRight();
    assert(pInputWriter != NULL);
    
    if (this->writeRight == 1) {
        pInputWriter->EndWrite();
        this->writeRight = 0;
    }
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcessParameter::TryToWriteParameter() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions

    IParameterEngineWriteRight* pWriter = this->paramMan->GetInputWriteRight();
    assert(pWriter != NULL);

    if (this->writeRight == 0) {
        pWriter->Clear();
        pWriter->PrepareWrite();
        this->writeRight = 1;
    }
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcessParameter::TryToReadParameter() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->paramMan->GetOutputReadRight();
    assert(pReader != NULL);
    
    if (this->readRight == 0) {
        pReader->PrepareRead();
        this->readRight = 1;
    }
}

//-----------------------------------------------------------------------------
cpl_FunctionProcessParameter::cpl_FunctionProcessParameter() { 
    this->paramMan   = cpl_ParameterEngineManager::New();
    this->writeRight = 0;
    this->readRight  = 0;
}

//-----------------------------------------------------------------------------
cpl_FunctionProcessParameter::~cpl_FunctionProcessParameter() {
    if (this->paramMan != NULL) {
        this->paramMan->Delete();
        this->paramMan = NULL;
    }
}
