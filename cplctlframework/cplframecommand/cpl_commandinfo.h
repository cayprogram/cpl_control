#ifndef CPL_COMMANDINFO_H
#define CPL_COMMANDINFO_H

class cpl_CommandInfo {
public:
    /** allocate. */
    virtual int Allocate(int sz, int ext);

    /** add command path */
    virtual int InsertNextItem(const char* c1);
    
    /** remove command item */
    virtual int RemoveItem(const char* c1);
    
    /** remove all */
    virtual int RemoveAllItems();
    
    /** get number of item */
    virtual int GetNumber();

    /** get group info */
    virtual int GetItem(int index, const char*& c1);

    /** deep copy */
    virtual cpl_CommandInfo* DeepCopy();

public:
    //inner structure
    struct _fbItem_s {
        char c1[64];
        char c2[64];
    };
     
    //resize array
    _fbItem_s* Resize(int size);

    //insert at the specific position.
    void InsertItem(int pos, const char* c1);

    //constructor.
    cpl_CommandInfo();

    //destructor
    virtual ~cpl_CommandInfo();

    //protected variables
    _fbItem_s* Array;
    int Size;
    int MaxId;
    int Extend;
};

#endif //CPL_COMMANDINFO_H
