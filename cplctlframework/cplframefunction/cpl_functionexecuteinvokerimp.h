#ifndef CPL_FUNCTIONEXECUTEINVOKERIMP_H
#define CPL_FUNCTIONEXECUTEINVOKERIMP_H

class cpl_FunctionExecuteInvokerImp : public IFunctionExecuteInvoker {
public:
    /** set execute function */
    void SetFunctionExecute(cpl_FunctionExecute* pExecuted);

    /** execute script function */
    int  Execute(int funcId);

public:
    /** set integer param */
    void SetInputAsINT(int index, int param0);

    // set the parameter at the specific index as float,
    void SetInputAsREAL(int index, float data);
    
    // set the parameter at the specific index as string,
    void SetInputAsSTRING(int index,  char *  data);
    
    // set the parameter at the specific index as integer array,
    void SetInputAsINTArray(int index,  int *  data, int num);

    // set the parameter at the specific index as integer id array,
    void SetInputAsIDArray(int index,  int *  data, int num);
    
    // set the parameter at the specific index as float array.,
    void SetInputAsREALArray(int index,  float *  data, int num);
    
    // set the parameter at the specific index as string array.,
    void SetInputAsSTRINGArray(int index,  char **data, int num);
    
    // set the parameter at the specific index as void array..
    void SetInputAsVOID(int index, void* data);
    
public:
    // get the parameter at the specific index as integer,
    void GetOutputAsINT(int index, int&  data);
    
    // get the parameter at the specific index as real,
    void GetOutputAsREAL(int index, float & data);
        
    // get the parameter at the specific index as string,
    void GetOutputAsSTRING(int index,  char *& data);
    
    // get the parameter at the specific index as integer array,
    void GetOutputAsINTArray(int index,  int *& data, int& num);

    // get the parameter at the specific index as integer id array,
    void GetOutputAsIDArray(int index,  int *& data, int& num);
    
    // get the parameter at the specific index as float array.,
    void GetOutputAsREALArray(int index,  float *& data, int &num);
    
    // get the parameter at the specific index as string array.,
    void GetOutputAsSTRINGArray(int index,  char **& data, int &num);

    // get the parameter at the specific index as void.
    void GetOutputAsVOID(int index, void*& data);

public:
    // reset parameter buffer 
    void ResetParamBuffer();

public:   
    //constructor
    cpl_FunctionExecuteInvokerImp();
    
    //constructor
    cpl_FunctionExecuteInvokerImp(cpl_FunctionExecute* pExecute);

    //destructor.
    virtual ~cpl_FunctionExecuteInvokerImp();

protected:
    cpl_FunctionExecute* FunctionExecute;
    int InputParamNum;
    int OutputParamNum;
};

#endif //CPL_FUNCTIONEXECUTEINVOKERIMP_H
