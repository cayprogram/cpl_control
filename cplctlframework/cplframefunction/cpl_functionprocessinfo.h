#ifndef CPL_FUNCTIONPROCESSINFO_H
#define CPL_FUNCTIONPROCESSINFO_H

class cpl_FunctionProcessInfo {    
public:
    /** create instance */
    static cpl_FunctionProcessInfo* New();

    /** delete instance */
    void Delete() { delete this; }

public:
    /** set function process description */
    void  SetFunctionProcessDescription(char* processDesp);
    
    /** get function process description */
    char* GetFunctionProcessDescription();

protected:
    /**constructor. */
    cpl_FunctionProcessInfo();

    /**destructor. */
    virtual ~cpl_FunctionProcessInfo();

    //protected variables
    struct PROCESSINFODAT {
        char* processDesp;
    };

    PROCESSINFODAT processInfo; 
};

#endif //CPL_FUNCTIONPROCESSINFO_H
