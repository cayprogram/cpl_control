#ifndef CPL_COMMANDSIMPLE_H
#define CPL_COMMANDSIMPLE_H

class cpl_ICommand;
class cpl_CommandSimple : public cpl_ICommandSimple, public cpl_CtlObject  {
public:    
    cpl_CtlTypeRevisionMacro(cpl_CommandSimple, cpl_CtlObject);

    /** release */
    virtual int Release();
public:
    /** do command */
    virtual void ExecuteDirect() {};

public:
    /** check parameter */
    virtual int CheckInputParameter (IParameterEngineCheckRight *check) { return 1; };
    virtual int CheckOutputParameter(IParameterEngineCheckRight *check) { return 1; };
    virtual int ReadInputParameter  (IParameterEngineReadRight  *read ) { return 1; };
    virtual int WriteOutputParameter(IParameterEngineWriteRight *write) { return 1; };

public:    
    /** constructor. */
    cpl_CommandSimple();
        
    /** destructor. */
    virtual ~cpl_CommandSimple() {}
};

#endif //CPL_COMMANDSIMPLE_H
