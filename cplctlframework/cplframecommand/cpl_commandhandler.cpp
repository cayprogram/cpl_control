#include "cpl_commandframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_CommandHandler
//------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------
void cpl_CommandHandler::SetName(char name[64]) {
    strcpy(this->StringId, name);
}

//------------------------------------------------------------------------------
void cpl_CommandHandler::GetName(char name[64]) {
    strcpy(name, this->StringId);
}

//------------------------------------------------------------------------------
void cpl_CommandHandler::SetCommandHandler(const char* stringId, void* commandHandler) {
}

//------------------------------------------------------------------------------
cpl_CommandHandler::cpl_CommandHandler() {
    this->StringId[0] = '\0';
}

//------------------------------------------------------------------------------
cpl_CommandHandler::~cpl_CommandHandler() {
}
