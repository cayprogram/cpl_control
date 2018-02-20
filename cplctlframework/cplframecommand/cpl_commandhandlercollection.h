#ifndef CPL_COMMANDHANDLERCOLLECTION_H
#define CPL_COMMANDHANDLERCOLLECTION_H

class cpl_HashTableCmdHandlerOneKey;
class cpl_CommandHandlerCollection  {
public:    
    /**insert command. */
    virtual int InsertCommandHandler(const char* string, cpl_CommandHandler * cmdHandlerObject);

    /** find command */
    virtual int FindCommandHandler(char* string, cpl_CommandHandler * & cmdHandlerObject);

    /** is valid command */
    virtual int IsCommandHandlerExist(char* string);

public:
    /**constructor. */
    cpl_CommandHandlerCollection();

    /**destructor. */    
    virtual ~cpl_CommandHandlerCollection();

protected:
    cpl_HashTableCmdHandlerOneKey * hashCmdHandlerStringKey;
};

#endif //CPL_COMMANDHANDLERCOLLECTION_H
