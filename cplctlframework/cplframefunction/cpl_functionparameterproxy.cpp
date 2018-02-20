#include "cpl_functionframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_FunctionParameterProxy.
//-----------------------------------------------------------------------------
//
void cpl_FunctionParameterProxy::SetInputParEngineReaderAndChecker(IParameterEngineReadRight *read, IParameterEngineCheckRight *check) {
    //@@preconditions
    assert(read  != NULL);
    assert(check != NULL);
    //@@end preconditions

	this->inParReader  = read;
	this->inParChecker = check;
}

//-----------------------------------------------------------------------------
void cpl_FunctionParameterProxy::SetOutputParEngineWriterAndChecker(IParameterEngineWriteRight *write, IParameterEngineCheckRight *check) {
    //@@preconditions
    assert(write != NULL);
    assert(check != NULL);
    //@@end preconditions

	this->outParWriter  = write;
	this->outParChecker = check;
}

//-----------------------------------------------------------------------------
int cpl_FunctionParameterProxy::GetError(int& error, char*& description) {
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
int cpl_FunctionParameterProxy::SetError(int error) {
    this->success = error;
    return 1;
}

//-----------------------------------------------------------------------------
void cpl_FunctionParameterProxy::ClearOutputParameter() {
    //@@preconditions
    assert(this->outParWriter != NULL);
    //@@end preconditions
    
    this->outParWriter->Clear();
}

//-----------------------------------------------------------------------------
void cpl_FunctionParameterProxy::ClearInputParameter() {
    //@@preconditions
    assert(this->inParReader != NULL);
    //@@end preconditions
    
    this->inParReader->Clear();
}

//-----------------------------------------------------------------------------
cpl_FunctionParameterProxy::cpl_FunctionParameterProxy() {
    this->inParChecker  = NULL;
    this->inParReader   = NULL;
    this->outParChecker = NULL;
    this->outParWriter  = NULL;
    this->success  = 0;
}

//-----------------------------------------------------------------------------
cpl_FunctionParameterProxy::~cpl_FunctionParameterProxy() {
    this->inParChecker  = NULL;
    this->inParReader   = NULL;
    this->outParChecker = NULL;
    this->outParWriter  = NULL;
    this->success  = 0;
}
