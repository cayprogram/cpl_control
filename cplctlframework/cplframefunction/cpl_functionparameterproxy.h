#ifndef CPL_FUNCTIONPARAMETERPROXY_H
#define CPL_FUNCTIONPARAMETERPROXY_H

class cpl_FunctionParameterProxy {

public:    
	/** set input parameter read and check rights*/
	void SetInputParEngineReaderAndChecker(IParameterEngineReadRight *read, IParameterEngineCheckRight *check);

    /** set output parameter read and check rights*/
	void SetOutputParEngineWriterAndChecker(IParameterEngineWriteRight *write, IParameterEngineCheckRight *check);

    /** set error no */
    int SetError(int error);
    int GetError(int& error, char*& description);
        
    /** clear output parameter buffer */
    void ClearOutputParameter();

    /** clear input parameter buffer */
    void ClearInputParameter();
    
public:
    /** constructor. */
    cpl_FunctionParameterProxy();

    /** destructor. */
    virtual ~cpl_FunctionParameterProxy();

	/** Interface for input.out parameter read and check rights */
	IParameterEngineReadRight * inParReader;
	IParameterEngineCheckRight* inParChecker;
	IParameterEngineWriteRight* outParWriter;
	IParameterEngineCheckRight* outParChecker;

    /** 0 is no error, other return error no */
	int success;
};

#endif //CPL_FUNCTIONPARAMETERPROXY_H
