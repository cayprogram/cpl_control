#ifndef CPL_COMMANDSIMPLEINTERFACE_H
#define CPL_COMMANDSIMPLEINTERFACE_H

class cpl_ICommand;
class cpl_ICommandSimple : public cpl_ICommand  {
public:
    /** do command */
    virtual void ExecuteDirect() = 0;
};

#endif //CPL_COMMANDSIMPLEINTERFACE_H
