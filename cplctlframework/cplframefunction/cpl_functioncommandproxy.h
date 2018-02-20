#ifndef CPL_FUNCTIONCOMMANDPROXY_H
#define CPL_FUNCTIONCOMMANDPROXY_H

class cpl_IFunctionCommandProxy;
class cpl_FunctionCommandProxy : public cpl_IFunctionCommandProxy {
public:
    /** do initialize */
    void DoInitialization(char* cmdType);

    /** do cleanup */
    void DoCleanup();

    /** do set default */
    void DoDefaultSetting();

    /** set runtime context */
    void SetRuntimeContext(int domainHaandle, int graphicHandle);

public:
    // set the parameter at the specific index as integer,
    int SetParamAsINT(int index, int data);
    
    // set the parameter at the specific index as float,
    int SetParamAsREAL(int index, float data);
    
    // set the parameter at the specific index as string,
    int SetParamAsVOID(int index,  void *  data);
    
    // set the parameter at the specific index as string,
    int SetParamAsSTRING(int index,  char *  data);
    
    // set the parameter at the specific index as integer array,
    int SetParamAsINTArray(int index,  int *  data, int num);

    // set the parameter at the specific index as integer id array,
    int SetParamAsIDArray(int index,  int *  data, int num);
    
    // set the parameter at the specific index as float array.,
    int SetParamAsREALArray(int index,  float *  data, int num);
    
    // set the parameter at the specific index as string array.,
    int SetParamAsSTRINGArray(int index,  char **data, int num);

    /** set the parameter at the specific index as func. */
    int SetParamAsFUNC(int index, ParamFunc data);

public:
    // get the parameter number 
    int GetParamNumber();

    // get the parameter at the specific index as integer,
    int GetParamAsINT(int index, int&  data);
    
    // get the parameter at the specific index as real,
    int GetParamAsREAL(int index, float & data);
    
    // get the parameter at the specific index as void,
    int GetParamAsVOID(int index,  void *& data);
    
    // get the parameter at the specific index as string,
    int GetParamAsSTRING(int index,  char *& data);
    
    // get the parameter at the specific index as integer array,
    int GetParamAsINTArray(int index,  int *& data, int& num);

    // get the parameter at the specific index as integer id array,
    int GetParamAsIDArray(int index,  int *& data, int& num);
    
    // get the parameter at the specific index as float array.,
    int GetParamAsREALArray(int index,  float *& data, int &num);
    
    // get the parameter at the specific index as string array.,
    int GetParamAsSTRINGArray(int index,  char **& data, int &num);

    /** get the parameter at the specific index as func pointer */
    int GetParamAsFUNC(int index, ParamFunc& data);

    /** get output parameter buffer */
    cpl_ParameterBuffer* GetOutputParamBuffer();

public:
    /** execute command */
    int ExecuteCommand(char* string);

    /** execute formated command*/
    int ExecuteCommandFormatted(char* string, cpl_ParameterBuffer*& outParams);

public:
    /**constructor. */
    cpl_FunctionCommandProxy(cpl_FunctionProcess* funProcess);

    /**destructor. */
    virtual ~cpl_FunctionCommandProxy();

protected:
    //protected variables.
    cpl_CommandsManager* uCmdManager;
    cpl_FunctionProcess* uFunProcess;
};

#endif //CPL_FUNCTIONCOMMANDPROXY_H
