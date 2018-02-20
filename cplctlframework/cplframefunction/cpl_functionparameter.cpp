#include "cpl_functionframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_FunctionParameter
//------------------------------------------------------------------------------
//

cpl_FunctionParameter* cpl_FunctionParameter::New() {
    return new cpl_FunctionParameter;
}

//------------------------------------------------------------------------------
cpl_FunctionParameter::cpl_FunctionParameter() {
    this->m_objElements.paramMan   = cpl_ParameterEngineManager::New();
    this->m_objElements.paramProxy = new cpl_FunctionParameterProxy;    
    this->m_objElements.paramProxy->SetInputParEngineReaderAndChecker(this->m_objElements.paramMan->GetInputReadRight(), this->m_objElements.paramMan->GetInputCheckRight());
    this->m_objElements.paramProxy->SetOutputParEngineWriterAndChecker(this->m_objElements.paramMan->GetOutputWriteRight(), this->m_objElements.paramMan->GetOuputCheckRight());
}

//------------------------------------------------------------------------------
cpl_FunctionParameter::~cpl_FunctionParameter() {
    if (this->m_objElements.paramMan != NULL) {
        this->m_objElements.paramMan->Delete();
    }    
    if (this->m_objElements.paramProxy != NULL) {
        delete this->m_objElements.paramProxy;
    }       
}
