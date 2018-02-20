#ifndef CPL_FUNCTIONWINDOWSTACK_H
#define CPL_FUNCTIONWINDOWSTACK_H

/** @stereotype container */
class cpl_StylerFunctionStack {

public:
    /** push open elements */
    virtual void PushOpenElement(cpl_StylerFunction* element);

    /** pop  open elements */
    virtual cpl_StylerFunction* PopOpenElement();    

    /** get current open element */
    virtual cpl_StylerFunction* GetCurrentOpenElement();

    /** is function on stack */
    virtual int IsFunctionOnStack(cpl_StylerFunction* func);

public:
    /** get number of elements */ 
    virtual int GetNumberOfElements();

    /** get ith item */
    virtual cpl_StylerFunction* GetElement(int ith);

public:
    //constructor
    cpl_StylerFunctionStack();
    
    //destructor
    virtual ~cpl_StylerFunctionStack();

protected:
    //inner structure.
    struct _fbWindowFunction_Item {
        cpl_StylerFunction* winfunc;
    };
    
    unsigned int m_objNumberOfOpenElements;
    unsigned int m_objOpenElementsSize;      

    _fbWindowFunction_Item* m_objOpenElements;
    _fbWindowFunction_Item* m_objCurrentElement;
};

#endif //CPL_FUNCTIONWINDOWSTACK_H
