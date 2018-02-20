#include "cpl_commandframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_Command
//------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------
void cpl_Command::Delete() { 
    delete this; 
}

//------------------------------------------------------------------------------
int cpl_Command::CheckInVariant() {
    return 1;
}

//------------------------------------------------------------------------------
int cpl_Command::CheckInputParameter_() {
    //@@preconditions
    assert(this->cmdData.paramProxy != NULL);
    //@@end @@preconditions

	this->CheckInVariant();
    return this->CheckInputParameter();
}

//------------------------------------------------------------------------------
int cpl_Command::ReadInputParameter_() {
    //@@preconditions
    assert(this->cmdData.paramProxy != NULL);
    //@@end @@preconditions

    this->CheckInVariant();
    return this->ReadInputParameter();	
}

//------------------------------------------------------------------------------
int cpl_Command::WriteOutputParameter_() {
    //@@preconditions
    assert(this->cmdData.paramProxy != NULL);
    //@@end @@preconditions
	
    this->CheckInVariant();
    return this->WriteOutputParameter();
}

//------------------------------------------------------------------------------
int cpl_Command::CheckOutputParameter_() {
    //@@preconditions
    assert(this->cmdData.paramProxy != NULL);
    //@@end @@preconditions
	
    this->CheckInVariant();
    return this->CheckOutputParameter();
}

//------------------------------------------------------------------------------
void cpl_Command::Execute() {
	//@@preconditions
	assert(this->cmdData.paramProxy != NULL);
	//@@end @@preconditions
	
    this->CheckInVariant();
    this->ExecuteDirect();
}

//------------------------------------------------------------------------------
void cpl_Command::SetParameterProxy(cpl_CommandParameterProxy* proxy) {
    //@@preconditions
    //@@end preconditions

    this->cmdData.paramProxy = proxy;      
}

void cpl_Command::SetRuntimeContext(int domainId, int graphicId) {
    //@@preconditions
    //@@end preconditions

    this->cmdData.ctxRuntimeData.domainId  = domainId;
    this->cmdData.ctxRuntimeData.graphicId = graphicId;
}

//------------------------------------------------------------------------------
cpl_CommandParameterProxy* cpl_Command::GetParamterProxy() {
    return this->cmdData.paramProxy;
}

//------------------------------------------------------------------------------
void cpl_Command::SetCommandHandler(const char* stringId, void* commandHandler) {
    this->cmdData.userdata = commandHandler;
}

//------------------------------------------------------------------------------
cpl_Command::cpl_Command() {
    this->cmdData.text[0]    ='\0';
    this->cmdData.cmdid      = 0;
    this->cmdData.type       = 0;
    this->cmdData.userdata   = NULL;
    this->cmdData.paramProxy = NULL;
    this->cmdData.ctxRuntimeData.domainId  = -1;
    this->cmdData.ctxRuntimeData.graphicId = -1;
}

