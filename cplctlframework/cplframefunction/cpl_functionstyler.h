#ifndef CPL_STYLERFUNCTION_H
#define CPL_STYLERFUNCTION_H

#define FUNC_STATUS_UNKNOWN  0
#define FUNC_STATUS_RUNNING  1
#define FUNC_STATUS_SUSPEND  2

#define FUNC_WINNAME(name) #name

#define UPDATE_ALL_CTLS  -99

class cpl_StylerFunction : public cpl_Function {
public:    
    cpl_CtlTypeRevisionMacro(cpl_StylerFunction, cpl_Function);

public:
    FUNC_COMMAND_MAP_DEL(cpl_StylerFunction,cpl_Function);

    /**Do initialization. */
    virtual void DoInitialization();

    /**Do cleanup */
    virtual void DoCleanup();
    
    /** do command */
    virtual void Suspend() ;

    /** do command */
    virtual void Resume() ;

    /** can suspend */
    virtual int  CanSuspend();

    /** do command */
    virtual void Interrupt();
    
    /** do command */
    virtual void Exit() {}

    /** block */
    virtual void Sleep() {}

    /** get attach window type */
    virtual const char* GetAttachWindowType() = 0;

    /** do command */
    virtual int  DoCommandId(int cmdId);

public:
    /** is synchronized function */
    virtual const int IsSynchorizedFunction() { return 0; }

public:
    /** is inline function */
    virtual const int IsInlineFunction() { return 0; }

    /** set inline function code*/
    virtual const int GetInlineFunctionCode();

    /** set inline function code*/
    virtual void SetInlineFunctionCode(int code);
    	
public:
	/** set supsend function */
	virtual void SetSuspendFunction(cpl_Function* contextFunction);

public:
    /** set window function proxy */
    virtual void SetWindowFunctionProxy(cpl_StylerFunctionProxy* proxy);
    
    /** get window function proxy. */
    virtual cpl_StylerFunctionProxy* GetWindowFunctionProxy();
    
    /** set window styler attached*/
    virtual void SetWindowStyler(IWindowStyler* styler);
    
    /** get window styler attached*/
    virtual IWindowStyler* GetWindowStyler();

    /** set window styler collection*/
    virtual void SetWindowStylerCollection(IWindowStylerCollection* stylerCollection);

    /** set session proxy */
    virtual void SetSessionProxy(cpl_SessionProxy* proxy);

public:
    /** get window imp */
    virtual IWindow* GetAttachWindow();

    /** get function execute */
    virtual cpl_FunctionExecuteInvokerImp* GetFunctionExecuteImp();

    /** get function data exchange */
    virtual cpl_StylerFunctionDataExchange* GetFunctionDataExchange();

    /** deep copy */
    virtual cpl_StylerFunction* DeepCopy() = 0;

public:
    /** update shortcut menu */
    virtual void UpdateShortCutMenu();

protected:
    //lower level execute.
    virtual void ExecuteDirect();

    //lower command execute.
    virtual void DoGlobalCommand(int cmdId);

    //do update action.
    virtual void DoUpdateAction() {}

    //do active action.
    virtual void DoActiveAction() {}

    //do synchronization.
    virtual void DoSynchronizationAction() {}

    //do end restore action.
    virtual void DoEndRestoreAction() {}

    //add short cut menu
    virtual void AttachShortCutMenu();

    //remove short cut menu
    virtual void DettachShortCutMenu();

    //update short cut direct
    virtual void UpdateShortCutMenuDirect();

protected:
    //record session function directly.
    int RecordSessionFuncCommand(int cmdId);

public:    
    //inner structure.
    struct _fbStylerFunctionData_s {
        cpl_Function* suspendFunction;
    };

    /** constructor. */
    cpl_StylerFunction();

    /** destructor. */
    virtual ~cpl_StylerFunction();

    _fbStylerFunctionData_s StylerFuncData; 

    //variables.
    IWindowStyler* windowStyler;    
    IWindowStylerCollection* windowStylerCollection;
    cpl_SessionProxy* pSessionProxy;
    int funcStatus;
    int InlineCode;
    int exeFuncStatus;
    int exeCmdStatus;
    int exeCmdRet;
protected:	
    cpl_StylerFunctionProxy* winProxy;
    cpl_StylerFunctionDataExchange* pDataExchange; 
    cpl_FunctionExecuteInvokerImp* ExecuteImpInvoker;
    cpl_FunctionSessionDataProxy* funcSessionData;
private:
    cpl_FunctionExecuteImp* ExecuteImp;
};

#endif //CPL_STYLERFUNCTION_H
