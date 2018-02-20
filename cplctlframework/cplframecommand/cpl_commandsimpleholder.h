#ifndef CPL_COMMANDSIMPLEHOLDER_H
#define CPL_COMMANDSIMPLEHOLDER_H

class cpl_ICommand;
class cpl_CommandSimple;
class cpl_CommandSimpleHolder : public cpl_Command {
public:    
    //create instance.
    static cpl_CommandSimpleHolder* New(cpl_ICommandSimple* func);

public:
    /** check parameter */
    virtual int CheckInputParameter();
    virtual int CheckOutputParameter();
    virtual int ReadInputParameter();
    virtual int WriteOutputParameter();

    /** get string cmd */
    virtual const char* GetStringId();

    /** execute .. */
    virtual void ExecuteDirect();

    /** set command handler */
    virtual void SetCommandHandler(const char* stringId, void* commandHandler);

public:
    /** deep copy */
    virtual cpl_CommandSimpleHolder* DeepCopy();

public:    
    /** constructor. */
    cpl_CommandSimpleHolder(cpl_ICommandSimple* pCmd);

    /** destructor. */
    virtual ~cpl_CommandSimpleHolder();

    //protected variables.
    cpl_ICommandSimple* pCmd;
};

#endif //CPL_COMMANDSIMPLEHOLDER_H
