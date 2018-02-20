#ifndef CPL_COMMANDLINKINFO_H
#define CPL_COMMANDLINKINFO_H

class cpl_CommandLinkInfo {
public:
    /** allocate. */
    virtual int Allocate(int sz, int ext);

    /** add command path */
    virtual int InsertNextItem(const char* c1, const char* c2);
    
    /** remove command item */
    virtual int RemoveItem(const char* c1, const char* c2);
    
    /** remove all */
    virtual int RemoveAllItems();
    
    /** get number of item */
    virtual int GetLinkNumber();

    /** get group info */
    virtual int GetLink(int index, const char*& c1, const char*& c2);

    /** deep copy */
    virtual cpl_CommandLinkInfo* DeepCopy();

public:
    //inner structure
    struct _fbLinkItem_s {
        char c1[64];
        char c2[64];
    };
     
    //resize array
    _fbLinkItem_s* Resize(int size);

    //insert at the specific position.
    void InsertItem(int pos, const char* c1, const char* c2);

    //constructor.
    cpl_CommandLinkInfo();

    //destructor
    virtual ~cpl_CommandLinkInfo();

    //protected variables
    _fbLinkItem_s* Array;
    int Size;
    int MaxId;
    int Extend;
};

#endif //CPL_COMMANDLINKINFO_H
