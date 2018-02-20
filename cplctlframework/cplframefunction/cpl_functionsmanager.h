#ifndef CPL_FUNCTIONSMANAGER_H
#define CPL_FUNCTIONSMANAGER_H

class cpl_FunctionsManager : public cpl_CtlObject {
public:
    /** create instance */
    static cpl_FunctionsManager* Instance();
    
    /** set instance. */
    static void SetFactory(cpl_FunctionsManager* uInstance);

public:
    /** do initialization */
    virtual void DoInitialization() {}

    /** do cleanup */
    virtual void DoCleanup() {}

public:
    /** is function context valid */
    virtual int IsContextValid(char* funcString);
    
    /** execute */
    virtual int ExecuteFunction(char* funcString);
    virtual int ExecuteFunction(char* funcName, cpl_FunctionProcess* funcProcess);
    virtual int ExecuteFunctionCallback(cpl_FunctionProcess* process, cpl_Function* func, int mode) { return 0; }

    /** find function */
    virtual int FindFunction(char* funcName, cpl_Function*& funcObj);

public:    
    /** init function process info */
    virtual void InitFunctionProcessInfo() {}

    /** start default function process */
    virtual void StartDefaultFunctionProcess() {}

public:
    /** get active function process */
    virtual cpl_FunctionProcess* GetActiveWinFunctionProcess(int& processId);

public:
    /** get function process proxy */
    cpl_FunctionProcessManager* GetFunctionProcessManager();

    /** get parameter buffer */
    cpl_FunctionProcessParameter* GetParamBufferIO();

protected:
    /**constructor. */
    cpl_FunctionsManager();

    /**destructor. */
    virtual ~cpl_FunctionsManager();

    //protected variables.
    cpl_FunctionProcessParameter* paramHandler;
    cpl_FunctionProcessManager*   funcProcessMan;    

    /** get current active function process */
    virtual void GetActiveFunctionProcesses(char* funcName, int& numProcess, cpl_FunctionProcess**& processes) {}

private:
    // private instance
    static cpl_FunctionsManager * instance;
};

#endif //CPL_FUNCTIONSMANAGER_H
