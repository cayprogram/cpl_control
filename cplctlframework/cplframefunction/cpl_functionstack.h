#ifndef CPL_FUNCTIONSTACK_H
#define CPL_FUNCTIONSTACK_H

class cpl_FunctionStack : public cpl_CtlObject {
public:   
    /** create instance */
    static cpl_FunctionStack* New();

    /** push open elements */
    virtual void PushOpenElement(cpl_Function* func);
    
    /** pop  open elements */
    virtual cpl_Function* PopOpenElement();    
    
    /** get current open element */
    virtual cpl_Function* GetCurrentOpenElement();
    
protected:
    //inner structure.
    struct _fbFuncStack_Item {
        cpl_Function* func;
    };

    /**constructor. */
    cpl_FunctionStack();

    /**destructor. */
    virtual ~cpl_FunctionStack();

    /**copy constructor */
    cpl_FunctionStack(const cpl_FunctionStack &) { }

    /**void operator = */
    void operator = (const cpl_FunctionStack &) { }

    unsigned int m_objNumberOfOpenElements;
    unsigned int m_objOpenElementsSize;      
    
    _fbFuncStack_Item* m_objOpenElements;
    _fbFuncStack_Item* m_objCurrentElement;
};

#endif //CPL_FUNCTIONSTACK_H
