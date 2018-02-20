#include "cpl_functionframeincludes.h"
#include "cpl_functionstylerwindow.h"

//-----------------------------------------------------------------------------
void cpl_StylerFunctionProxy::UpdateDisplay() {
    //@@preconditions
    assert(this->proxyWin != NULL);
    assert(this->stateMachine != NULL);
    //@@end preconditions

    if (this->currentFunction == NULL) {
        return;
    }
    if (this->currentFunction->GetWindowStyler() == NULL) {
        return;
    }

    IWindow* pWindow = this->currentFunction->GetAttachWindow();
    assert(pWindow != NULL);

    if (pWindow->IsWindowInitialized() == 0) {
        pWindow->WindowInitialization(this->proxyWin->GetFuncWindowHandler(), this->proxyWin->GetToolWindowHandler(), NULL);
        pWindow->UpdateDisplay();            
    }
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionProxy::SetFuncWindowProxyWinHandler(void* pWinHandler) {
    //@@preconditions
    assert(pWinHandler != NULL);
    assert(this->proxyWin != NULL);
    //@@end preconditions

    this->proxyWin->SetFuncWindowHandler(pWinHandler);
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionProxy::SetToolWindowProxyWinHandler(void* pWinHandler) {
    //@@preconditions
    assert(pWinHandler != NULL);
    assert(this->proxyWin != NULL);
    //@@end preconditions

    this->proxyWin->SetToolWindowHandler(pWinHandler);
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionProxy::EnterWindowFunction(cpl_StylerFunction* winFunction) {
    //@@preconditions
    assert(winFunction != NULL);
    assert(this->winFunctionStack != NULL);
    assert(this->stateMachine != NULL);
    //@@end preconditions
    
    //check inline function.
    if (winFunction->IsInlineFunction() == 1) {
        assert(winFunction->GetInlineFunctionCode() == 0);
        int scode = this->stateMachine->GetFunctionGroupCode(this->GetStylerFunction());
        winFunction->SetInlineFunctionCode(++scode);
    }

    this->stateMachine->ExecuteFunction(winFunction, 1);
    this->UpdateDisplay();
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionProxy::LeaveWindowFunction(cpl_StylerFunction* winFunction) {
    //@@preconditions
    assert(winFunction != NULL);
    assert(this->winFunctionStack != NULL);
    assert(this->stateMachine != NULL);
    //@@end preconditions
    
    //check inline function.
    if (winFunction->IsInlineFunction() == 1) {
        assert(winFunction->GetInlineFunctionCode() != 0);
        winFunction->SetInlineFunctionCode(0);
    }
    
    this->stateMachine->ExecuteFunction(winFunction, 0);
    this->UpdateDisplay();
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionProxy::StopFunctionOnStackTop() {
    //@@preconditions
    assert(this->currentFunction != NULL);
    assert(this->winFunctionStack != NULL);
    assert(this->stateMachine != NULL);
    //@@end preconditions
    
    *this /= this->currentFunction;
    this->UpdateDisplay();
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionProxy& cpl_StylerFunctionProxy::operator+=(cpl_StylerFunction* winFunction) {
    //@@preconditions
    assert(winFunction != NULL);
    //@@end preconditions

    if (this->currentFunction != NULL) {
		this->currentFunction->SetSuspendFunction(winFunction);
        this->currentFunction->Suspend();
		this->currentFunction->SetSuspendFunction(NULL);
    }
    
    //push the win function onto stack and call initialization.
    this->winFunctionStack->PushOpenElement(winFunction);
    this->currentFunction = winFunction;
    this->currentFunction->DoInitialization(); 
    return *this;
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionProxy& cpl_StylerFunctionProxy::operator/=(cpl_StylerFunction* wFunction) {
    //@@preconditions
    assert(this->winFunctionStack != NULL);
    assert(this->currentFunction != NULL);
    //@@end preconditions
    
    //do the current function .cleanup 
    this->currentFunction->DoCleanup();
        
    //popup the new function.
    this->winFunctionStack->PopOpenElement();   
    this->currentFunction = this->winFunctionStack->GetCurrentOpenElement();
    if (this->currentFunction != NULL) {
        this->currentFunction->Resume(); 
    } 
    return *this;
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionProxy& cpl_StylerFunctionProxy::operator-=(cpl_StylerFunction* wFunction) {
    //@@preconditions
    assert(this->winFunctionStack != NULL);
    assert(this->currentFunction != NULL);
    //@@end preconditions
    
    //do the current function .cleanup 
    this->currentFunction->DoCleanup();
        
    //popup the new function.
    cpl_StylerFunction* func = this->winFunctionStack->PopOpenElement();  
    if (func != NULL && func->IsInlineFunction() == 1) {
        func->UnRegister(NULL);        
    }

    this->currentFunction = this->winFunctionStack->GetCurrentOpenElement();
    if (this->currentFunction != NULL) {
        this->currentFunction->Resume(); 
    } 
    return *this;
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionProxy& cpl_StylerFunctionProxy::operator|=(cpl_StylerFunction* wFunction) {
    //@@preconditions
    assert(this->winFunctionStack != NULL);
    assert(this->currentFunction != NULL);
    //@@end preconditions
    
    //do the current function .cleanup 
    this->currentFunction->DoCleanup();
    
    //popup the new function.
    cpl_StylerFunction* func = this->winFunctionStack->PopOpenElement();  
    if (func != NULL && func->IsInlineFunction() == 1) {
        func->UnRegister(NULL);        
    }

    //push the win function onto stack and call initialization.
    this->winFunctionStack->PushOpenElement(wFunction);
    this->currentFunction = wFunction;
    this->currentFunction->DoInitialization(); 
    return *this;
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionProxy::SetStateMachine(cpl_StylerFunctionStateMachine* stateMachine) {
    //@@preconditions
    assert(stateMachine != NULL);
    //@@end preconditions

    if (this->stateMachine != NULL) {
        delete this->stateMachine;
        this->stateMachine = NULL;            
    }

    this->stateMachine = stateMachine;     
    this->stateMachine->SetFunctionProxy(this);
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionProxy::HaltWindowFunction() {
    //@@preconditions
    assert(this->winFunctionStack != NULL);
    assert(this->currentFunction != NULL);
    //@@end preconditions
    
    //pop up all functions
    for (; this->currentFunction != NULL; ) {
        this->currentFunction->Interrupt();
        this->currentFunction = this->winFunctionStack->PopOpenElement();   
    }
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionProxy::StopFunction() {
    //@@preconditions
    assert(this->winFunctionStack != NULL);
    //@@end preconditions
    
    //pop up all functions
    for (; this->winFunctionStack->GetCurrentOpenElement() != NULL; ) {
        cpl_StylerFunction* func = this->winFunctionStack->PopOpenElement(); 
        if (func->funcStatus == FUNC_STATUS_SUSPEND) { //suspend.
            func->Resume();
        }
        if (func->funcStatus == FUNC_STATUS_RUNNING) {
            func->DoCleanup();                         
        }
        if (func->IsInlineFunction() == 1) {
            func->UnRegister(0);
        }
    }    
    this->currentFunction = NULL;
}

//-----------------------------------------------------------------------------
int cpl_StylerFunctionProxy::IsFunctionOnStack(cpl_StylerFunction* func) {
    //@@preconditions
    assert(func != NULL);
    assert(this->winFunctionStack != NULL);
    //@@end preconditions

    return this->winFunctionStack->IsFunctionOnStack(func);
}

//-----------------------------------------------------------------------------
void cpl_StylerFunctionProxy::SynchronizeFunctionOnStack() {
    //@@preconditions
    assert(this->winFunctionStack != NULL);
    //@@end preconditions

    int num = this->winFunctionStack->GetNumberOfElements();
    assert(num >= 0);

    for (int i = 0; i < num; i++) {
        cpl_StylerFunction* pFunc = this->winFunctionStack->GetElement(i);
        if (pFunc != NULL) {
            pFunc->DoCommandId(FUNC_CMD_SYNC);
        }
    }
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionProxy::cpl_StylerFunctionProxy() {
    this->winFunctionStack = new cpl_StylerFunctionStack;
    this->proxyWin         = new cpl_StylerFunctionWindow;
    this->currentFunction  = NULL;
    this->stateMachine     = NULL;
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionProxy::~cpl_StylerFunctionProxy() {
    if (this->stateMachine != NULL) {
        delete this->stateMachine;
        this->stateMachine = NULL;            
    }
    if (this->winFunctionStack != NULL) {
        delete this->winFunctionStack;
        this->winFunctionStack = NULL;
    }
    if (this->proxyWin != NULL) {
        delete this->proxyWin;
        this->proxyWin = NULL;
    }
    this->currentFunction  = NULL;
}
