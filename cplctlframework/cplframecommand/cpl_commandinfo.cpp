#include "cpl_commandframeincludes.h"


//-----------------------------------------------------------------------------
// class cpl_CommandInfo
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
cpl_CommandInfo* cpl_CommandInfo::DeepCopy() {
    //@@preconditions
    assert(this != NULL);
    //@@end preconditions
    
    cpl_CommandInfo* pManager = new cpl_CommandInfo;
    assert(pManager != NULL);
         
    pManager->Size     = this->MaxId+1;
    pManager->MaxId    = this->MaxId;
    pManager->Extend   = this->Extend;
    pManager->Array    = NULL;
    
    if (this->MaxId >= 0) {
        int tmpSize = this->MaxId+1;
        pManager->Array = new _fbItem_s[tmpSize];
        assert(pManager->Array != NULL);
        for(int i = 0; i < tmpSize; i++) {
            strcpy(pManager->Array[i].c1, this->Array[i].c1);
        }             
    }
    
    //@@postconditions
    assert(pManager != NULL);
    //@@end postconditions
    
    return pManager;
}

//-----------------------------------------------------------------------------
int cpl_CommandInfo::Allocate(int sz, int ext) {
    //@@preconditions
    assert(sz > 0);
    assert(ext> 0);
    //@@end preconditions

    if (sz > this->Size || this->Array == NULL) {
        if (this->Array != NULL) {
            delete[] this->Array;
        }
        this->Size = (sz > 0 ? sz : 1);
        this->Array = new _fbItem_s[this->Size];
        if (this->Array == NULL) {
            return 0;
        }
        for (int i = 0; i < this->Size; i++) {
             this->Array[i].c1[0] = '\0';
        }
    }
    this->Extend = (ext > 0 ? ext : 1);
    this->MaxId = -1;
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_CommandInfo::InsertNextItem(const char* c1) {
    //@@preconditions
    assert(c1 != NULL);
    assert(strlen(c1) < 63);
    //@@end preconditions

    this->InsertItem(++this->MaxId, c1);
    return this->MaxId;
}

//-----------------------------------------------------------------------------
void cpl_CommandInfo::InsertItem(int pos, const char* c1) {
    //@@preconditions
    assert(pos >= 0);
    assert(c1 != NULL);
    //@@end preconditions

    if (pos >= this->Size) {
        this->Resize(pos + 1);
    }
    if (pos > this->MaxId) {
        this->MaxId = pos;
    }

    _fbItem_s * item = NULL;
    item = this->Array + pos;
    assert(item != NULL);

    sprintf(item->c1, c1);
    return;
}

//-----------------------------------------------------------------------------
int cpl_CommandInfo::RemoveItem(const char* c1) {
    //@@preconditions
    assert(c1 != NULL);
    assert(this->Array != NULL);
    //@@end preconditions

    int findId = -1;
    for (int i = 0; i <= this->MaxId; i++) {
        if (strcmp(this->Array[i].c1, c1) == 0) {
            findId = i;
            break;
        }
    }
    assert(findId != -1);

    //exchange position between lnId and MaxId.
    if (findId != this->MaxId) {
        this->Array[findId] = this->Array[this->MaxId];
        this->Array[this->MaxId].c1[0]  = '\0';
    }
    else {
        this->Array[findId].c1[0]  = '\0';
    }
    this->MaxId--;
    return this->MaxId;
}
    
//-----------------------------------------------------------------------------
int cpl_CommandInfo::RemoveAllItems(){
    for (int i = 0; i <= this->MaxId; i++) {
        this->Array[i].c1[0]  = '\0';
    }
    this->MaxId = -1;
    return 1;
}
      
//-----------------------------------------------------------------------------
cpl_CommandInfo::_fbItem_s* cpl_CommandInfo::Resize(int sz) {
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

    _fbItem_s * newArray = new _fbItem_s[newSize];
    assert(newArray != NULL);

    for (int j = 0; j < newSize; j++) {
        newArray[j].c1[0]  = '\0';
    }
    for (int i = 0; i < sz && i < this->Size; i++) {
        sprintf(newArray[i].c1, this->Array[i].c1);
    }

    this->Size = newSize;
    delete[] this->Array;
    this->Array = newArray;
    return this->Array;
}

//-----------------------------------------------------------------------------
int cpl_CommandInfo::GetNumber() {
    return this->MaxId+1;
}

//-----------------------------------------------------------------------------
int cpl_CommandInfo::GetItem(int index, const char*& c1) {
    //@@preconditions
    assert(index >= 0 && index <= this->MaxId);
    //@@end preconditions

    c1 = this->Array[index].c1;
    return index;
}

//-----------------------------------------------------------------------------
cpl_CommandInfo::cpl_CommandInfo(){
    this->Array  =  NULL;
    this->MaxId  = -1;
    this->Size   =  0;
    this->Extend = 10;
}

//-----------------------------------------------------------------------------
cpl_CommandInfo::~cpl_CommandInfo() {
    if (this->Array != NULL) {
        delete[] this->Array;
        this->Array = NULL;
    }
}
