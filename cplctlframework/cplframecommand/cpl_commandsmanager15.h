#ifndef CPL_COMMANDSMANAGER15_H
#define CPL_COMMANDSMANAGER15_H

class cpl_HashTableCmdOneKey;
class cpl_CommandsManager10;
class cpl_CommandsManager15 : public cpl_CommandsManager10 {

public:
    /**execute */
    virtual int ExecuteCommand(char* string);

    /**execute command */
    virtual int ExecuteCommandDirect(cpl_Command* command);  
    
    /** find command */
    virtual int FindCommand(char* string, cpl_Command * & cmdObject);

public:
    /**insert command. */
    virtual int InsertCommand(cpl_Command * cmdObject);
    
    /**set command callback */    
    virtual int SetCommandCallback(void (* fun) (int, void*), void* clientData);

public:
    /** set domain process id */
    void SetRuntimeContext(int domainId, int graphicId);
    
    /** get domain process id */
    void GetRuntimeContext(int& domainId, int& graphicId);

protected:
    /**constructor. */
    cpl_CommandsManager15();

    /**destructor. */
    virtual ~cpl_CommandsManager15();

    //callback function
    void(*CommandExecCallback) (int, void*);
    void* CommandExecClientData;

    //hash table.
    cpl_HashTableCmdOneKey* hashCmdStringKey;
    _fbCommandCtxRuntime_s  cmdCtxRuntime; 
    
private:
    cpl_CommandsManager15(const cpl_CommandsManager15 &); // Not implemented.
    void operator = (const cpl_CommandsManager15 &); // Not implemented. 
};

#endif //CPL_COMMANDSMANAGER15_H
