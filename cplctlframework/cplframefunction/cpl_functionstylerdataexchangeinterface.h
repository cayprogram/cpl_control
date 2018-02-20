#ifndef CPL_STYLERFUNCTIONDATAEXCHANGEINTERFACE_H
#define CPL_STYLERFUNCTIONDATAEXCHANGEINTERFACE_H

class cpl_IFunctionDataExchange {
public:
    // prepare writing.
    virtual int PrepareWrite() = 0;
    
    // set the parameter at the specific index as integer,
    virtual int SetParamAsINT(int index, int data) = 0;
    
    // set the parameter at the specific index as float,
    virtual int SetParamAsREAL(int index, float data) = 0;
    
    // set the parameter at the specific index as string,
    virtual int SetParamAsVOID(int index,  void *  data) = 0;
    
    // set the parameter at the specific index as string,
    virtual int SetParamAsSTRING(int index,  char *  data) = 0;
    
    // set the parameter at the specific index as integer array,
    virtual int SetParamAsINTArray(int index,  int *  data, int num) = 0;

    // set the parameter at the specific index as integer id array,
    virtual int SetParamAsIDArray(int index,  int *  data, int num) = 0;
    
    // set the parameter at the specific index as float array.,
    virtual int SetParamAsREALArray(int index,  float *  data, int num) = 0;
    
    // set the parameter at the specific index as string array.,
    virtual int SetParamAsSTRINGArray(int index,  char **data, int num) = 0;
    
    /** set the parameter at the specific index as func. */
    virtual int SetParamAsFUNC(int index, ParamFunc data) = 0;
    
    // end writing
    virtual int EndWrite() = 0;

public:
    // prepare reading.
    virtual int PrepareRead() = 0;
    
    // get the parameter at the specific index as integer,
    virtual int GetParamAsINT(int index, int&  data) = 0;
    
    // get the parameter at the specific index as real,
    virtual int GetParamAsREAL(int index, float & data) = 0;
    
    // get the parameter at the specific index as void,
    virtual int GetParamAsVOID(int index,  void *& data) = 0;
    
    // get the parameter at the specific index as string,
    virtual int GetParamAsSTRING(int index,  char *& data) = 0;
    
    // get the parameter at the specific index as integer array,
    virtual int GetParamAsINTArray(int index,  int *& data, int& num) = 0;

    // get the parameter at the specific index as integer id array,
    virtual int GetParamAsIDArray(int index,  int *& data, int& num) = 0;
    
    // get the parameter at the specific index as float array.,
    virtual int GetParamAsREALArray(int index,  float *& data, int &num) = 0;
    
    // get the parameter at the specific index as string array.,
    virtual int GetParamAsSTRINGArray(int index,  char **& data, int &num) = 0;
    
    /** get the parameter at the specific index as func pointer */
    virtual int GetParamAsFUNC(int index, ParamFunc& data) = 0;
    
    //end reading.
    virtual int EndRead() = 0;
};

#endif //CPL_STYLERFUNCTIONDATAEXCHANGEINTERFACE_H
