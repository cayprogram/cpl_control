#include "cpl_commandframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_CommandHandlerCollection
//------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------
int cpl_CommandHandlerCollection::InsertCommandHandler(const char* stringId, cpl_CommandHandler * cmdObject) {
    //@@preconditions
    assert(cmdObject != NULL);
    //@@end preconditions
    
    CmdHandlerIdRecType stringRec;
    const char * stringCmdHandler = stringId;
    assert(stringCmdHandler != NULL);
    
    CmdHandlerIdKeyType stringKey;    
    strcpy(stringKey.id, stringCmdHandler);
    
    CmdHandlerIdStatusEnum stat = this->hashCmdHandlerStringKey->CmdHandlerIdFind(stringKey, & stringRec);
    if (stat == CMDHND_STATUS_OK) {
        assert(0);
        return 0;
    }
    
    strcpy(stringRec.inkey.id, stringCmdHandler);
    stringRec.stuff = cmdObject;
    this->hashCmdHandlerStringKey->CmdHandlerIdInsert(stringRec.inkey, & stringRec);
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_CommandHandlerCollection::IsCommandHandlerExist(char * string) {
    //@@preconditions
    assert(string != NULL);
    assert(strlen(string) > 0);
    assert(this->hashCmdHandlerStringKey != NULL);
    //@@end preconditions
    
    CmdHandlerIdRecType stringRec;
    CmdHandlerIdKeyType stringKey;
    
    strcpy(stringKey.id, string);
    stringRec.stuff = NULL;
    CmdHandlerIdStatusEnum stat = this->hashCmdHandlerStringKey->CmdHandlerIdFind(stringKey, & stringRec);
    if (stat == CMDHND_STATUS_KEY_NOT_FOUND) {
        return 0;
    }
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_CommandHandlerCollection::FindCommandHandler(char* string, cpl_CommandHandler * & cmdHandlerObject) {
    //@@preconditions
    assert(cmdHandlerObject == NULL);
    assert(string != NULL);
    assert(strlen(string) > 0);
    assert(this->hashCmdHandlerStringKey != NULL);
    //@@end preconditions
    
    CmdHandlerIdRecType stringRec;
    CmdHandlerIdKeyType stringKey;
    
    strcpy(stringKey.id, string);
    
    stringRec.stuff = NULL;
    CmdHandlerIdStatusEnum stat = this->hashCmdHandlerStringKey->CmdHandlerIdFind(stringKey, & stringRec);
    if (stat == CMDHND_STATUS_KEY_NOT_FOUND) {
        return 0;
    }
    cmdHandlerObject = stringRec.stuff;
    
    //@@postconditions
    assert(cmdHandlerObject != NULL);
    //@@end postconditions
    
    return 1;
}

//------------------------------------------------------------------------------
cpl_CommandHandlerCollection::cpl_CommandHandlerCollection() {
    this->hashCmdHandlerStringKey = new cpl_HashTableCmdHandlerOneKey;
}

//------------------------------------------------------------------------------
cpl_CommandHandlerCollection::~cpl_CommandHandlerCollection() {
    if (this->hashCmdHandlerStringKey) {
        delete this->hashCmdHandlerStringKey;
        this->hashCmdHandlerStringKey = NULL;
    }
}
