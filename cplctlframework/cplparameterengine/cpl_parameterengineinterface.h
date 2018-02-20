#ifndef CPL_PARAMETERENGINEINTERFACE_H
#define CPL_PARAMETERENGINEINTERFACE_H

struct IParameterEngineReadRight {

    // prepare reading.
    virtual int PrepareRead() = 0;

    // get the parameter at the specific index as integer,
    virtual int GetParamAsINT(int index, int&  data) = 0;
    virtual int GetParamAsINT(int index, int&  data, char*& vdecl) = 0;

    // get the parameter at the specific index as real,
    virtual int GetParamAsREAL(int index, float & data) = 0;
    virtual int GetParamAsREAL(int index, float & data, char*& vdecl) = 0;

    // get the parameter at the specific index as void,
    virtual int GetParamAsVOID(int index,  void *& data) = 0;
    virtual int GetParamAsVOID(int index,  void *& data, char*& vdecl) = 0;
    
    // get the parameter at the specific index as string,
    virtual int GetParamAsSTRING(int index,  char *& data) = 0;
    virtual int GetParamAsSTRING(int index,  char *& data, char*& vdecl) = 0;

    // get the parameter at the specific index as integer array,
    virtual int GetParamAsINTArray(int index,  int *& data, int& num) = 0;
    virtual int GetParamAsINTArray(int index,  int *& data, int& num, char*& vdecl) = 0;

    // get the parameter at the specific index as integer id array,
    virtual int GetParamAsIDArray(int index,  int *& data, int& num) = 0;
    virtual int GetParamAsIDArray(int index,  int *& data, int& num, char*& vdecl) = 0;

    // get the parameter at the specific index as float array.,
    virtual int GetParamAsREALArray(int index,  float *& data, int &num) = 0;
    virtual int GetParamAsREALArray(int index,  float *& data, int &num, char*& vdecl) = 0;

    // get the parameter at the specific index as string array.,
    virtual int GetParamAsSTRINGArray(int index,  char **& data, int &num) = 0;
    virtual int GetParamAsSTRINGArray(int index,  char **& data, int &num, char*& vdecl) = 0;

    /** get the parameter at the specific index as func pointer */
    virtual int GetParamAsFUNC(int index, ParamFunc& data) = 0;
    virtual int GetParamAsFUNC(int index, ParamFunc& data, char*& vdecl) = 0;
    
    //end reading.
    virtual int EndRead() = 0;

    // Clear Buffer
    virtual int Clear() = 0;
};

struct IParameterEngineWriteRight {

    // prepare writing.
    virtual int PrepareWrite() = 0;

    // set the parameter at the specific index as integer,
    virtual int SetParamAsINT(int index, int data) = 0;
    virtual int SetParamAsINT(int index, int data, char* vdecl) = 0;

    // set the parameter at the specific index as float,
    virtual int SetParamAsREAL(int index, float data) = 0;
    virtual int SetParamAsREAL(int index, float data, char* vdecl) = 0;

    // set the parameter at the specific index as string,
    virtual int SetParamAsVOID(int index,  void *  data) = 0;
    virtual int SetParamAsVOID(int index,  void *  data, char* vdecl) = 0;

    // set the parameter at the specific index as string,
    virtual int SetParamAsSTRING(int index,  char *  data) = 0;
    virtual int SetParamAsSTRING(int index,  char *  data, char* vdecl) = 0;

    // set the parameter at the specific index as integer array,
    virtual int SetParamAsINTArray(int index,  int *  data, int num) = 0;
    virtual int SetParamAsINTArray(int index,  int *  data, int num, char* vdecl) = 0;

    // set the parameter at the specific index as integer id array,
    virtual int SetParamAsIDArray(int index,  int *  data, int num) = 0;
    virtual int SetParamAsIDArray(int index,  int *  data, int num, char* vdecl) = 0;

    // set the parameter at the specific index as float array.,
    virtual int SetParamAsREALArray(int index,  float *  data, int num) = 0;
    virtual int SetParamAsREALArray(int index,  float *  data, int num, char* vdecl) = 0;

    // set the parameter at the specific index as string array.,
    virtual int SetParamAsSTRINGArray(int index,  char **data, int num) = 0;
    virtual int SetParamAsSTRINGArray(int index,  char **data, int num, char* vdecl) = 0;

    /** set the parameter at the specific index as func. */
    virtual int SetParamAsFUNC(int index, ParamFunc data) = 0;
    virtual int SetParamAsFUNC(int index, ParamFunc data, char* vdecl) = 0;

    // end writing
    virtual int EndWrite() = 0;
    
    // Clear Buffer
    virtual int Clear() = 0;
};


struct IParameterEngineCheckRight {

    //prepare for checking
    virtual int PrepareCheck() = 0;

    // check the parameter at the specific index as integer,
    virtual int CheckParamAsINT(int index) = 0;

    // check the parameter at the specific index as real,
    virtual int CheckParamAsREAL(int index) = 0;

    // check the parameter at the specific index as string,
    virtual int CheckParamAsSTRING(int index) = 0;

    // check the parameter at the specific index as integer array,
    virtual int CheckParamAsINTArray(int index) = 0;

    // check the parameter at the specific index as integer id array,
    virtual int CheckParamAsIDArray(int index) = 0;

    // check the parameter at the specific index as float array.,
    virtual int CheckParamAsREALArray(int index) = 0;

    // check the parameter at the specific index as float array.,
    virtual int CheckParamAsSTRINGArray(int index) = 0;
    
    /** check the parameter at the specific index as void. */
    virtual int CheckParamAsVOID(int index) = 0;

    // get param type.
    virtual int GetParamType(int index) = 0;

    // how many parameters we have.
    virtual int GetParamNumber(int &num) = 0;

    //end checking
    virtual int EndCheck() = 0;
};

#endif  //CPL_PARAMETERENGINEINTERFACE_H
