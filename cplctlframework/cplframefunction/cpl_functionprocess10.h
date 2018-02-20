#ifndef CPL_FUNCTIONPROCESS10_H
#define CPL_FUNCTIONPROCESS10_H

class cpl_FunctionProcess10 : public cpl_IFunctionProcess, public cpl_CtlObject {
public:
    /** enter new scope */
    virtual int EnterFunctionScope();

    /** enter new scope */
    virtual int LeaveFunctionScope();
    
    /** execute command */
    virtual int ExecuteFunctionDirect(cpl_Function* func);
    
    /**execute */
    virtual int ExecuteFunction(char* string) = 0;

public:   
    /**get command output parameter reader. */
    virtual IParameterEngineReadRight * GetOutputParamReader();    

    /**get command input parameter writer. */
    virtual IParameterEngineWriteRight* GetInputParamWriter();    

    /**get command output parameter checker. */
    virtual IParameterEngineCheckRight* GetOutputParamChecker();    

    /**get command output parameter reader. */
    virtual IParameterEngineCheckRight* GetInputParamChecker();
        
protected:
    /**constructor. */
    cpl_FunctionProcess10();

    /**destructor. */
    virtual ~cpl_FunctionProcess10();

    /** execute command */
    virtual int ExecuteFunctionOnStack(cpl_Function* func);

    //protected variables.
    cpl_Function               * functionCurrent;
    cpl_FunctionStack          * functionStack;
    cpl_FunctionParameter      * functionParameter;  
    cpl_FunctionParameterStack * functionParameterStack;
    
private:
    cpl_FunctionProcess10(const cpl_FunctionProcess10 &); // Not implemented.
    void operator = (const cpl_FunctionProcess10 &); // Not implemented. 
};

#endif //CPL_FUNCTIONPROCESS10_H
