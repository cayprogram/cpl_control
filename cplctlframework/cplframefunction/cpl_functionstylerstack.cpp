#include "cpl_functionframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_StylerFunctionStack
//-----------------------------------------------------------------------------
//

void cpl_StylerFunctionStack::PushOpenElement(cpl_StylerFunction* element) {
    //@@preconditions
    assert(element != NULL);
    //@@end preconditions

    if (this->m_objNumberOfOpenElements == this->m_objOpenElementsSize) {
        unsigned int newSize = this->m_objOpenElementsSize*2;
        _fbWindowFunction_Item* newOpenElements = new _fbWindowFunction_Item[newSize];
        for (unsigned int i = 0; i < this->m_objNumberOfOpenElements; ++i) {
            newOpenElements[i].winfunc = this->m_objOpenElements[i].winfunc;
        }
        for (unsigned int j = this->m_objNumberOfOpenElements; this->m_objNumberOfOpenElements < newSize; ++j) {
            newOpenElements[j].winfunc = NULL;
        }
        delete [] this->m_objOpenElements;
        this->m_objOpenElements = newOpenElements;
        this->m_objOpenElementsSize = newSize;
    }  
    this->m_objOpenElements[this->m_objNumberOfOpenElements++].winfunc = element;
}

//-----------------------------------------------------------------------------
cpl_StylerFunction* cpl_StylerFunctionStack::PopOpenElement() {
    if (this->m_objNumberOfOpenElements > 0) {
        --this->m_objNumberOfOpenElements;
        cpl_StylerFunction* elem = this->m_objOpenElements[this->m_objNumberOfOpenElements].winfunc;
        this->m_objOpenElements[this->m_objNumberOfOpenElements].winfunc = NULL;
        return elem;
    }
    return NULL;
}

//-----------------------------------------------------------------------------
cpl_StylerFunction* cpl_StylerFunctionStack::GetCurrentOpenElement() {
    //@@postconditions
    //@@end postconditions

    if (this->m_objNumberOfOpenElements > 0) {
        return this->m_objOpenElements[this->m_objNumberOfOpenElements-1].winfunc;
    }
    else {
        return NULL;
    }
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionStack::IsFunctionOnStack(cpl_StylerFunction* func) {
    //@@preconditions
    assert(func != NULL);
    //@@end preconditions

    for (unsigned i = 0; i < this->m_objNumberOfOpenElements; i++) {
        if (this->m_objOpenElements[i].winfunc == func) {
            return 1;
        }
    }
    return 0;
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionStack::GetNumberOfElements() {
    return this->m_objNumberOfOpenElements;
}

//-----------------------------------------------------------------------------
cpl_StylerFunction* cpl_StylerFunctionStack::GetElement(int ith) {
    //@@preconditons
    assert(ith >= 0 && ith < this->m_objNumberOfOpenElements);
    //@@end preconditions

    return this->m_objOpenElements[ith].winfunc;
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionStack::cpl_StylerFunctionStack() {
    this->m_objNumberOfOpenElements = 0;
    this->m_objOpenElementsSize = 10;        
    this->m_objOpenElements = new _fbWindowFunction_Item[this->m_objOpenElementsSize];
    for (unsigned int i = 0; i < this->m_objOpenElementsSize; i++) {
        this->m_objOpenElements[i].winfunc = NULL;
    }    
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionStack::~cpl_StylerFunctionStack() {
    for (unsigned int i = 0;i < this->m_objNumberOfOpenElements; ++i) {
        if (this->m_objOpenElements[i].winfunc != NULL) {
            this->m_objOpenElements[i].winfunc = NULL;
        }
    }    
    delete [] this->m_objOpenElements;
}
