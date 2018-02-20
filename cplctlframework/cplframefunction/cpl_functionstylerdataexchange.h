#ifndef CPL_STYLERFUNCTIONDATAEXCHANGE_H
#define CPL_STYLERFUNCTIONDATAEXCHANGE_H

class cpl_IFunctionDataExchange;
class cpl_StylerFunctionDataExchange: public cpl_IFunctionDataExchange {
public:
    /** create instance */
    static cpl_StylerFunctionDataExchange* New();

    /** delete this */
    void Delete();

public:
    // prepare writing.
    virtual int PrepareWrite();
    
    // set the parameter at the specific index as integer,
    virtual int SetParamAsINT(int index, int data);
    
    // set the parameter at the specific index as float,
    virtual int SetParamAsREAL(int index, float data);
    
    // set the parameter at the specific index as string,
    virtual int SetParamAsVOID(int index,  void *  data);
    
    // set the parameter at the specific index as string,
    virtual int SetParamAsSTRING(int index,  char *  data);
    
    // set the parameter at the specific index as integer array,
    virtual int SetParamAsINTArray(int index,  int *  data, int num);

    // set the parameter at the specific index as integer id array,
    virtual int SetParamAsIDArray(int index,  int *  data, int num);
    
    // set the parameter at the specific index as float array.,
    virtual int SetParamAsREALArray(int index,  float *  data, int num);
    
    // set the parameter at the specific index as string array.,
    virtual int SetParamAsSTRINGArray(int index,  char **data, int num);
    
    /** set the parameter at the specific index as func. */
    virtual int SetParamAsFUNC(int index, ParamFunc data);
    
    // end writing
    virtual int EndWrite();

public:
    // prepare reading.
    virtual int PrepareRead();
    
    // get the parameter at the specific index as integer,
    virtual int GetParamAsINT(int index, int&  data);
    
    // get the parameter at the specific index as real,
    virtual int GetParamAsREAL(int index, float & data);
    
    // get the parameter at the specific index as void,
    virtual int GetParamAsVOID(int index,  void *& data);
    
    // get the parameter at the specific index as string,
    virtual int GetParamAsSTRING(int index,  char *& data);
    
    // get the parameter at the specific index as integer array,
    virtual int GetParamAsINTArray(int index,  int *& data, int& num);

    // get the parameter at the specific index as integer id array,
    virtual int GetParamAsIDArray(int index,  int *& data, int& num);
    
    // get the parameter at the specific index as float array.,
    virtual int GetParamAsREALArray(int index,  float *& data, int &num);
    
    // get the parameter at the specific index as string array.,
    virtual int GetParamAsSTRINGArray(int index,  char **& data, int &num);
    
    /** get the parameter at the specific index as func pointer */
    virtual int GetParamAsFUNC(int index, ParamFunc& data);
    
    //end reading.
    virtual int EndRead();

public:
    /** get function parameter */
    cpl_FunctionParameter* GetFunctionParameter();

public:    
    /** constructor. */
    cpl_StylerFunctionDataExchange();

    /** destructor. */
    virtual ~cpl_StylerFunctionDataExchange();

protected: 
    //member variables.
    cpl_FunctionParameter* pFuncParameter; 
};

#endif //CPL_STYLERFUNCTIONDATAEXCHANGE_H
