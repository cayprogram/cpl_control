#ifndef CPL_COMMONSTYLERFUNCTION_H
#define CPL_COMMONSTYLERFUNCTION_H

class cpl_StylerFunctionNullInputParameter : public cpl_StylerFunction {
public:
    cpl_CtlTypeRevisionMacro(cpl_StylerFunctionNullInputParameter, cpl_StylerFunction);

    /** check parameter */
    virtual int CheckInputParameter()  { return 1; };
    virtual int ReadInputParameter()   { return 1; };
};

class cpl_StylerFunctionNullOutputParameter : public cpl_StylerFunction {
public:
    /** check parameter */
    virtual int CheckOutputParameter() { return 1; };
    virtual int WriteOutputParameter() { return 1; };
};

class cpl_StylerFunctionNullInputOutputParameter : public cpl_StylerFunction {
public:
    /** check parameter */
    virtual int CheckInputParameter()  { return 1; };
    virtual int CheckOutputParameter() { return 1; };
    virtual int ReadInputParameter()   { return 1; };
    virtual int WriteOutputParameter() { return 1; };
};

#endif //CPL_COMMONSTYLERFUNCTION_H
