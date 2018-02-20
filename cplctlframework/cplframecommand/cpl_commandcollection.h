#ifndef CPL_COMMANDCOLLECTION_H
#define CPL_COMMANDCOLLECTION_H

class cpl_HashTableCmdOneKey;
class cpl_CommandCollection  {
public:    
    /**insert command. */
    virtual int InsertCommand(cpl_Command * funcObject);

    /** find command */
    virtual int FindCommand(char* string, cpl_Command * & funcObject);

    /** is valid command */
    virtual int IsCommandExist(char* string);

public:
    /**constructor. */
    cpl_CommandCollection();

    /**destructor. */    
    virtual ~cpl_CommandCollection();

protected:
    cpl_HashTableCmdOneKey * hashCmdStringKey;
};

#endif //CPL_COMMANDCOLLECTION_H
