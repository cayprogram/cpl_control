#ifndef CPL_COMMANDHANDLER_H
#define CPL_COMMANDHANDLER_H

class cpl_CommandHandler : public cpl_CtlObject { 
public:    
    cpl_CtlTypeRevisionMacro(cpl_CommandHandler, cpl_CtlObject);

public:
    /** do initialize */
    virtual void DoInitialize() {}

    /** do cleanup */
    virtual void DoCleanup() {}

    /** do update */
    virtual void DoUpdate() {}

    /** set command handler */
    virtual void SetCommandHandler(const char* stringId, void* commandHandler);

    /** set name */
    virtual void SetName(char name[64]);
    virtual void GetName(char name[64]);

    /** deep copy */
    virtual cpl_CommandHandler* DeepCopy() { return 0; };

    /** get interface imp */
    virtual void* GetInterfaceImp() { return this; }

protected:
    /** constructor. */
    cpl_CommandHandler();
    
    /** destructor. */
    virtual ~cpl_CommandHandler();

    //name.
    char StringId[64];

private:
    cpl_CommandHandler(const cpl_CommandHandler &); // Not implemented.
    void operator = (const cpl_CommandHandler &); // Not implemented.     
};

#endif //CPL_COMMANDHANDLER_H
