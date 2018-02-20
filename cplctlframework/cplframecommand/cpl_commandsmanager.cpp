#include "cpl_commandframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_CommandsManager.
//-----------------------------------------------------------------------------
//
cpl_CommandsManager* cpl_CommandsManager::New() {
    return cpl_CommandsManagerObjectFactory::Instance()->CreateCommandsManager();
}

//-----------------------------------------------------------------------------
void cpl_CommandsManager::DoInitialization(char* cmdType) {
    //@@preconditions
    assert(this->cmdHandlerArray != NULL);
    //@@end preconditions

    this->cmdHandlerArray->Allocate(100, 100);
}

//-----------------------------------------------------------------------------
void cpl_CommandsManager::DoCleanup() {
    //@@preconditions
    assert(this->cmdHandlerArray != NULL);
    //@@end preconditions
    
    this->CleanupCommandHandlers();

    this->cmdHandlerArray->RemoveAllItems();
}

//-----------------------------------------------------------------------------
void cpl_CommandsManager::DoDefaultSetting() {
    //@@preconditions
    assert(this->cmdHandlerArray != NULL);
    //@@end preconditions

    this->InitializeCommandHandlers();
}

//-----------------------------------------------------------------------------
int cpl_CommandsManager::RegisterCommandHandler(cpl_CommandHandler* cmdHandler) {
    //@@preconditions
    assert(cmdHandler != NULL);
    assert(this->cmdHandlerArray != NULL);
    //@@end preconditions

    return this->cmdHandlerArray->RegisterCommandHandler(cmdHandler);
}

//-----------------------------------------------------------------------------
int cpl_CommandsManager::FindCommandHandler(char* stringId, cpl_CommandHandler*& pHandler) {
    //@@preconditions
    assert(pHandler == NULL);
    assert(this->cmdHandlerArray != NULL);
    //@@end preconditions

    int arraySize = this->cmdHandlerArray->GetNumberOfItems();
    for (int i = 0; i < arraySize; i++) {
        cpl_CommandHandler* cmdHandler = (cpl_CommandHandler*) this->cmdHandlerArray->GetItem(i);
        assert(cmdHandler != NULL);

        char name[64];
        cmdHandler->GetName(name);
        if (strcmp(stringId, name) == 0) {
            pHandler = cmdHandler;
            return 1;
        }
    }
    return 0;
}

//-----------------------------------------------------------------------------
void cpl_CommandsManager::InitializeCommandHandlers() {
    //@@preconditions
    assert(this->cmdHandlerArray != NULL);
    //@@end preconditions

    int arraySize = this->cmdHandlerArray->GetNumberOfItems();
    for (int i = 0; i < arraySize; i++) {
        cpl_CommandHandler* cmdHandler = (cpl_CommandHandler*) this->cmdHandlerArray->GetItem(i);
        assert(cmdHandler != NULL);

        cmdHandler->DoInitialize();
    }
}

//-----------------------------------------------------------------------------
void cpl_CommandsManager::CleanupCommandHandlers() {
    //@@preconditions
    assert(this->cmdHandlerArray != NULL);
    //@@end preconditions

    int arraySize = this->cmdHandlerArray->GetNumberOfItems();
    for (int i = 0; i < arraySize; i++) {
        cpl_CommandHandler* cmdHandler = (cpl_CommandHandler*) this->cmdHandlerArray->GetItem(i);
        assert(cmdHandler != NULL);
        
        cmdHandler->DoCleanup();
    }
}

//-----------------------------------------------------------------------------
cpl_CommandsManager::cpl_CommandsManager() {
    this->cmdHandlerArray = cpl_CommandHandlerArray::New();
}

//-----------------------------------------------------------------------------
cpl_CommandsManager::~cpl_CommandsManager() {
    if (this->cmdHandlerArray != NULL) {
        this->cmdHandlerArray->Delete();
        this->cmdHandlerArray = NULL;
    }
}
