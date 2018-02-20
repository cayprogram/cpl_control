#include "cpl_commandframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_CommandsManager15.
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
int cpl_CommandsManager15::SetCommandCallback(void (* fun) (int, void*), void* clientData) {
    //@@preconditions
    //@@end preconditions

    this->CommandExecCallback = fun;
    this->CommandExecClientData = clientData;
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_CommandsManager15::FindCommand(char* string, cpl_Command * & cmdObject) {
    //@@preconditions
    assert(cmdObject == NULL);
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
    cmdObject = stringRec.stuff;
    
    //@@postconditions
    assert(cmdObject != NULL);
    //@@end postconditions
    
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_CommandsManager15::InsertCommand(cpl_Command * cmdObject) {
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

    //link with runtime context.
    cmdObject->SetRuntimeContext(this->cmdCtxRuntime.domainId, this->cmdCtxRuntime.graphicId);

    return 1;
}

//-----------------------------------------------------------------------------
int cpl_CommandsManager15::ExecuteCommand(char* string) {
    //@@preconditions.
    assert(string != NULL);
    //@@end preconditions

    CmdIdRecType stringRec;
    CmdIdKeyType stringKey;
    
    strcpy(stringKey.id, string);
    stringRec.stuff = NULL;
    CmdIdStatusEnum stat = this->hashCmdStringKey->CmdIdFind(stringKey, & stringRec);
    if (stat == CMD_STATUS_KEY_NOT_FOUND) {
        assert(0);
        return 0;
    }

    return this->ExecuteCommandDirect(stringRec.stuff);  
}

//-----------------------------------------------------------------------------
int cpl_CommandsManager15::ExecuteCommandDirect(cpl_Command* command) {
    //@@preconditions.
    assert(command != NULL);
    //@@end preconditions

    //link with runtime context.
    command->SetRuntimeContext(this->cmdCtxRuntime.domainId, this->cmdCtxRuntime.graphicId);

    //set parameter proxy.
    command->SetParameterProxy(this->paramProxy);        
    this->paramProxy->ClearOutputParameter();  

    ///-------------------------------------------
    if (command->CheckInputParameter_() != 1) {
        if (this->CommandExecCallback != NULL) {
            this->CommandExecCallback(1, this->CommandExecClientData);
        }
        this->paramProxy->ClearInputParameter();        
        command->SetParameterProxy(NULL);
        assert(0);
        return 0;
    }
    
    /** Read Input Parameter */
    if (command->ReadInputParameter_() != 1) {
        if (this->CommandExecCallback != NULL) {
            this->CommandExecCallback(2, this->CommandExecClientData);
        }
        this->paramProxy->ClearInputParameter();        
        command->SetParameterProxy(NULL);
        assert(0);
        return 0;
    }   
    command->Execute();
    
    /** Write output Parameter */
    if (command->WriteOutputParameter_() != 1) {
        if (this->CommandExecCallback != NULL) {
            this->CommandExecCallback(3, this->CommandExecClientData);
        }
        this->paramProxy->ClearInputParameter();        
        command->SetParameterProxy(NULL);
        assert(0);
        return 0;
    }
    /** Check output Parameter */
    if (command->CheckOutputParameter_() != 1) {
        if (this->CommandExecCallback != NULL) {
            this->CommandExecCallback(4, this->CommandExecClientData);
        }
        this->paramProxy->ClearInputParameter();        
        command->SetParameterProxy(NULL);
        assert(0);
        return 0;
    }
    
    if (this->CommandExecCallback != NULL) {
        this->CommandExecCallback(0, this->CommandExecClientData);
    }

    this->paramProxy->ClearInputParameter();        
    command->SetParameterProxy(NULL);               
    return 1;  
}

//-----------------------------------------------------------------------------
void cpl_CommandsManager15::SetRuntimeContext(int domainId, int graphicId) {
    //@@preconditions
    //@@end preconditions
    
    this->cmdCtxRuntime.domainId  = domainId;
    this->cmdCtxRuntime.graphicId = graphicId;
}

//-----------------------------------------------------------------------------
void cpl_CommandsManager15::GetRuntimeContext(int& domainId, int& graphicId) {
    //@@preconditions
    //@@end preconditions
    
    domainId  = this->cmdCtxRuntime.domainId;
    graphicId = this->cmdCtxRuntime.graphicId;
}

//-----------------------------------------------------------------------------
cpl_CommandsManager15::cpl_CommandsManager15() {
    this->hashCmdStringKey = new cpl_HashTableCmdOneKey;
    this->CommandExecCallback   = NULL;
    this->CommandExecClientData = NULL;

    this->cmdCtxRuntime.domainId  = -1;
    this->cmdCtxRuntime.graphicId = -1;
}

//-----------------------------------------------------------------------------
cpl_CommandsManager15::~cpl_CommandsManager15() {
    if (this->hashCmdStringKey) {
        delete this->hashCmdStringKey;
        this->hashCmdStringKey = NULL;
    }
}
