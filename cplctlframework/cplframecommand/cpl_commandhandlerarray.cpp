#include "cpl_commandframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_CommandHandler
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
cpl_CommandHandlerArray* cpl_CommandHandlerArray::New() { 
    return new cpl_CommandHandlerArray;
}

//------------------------------------------------------------------------------
int cpl_CommandHandlerArray::RegisterCommandHandler(cpl_CommandHandler* cmdHandler) {
    //@@preconditions
    assert(cmdHandler != NULL);
    //@@end preconditions

    return this->InsertNextItem(cmdHandler);
}
