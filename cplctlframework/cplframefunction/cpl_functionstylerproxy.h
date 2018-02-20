#ifndef CPL_STYLERFUNCTIONPROXY_H
#define CPL_STYLERFUNCTIONPROXY_H

class cpl_StylerFunctionProxy {       

public:
    /** set state machine*/
    virtual void SetStateMachine(cpl_StylerFunctionStateMachine* stateMachine);

public:
    /** get window function */
    virtual cpl_StylerFunction* GetStylerFunction();
           
    /** set window function */
    virtual void EnterWindowFunction(cpl_StylerFunction* wFunction);
    
    /** interrupt function. */
    virtual void LeaveWindowFunction(cpl_StylerFunction* wFunction);
    
    /** interrupt function. */
    virtual void HaltWindowFunction();
    
    /** set window styler */
    virtual void UpdateDisplay();
    
    /** stop function */
    virtual void StopFunction();

    /** stop function */
    virtual void StopFunctionOnStackTop();
    
    /** set window handler */
    virtual void SetFuncWindowProxyWinHandler(void* pWinHandler);
    
    /** set window handler */
    virtual void SetToolWindowProxyWinHandler(void* pWinHandler);

    /** update function on stack */
    virtual void SynchronizeFunctionOnStack();

    /** is function on stack */
    virtual int  IsFunctionOnStack(cpl_StylerFunction* func);
    
public:
    /** constructor. */
    cpl_StylerFunctionProxy();
    
    /** destructor. */
    virtual ~cpl_StylerFunctionProxy();
    
protected:
    friend class cpl_StylerFunctionStateMachine;

    /** operator: -= */
    cpl_StylerFunctionProxy& operator/=(cpl_StylerFunction* wFunction);

    /** operator: += */
    cpl_StylerFunctionProxy& operator+=(cpl_StylerFunction* wFunction);
    
    /** operator: -= */
    cpl_StylerFunctionProxy& operator-=(cpl_StylerFunction* wFunction);
    
    /** operator: -= */
    cpl_StylerFunctionProxy& operator|=(cpl_StylerFunction* wFunction);

protected:        
    //protected variables
    cpl_StylerFunction* currentFunction;
    cpl_StylerFunctionStack* winFunctionStack;
    cpl_StylerFunctionStateMachine* stateMachine;

    //function window proxy.
    cpl_StylerFunctionWindow* proxyWin;
};

//-----------------------------------------------------------------------------
inline cpl_StylerFunction* cpl_StylerFunctionProxy::GetStylerFunction() {
    //@@preconditions
    assert(this->winFunctionStack != NULL);
    //@@end preconditions
    
    return this->currentFunction;
}

#endif //CPL_STYLERFUNCTIONPROXY_H
