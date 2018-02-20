#include "cpl_commandframeincludes.h"
#include "cpl_commanddefine.h"
#include "cpl_commandsimpleinterface.h"
#include "cpl_commandsimpleholder.h"
#include "cpl_commandsimple.h"
#include "cpl_commandhandlersimpleinterface.h"
#include "cpl_commandhandlersimpleholder.h"
#include "cpl_commandhandlersimple.h"

//-----------------------------------------------------------------------------
// create instance.
//-----------------------------------------------------------------------------
cpl_CommandSimpleHolder* cpl_CommandSimpleHolder::New(cpl_ICommandSimple* cmd) {
    //@@preconditions
    assert(cmd != NULL);
    //@@end preconditions

    return new cpl_CommandSimpleHolder(cmd);
}

//-----------------------------------------------------------------------------
// class cpl_CommandSimpleHolder
//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
cpl_CommandSimpleHolder* cpl_CommandSimpleHolder::DeepCopy() {
    //@@preconditions
    assert(this->pCmd != NULL);
    //@@end preconditions

    return cpl_CommandSimpleHolder::New((cpl_ICommandSimple *)this->pCmd->DeepCopy());
}

//-----------------------------------------------------------------------------
const char* cpl_CommandSimpleHolder::GetStringId() { 
    //@@preconditions
    assert(this->pCmd != NULL);
    //@@end preconditions

    return this->pCmd->GetStringId(); 
}
        
//-----------------------------------------------------------------------------
void cpl_CommandSimpleHolder::ExecuteDirect() {  
    //@@preconditions
    assert(this->pCmd != NULL);
    //@@end preconditions

    this->pCmd->ExecuteDirect();
}

//-----------------------------------------------------------------------------
void cpl_CommandSimpleHolder::SetCommandHandler(const char* stringId, void* commandHandler) {
    //@@preconditions
    assert(this->pCmd != NULL);
    //@@end preconditions

    cpl_CommandHandler* _cmdHandler = static_cast<cpl_CommandHandler*>(commandHandler);
    assert(_cmdHandler != NULL);

    if (cpl_CommandHandlerSimpleHolder::SafeDownCast(_cmdHandler) != NULL) {
        cpl_CommandHandlerSimpleHolder* pSimpleHolder = static_cast<cpl_CommandHandlerSimpleHolder*> (_cmdHandler);
        assert(pSimpleHolder != NULL);

        this->pCmd->SetCommandHandler(stringId, pSimpleHolder->GetInterfaceImp());
    }
    else {
        this->pCmd->SetCommandHandler(stringId, commandHandler);
    }    
}

//-----------------------------------------------------------------------------
int cpl_CommandSimpleHolder::CheckInputParameter() {  
    //@@preconditions
    assert(this->pCmd != NULL);
    //@@end preconditions

    cpl_CommandParameterProxy* proxy = this->GetParamterProxy();
    assert(proxy != NULL);

    return this->pCmd->CheckInputParameter(proxy->inParChecker);
}

//-----------------------------------------------------------------------------
int cpl_CommandSimpleHolder::CheckOutputParameter() {  
    //@@preconditions
    assert(this->pCmd != NULL);
    //@@end preconditions

    cpl_CommandParameterProxy* proxy = this->GetParamterProxy();
    assert(proxy != NULL);

    return this->pCmd->CheckOutputParameter(proxy->outParChecker);
}

//-----------------------------------------------------------------------------
int cpl_CommandSimpleHolder::ReadInputParameter() {  
    //@@preconditions
    assert(this->pCmd != NULL);
    //@@end preconditions

    cpl_CommandParameterProxy* proxy = this->GetParamterProxy();
    assert(proxy != NULL);

    return this->pCmd->ReadInputParameter(proxy->inParReader);
}

//-----------------------------------------------------------------------------
int cpl_CommandSimpleHolder::WriteOutputParameter(){  
    //@@preconditions
    assert(this->pCmd != NULL);
    //@@end preconditions

    cpl_CommandParameterProxy* proxy = this->GetParamterProxy();
    assert(proxy != NULL);

    return this->pCmd->WriteOutputParameter(proxy->outParWriter);
}

//-----------------------------------------------------------------------------
cpl_CommandSimpleHolder::cpl_CommandSimpleHolder(cpl_ICommandSimple* cmd):pCmd(cmd) {  
}

//-----------------------------------------------------------------------------
cpl_CommandSimpleHolder::~cpl_CommandSimpleHolder() {
    if (this->pCmd != NULL) {
        this->pCmd->Release();
        this->pCmd = NULL;
    }
}
