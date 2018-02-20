#include "cpl_functionframeincludes.h"
#include "cpl_functionserialdatacoder.h"

//------------------------------------------------------------------------
// class cpl_FunctionSerialDataCoder
//------------------------------------------------------------------------
//
//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
cpl_FunctionSerialDataCoder* cpl_FunctionSerialDataCoder::New() {
    return new cpl_FunctionSerialDataCoder;
}

//------------------------------------------------------------------------
void cpl_FunctionSerialDataCoder::Delete() { 
    delete this; 
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
char* cpl_FunctionSerialDataCoder::EncodeFuncSerialData(int num, int* iarray) {
    //@@preconditions
    assert(num > 0);
    assert(iarray != NULL);
    assert(this->numToStr != NULL);
    //@@end preconditions

    const char* dataStr = NULL;
    this->numToStr->IntArrayToString(num, iarray, dataStr);
    assert(dataStr != NULL);

    return (char*)dataStr;
}

//------------------------------------------------------------------------
char* cpl_FunctionSerialDataCoder::EncodeFuncSerialData(int num, float* farray) {
    //@@preconditions
    assert(num > 0);
    assert(farray != NULL);
    //@@end preconditions

    const char* dataStr = NULL;
    this->numToStr->FloatArrayToString(num, farray, dataStr);
    assert(dataStr != NULL);

    return (char*)dataStr;
}

//------------------------------------------------------------------------
char* cpl_FunctionSerialDataCoder::EncodeFuncSerialData(int num, double* darray) {
    //@@preconditions
    assert(num > 0);
    assert(darray != NULL);
    //@@end preconditions

    const char* dataStr = NULL;
    this->numToStr->DoubleArrayToString(num, darray, dataStr);
    assert(dataStr != NULL);

    return (char*)dataStr;
}

//------------------------------------------------------------------------
char* cpl_FunctionSerialDataCoder::EncodeFuncIdSerialData(int num, int* iarray) {
    //@@preconditions
    assert(num > 0);
    assert(iarray != NULL);
    assert(this->numToStr != NULL);
    //@@end preconditions

    const char* iarrayStr = NULL;
    this->numToStr->SortedIntArrayToString(num, iarray, iarrayStr);
    assert(iarrayStr != NULL);

    return (char*)iarrayStr;
}

//------------------------------------------------------------------------
int cpl_FunctionSerialDataCoder::ParseFuncSerialData(char* dataStr, int& num, int*& iarray) {
    //@@preconditions
    assert(dataStr != NULL);
    assert(this->numToStr != NULL);
    //@@end preconditions

    return this->numToStr->IntArrayFromString((const char*)dataStr, num, iarray);
}

//------------------------------------------------------------------------
int cpl_FunctionSerialDataCoder::ParseFuncSerialData(char* dataStr, int& num, float*& farray) {
    //@@preconditions
    assert(dataStr != NULL);
    assert(this->numToStr != NULL);
    //@@end preconditions

    return this->numToStr->FloatArrayFromString((const char*)dataStr, num, farray);
}

//------------------------------------------------------------------------
int cpl_FunctionSerialDataCoder::ParseFuncSerialData(char* dataStr, int& num, double*& darray) {
    //@@preconditions
    assert(dataStr != NULL);
    assert(this->numToStr != NULL);
    //@@end preconditions

    return this->numToStr->DoubleArrayFromString((const char*)dataStr, num, darray);
}

//------------------------------------------------------------------------
int cpl_FunctionSerialDataCoder::ParseFuncIdSerialData(char* dataStr, int& num, int*& iarray) {
    //@@preconditions
    assert(dataStr != NULL);
    assert(this->numToStr != NULL);
    //@@end preconditions

    return this->numToStr->SortedIntArrayFromString((const char*)dataStr, num, iarray);
}

//------------------------------------------------------------------------
int cpl_FunctionSerialDataCoder::ParseFuncCmdSerialData(char* dataStr, char*& cmdStr, cpl_ParameterBuffer*& cmdPar) {
    //@@preconditions
    assert(dataStr != NULL);
    assert(this->textFormater != NULL);
    //@@end preconditions

    return this->textFormater->ParseCtlActionText(dataStr, cmdStr, cmdPar);
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
cpl_FunctionSerialDataCoder::cpl_FunctionSerialDataCoder() {
    this->tmpStringBuf = NULL;
    this->tmpParBuf    = NULL;
    this->numToStr     = cpl_NumericToString::New();
    this->textFormater = cpl_CtlDataTextFormatter::New();
}

//------------------------------------------------------------------------
cpl_FunctionSerialDataCoder::~cpl_FunctionSerialDataCoder() {
    if (this->tmpStringBuf != NULL) {
        delete[] this->tmpStringBuf;
        this->tmpStringBuf = NULL;
    }
    if (this->tmpParBuf != NULL) {
        delete this->tmpParBuf;
        this->tmpParBuf = NULL;
    }
    if (this->numToStr != NULL) {
        this->numToStr->Delete();
        this->numToStr = NULL;
    }
    if (this->textFormater != NULL) {
        this->textFormater->Delete();
        this->textFormater = NULL;
    }
}
