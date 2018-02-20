#include "cpl_functionframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_FunctionProcess10
//------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------
int cpl_FunctionProcess10::EnterFunctionScope() {
    //@@preconditions
    assert(this->functionParameter != NULL);
    assert(this->functionParameterStack != NULL);
    //@@end preconditions

    cpl_FunctionParameter* param = cpl_FunctionParameter::New();  
    assert(param != NULL);

    this->functionParameterStack->PushOpenElement(param);
    this->functionParameter = this->functionParameterStack->GetCurrentOpenElement();
    assert(this->functionParameter != NULL);
    return this->functionParameterStack->GetStackDepth();        
}

//------------------------------------------------------------------------------
int cpl_FunctionProcess10::LeaveFunctionScope() {
    //@@preconditions
    assert(this->functionParameter != NULL);
    assert(this->functionParameterStack != NULL);
    //@@end preconditions

    cpl_FunctionParameter* param = this->functionParameterStack->PopOpenElement();
    assert(param != NULL);
    assert(param == this->functionParameter);

    this->functionParameter->Delete();
    this->functionParameter = this->functionParameterStack->GetCurrentOpenElement();
    assert(this->functionParameter != NULL);
    return this->functionParameterStack->GetStackDepth();
}

//------------------------------------------------------------------------------
int cpl_FunctionProcess10::ExecuteFunctionDirect(cpl_Function* func) {
    //@@preconditions
    assert(func != NULL);
    assert(this->functionParameter != NULL);
    assert(this->functionParameterStack != NULL);
    assert(this->functionStack != NULL);
    //@@end preconditions

    if (func->IsValidContext() == 0) {   
        return 0;
    }        

    this->functionStack->PushOpenElement(func);
    this->functionCurrent= this->functionStack->GetCurrentOpenElement();

    cpl_FunctionParameterProxy* proxy = this->functionParameter->GetParamProxy();
    assert(proxy != NULL);

    func->SetParameterProxy(proxy);
    int ret = this->ExecuteFunctionOnStack(func);
    func->SetParameterProxy(NULL);   

    this->functionStack->PopOpenElement();
    this->functionCurrent= this->functionStack->GetCurrentOpenElement();
    return ret;
}

//------------------------------------------------------------------------------
int cpl_FunctionProcess10::ExecuteFunctionOnStack(cpl_Function* func) {
    //@@preconditions
    assert(func != NULL); 
    //@@end preconditions

    if (func->CheckInputParameter() != 1 || func->ReadInputParameter() != 1) {
        return 0;
    }    
    func->Execute();
    if (func->WriteOutputParameter() != 1 || func->CheckOutputParameter() != 1) {
        return 0;
    }
    return 1;
}

//------------------------------------------------------------------------------
IParameterEngineReadRight* cpl_FunctionProcess10::GetOutputParamReader() {
    //@@preconditions
    assert(this->functionParameter != NULL);
    assert(this->functionParameterStack != NULL);
    //@@end preconditions

    return this->functionParameter->GetParamEngine()->GetOutputReadRight();
}

//------------------------------------------------------------------------------
IParameterEngineWriteRight* cpl_FunctionProcess10::GetInputParamWriter() {
    //@@preconditions
    assert(this->functionParameter != NULL);
    assert(this->functionParameterStack != NULL);
    //@@end preconditions

    return this->functionParameter->GetParamEngine()->GetInputWriteRight();
}

//------------------------------------------------------------------------------
IParameterEngineCheckRight* cpl_FunctionProcess10::GetOutputParamChecker() {
    //@@preconditions
    assert(this->functionParameter != NULL);
    assert(this->functionParameterStack != NULL);
    //@@end preconditions

     return this->functionParameter->GetParamEngine()->GetOuputCheckRight();
}

//------------------------------------------------------------------------------
IParameterEngineCheckRight* cpl_FunctionProcess10::GetInputParamChecker() {
    //@@preconditions
    assert(this->functionParameter != NULL);
    assert(this->functionParameterStack != NULL);
    //@@end preconditions

    return this->functionParameter->GetParamEngine()->GetInputCheckRight();
}

//------------------------------------------------------------------------------
cpl_FunctionProcess10::cpl_FunctionProcess10() {
    this->functionCurrent        = NULL;
    this->functionStack          = cpl_FunctionStack::New();
    this->functionParameter      = cpl_FunctionParameter::New();    
    this->functionParameterStack = cpl_FunctionParameterStack::New();

    //push global parameter stack.
    this->functionParameterStack->PushOpenElement(this->functionParameter);
}

//------------------------------------------------------------------------------
cpl_FunctionProcess10::~cpl_FunctionProcess10() {  
    if (this->functionParameter != NULL) {
        this->functionParameter->Delete();
    }  
    if (this->functionParameterStack != NULL) {
        this->functionParameterStack->Delete();    
    }
    if (this->functionStack != NULL) {
        this->functionStack->Delete();
    }
}
