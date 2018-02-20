#ifndef CPL_FUNCTIONPROCESS20_H
#define CPL_FUNCTIONPROCESS20_H

class cpl_FunctionProcess20 : public cpl_FunctionProcess15 {
public:
    /** execute function */
    virtual int ExecuteFunction(char* string);  

protected:
    //is record session opened for functions.
    int IsRecordSessionForFunction(char* funcName);

    //record session function directly.
    int RecordSessionFunction(char* funcName);

protected:
    /**constructor. */
    cpl_FunctionProcess20();

    /**destructor. */    
    virtual ~cpl_FunctionProcess20();

    //protected variables.
    cpl_SessionProxy* pSessionProxy;
    cpl_FunctionSessionDataProxy* funcSessionData;
    int funcExecuteStatus;

private:
    cpl_FunctionProcess20(const cpl_FunctionProcess20 &); // Not implemented.
    void operator = (const cpl_FunctionProcess20 &); // Not implemented. 
};

#endif //CPL_FUNCTIONPROCESS20_H
