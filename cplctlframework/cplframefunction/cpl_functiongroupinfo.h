#ifndef CPL_FUNCTIONGROUPINFO_H
#define CPL_FUNCTIONGROUPINFO_H

class cpl_FunctionGroupInfo {
public:
    /** allocate. */
    virtual int Allocate(int sz, int ext);

    /** add function */
    virtual int InsertNextItem(const char* funcName);

    /** add function */
    virtual int InsertNextItem(const char* funcName, int group);
    
    /** remove function item */
    virtual int RemoveItem(const char* funcName);
    
    /** remove all */
    virtual int RemoveAllItems();
    
    /** get group info */
    virtual int GetGroupInfo(const char* funcName);

    /** get number of item */
    virtual int GetFunctionNumber();

    /** get group info */
    virtual const char* GetFuncName(int index);

    /** deep copy */
    virtual cpl_FunctionGroupInfo* DeepCopy();

public:
    //inner structure
    struct _fbFuncItem_s {
        char funcid[64];
        int  group;
    };
     
    //resize array
    _fbFuncItem_s* Resize(int size);

    //insert at the specific position.
    void InsertItem(int pos, const char* textid, int group);

    //constructor.
    cpl_FunctionGroupInfo();

    //destructor
    virtual ~cpl_FunctionGroupInfo();

    //protected variables
    _fbFuncItem_s* Array;
    int Size;
    int MaxId;
    int Extend;
};

#endif //CPL_FUNCTIONGROUPINFO_H
