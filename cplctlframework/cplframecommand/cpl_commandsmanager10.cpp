#include "cpl_commandframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_CommandsManager10.
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
IParameterEngineReadRight* cpl_CommandsManager10::GetOutputParamReader() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions

    return this->paramMan->GetOutputReadRight();
}

//-----------------------------------------------------------------------------
IParameterEngineWriteRight*  cpl_CommandsManager10::GetInputParamWriter() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions

    return this->paramMan->GetInputWriteRight();  
}

//-----------------------------------------------------------------------------
IParameterEngineCheckRight* cpl_CommandsManager10::GetOutputParamChecker() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions

    return this->paramMan->GetOuputCheckRight();
}

//-----------------------------------------------------------------------------
IParameterEngineCheckRight* cpl_CommandsManager10::GetInputParamChecker() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions

    return this->paramMan->GetInputCheckRight();
}

//-----------------------------------------------------------------------------
cpl_ParameterBuffer* cpl_CommandsManager10::GetInputParamBuffer() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions

    return this->paramMan->GetInputParamBuffer();
}

//-----------------------------------------------------------------------------
cpl_ParameterBuffer* cpl_CommandsManager10::GetOutputParamBuffer() {
    //@@preconditions
    assert(this->paramMan != NULL);
    //@@end preconditions

    return this->paramMan->GetOutputParamBuffer();
}

//-----------------------------------------------------------------------------
cpl_CommandsManager10::cpl_CommandsManager10() {
    this->paramMan   = cpl_ParameterEngineManager::New();
    this->paramProxy = new cpl_CommandParameterProxy;    
    this->paramProxy->SetInputParEngineReaderAndChecker(this->paramMan->GetInputReadRight(), this->paramMan->GetInputCheckRight());
    this->paramProxy->SetOutputParEngineWriterAndChecker(this->paramMan->GetOutputWriteRight(), this->paramMan->GetOuputCheckRight());
}

//-----------------------------------------------------------------------------
cpl_CommandsManager10::~cpl_CommandsManager10() {
    if (this->paramMan != NULL) {
        this->paramMan->Delete();
    }    
    if (this->paramProxy != NULL) {
        delete this->paramProxy;
    }
}
