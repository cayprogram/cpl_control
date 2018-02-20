#ifndef CPL_COMMANDSMANAGER10_H
#define CPL_COMMANDSMANAGER10_H

class cpl_CommandsManager10 : public cpl_CtlObject {
public:
    /**get command output parameter reader. */
    IParameterEngineReadRight* GetOutputParamReader();    

    /**get command output parameter reader. */
    IParameterEngineWriteRight* GetInputParamWriter();    
    
    /**get command output parameter checker. */
    IParameterEngineCheckRight* GetOutputParamChecker();    
    
    /**get command output parameter reader. */
    IParameterEngineCheckRight* GetInputParamChecker();
    
    /** get input parameter buffer */
    cpl_ParameterBuffer* GetInputParamBuffer();

    /** get output parameter buffer */
    cpl_ParameterBuffer* GetOutputParamBuffer();
    
protected:
    /**constructor. */
    cpl_CommandsManager10();

    /**destructor. */
    virtual ~cpl_CommandsManager10();

	//protected variables.
    cpl_ParameterEngineManager* paramMan;
    cpl_CommandParameterProxy* paramProxy;
    
private:
    cpl_CommandsManager10(const cpl_CommandsManager10 &); // Not implemented.
    void operator = (const cpl_CommandsManager10 &); // Not implemented. 
};

#endif //CPL_COMMANDSMANAGER10_H
