#include "cpl_functionframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_FunctionStack
//------------------------------------------------------------------------------
//

//------------------------------------------------------------------------------
cpl_FunctionStack* cpl_FunctionStack::New() {
    return new cpl_FunctionStack;
}

//------------------------------------------------------------------------------
void cpl_FunctionStack::PushOpenElement(cpl_Function* func) {
    //@@preconditions
    assert(func != NULL);
    //@@end preconditions
    
    if (this->m_objNumberOfOpenElements == this->m_objOpenElementsSize) {
        unsigned int newSize = this->m_objOpenElementsSize*2;
        _fbFuncStack_Item* newOpenElements = new _fbFuncStack_Item[newSize];
        for (unsigned int i = 0; i < this->m_objNumberOfOpenElements; ++i) {
            newOpenElements[i].func      = this->m_objOpenElements[i].func;
        }
        for (unsigned int j = this->m_objNumberOfOpenElements; this->m_objNumberOfOpenElements < newSize; ++j) {
            newOpenElements[j].func = NULL;
        }
        delete [] this->m_objOpenElements;
        this->m_objOpenElements = newOpenElements;
        this->m_objOpenElementsSize = newSize;
    }  
    this->m_objOpenElements[this->m_objNumberOfOpenElements].func = func;
    this->m_objNumberOfOpenElements++;
}

//------------------------------------------------------------------------------
cpl_Function* cpl_FunctionStack::PopOpenElement() {
    cpl_Function* func = NULL;
    if (this->m_objNumberOfOpenElements > 0) {
        --this->m_objNumberOfOpenElements;
        func  = this->m_objOpenElements[this->m_objNumberOfOpenElements].func;
        this->m_objOpenElements[this->m_objNumberOfOpenElements].func = NULL;
    }
    return func;
}

//------------------------------------------------------------------------------
cpl_Function* cpl_FunctionStack::GetCurrentOpenElement() {
    if (this->m_objNumberOfOpenElements > 0) {
        return this->m_objOpenElements[this->m_objNumberOfOpenElements-1].func;
    }
    else {
        return NULL;
    }
}

//------------------------------------------------------------------------------
cpl_FunctionStack::cpl_FunctionStack() {
    this->m_objNumberOfOpenElements = 0;
    this->m_objOpenElementsSize = 10;        
    this->m_objOpenElements = new _fbFuncStack_Item[this->m_objOpenElementsSize];
    for (unsigned int i = 0; i < this->m_objOpenElementsSize; i++) {
        this->m_objOpenElements[i].func      = NULL;
    }    
}

//------------------------------------------------------------------------------
cpl_FunctionStack::~cpl_FunctionStack() {
    for (unsigned int i = 0;i < this->m_objNumberOfOpenElements; ++i) {
        if (this->m_objOpenElements[i].func != NULL) {
            this->m_objOpenElements[i].func = NULL;
        }
    }    
    delete [] this->m_objOpenElements;
}
