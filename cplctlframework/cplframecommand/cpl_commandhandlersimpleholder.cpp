#include "cpl_commandframeincludes.h"
#include "cpl_commandhandlersimpleinterface.h"
#include "cpl_commandhandlersimpleholder.h"
#include "cpl_commandhandlersimple.h"

//-----------------------------------------------------------------------------
// create instance.
//-----------------------------------------------------------------------------
cpl_CommandHandlerSimpleHolder* cpl_CommandHandlerSimpleHolder::New() {
    return new cpl_CommandHandlerSimpleHolder;
}

//-----------------------------------------------------------------------------
// class cpl_CommandSimpleHolder
//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
cpl_CommandHandlerSimpleHolder* cpl_CommandHandlerSimpleHolder::DeepCopy() {
    //@@preconditions
    assert(this->pCmdHandler != NULL);
    //@@end preconditions

    cpl_CommandHandlerSimpleHolder* pThis = cpl_CommandHandlerSimpleHolder::New();
    assert(pThis != NULL);
    pThis->SetHandleObject((cpl_ICommandHandlerSimple *)this->pCmdHandler->DeepCopy());
    return pThis;
}

//-----------------------------------------------------------------------------
void cpl_CommandHandlerSimpleHolder::DoInitialize() {
    //@@preconditions
    assert(this->pCmdHandler != NULL);
    //@@end preconditions

    this->pCmdHandler->DoInitialize();
}

//-----------------------------------------------------------------------------
void cpl_CommandHandlerSimpleHolder::DoCleanup() {
    //@@preconditions
    assert(this->pCmdHandler != NULL);
    //@@end preconditions

    this->pCmdHandler->DoCleanup();
}

//-----------------------------------------------------------------------------
void cpl_CommandHandlerSimpleHolder::DoUpdate() {
    //@@preconditions
    assert(this->pCmdHandler != NULL);
    //@@end preconditions

    this->pCmdHandler->DoUpdate();
}

//-----------------------------------------------------------------------------
void* cpl_CommandHandlerSimpleHolder::GetInterfaceImp() {
    //@@preconditions
    assert(this->pCmdHandler != NULL);
    //@@end preconditions

    return this->pCmdHandler;
}

//-----------------------------------------------------------------------------
void cpl_CommandHandlerSimpleHolder::SetCommandHandler(const char* stringId, void* commandHandler) {
    //@@preconditions
    assert(this->pCmdHandler != NULL);
    //@@end preconditions

    cpl_CommandHandler* _cmdHandler = static_cast<cpl_CommandHandler*>(commandHandler);
    assert(_cmdHandler != NULL);

    if (cpl_CommandHandlerSimpleHolder::SafeDownCast(_cmdHandler) != NULL) {
        cpl_CommandHandlerSimpleHolder* pSimpleHolder = static_cast<cpl_CommandHandlerSimpleHolder*> (_cmdHandler);
        assert(pSimpleHolder != NULL);

        this->pCmdHandler->SetCommandHandler(stringId, pSimpleHolder->GetInterfaceImp());
    }
    else {
        this->pCmdHandler->SetCommandHandler(stringId, commandHandler);
    }    
}

//-----------------------------------------------------------------------------
void cpl_CommandHandlerSimpleHolder::SetHandleObject(cpl_ICommandHandlerSimple* cmdhandler) {
    this->pCmdHandler = cmdhandler;
}

//-----------------------------------------------------------------------------
cpl_CommandHandlerSimpleHolder::cpl_CommandHandlerSimpleHolder() {  
    this->pCmdHandler = NULL;
}

//-----------------------------------------------------------------------------
cpl_CommandHandlerSimpleHolder::~cpl_CommandHandlerSimpleHolder() {
    if (this->pCmdHandler != NULL) {
        this->pCmdHandler->Release();
        this->pCmdHandler = NULL;
    }
}
