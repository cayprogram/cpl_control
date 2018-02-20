#include "cpl_functionframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_StylerFunctionDataExchange
//-----------------------------------------------------------------------------
//
cpl_StylerFunctionDataExchange* cpl_StylerFunctionDataExchange::New() {
    return new cpl_StylerFunctionDataExchange;
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionDataExchange::Delete() {
    delete this;
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::PrepareWrite() {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions

    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);

    pWriter->Clear();
    return pWriter->PrepareWrite();
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::SetParamAsINT(int index, int data) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsINT(index, data);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::SetParamAsREAL(int index, float data) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsREAL(index, data);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::SetParamAsVOID(int index,  void *  data) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsVOID(index, data);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::SetParamAsSTRING(int index,  char *  data) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsSTRING(index, data);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::SetParamAsINTArray(int index,  int *  data, int num) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsINTArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::SetParamAsIDArray(int index,  int *  data, int num) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions

    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);

    return pWriter->SetParamAsIDArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::SetParamAsREALArray(int index,  float *  data, int num) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsREALArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::SetParamAsSTRINGArray(int index,  char **data, int num) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsSTRINGArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::SetParamAsFUNC(int index, ParamFunc data) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->SetParamAsFUNC(index, data);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::EndWrite() {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineWriteRight* pWriter = this->pFuncParameter->GetParamEngine()->GetOutputWriteRight();
    assert(pWriter != NULL);
    
    return pWriter->EndWrite();
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::PrepareRead() {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);

    return pReader->PrepareRead();
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::GetParamAsINT(int index, int&  data) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsINT(index, data);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::GetParamAsREAL(int index, float & data) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsREAL(index, data);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::GetParamAsVOID(int index,  void *& data) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsVOID(index, data);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::GetParamAsSTRING(int index,  char *& data) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsSTRING(index, data);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::GetParamAsINTArray(int index,  int *& data, int& num) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsINTArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::GetParamAsIDArray(int index,  int *& data, int& num) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions

    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);

    return pReader->GetParamAsIDArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::GetParamAsREALArray(int index,  float *& data, int &num) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsREALArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::GetParamAsSTRINGArray(int index,  char **& data, int &num) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsSTRINGArray(index, data, num);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::GetParamAsFUNC(int index, ParamFunc& data) {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);
    
    return pReader->GetParamAsFUNC(index, data);
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionDataExchange::EndRead() {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    assert(this->pFuncParameter->GetParamEngine());
    //@@end preconditions
    
    IParameterEngineReadRight* pReader = this->pFuncParameter->GetParamEngine()->GetInputReadRight();
    assert(pReader != NULL);
    
    return pReader->EndRead();
}

//-----------------------------------------------------------------------------
cpl_FunctionParameter* cpl_StylerFunctionDataExchange::GetFunctionParameter() {
    //@@preconditions
    assert(this->pFuncParameter != NULL);
    //@@end preconditions

    return this->pFuncParameter;
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionDataExchange::cpl_StylerFunctionDataExchange() {  
    this->pFuncParameter = cpl_FunctionParameter::New();
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionDataExchange::~cpl_StylerFunctionDataExchange() {
    if (this->pFuncParameter) {
        this->pFuncParameter->Delete();
        this->pFuncParameter = NULL;
    }
}
