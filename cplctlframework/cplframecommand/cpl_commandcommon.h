#ifndef CPL_COMMONCOMMAND_H
#define CPL_COMMONCOMMAND_H

class cpl_CommandNullInputParameter : public cpl_Command {
public:
  	/** check parameter */
	virtual int CheckInputParameter()  { return 1; };
    virtual int ReadInputParameter()   { return 1; };
};

class cpl_CommandNullOutputParameter : public cpl_Command {
public:
	/** check parameter */
	virtual int CheckOutputParameter() { return 1; };
    virtual int WriteOutputParameter() { return 1; };
};

class cpl_CommandNullInputOutputParameter : public cpl_Command {
public:
	/** check parameter */
    virtual int CheckInputParameter()  { return 1; };
    virtual int CheckOutputParameter() { return 1; };
	virtual int ReadInputParameter()   { return 1; };
	virtual int WriteOutputParameter() { return 1; };
};

#endif //CPL_COMMONCOMMAND_H
