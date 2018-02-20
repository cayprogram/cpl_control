#ifndef CPL_FUNCTION_H
#define CPL_FUNCTION_H

#define FUNC_CONTEXT_NODATABASE          0
#define FUNC_CONTEXT_DATABASEEXIST       1
#define FUNC_CONTEXT_INATOM_ACTION       2
#define FUNC_CONTEXT_STYLER_STATIC       3
#define FUNC_CONTEXT_STYLER_DYNAMICRUN   4
#define FUNC_CONTEXT_STYLER_DYNAMICPREP  5
#define FUNC_CONTEXT_STYLER_DYNAMICPAUSE 6
#define FUNC_CONTEXT_MAX                 7

class cpl_Function : public cpl_CtlObject {     

public:
	/** check parameter */
    virtual int  CheckInputParameter()  = 0;
    virtual int  ReadInputParameter()   = 0;
    virtual int  WriteOutputParameter() = 0;
    virtual int  CheckOutputParameter() = 0;

    /** is valid context */
    virtual int  IsValidContext() {return 0;}

    /** deep copy */
    virtual cpl_Function* DeepCopy() = 0;

    /** do command */
    virtual int  DoCommandId(int cmdId);

    /** execute .. */
    virtual void Execute();

    /** get string id */
    virtual const char* GetStringId() = 0;

    /** is synchronized function */
    virtual const int IsSynchorizedFunction() = 0;

    /** is inline function */
    virtual const int IsInlineFunction() { return 0; }

    /** is valid record session */
    virtual int  IsValidRecordSession() { return 1; }

public:
    /** set local status */
    virtual void SetLocalStatus(int status);

    /** get local status */
    virtual int  GetLocalStatus();
    
    /** set process status */
    virtual void SetProcessFunctionLockStatus(int status);
    
    /** get process status */
    virtual int  GetProcessFunctionLockStatus();

    //set parameter proxy.
    virtual void SetParameterProxy(cpl_FunctionParameterProxy* proxy);

    //get parameter proxy.
    virtual cpl_FunctionParameterProxy* GetParamterProxy();    

    //set function process.
    virtual void SetFunctionProcess(cpl_FunctionProcess* process);

    //get function process.
    virtual cpl_FunctionProcess* GetFunctionProcess();    

    //set command proxy
    virtual void SetCommandProxy(cpl_FunctionCommandProxy* proxy);

    //get command proxy
    virtual cpl_FunctionCommandProxy* GetCommandProxy();

    //set context proxy
    virtual void SetContextProxy(cpl_FunctionContextProxy* proxy);

    //get context proxy
    virtual cpl_FunctionContextProxy* GetContextProxy();

public:
    /** get function serial data */
    virtual cpl_FunctionSerialDataProxy* GetFuncSerialDataProxy();

public:
    /** update function data into serial data */
    virtual int  UpdateFunctionDataIntoSerialData(int mode) {return 0;}

    /** update function data from serial data */
    virtual int  UpdateFunctionDataFromSerialData(int mode) {return 0;}

    /** do function serial action */
    virtual int  ExecuteWithSerialData(int mode) {return 0;}

    /** get function serial data description */
    virtual char* GetSerialDataTitle() {return "NOTITLE";}

public:
    /** is command async */
    virtual int IsAsyncCommand(int id);

    /** get command name from id */
    virtual int GetCommandNameFromID(int id, const char*& name);

    /** get command id from name */
    virtual int GetCommandIDFromName(const char* name, int& id); 

    /** is command need to be recorded */
    virtual int GetCommandNeedRecord(int id); 

    /** is command need to refresh gui. */
    virtual int GetCommandNeedRefreshGUI(int id);

protected:
    /** do command */
    virtual void DoCommandDirect(int cmdId) {}

    /** execute .. */
    virtual void ExecuteDirect() = 0;

    /** enter execute .. */
    virtual void EnterExecuteDirect() {}

    /** leave execute .. */
    virtual void LeaveExecuteDirect() {}

    /** update function on stack */
    virtual void SynchronizeFunctionOnStack();

protected:
    /** get graphic window id */
    int GetWindowId(); 

protected:
    //inner structure.
    struct _fbFunction_s {
        char text[64];
        int  type;
        int  funcid;
        int  lockStatus;
        int  lockfuncdata;
        cpl_FunctionProcess* process;
        cpl_FunctionCommandProxy* cmdProxy;
        cpl_FunctionContextProxy* ctxProxy;
        cpl_FunctionParameterProxy* paramPoxy;
    };

    /** constructor. */
    cpl_Function();

    /** destructor. */
    virtual ~cpl_Function();

    //protected variables
    _fbFunction_s functionData;
    cpl_FunctionSerialDataProxy* serialDatProxy;
};

#endif //CPL_FUNCTION_H
