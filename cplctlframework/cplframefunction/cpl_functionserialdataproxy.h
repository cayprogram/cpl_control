#ifndef CPL_FUNCTIONSERIALDATAHANDLER_H
#define CPL_FUNCTIONSERIALDATAHANDLER_H

class cpl_FunctionSerialData;
class cpl_FunctionSerialDataCoder;
class cpl_FunctionSerialDataProxy {
public:
    /** create instance */
    static cpl_FunctionSerialDataProxy* New();

    /** delete */
    void Delete();

public:
    /** set function command proxy */
    void SetCommandProxy(cpl_FunctionCommandProxy* proxy);

    /** do allocate */
    void AllocateFuncSerialData(int sz, int ext);

    /** do reset */
    void ResetFuncSerialData();

    /** get function serial data number */
    int  GetFuncSerialDataNumber();

    /** insert function serial data */
    int  InsertFuncSerialData(char* datName, char* datVal);

    /** get function serial data name string */
    void GetFuncSerialData(int datid, char*& datName, char*& datVal);

public:
    /** encode function serial data */
    char* EncodeFuncSerialData(int num, int* iarray);

    /** encode function serial data */
    char* EncodeFuncSerialData(int num, float* farray);

    /** parse function serial data */
    int   ParseFuncSerialData(char* dataStr, int& num, int*& iarray);

    /** parse function serial data */
    int   ParseFuncSerialData(char* dataStr, int& num, float*& farray);

protected:
    //get serial data from command running.
    int   GetFuncSerialDataFromCommand(int runTyp, char* dataStr);

protected:
    /** constructor. */
    cpl_FunctionSerialDataProxy();

    /** destructor. */
    virtual ~cpl_FunctionSerialDataProxy();

    //protected variables
    cpl_FunctionSerialData*      serialDat;
    cpl_FunctionSerialDataCoder* serialDatCoder; 
    cpl_FunctionCommandProxy*    cmdProxy;
    cpl_IntArray*   idatArray;
    cpl_FloatArray* fdatArray;
};

#endif //CPL_FUNCTIONSERIALDATAHANDLER_H
