#ifndef CPL_FUNCTIONPARAMETERSTACK_H
#define CPL_FUNCTIONPARAMETERSTACK_H

class cpl_FunctionParameterStack {
public:   
    /** create instance */
    static cpl_FunctionParameterStack* New();
    
    /** delete */
    void Delete() {delete this; }

    /** push open elements */
    virtual void PushOpenElement(cpl_FunctionParameter* param);
    
    /** pop  open elements */
    virtual cpl_FunctionParameter* PopOpenElement();    
    
    /** get current open element */
    virtual cpl_FunctionParameter* GetCurrentOpenElement();
    
    /** get current stack depth */
    virtual int  GetStackDepth() { return this->m_objNumberOfOpenElements; }
protected:
    //inner structure.
    struct _fbFuncStack_Item {
        cpl_FunctionParameter* parameter;
    };

    /**constructor. */
    cpl_FunctionParameterStack();

    /**destructor. */
    virtual ~cpl_FunctionParameterStack();

    /**copy constructor */
    cpl_FunctionParameterStack(const cpl_FunctionParameterStack &) { }

    /**void operator = */
    void operator = (const cpl_FunctionParameterStack &) { }

    unsigned int m_objNumberOfOpenElements;
    unsigned int m_objOpenElementsSize;      
    
    _fbFuncStack_Item* m_objOpenElements;
    _fbFuncStack_Item* m_objCurrentElement;
};

#endif //CPL_FUNCTIONPARAMETERSTACK_H
