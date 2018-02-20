#ifndef CPL_FUNCTIONSPARAMETER_H
#define CPL_FUNCTIONSPARAMETER_H

class cpl_FunctionParameter {
public:    
    /** create instance */
    static cpl_FunctionParameter* New();

    /** delete */
    void Delete() {delete this; }

    /** get parameter proxy */
    cpl_FunctionParameterProxy* GetParamProxy() { return this->m_objElements.paramProxy; }

    /** get parameter engine */
    cpl_ParameterEngineManager* GetParamEngine() { return this->m_objElements.paramMan; }

protected:
    //inner structure.
    struct _fbParam_Item {
        cpl_ParameterEngineManager* paramMan;
        cpl_FunctionParameterProxy* paramProxy;
    };

    /**constructor. */
    cpl_FunctionParameter();

    /**destructor. */
    virtual ~cpl_FunctionParameter();
       
    _fbParam_Item m_objElements;
};

#endif //CPL_FUNCTIONSPARAMETER_H
