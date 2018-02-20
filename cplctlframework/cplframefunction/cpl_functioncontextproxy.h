#ifndef CPL_FUNCTIONCONTEXTPROXY_H
#define CPL_FUNCTIONCONTEXTPROXY_H

class cpl_FunctionContextProxy {
public:
    /** set function key string */
    void SetFunctionKeyString(char* funString);

    /** get function key string */
    char* GetFunctionKeyString();

public:
    /**constructor. */
    cpl_FunctionContextProxy();

    /**destructor. */
    virtual ~cpl_FunctionContextProxy();

protected:
    //protected variables.
    struct FUNCONTEXTDAT {
        char* keyString;
    };

    FUNCONTEXTDAT funcContextData;
};

#endif //CPL_FUNCTIONCONTEXTPROXY_H
