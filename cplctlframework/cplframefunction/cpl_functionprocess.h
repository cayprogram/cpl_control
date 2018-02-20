#ifndef CPL_FUNCTIONPROCESS_H
#define CPL_FUNCTIONPROCESS_H

class cpl_FunctionSimple;
class cpl_StylerFunctionSimple;
class cpl_FunctionProcess : public cpl_FunctionProcess20 {
public:
    /** enter use function process */
    virtual void EnterProcess() {}
    
    /** leave use function process */
    virtual void LeaveProcess() {}

    /** start use function process */
    virtual void StartProcess(char* cmdType) {}
    
    /** stop use function process*/
    virtual void StopProcess();

    /** init function process */
    virtual void InitProcess() {}

    /** clean function process */
    virtual void CleanupProcess() {}

    /** active function process */
    virtual void ActiveProcess() {}

    /** suspend function process */
    virtual void SuspendProcess() {}

    /** resume function process */
    virtual void ResumeProcess() {}

    /** create process data */
    virtual void Create(FUNCPROCESS_CONTEXT* processContext) {}

    /** get process type */
    virtual int  GetProcessType() = 0;

public:
    /** set render site */
    void SetRenderSite(cpl_RenderSite* renderSite);

    /** get render site */
    cpl_RenderSite* GetRenderSite();
     
    /** set function process manager */
    void SetFunctionProcessManager(cpl_FunctionProcessManager* processManager);

    /** get function process manager */
    cpl_FunctionProcessManager* GetFunctionProcessManager();

public:
    /** set session proxy */
    void SetSessionProxy(cpl_SessionProxy* proxy);

    /** set window proxy */
    void SetWindowFunctionProxyWinHandler(void* winHandler);

    /** set window proxy */
    void SetToolFunctionProxyWinHandler(void* winHandler);

    /** set window proxy */
    void SetShortCutFunctionProxyWinHandler(void* winHandler);

    /** set window styler collection */
    void SetWindowStylerCollection(IWindowStylerCollection* pCollection);

    /** set state machine*/
    void SetStateMachine(cpl_StylerFunctionStateMachine* stateMachine);
    
public:
    /** get current function */
    cpl_Function* GetCurrentFunction();

    /** get current styler function */
    cpl_Function* GetStylerFunction();

    /** get current styler function */
    cpl_Function* GetStylerFunctionShortCut();

    /** get command proxy */
    cpl_FunctionCommandProxy* GetCommandProxy();

    /** set local status */
    void SetLocalStatus(int status);

    /** get local status */
    int  GetLocalStatus();
   
    /** set function window Id*/
    void SetFunctionWindow(int fid);

    /** get function window Id */
    int  GetFunctionWindow();

    /** set graphic window Id*/
    void SetGraphicWindow(int wid);

    /** get graphic window Id */
    int  GetGraphicWindow();

    /** set process Id */
    void SetProcessId(int pId);

    /** get process Id */
    int  GetProcessId();
    
    /** set process name */
    void SetProcessName(char* pname);
    
    /** get process name */
    char* GetProcessName();

    /** set process type name */
    void SetProcessTypeName(char* tname);
    
    /** get process type name */
    char* GetProcessTypeName();

    /** get domain id */
    char* GetDomainId();

public:
    /** update function on stack */
    virtual void SynchronizeFunctionOnStack();

public:
    /** insert command. */
    virtual int InsertFunction(cpl_Function * funcObject);
    
    /** execute command */
    virtual int ExecuteFunctionDirect(cpl_Function* func);
    
    /** execute command callback*/
    virtual int ExecuteFunctionCallback(cpl_Function* func, int mode);

    /** on command executed */
    virtual int OnCommandExecuted(int commandId, cpl_Function* func, cpl_StylerFunctionProxy* proxy);

protected:
    //inner structure.
    struct _fbProcess_s {
        char nameText[64];
        char typeText[64];
        int  lockStatus;
        int  processId;
        int  funWinid;
        int  graphicWid;
        cpl_FunctionProcessInfo* processInfo;
    };
    
    /**constructor. */
    cpl_FunctionProcess();

    /**destructor. */    
    virtual ~cpl_FunctionProcess();
    
    //clean execute result.
    void DoExecuteCleanup(cpl_Function* func);

    //protected variables.
    _fbProcess_s processData;
    cpl_RenderSite* uRenderSite;
    cpl_StylerFunctionStateMachine* stateMachine;
    cpl_StylerFunctionProxy* winFunctionProxy;   
    cpl_StylerFunctionProxy* winFunctionProxyShortCut; 
    cpl_FunctionCommandProxy* functionCommandProxy;
    cpl_FunctionContextProxy* functionContextProxy;
    cpl_FunctionProcessManager* functionProcessManager;
    IWindowStylerCollection* windowStylerCollection;   

private:
    cpl_FunctionProcess(const cpl_FunctionProcess &); // Not implemented.
    void operator = (const cpl_FunctionProcess &); // Not implemented.  
};

#endif //CPL_FUNCTIONPROCESS_H
