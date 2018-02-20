#ifndef CPL_COMMANDHANDLERARRAY_H
#define CPL_COMMANDHANDLERARRAY_H

class cpl_CommandHandlerArray : public cpl_CtlObjectArray {
public:
    /** create instance */
    static cpl_CommandHandlerArray* New();

public:
    /** insert command handler */
    int RegisterCommandHandler(cpl_CommandHandler* cmdHandler);
    
protected:
    /** constructor. */
    cpl_CommandHandlerArray() {}
    
    /** destructor. */
    virtual ~cpl_CommandHandlerArray() {}
    
private:
    cpl_CommandHandlerArray(const cpl_CommandHandlerArray &); // Not implemented.
    void operator = (const cpl_CommandHandlerArray &); // Not implemented. 
};

#endif //CPL_COMMANDHANDLERARRAY_H
