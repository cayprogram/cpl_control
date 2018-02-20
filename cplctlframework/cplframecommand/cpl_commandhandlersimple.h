#ifndef CPL_COMMANDHANDLERSIMPLE_H
#define CPL_COMMANDHANDLERSIMPLE_H

class cpl_CommandHandlerSimple : public cpl_ICommandHandlerSimple, public cpl_CtlObject  {
public:    
    cpl_CtlTypeRevisionMacro(cpl_CommandHandlerSimple, cpl_CtlObject);

    /** release */
    virtual int Release();

public:
    /** do initialize */
    virtual void DoInitialize() {}

    /** do cleanup */
    virtual void DoCleanup() {}

    /** do update */
    virtual void DoUpdate() {}

    /** set command handler */
    virtual void SetCommandHandler(const char* stringId, void* commandHandler) {}

public:    
    /** constructor. */
    cpl_CommandHandlerSimple();
        
    /** destructor. */
    virtual ~cpl_CommandHandlerSimple() {}
};

#endif //CPL_COMMANDHANDLERSIMPLE_H
