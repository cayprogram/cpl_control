#ifndef CPL_FUNCTIONPROCESS15_H
#define CPL_FUNCTIONPROCESS15_H

class cpl_HashTableFuncOneKey;
class cpl_FunctionProcess15 : public cpl_FunctionProcess10 {
public:    
    /**insert command. */
    virtual int InsertFunction(cpl_Function * funcObject);

    /** find command */
    virtual int FindFunction(char* string, cpl_Function * & funcObject);

    /** is function context valid */
    virtual int IsContextValid(char* string);

    /**execute */
    virtual int ExecuteFunction(char* string);

    /** is valid command */
    virtual int IsFunctionExist(char* string);

    /** init traversal */
    virtual int InitTraversal();

    /** get first hash table node */
    virtual int GetFirstItemDetail(cpl_Function * & funcObject);

    /** get next hash table node */
    virtual int GetNextItemDetail(cpl_Function * & funcObject);

protected:
    /**constructor. */
    cpl_FunctionProcess15();

    /**destructor. */    
    virtual ~cpl_FunctionProcess15();

protected:
    cpl_HashTableFuncOneKey * hashFuncStringKey;
    
private:
    cpl_FunctionProcess15(const cpl_FunctionProcess15 &); // Not implemented.
    void operator = (const cpl_FunctionProcess15 &); // Not implemented. 
};

#endif //CPL_FUNCTIONPROCESS15_H
