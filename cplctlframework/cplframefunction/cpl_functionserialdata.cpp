#include "cpl_functionframeincludes.h"
#include "cpl_functionserialdata.h"

//------------------------------------------------------------------------
// class cpl_FunctionSerialData
//------------------------------------------------------------------------
//
//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
cpl_FunctionSerialData* cpl_FunctionSerialData::New() {
    return new cpl_FunctionSerialData;
}

//------------------------------------------------------------------------
void cpl_FunctionSerialData::Delete() { 
    delete this; 
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
void cpl_FunctionSerialData::Allocate(int sz, int ext) {
    //@@preconditions
    assert(sz  > 0);
    assert(ext > 0);
    //@@end preconditions

    if (sz > this->serialDatSize) {
        this->ClearAll();

        this->serialDatSize = sz;
        this->serialDatVal = new char*[sz];
        this->serialDatName = new char*[sz];

        for (int i = 0; i < sz; i++) {
            this->serialDatName[i] = NULL;
            this->serialDatVal[i] = NULL;
        }
    }

    this->serialDatExt = ext;
}

//------------------------------------------------------------------------
void cpl_FunctionSerialData::Reset() {
    this->serialDatMaxId = -1;
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
int  cpl_FunctionSerialData::InsertNextFuncSerialData(char* datName, char* datVal) {
    //@@preconditions
    assert(datName != NULL);
    assert(datVal != NULL);
    //@@end preconditions

    if (this->serialDatMaxId == this->serialDatSize-1) {
        this->Resize(this->serialDatSize+this->serialDatExt);
        assert(this->serialDatSize > this->serialDatMaxId);
    }

    this->serialDatMaxId++;
    this->SetFuncSerialDataName(this->serialDatMaxId, datName);
    this->SetFuncSerialDataValue(this->serialDatMaxId, datVal);

    return this->serialDatMaxId;
}

//------------------------------------------------------------------------
void cpl_FunctionSerialData::SetFuncSerialDataName(int datid, char* datName) {
    //@@preconditions
    assert(datid >= 0 && datid <= this->serialDatMaxId);
    assert(datName != NULL);
    //@@end preconditions

    if (this->serialDatName[datid] != NULL) {
        delete[] this->serialDatName[datid];
    }

    int slen = (int)strlen(datName);
    assert(slen > 0);
    this->serialDatName[datid] = new char[slen+1];
    sprintf(this->serialDatName[datid], "%s", datName);
}

//------------------------------------------------------------------------
char* cpl_FunctionSerialData::GetFuncSerialDataName(int datid) {
    //@@preconditions
    assert(datid >= 0 && datid <= this->serialDatMaxId);
    assert(this->serialDatName != NULL);
    //@@end preconditions

    return this->serialDatName[datid];
}

//------------------------------------------------------------------------
void cpl_FunctionSerialData::SetFuncSerialDataValue(int datid, char* datVal) {
    //@@preconditions
    assert(datid >= 0 && datid <= this->serialDatMaxId);
    assert(datVal != NULL);
    //@@end preconditions

    if (this->serialDatVal[datid] != NULL) {
        delete[] this->serialDatVal[datid];
    }
    int slen = (int)strlen(datVal);
    assert(slen > 0);
    this->serialDatVal[datid] = new char[slen+1];
    sprintf(this->serialDatVal[datid], "%s", datVal);
}

//------------------------------------------------------------------------
char* cpl_FunctionSerialData::GetFuncSerialDataValue(int datid) {
    //@@preconditions
    assert(datid >= 0 && datid <= this->serialDatMaxId);
    assert(this->serialDatVal != NULL);
    //@@end preconditions

    return this->serialDatVal[datid];
}

//------------------------------------------------------------------------
int cpl_FunctionSerialData::GetFuncSerialDataNumber() {
    return this->serialDatMaxId + 1;
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
void cpl_FunctionSerialData::Resize(int newSz) {
    //@@preconditions
    assert(newSz > 0);
    //@@end preconditions

    if (newSz > this->serialDatSize) {
        char** newSerialDatName = new char*[newSz];
        char** newSerialDatPara = new char*[newSz];
        int newSerialDatMaxId   = this->serialDatMaxId;
        for (int k = 0; k < newSz; k++) {
            newSerialDatName[k] = NULL;
            newSerialDatPara[k] = NULL;
        }

        for (int i = 0; i <= this->serialDatMaxId; i++) {
            if (this->serialDatName[i] != NULL) {
                int slen = (int)strlen(this->serialDatName[i]);
                newSerialDatName[i] = new char[slen+1];
                sprintf(newSerialDatName[i], "%s", this->serialDatName[i]);
            }
            if (this->serialDatVal[i] != NULL) {
                int slen = (int)strlen(this->serialDatVal[i]);
                newSerialDatPara[i] = new char[slen+1];
                sprintf(newSerialDatPara[i], "%s", this->serialDatVal[i]);
            }
        }

        this->ClearAll();
        this->serialDatName  = newSerialDatName;
        this->serialDatVal   = newSerialDatPara;
        this->serialDatMaxId = newSerialDatMaxId;
        this->serialDatSize  = newSz;
    }
}

//------------------------------------------------------------------------
void cpl_FunctionSerialData::ClearAll() {
    if (this->serialDatName != NULL) {
        for (int i = 0; i < this->serialDatSize; i++) {
            if (this->serialDatName[i] != NULL) {
                delete[] this->serialDatName[i];
                this->serialDatName[i] = NULL;
            }
        }
        delete[] this->serialDatName;
        this->serialDatName = NULL;
    }
    if (this->serialDatVal != NULL) {
        for (int i = 0; i < this->serialDatSize; i++) {
            if (this->serialDatVal[i] != NULL) {
                delete[] this->serialDatVal[i];
                this->serialDatVal[i] = NULL;
            }
        }
        delete[] this->serialDatVal;
        this->serialDatVal = NULL;
    }
    this->serialDatSize  = 0;
    this->serialDatMaxId = -1;
}

//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
cpl_FunctionSerialData::cpl_FunctionSerialData() {
    this->serialDatMaxId = -1;
    this->serialDatSize  = 0;
    this->serialDatExt   = 10;
    this->serialDatName  = NULL;
    this->serialDatVal   = NULL;
}

//------------------------------------------------------------------------
cpl_FunctionSerialData::~cpl_FunctionSerialData() {
    this->ClearAll();
}
