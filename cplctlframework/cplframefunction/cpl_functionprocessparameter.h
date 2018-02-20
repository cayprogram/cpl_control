#ifndef CPL_FUNCTIONPROCESSPARAMETER_H
#define CPL_FUNCTIONPROCESSPARAMETER_H

class cpl_FunctionProcessParameter: public IParameterBufferIO {    
public:
    /** create instance */
    static cpl_FunctionProcessParameter* New();

    /** delete instance */
    void Delete() { delete this; }

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

public:
    /** set input parameters to process */
    void ExechangeInputParameter(cpl_FunctionProcess* uFuncProcess);
    
    /** get output parameters in process */
    void ExechangeOutputParameter(cpl_FunctionProcess* uFuncProcess);

    /** get parameter manager */
    cpl_ParameterEngineManager* GetParamManager();

protected:
    /** close read process */
    void EncloseReadProcess();

    /** close write process */
    void EncloseWriteProcess();

    //try to read/write parameter */
    void TryToReadParameter();
    void TryToWriteParameter();

protected:
    /**constructor. */
    cpl_FunctionProcessParameter();

    /**destructor. */
    virtual ~cpl_FunctionProcessParameter();

    //protected variables
    cpl_ParameterEngineManager* paramMan;
    int writeRight;
    int readRight;
};

#endif //CPL_FUNCTIONPROCESSPARAMETER_H
