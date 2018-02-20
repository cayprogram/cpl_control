#include "cpl_commandframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_CommandCollection
//------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------
int cpl_CommandCollection::InsertCommand(cpl_Command * cmdObject) {
    //@@preconditions
    assert(cmdObject != NULL);
    //@@end preconditions
    
    CmdIdRecType stringRec;
    const char * stringCmd = cmdObject->GetStringId();
    assert(stringCmd != NULL);
    
    CmdIdKeyType stringKey;    
    strcpy(stringKey.id, stringCmd);
    
    CmdIdStatusEnum stat = this->hashCmdStringKey->CmdIdFind(stringKey, & stringRec);
    if (stat == CMD_STATUS_OK) {
        assert(0);
        return 0;
    }
    
    strcpy(stringRec.inkey.id, stringCmd);
    stringRec.stuff = cmdObject;
    this->hashCmdStringKey->CmdIdInsert(stringRec.inkey, & stringRec);
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_CommandCollection::IsCommandExist(char * string) {
    //@@preconditions
    assert(string != NULL);
    assert(strlen(string) > 0);
    assert(this->hashCmdStringKey != NULL);
    //@@end preconditions
    
    CmdIdRecType stringRec;
    CmdIdKeyType stringKey;
    
    strcpy(stringKey.id, string);
    stringRec.stuff = NULL;
    CmdIdStatusEnum stat = this->hashCmdStringKey->CmdIdFind(stringKey, & stringRec);
    if (stat == CMD_STATUS_KEY_NOT_FOUND) {
        return 0;
    }
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_CommandCollection::FindCommand(char* string, cpl_Command * & funcObject) {
    //@@preconditions
    assert(funcObject == NULL);
    assert(string != NULL);
    assert(strlen(string) > 0);
    assert(this->hashCmdStringKey != NULL);
    //@@end preconditions
    
    CmdIdRecType stringRec;
    CmdIdKeyType stringKey;
    
    strcpy(stringKey.id, string);
    
    stringRec.stuff = NULL;
    CmdIdStatusEnum stat = this->hashCmdStringKey->CmdIdFind(stringKey, & stringRec);
    if (stat == CMD_STATUS_KEY_NOT_FOUND) {
        return 0;
    }
    funcObject = stringRec.stuff;
    
    //@@postconditions
    assert(funcObject != NULL);
    //@@end postconditions
    
    return 1;
}

//------------------------------------------------------------------------------
cpl_CommandCollection::cpl_CommandCollection() {
    this->hashCmdStringKey = new cpl_HashTableCmdOneKey;
}

//------------------------------------------------------------------------------
cpl_CommandCollection::~cpl_CommandCollection() {
    if (this->hashCmdStringKey) {
        delete this->hashCmdStringKey;
        this->hashCmdStringKey = NULL;
    }
}
