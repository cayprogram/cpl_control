#ifndef CPL_PARAMETERENGINE_H
#define CPL_PARAMETERENGINE_H

class cpl_ParameterEngine : public IParameterEngineReadRight, 
                            public IParameterEngineWriteRight,  
                            public IParameterEngineCheckRight {

//Interface of IParameterEngineReadRight
public: 
    // prepare reading.
    virtual int PrepareRead();

    // get the parameter at the specific index as integer,
    virtual int GetParamAsINT(int index, int&  data);
    virtual int GetParamAsINT(int index, int&  data, char*& vdecl);

    // get the parameter at the specific index as real,
    virtual int GetParamAsREAL(int index, float & data);
    virtual int GetParamAsREAL(int index, float & data, char*& vdecl);

    // get the parameter at the specific index as void,
    virtual int GetParamAsVOID(int index,  void *& data);
    virtual int GetParamAsVOID(int index,  void *& data, char*& vdecl);
    
    // get the parameter at the specific index as string,
    virtual int GetParamAsSTRING(int index,  char *& data);
    virtual int GetParamAsSTRING(int index,  char *& data, char*& vdecl);

    // get the parameter at the specific index as integer array,
    virtual int GetParamAsINTArray(int index,  int *& data, int& num);
    virtual int GetParamAsINTArray(int index,  int *& data, int& num, char*& vdecl);

    // get the parameter at the specific index as integer id array,
    virtual int GetParamAsIDArray(int index,  int *& data, int& num);
    virtual int GetParamAsIDArray(int index,  int *& data, int& num, char*& vdecl);

    // get the parameter at the specific index as float array.,
    virtual int GetParamAsREALArray(int index,  float *& data, int &num);
    virtual int GetParamAsREALArray(int index,  float *& data, int &num, char*& vdecl);

    // get the parameter at the specific index as string array.,
    virtual int GetParamAsSTRINGArray(int index,  char **& data, int &num);
    virtual int GetParamAsSTRINGArray(int index,  char **& data, int &num, char*& vdecl);

    /** get the parameter at the specific index as func pointer */
    virtual int GetParamAsFUNC(int index, ParamFunc& data);
    virtual int GetParamAsFUNC(int index, ParamFunc& data, char*& vdecl);

    //end reading.
    virtual int EndRead();

//Interface of IParameterEngineWriteRight
public:
    // prepare writing.
    virtual int PrepareWrite();

    // set the parameter at the specific index as integer,
    virtual int SetParamAsINT(int index, int data);
    virtual int SetParamAsINT(int index, int data, char* vdecl);

    // set the parameter at the specific index as float,
    virtual int SetParamAsREAL(int index, float data);
    virtual int SetParamAsREAL(int index, float data, char* vdecl);

    // set the parameter at the specific index as string,
    virtual int SetParamAsVOID(int index,  void *  data);
    virtual int SetParamAsVOID(int index,  void *  data, char* vdecl);

    // set the parameter at the specific index as string,
    virtual int SetParamAsSTRING(int index,  char *  data);
    virtual int SetParamAsSTRING(int index,  char *  data, char* vdecl);

    // set the parameter at the specific index as integer array,
    virtual int SetParamAsINTArray(int index,  int *  data, int num);
    virtual int SetParamAsINTArray(int index,  int *  data, int num, char* vdecl);

    // set the parameter at the specific index as integer id array,
    virtual int SetParamAsIDArray(int index,  int *  data, int num);
    virtual int SetParamAsIDArray(int index,  int *  data, int num, char* vdecl);

    // set the parameter at the specific index as float array.,
    virtual int SetParamAsREALArray(int index,  float *  data, int num);
    virtual int SetParamAsREALArray(int index,  float *  data, int num, char* vdecl);

    // set the parameter at the specific index as string array.,
    virtual int SetParamAsSTRINGArray(int index,  char **data, int num);
    virtual int SetParamAsSTRINGArray(int index,  char **data, int num, char* vdecl);

    /** set the parameter at the specific index as func. */
    virtual int SetParamAsFUNC(int index, ParamFunc data);
    virtual int SetParamAsFUNC(int index, ParamFunc data, char* vdecl);
    
    // end writing
    virtual int EndWrite();
    
    // Clear Buffer
    virtual int Clear();

//Interface of IParameterEngineCheckRight
public:

    //prepare for checking
    virtual int PrepareCheck();

    // check the parameter at the specific index as integer,
    virtual int CheckParamAsINT(int index);

    // check the parameter at the specific index as real,
    virtual int CheckParamAsREAL(int index);

    // check the parameter at the specific index as string,
    virtual int CheckParamAsSTRING(int index);

    // check the parameter at the specific index as integer array,
    virtual int CheckParamAsINTArray(int index);

    // check the parameter at the specific index as integer id array,
    virtual int CheckParamAsIDArray(int index);

    // check the parameter at the specific index as float array.,
    virtual int CheckParamAsREALArray(int index);

    // check the parameter at the specific index as string array.,
    virtual int CheckParamAsSTRINGArray(int index);

    /** check the parameter at the specific index as void. */
    virtual int CheckParamAsVOID(int index);

    // get param type.
    virtual int GetParamType(int index);    

    // how many parameters we have.
    virtual int GetParamNumber(int &num);

    /** get parameter buffer */
    virtual cpl_ParameterBuffer* GetParamBuffer();

    //end checking
    virtual int EndCheck();

public:
    /** is writing */
    virtual int IsWriting();

    /** is reading */
    virtual int IsReading();

protected:
    /** Indicate cpl_ParameterEngineManager is friend class */
    friend class cpl_ParameterEngineManager;

    /** Constructor */
    cpl_ParameterEngine();
    
    /** Destructor */
    virtual ~cpl_ParameterEngine();

private:
    /** flag to see if is in writing procedure */
    /** 1 is in writing, 0 is not */
    int writeFlag;

    /** flag to see if is in writing procedure */
    /** 1 is in writing, 0 is not */
    int readFlag;

    /** parameter Buffer */
    cpl_ParameterBuffer parBuffer;
};

#endif //CPL_PARAMETERENGINE_H
