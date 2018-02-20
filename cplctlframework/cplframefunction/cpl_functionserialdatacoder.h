#ifndef CPL_FUNCTIONSERIALDATACODER_H
#define CPL_FUNCTIONSERIALDATACODER_H

class cpl_FunctionSerialDataCoder {
public:
    /** create instance */
    static cpl_FunctionSerialDataCoder* New();

    /** delete */
    void Delete();

public:
    /** encode function serial data */
    char* EncodeFuncSerialData(int num, int* iarray);

    /** encode function serial data */
    char* EncodeFuncSerialData(int num, float* farray);

    /** encode function serial data */
    char* EncodeFuncSerialData(int num, double* darray);

    /** encode function id serial data */
    char* EncodeFuncIdSerialData(int num, int* iarray);

    /** parse function serial data */
    int   ParseFuncSerialData(char* dataStr, int& num, int*& iarray);

    /** parse function serial data */
    int   ParseFuncSerialData(char* dataStr, int& num, float*& farray);

    /** parse function serial data */
    int   ParseFuncSerialData(char* dataStr, int& num, double*& darray);

    /** parse function id serial data */
    int   ParseFuncIdSerialData(char* dataStr, int& num, int*& iarray);

    /** parse function command serial data */
    int   ParseFuncCmdSerialData(char* dataStr, char*& cmdStr, cpl_ParameterBuffer*& cmdPar);

protected:
    /** constructor. */
    cpl_FunctionSerialDataCoder();

    /** destructor. */
    virtual ~cpl_FunctionSerialDataCoder();

    //protected variables
    char*   tmpStringBuf;
    cpl_ParameterBuffer* tmpParBuf;
    cpl_NumericToString* numToStr;
    cpl_CtlDataTextFormatter* textFormater;
};

#endif //CPL_FUNCTIONSERIALDATACODER_H
