#ifndef CPL_COMMONCOMMANDSIMPLE_H
#define CPL_COMMONCOMMANDSIMPLE_H

class cpl_CommandSimpleNullInputParameter : public cpl_CommandSimple {
public:
    cpl_CtlTypeRevisionMacro(cpl_CommandSimpleNullInputParameter, cpl_CommandSimple);

    /** check parameter */
    virtual int CheckInputParameter(IParameterEngineCheckRight *check)  { return 1; };
    virtual int ReadInputParameter (IParameterEngineReadRight  *read )  { return 1; };
};

class cpl_CommandSimpleNullOutputParameter : public cpl_CommandSimple {
public:
    cpl_CtlTypeRevisionMacro(cpl_CommandSimpleNullOutputParameter, cpl_CommandSimple);

    /** check parameter */
    virtual int CheckOutputParameter(IParameterEngineCheckRight *check) { return 1; };
    virtual int WriteOutputParameter(IParameterEngineWriteRight *write) { return 1; };
};

class cpl_CommandSimpleNullInputOutputParameter : public cpl_CommandSimple {
public:
    cpl_CtlTypeRevisionMacro(cpl_CommandSimpleNullInputOutputParameter, cpl_CommandSimple);

    /** check parameter */
    virtual int CheckInputParameter (IParameterEngineCheckRight *check) { return 1; };
    virtual int CheckOutputParameter(IParameterEngineCheckRight *check) { return 1; };
    virtual int ReadInputParameter  (IParameterEngineReadRight  *read ) { return 1; };
    virtual int WriteOutputParameter(IParameterEngineWriteRight *write) { return 1; };
};

#endif //CPL_COMMONCOMMANDSIMPLE_H
