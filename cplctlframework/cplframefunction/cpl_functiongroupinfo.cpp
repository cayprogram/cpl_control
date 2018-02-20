#include "cpl_functionframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_FunctionGroupInfo
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
cpl_FunctionGroupInfo* cpl_FunctionGroupInfo::DeepCopy() {
    //@@preconditions
    assert(this != NULL);
    //@@end preconditions
    
    cpl_FunctionGroupInfo* pManager = new cpl_FunctionGroupInfo;
    assert(pManager != NULL);
         
    pManager->Size     = this->MaxId+1;
    pManager->MaxId    = this->MaxId;
    pManager->Extend   = this->Extend;
    pManager->Array    = NULL;
    
    if (this->MaxId >= 0) {
        int tmpSize = this->MaxId+1;
        pManager->Array = new _fbFuncItem_s[tmpSize];
        assert(pManager->Array != NULL);
        for(int i = 0; i < tmpSize; i++) {
            strcpy(pManager->Array[i].funcid, this->Array[i].funcid);
            pManager->Array[i].group = this->Array[i].group;
        }             
    }
    
    //@@postconditions
    assert(pManager != NULL);
    //@@end postconditions
    
    return pManager;
}

//-----------------------------------------------------------------------------
int cpl_FunctionGroupInfo::Allocate(int sz, int ext) {
    //@@preconditions
    assert(sz > 0);
    assert(ext> 0);
    //@@end preconditions

    if (sz > this->Size || this->Array == NULL) {
        if (this->Array != NULL) {
            delete[] this->Array;
        }
        this->Size = (sz > 0 ? sz : 1);
        this->Array = new _fbFuncItem_s[this->Size];
        if (this->Array == NULL) {
            return 0;
        }
        for (int i = 0; i < this->Size; i++) {
             this->Array[i].funcid[0]  = '\0';
             this->Array[i].group      = 0;
        }
    }
    this->Extend = (ext > 0 ? ext : 1);
    this->MaxId = -1;
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_FunctionGroupInfo::InsertNextItem(const char* funcname) {
    //@@preconditions
    assert(funcname != NULL);
    assert(strlen(funcname) < 63);
    //@@end preconditions

    this->InsertItem(++this->MaxId, funcname, 0);
    return this->MaxId;
}

//-----------------------------------------------------------------------------
int cpl_FunctionGroupInfo::InsertNextItem(const char* funcname, int group) {
    //@@preconditions
    assert(funcname != NULL);
    assert(strlen(funcname) < 63);
    //@@end preconditions

    this->InsertItem(++this->MaxId, funcname, group);
    return this->MaxId;
}

//-----------------------------------------------------------------------------
void cpl_FunctionGroupInfo::InsertItem(int pos, const char* funcname, int group) {
    //@@preconditions
    assert(pos >= 0);
    assert(funcname != NULL);
    //@@end preconditions

    if (pos >= this->Size) {
        this->Resize(pos + 1);
    }
    if (pos > this->MaxId) {
        this->MaxId = pos;
    }

    _fbFuncItem_s * item = NULL;
    item = this->Array + pos;
    assert(item != NULL);

    item->group = group;
    sprintf(item->funcid, funcname);
    return;
}

//-----------------------------------------------------------------------------
int cpl_FunctionGroupInfo::RemoveItem(const char* funcname) {
    //@@preconditions
    assert(funcname != NULL);
    assert(this->Array != NULL);
    //@@end preconditions

    int findId = -1;
    for (int i = 0; i <= this->MaxId; i++) {
        if (strcmp(this->Array[i].funcid, funcname) == 0) {
            findId = i;
            break;
        }
    }
    assert(findId != -1);

    //exchange position between lnId and MaxId.
    if (findId != this->MaxId) {
        this->Array[findId] = this->Array[this->MaxId];
        this->Array[this->MaxId].funcid[0]  = '\0';
        this->Array[this->MaxId].group    = 0;
    }
    else {
        this->Array[findId].funcid[0]  = '\0';
        this->Array[findId].group      = 0;
    }
    this->MaxId--;
    return this->MaxId;
}
    
//-----------------------------------------------------------------------------
int cpl_FunctionGroupInfo::RemoveAllItems(){
    for (int i = 0; i <= this->MaxId; i++) {
        this->Array[i].funcid[0]  = '\0';
        this->Array[i].group    = 0;
    }
    this->MaxId = -1;
    return 1;
}
       
//-----------------------------------------------------------------------------
int cpl_FunctionGroupInfo::GetGroupInfo(const char* funcname) {
    //@@preconditions
    assert(funcname != NULL);
    assert(this->Array != NULL);
    //@@end preconditions

    int findId = -1;
    for (int i = 0; i <= this->MaxId; i++) {
        if (strcmp(this->Array[i].funcid, funcname) == 0) {
            findId = i;
            break;
        }
    }
    assert(findId != -1);

    return this->Array[findId].group;
}

//-----------------------------------------------------------------------------
cpl_FunctionGroupInfo::_fbFuncItem_s* cpl_FunctionGroupInfo::Resize(int sz) {
    //@@preconditions
    assert(sz > 0);
    //@@end preconditions

    int newSize = 0;

    if (sz >= this->Size) {
        newSize = this->Size + sz;
    }
    else {
        assert(0);
        newSize = sz;
    }

    _fbFuncItem_s * newArray = new _fbFuncItem_s[newSize];
    assert(newArray != NULL);

    for (int j = 0; j < newSize; j++) {
        newArray[j].group      = 0;
        newArray[j].funcid[0]  = '\0';
    }
    for (int i = 0; i < sz && i < this->Size; i++) {
        newArray[i].group = this->Array[i].group;
        sprintf(newArray[i].funcid, this->Array[i].funcid);
    }

    this->Size = newSize;
    delete[] this->Array;
    this->Array = newArray;
    return this->Array;
}

//-----------------------------------------------------------------------------
int cpl_FunctionGroupInfo::GetFunctionNumber() {
    return this->MaxId+1;
}

//-----------------------------------------------------------------------------
const char* cpl_FunctionGroupInfo::GetFuncName(int index) {
    //@@preconditions
    assert(index >= 0 && index <= this->MaxId);
    //@@end preconditions

    return this->Array[index].funcid;
}

//-----------------------------------------------------------------------------
cpl_FunctionGroupInfo::cpl_FunctionGroupInfo(){
    this->Array  =  NULL;
    this->MaxId  = -1;
    this->Size   =  0;
    this->Extend = 10;
}

//-----------------------------------------------------------------------------
cpl_FunctionGroupInfo::~cpl_FunctionGroupInfo() {
    if (this->Array != NULL) {
        delete[] this->Array;
        this->Array = NULL;
    }
}
