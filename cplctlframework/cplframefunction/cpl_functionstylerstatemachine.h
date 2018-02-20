#ifndef CPL_STYLERFUNCTIONSTATEMACHINE_H
#define CPL_STYLERFUNCTIONSTATEMACHINE_H

#define OP_UNKNOWN    0
#define OP_INSERT     1
#define OP_REPLACE    2
#define OP_REPLACEANY 3

class cpl_StylerFunctionStateMachine {   

public:    
    /** set state machine*/
    virtual void SetFunctionProxy(cpl_StylerFunctionProxy* proxy);

    /** execute window function */
    virtual void ExecuteFunction(cpl_StylerFunction* wFunction, int mode);

    /** get operator type */
    virtual int  GetOperatorType(cpl_StylerFunction* sFunction, cpl_StylerFunction* tFunction) = 0;

    /** get styler function group. */
    virtual int  GetFunctionGroupCode(cpl_StylerFunction* func);
    
    /** deep copy */
    virtual cpl_StylerFunctionStateMachine* DeepCopy() { return NULL; }

public:
    //init process config.
    virtual void InitProcessConfig() = 0;

    //clean process config.
    virtual void CleanupProcessConfig() = 0;

public:
    /** constructor. */
    cpl_StylerFunctionStateMachine();
    
    /** destructor. */
    virtual ~cpl_StylerFunctionStateMachine();

    //execute.
    void Execute(cpl_StylerFunction* wFunction);

    //protected variables
    cpl_StylerFunctionProxy* functionProxy;
};

#endif //CPL_STYLERFUNCTIONSTATEMACHINE_H
