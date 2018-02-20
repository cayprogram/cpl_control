#ifndef CPL_COMMANDHANDLERSIMPLEINTERFACE_H
#define CPL_COMMANDHANDLERSIMPLEINTERFACE_H

class cpl_ICommandHandlerSimple  {
public:
public:
    /** release */
    virtual int Release() = 0;

    /** do initialize */
    virtual void DoInitialize() = 0;

    /** do cleanup */
    virtual void DoCleanup() = 0;

    /** do update */
    virtual void DoUpdate() = 0;

    /** set command handler */
    virtual void SetCommandHandler(const char* stringId, void* commandHandler) = 0;

public:
    /** get string cmd */
    virtual const char* GetStringId() = 0;    

    /** deep copy */
    virtual cpl_ICommandHandlerSimple* DeepCopy() = 0;
};

#endif //CPL_COMMANDHANDLERSIMPLEINTERFACE_H
