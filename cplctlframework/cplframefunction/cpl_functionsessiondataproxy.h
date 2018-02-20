#ifndef CPL_FUNCTIONSESSIONDATAPROXY_H
#define CPL_FUNCTIONSESSIONDATAPROXY_H

class cpl_FunctionSerialDataCoder;
class cpl_FunctionSessionDataProxy {
public:
    /** create instance */
    static cpl_FunctionSessionDataProxy* New();

    /** delete */
    void Delete();

public:
    /** set function parameter proxy */
    void SetFunctionParamManager(cpl_ParameterEngineManager* paramMan);

    //divide long data string as several segments.
    char* SegmentParameterString(char* paramStr);

    /** apply current function parameter by string */
    int  ApplyFunctionParameter(cpl_ParameterBuffer* params);

    /** apply current function command parameter by string */
    int  ApplyFunctionCommandParameter(cpl_StylerFunction* uFunc, cpl_ParameterBuffer* params);

protected:
    /** constructor. */
    cpl_FunctionSessionDataProxy();

    /** destructor. */
    virtual ~cpl_FunctionSessionDataProxy();

    //protected variables.
    cpl_ParameterEngineManager* uParamMan;
    char* parStringBuf;
};

#endif //CPL_FUNCTIONSESSIONDATAPROXY_H
