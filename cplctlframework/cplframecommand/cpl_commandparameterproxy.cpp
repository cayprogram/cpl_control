#include "cpl_commandframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_Command.
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
void cpl_CommandParameterProxy::SetInputParEngineReaderAndChecker(IParameterEngineReadRight *read, IParameterEngineCheckRight *check) {
    //@@preconditions
    assert(read  != NULL);
    assert(check != NULL);
    //@@end preconditions

	this->inParReader  = read;
	this->inParChecker = check;
}

//-----------------------------------------------------------------------------
void cpl_CommandParameterProxy::SetOutputParEngineWriterAndChecker(IParameterEngineWriteRight *write, IParameterEngineCheckRight *check) {
    //@@preconditions
    assert(write != NULL);
    assert(check != NULL);
    //@@end preconditions

	this->outParWriter  = write;
	this->outParChecker = check;
}

//-----------------------------------------------------------------------------
int cpl_CommandParameterProxy::GetError(int& error, char*& description) {
    static char error_description[][64] = {
        "NO ERROR",
        "PARAMETER ERROR[IN ]: NUMBER ERROR OR TYPE MISMATCH",
        "PARAMETER ERROR[IN ]: ILLEGAL PARAMETER VALUE",
        "COMMAND   ERROR     : COMMAND NAME MISMATCH",
        "PARAMETER ERROR[OUT]: ILLEGAL PARAMETER VALUE",
        "PARAMETER ERROR[OUT]: NUMBER ERROR OR TYPE MISMATCH",
    };

    error = this->success;
    description = error_description[error];

    return this->success;
}

//-----------------------------------------------------------------------------
int cpl_CommandParameterProxy::SetError(int error) {
    this->success = error;
    return 1;
}

//-----------------------------------------------------------------------------
void cpl_CommandParameterProxy::ClearOutputParameter() {
    //@@preconditions
    assert(this->outParWriter != NULL);
    //@@end preconditions
    
    this->outParWriter->Clear();
}

//-----------------------------------------------------------------------------
void cpl_CommandParameterProxy::ClearInputParameter() {
    //@@preconditions
    assert(this->inParReader != NULL);
    //@@end preconditions
    
    this->inParReader->Clear();
}

//-----------------------------------------------------------------------------
cpl_CommandParameterProxy::cpl_CommandParameterProxy() {
    this->inParChecker  = NULL;
    this->inParReader   = NULL;
    this->outParChecker = NULL;
    this->outParWriter  = NULL;
    this->success  = 0;
}

//-----------------------------------------------------------------------------
cpl_CommandParameterProxy::~cpl_CommandParameterProxy() {
    this->inParChecker  = NULL;
    this->inParReader   = NULL;
    this->outParChecker = NULL;
    this->outParWriter  = NULL;
    this->success  = 0;
}

