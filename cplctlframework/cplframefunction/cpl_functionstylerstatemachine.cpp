#include "cpl_functionframeincludes.h"

//-----------------------------------------------------------------------------
void cpl_StylerFunctionStateMachine::SetFunctionProxy(cpl_StylerFunctionProxy* proxy) {
    //@@preconditions
    assert(proxy != NULL);
    //@@end preconditions

    this->functionProxy = proxy;
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionStateMachine::ExecuteFunction(cpl_StylerFunction* wFunction, int mode) {
    //@@preconditions
    assert(wFunction != NULL);
    assert(this->functionProxy != NULL);
    //@@end preconditions
    
    //exit function
    if (mode == 0) { 
        *this->functionProxy /= wFunction;
        return;
    }
    this->Execute(wFunction);
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionStateMachine::Execute(cpl_StylerFunction* wFunction) {
    //@@preconditions
    assert(wFunction != NULL);
    assert(this->functionProxy != NULL);
    //@@end preconditions
    
    cpl_StylerFunction* currentFunc = this->functionProxy->GetStylerFunction();
    if (currentFunc != NULL && currentFunc->CanSuspend() == 0) {
        return;
    }

    if (wFunction == this->functionProxy->GetStylerFunction()) {
        return;
    }

    int opr = this->GetOperatorType(wFunction, this->functionProxy->GetStylerFunction());
    assert (opr >= 0);
    
    switch(opr) {
        case OP_INSERT:
            *this->functionProxy += wFunction;
            break;
        case OP_REPLACE:
            *this->functionProxy |= wFunction;
            break;
        case OP_REPLACEANY:                    
            *this->functionProxy -= wFunction;
            this->Execute(wFunction);
            break;            
        case OP_UNKNOWN:
            break;
        default:
            assert(0);
            break;
    }    
    return;
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionStateMachine::GetOperatorType(cpl_StylerFunction* sFunction, cpl_StylerFunction* tFunction) {
    if (tFunction == NULL) {
        return OP_INSERT;
    }    
    return OP_REPLACE;
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionStateMachine::GetFunctionGroupCode(cpl_StylerFunction* func) {
    //@@preconditions
    assert(0);
    //@@end preconditions
    
    return 0;
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionStateMachine::cpl_StylerFunctionStateMachine() {
    this->functionProxy = NULL;
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionStateMachine::~cpl_StylerFunctionStateMachine() {
}
