#ifndef CPL_COMMONFUNCTION_H
#define CPL_COMMONFUNCTION_H

class cpl_FunctionNullInputParameter : public cpl_Function {
public:
  	/** check parameter */
	virtual int CheckInputParameter()  { return 1; };
    virtual int ReadInputParameter()   { return 1; };
};

class cpl_FunctionNullOutputParameter : public cpl_Function {
public:
	/** check parameter */
	virtual int CheckOutputParameter() { return 1; };
    virtual int WriteOutputParameter() { return 1; };
};

class cpl_FunctionNullInputOutputParameter : public cpl_Function {
public:
	/** check parameter */
    virtual int CheckInputParameter()  { return 1; };
    virtual int CheckOutputParameter() { return 1; };
	virtual int ReadInputParameter()   { return 1; };
	virtual int WriteOutputParameter() { return 1; };
};

#endif //CPL_COMMONFUNCTION_H
