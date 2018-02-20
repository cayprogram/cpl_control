#ifndef CPL_FUNCTIONCOLLECTION_H
#define CPL_FUNCTIONCOLLECTION_H

class cpl_HashTableFuncOneKey;
class cpl_FunctionCollection  {
public:    
    /**insert command. */
    virtual int InsertFunction(cpl_Function * funcObject);

    /** find command */
    virtual int FindFunction(char* string, cpl_Function * & funcObject);

    /** is valid command */
    virtual int IsFunctionExist(char* string);

public:
    /** init traversal hash table*/
    int InitTraversal();

    /** get first node in hash table*/
    int GetFirstItem(cpl_Function *& objFunc);

    /** get hash table node */
    int GetNextItem(cpl_Function *& objFunc);

public:
    /**constructor. */
    cpl_FunctionCollection();

    /**destructor. */    
    virtual ~cpl_FunctionCollection();

protected:
    cpl_HashTableFuncOneKey * hashFuncStringKey;
};

#endif //CPL_FUNCTIONCOLLECTION_H
