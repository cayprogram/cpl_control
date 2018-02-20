#ifndef CPL_COMMANDSMANAGEROBJECTFACTORY_H
#define CPL_COMMANDSMANAGEROBJECTFACTORY_H

/**
 * @stereotype abstract factory 
 */
class cpl_CommandsManager;
class cpl_CommandsManagerObjectFactory {
public:
    /** Create commands manager Imp.*/
    virtual cpl_CommandsManager* CreateCommandsManager() = 0;

public:
    /** create Instance */
    static cpl_CommandsManagerObjectFactory * Instance();

    /** Release */
    static void Delete();

    /** set instance. */
    static void SetFactory(cpl_CommandsManagerObjectFactory* factory);

protected:
    //constructor.
    cpl_CommandsManagerObjectFactory();

    //destructor
    virtual ~cpl_CommandsManagerObjectFactory();

private:
    // private instance
    static cpl_CommandsManagerObjectFactory * instance;
};

#endif //CPL_COMMANDSMANAGEROBJECTFACTORY_H
