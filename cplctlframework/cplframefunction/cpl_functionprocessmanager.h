#ifndef CPL_FUNCTIONPROCESSMANAGER_H
#define CPL_FUNCTIONPROCESSMANAGER_H

class cpl_FunctionProcessManager {    
public:
    /** delete instance */
    void Delete() { delete this; }

public:
    /** create function process */
    virtual int CreateFunctionProcess(FUNCPROCESS_CONTEXT* processContext) { return 0; }

    /** execute command callback*/
    virtual int ExecuteFunctionCallback(cpl_FunctionProcess* process, cpl_Function* func, int mode) { return 0; }

public:
    /** get function process number */
    int GetFunctionProcessNumber();

    /** delete function process */
    int DeleteFunctionProcess(int processId);

    /** set function manager */
    int SetFunctionManager(cpl_FunctionsManager* functionManager);

    /** get function manager */
    cpl_FunctionsManager* GetFunctionManager();

public:    
    /** get function process by Id. */
    cpl_FunctionProcess* GetFunctionProcess(int processId);

    /** get function process by name */
    cpl_FunctionProcess* GetFunctionProcess(char* processName);

    /** get function process directly */
    cpl_FunctionProcess* GetFunctionProcessByIndex(int idx);

    /** get active function process */
    cpl_FunctionProcess* GetActiveWinFunctionProcess(int& processId);

protected:
    /** find function process by Id */
    int FindFunctionProcess(int processId);
    
    /** find function process by name */
    int FindFunctionProcess(char* processName);
    
protected:
    /**constructor. */
    cpl_FunctionProcessManager();

    /**destructor. */
    virtual ~cpl_FunctionProcessManager();

    //protected variables
    cpl_FunctionsManager* uFuncManager;
    cpl_FunctionProcessArray* uFuncProcessSet;
};

#endif //CPL_FUNCTIONPROCESSMANAGER_H
