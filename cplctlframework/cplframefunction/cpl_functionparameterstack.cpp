#include "cpl_functionframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_FunctionParameterStack
//------------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
cpl_FunctionParameterStack* cpl_FunctionParameterStack::New() {
    return new cpl_FunctionParameterStack;
}

//-----------------------------------------------------------------------------
void cpl_FunctionParameterStack::PushOpenElement(cpl_FunctionParameter* param) {
    //@@preconditions
    assert(param != NULL);
    //@@end preconditions
    
    if (this->m_objNumberOfOpenElements == this->m_objOpenElementsSize) {
        unsigned int newSize = this->m_objOpenElementsSize*2;
        _fbFuncStack_Item* newOpenElements = new _fbFuncStack_Item[newSize];
        for (unsigned int i = 0; i < this->m_objNumberOfOpenElements; ++i) {
            newOpenElements[i].parameter = this->m_objOpenElements[i].parameter;
        }
        for (unsigned int j = this->m_objNumberOfOpenElements; this->m_objNumberOfOpenElements < newSize; ++j) {
            newOpenElements[j].parameter = NULL;
        }
        delete [] this->m_objOpenElements;
        this->m_objOpenElements = newOpenElements;
        this->m_objOpenElementsSize = newSize;
    }  
    this->m_objOpenElements[this->m_objNumberOfOpenElements].parameter = param;
    this->m_objNumberOfOpenElements++;
}

//-----------------------------------------------------------------------------
cpl_FunctionParameter* cpl_FunctionParameterStack::PopOpenElement() {
    cpl_FunctionParameter* param = NULL;
    if (this->m_objNumberOfOpenElements > 0) {
        --this->m_objNumberOfOpenElements;
        param = this->m_objOpenElements[this->m_objNumberOfOpenElements].parameter;
        this->m_objOpenElements[this->m_objNumberOfOpenElements].parameter = NULL;
    }
    return param;
}

//-----------------------------------------------------------------------------
cpl_FunctionParameter* cpl_FunctionParameterStack::GetCurrentOpenElement() {
    if (this->m_objNumberOfOpenElements > 0) {
        return this->m_objOpenElements[this->m_objNumberOfOpenElements-1].parameter;
    }
    else {
        return NULL;
    }
}

//-----------------------------------------------------------------------------
cpl_FunctionParameterStack::cpl_FunctionParameterStack() {
    this->m_objNumberOfOpenElements = 0;
    this->m_objOpenElementsSize = 10;        
    this->m_objOpenElements = new _fbFuncStack_Item[this->m_objOpenElementsSize];
    for (unsigned int i = 0; i < this->m_objOpenElementsSize; i++) {
        this->m_objOpenElements[i].parameter = NULL;
    }    
}

//-----------------------------------------------------------------------------
cpl_FunctionParameterStack::~cpl_FunctionParameterStack() {
    for (unsigned int i = 0;i < this->m_objNumberOfOpenElements; ++i) {
        if (this->m_objOpenElements[i].parameter != NULL) {
            this->m_objOpenElements[i].parameter = NULL;
        }
    }    
    delete [] this->m_objOpenElements;
}
