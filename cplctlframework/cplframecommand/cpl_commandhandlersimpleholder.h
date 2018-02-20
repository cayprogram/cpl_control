#ifndef CPL_COMMANDHANDLERSIMPLEHOLDER_H
#define CPL_COMMANDHANDLERSIMPLEHOLDER_H

class cpl_ICommandHandlerSimple;
class cpl_CommandHandlerSimpleHolder : public cpl_CommandHandler {
public:    
    cpl_CtlTypeRevisionMacro(cpl_CommandHandlerSimpleHolder, cpl_CommandHandler);

    //create instance.
    static cpl_CommandHandlerSimpleHolder* New();

public:
    /** do initialize */
    virtual void DoInitialize();

    /** do cleanup */
    virtual void DoCleanup();

    /** do update */
    virtual void DoUpdate();

    /** set command handler */
    virtual void SetCommandHandler(const char* stringId, void* commandHandler);

    /** get interface imp */
    virtual void* GetInterfaceImp() ;

public:
    /** deep copy */
    virtual cpl_CommandHandlerSimpleHolder* DeepCopy();

public:    
    /** constructor. */
    cpl_CommandHandlerSimpleHolder();

    /** destructor. */
    virtual ~cpl_CommandHandlerSimpleHolder();

    /** set simple object */
    void SetHandleObject(cpl_ICommandHandlerSimple* cmdhandler);

    //protected variables.
    cpl_ICommandHandlerSimple* pCmdHandler;
};

#endif //CPL_COMMANDHANDLERSIMPLEHOLDER_H
