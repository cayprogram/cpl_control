#ifndef CPL_COMMAND_H
#define CPL_COMMAND_H

struct _fbCommandCtxRuntime_s {
    int domainId;
    int graphicId;
};

class cpl_CommandHandler;
class cpl_Command {
public:
    /** release object. */
    virtual void Delete();

    /** check parameter */
    virtual int CheckInputParameter_();
    virtual int ReadInputParameter_();
    virtual int WriteOutputParameter_();
    virtual int CheckOutputParameter_();

    /** check invariant */
    virtual int CheckInVariant();

    /** execute .. */
    virtual void Execute();

    /** set command handler */
    virtual void SetCommandHandler(const char* stringId, void* commandHandler);

    /** get string id */
    virtual const char* GetStringId() = 0;

    /** deep copy */
    virtual cpl_Command* DeepCopy() { return 0; }

public:
    /** set runtime context */
    void SetRuntimeContext(int domainId, int graphicId);

    //set parameter proxy.
    void SetParameterProxy(cpl_CommandParameterProxy* proxy);
    
    //get parameter proxy.
    cpl_CommandParameterProxy* GetParamterProxy();

protected:
    /** check parameter */
    virtual int CheckInputParameter()  = 0;
    virtual int ReadInputParameter()   = 0;
    virtual int WriteOutputParameter() = 0;
    virtual int CheckOutputParameter() = 0;

    /** execute .. */
    virtual void ExecuteDirect() = 0;
    
protected:
    /** constructor. */
    cpl_Command();
    
    /** destructor. */
    virtual ~cpl_Command() {} ;

    //inner structure.
    struct _fbCommand_s {
        char   text[64];
        int    type;
        int    cmdid;
        void * userdata;
        cpl_CommandParameterProxy * paramProxy;
        _fbCommandCtxRuntime_s      ctxRuntimeData;
    };

    //protected variables
    _fbCommand_s cmdData;
};

#endif //CPL_COMMAND_H
