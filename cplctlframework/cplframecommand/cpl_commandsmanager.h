#ifndef CPL_COMMANDSMANAGER_H
#define CPL_COMMANDSMANAGER_H

class cpl_CommandHandler;
class cpl_CommandHandlerArray;
class cpl_CommandsManager15;
class cpl_CommandsManager: public cpl_CommandsManager15 {
public:
    /** create function */
    static cpl_CommandsManager* New();

public:
    /** Do initialization */
    virtual void DoInitialization(char* cmdType);

    /** Do cleanup */
    virtual void DoCleanup();

    /** Do default set */
    virtual void DoDefaultSetting();

    /** Reset */
    virtual void Reset() {}

public:
    /** insert command handler */
    int  RegisterCommandHandler(cpl_CommandHandler* cmdHandler);

    /** find command handler */
    int FindCommandHandler(char* stringId, cpl_CommandHandler*& cmdHandler);

public:
    /** init command handlers */
    void InitializeCommandHandlers();

    /** cleanup command handlers */
    void CleanupCommandHandlers();

protected:
    /**constructor. */
    cpl_CommandsManager();

    /**destructor. */
    virtual ~cpl_CommandsManager();

    //protected variables.
    cpl_CommandHandlerArray* cmdHandlerArray;   
    
private:
    cpl_CommandsManager(const cpl_CommandsManager &); // Not implemented.
    void operator = (const cpl_CommandsManager &); // Not implemented. 
};

#endif //CPL_COMMANDSMANAGER_H
