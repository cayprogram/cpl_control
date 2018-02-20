#ifndef CPL_FUNCTIONSERIALDATA_H
#define CPL_FUNCTIONSERIALDATA_H

class cpl_FunctionSerialData {
public:
    /** create instance */
    static cpl_FunctionSerialData* New();

    /** delete */
    void Delete();

public:
    /** do allocate */
    void Allocate(int sz, int ext);

    /** do reset */
    void Reset();

public:
    /** get function serial data number */
    int   GetFuncSerialDataNumber();

    /** insert next function serial data */
    int   InsertNextFuncSerialData(char* datName, char* datVal);

public:
    /** set function serial data name*/
    void  SetFuncSerialDataName(int datid, char* datName);

    /** get function serial data name*/
    char* GetFuncSerialDataName(int datid);

    /** set function serial data value */
    void  SetFuncSerialDataValue(int datid, char* datVal);

    /** get function serial data parameter */
    char* GetFuncSerialDataValue(int datid);

protected:
    //resize.
    void Resize(int newSz);

    //delete all.
    void ClearAll();

protected:
    /** constructor. */
    cpl_FunctionSerialData();

    /** destructor. */
    virtual ~cpl_FunctionSerialData();

    //protected variables
    char** serialDatName;
    char** serialDatVal;
    int serialDatSize;
    int serialDatMaxId;
    int serialDatExt;
};

#endif //CPL_FUNCTIONSERIALDATA_H
