#ifndef CPL_FUNCTIONPROCESSARRAY_H
#define CPL_FUNCTIONPROCESSARRAY_H

class cpl_FunctionProcessArray : public cpl_CtlObjectArray {
public:
    /** create function */
    static cpl_FunctionProcessArray* New();

public:
    /** operator: insert the specific function stack.*/
    int InsertNextFunctionProcess(cpl_FunctionProcess* funcProcess);
    
    /** operator: remove the specific function stack.*/
    int RemoveFunctionProcess(cpl_FunctionProcess* funcProcess);
    
    /** operator: get the specific function by idx. */
    cpl_FunctionProcess* GetFunctionProcessByIndex(int idx);
    
public:    
    //constructor
    cpl_FunctionProcessArray();
    
    //destructor
    virtual ~cpl_FunctionProcessArray();
    
private:
    cpl_FunctionProcessArray(const cpl_FunctionProcessArray &); // Not implemented.
    void operator = (const cpl_FunctionProcessArray &); // Not implemented.  
};

#endif //CPL_FUNCTIONPROCESSARRAY_H
