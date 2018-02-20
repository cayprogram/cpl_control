#ifndef CPL_FUNCTIONPROCESSINTERFACE_H
#define CPL_FUNCTIONPROCESSINTERFACE_H

class cpl_IFunctionProcess { 
public:   
    /**get command output parameter reader. */
    virtual IParameterEngineReadRight * GetOutputParamReader() = 0;    

    /**get command input parameter writer. */
    virtual IParameterEngineWriteRight* GetInputParamWriter() = 0;    

    /**get command output parameter checker. */
    virtual IParameterEngineCheckRight* GetOutputParamChecker() = 0;    

    /**get command output parameter reader. */
    virtual IParameterEngineCheckRight* GetInputParamChecker() = 0;     

public:
    /** execute function */
    virtual int ExecuteFunction(char* string) = 0;
};

#endif //CPL_FUNCTIONPROCESSINTERFACE_H
