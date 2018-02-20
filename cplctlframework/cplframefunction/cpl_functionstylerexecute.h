#ifndef CPL_FUNCTIONEXECUTEIMP_H
#define CPL_FUNCTIONEXECUTEIMP_H

class cpl_StylerFunction;
class cpl_FunctionExecuteImp : public cpl_FunctionExecute {
public:
    /** get input write right. */
    virtual IParameterEngineWriteRight* GetInputWriteRight();
    
    /** get output read right. */   
    virtual IParameterEngineReadRight* GetOutputReadRight(); 

public:    
    /** do command */
    virtual int  DoCommandId(int cmdId);

    /** set DDX*/
    virtual void SetDataExchange(cpl_FunctionParameter* pDataX);

public:
    //constructor.
    cpl_FunctionExecuteImp(cpl_StylerFunction* pOwner);

    //destructor.
    virtual ~cpl_FunctionExecuteImp();

protected:
    cpl_StylerFunction* Owner;
    cpl_FunctionParameter* pDDX; 
};

#endif //CPL_FUNCTIONEXECUTEIMP_H

