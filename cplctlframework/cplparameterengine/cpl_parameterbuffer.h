#ifndef CPL_PARAMETERBUFFER_H
#define CPL_PARAMETERBUFFER_H

//Const length for the Variant data dimension
#define NUM_AVAILABLE_STORAGE 300

typedef struct {
    void (*funcValue)(void * data1, void* data2);
}
FuncPointer;

typedef enum {
    AtomINVALID,
    AtomFLOAT,
    AtomFLOATArray,
    AtomINTEGER,
    AtomINTEGERArray,
    AtomSTRING,
    AtomSTRINGArray,
    AtomVOID,
    AtomFUNC,
    AtomIDArray
}AtomDataTypeEnum;

typedef union {
    int * intValue;  
    float * floatValue;  
    char ** charValue;
    void * voidValue;
    FuncPointer* funcValue;
}AtomDataValueUnion;

typedef struct {
    AtomDataTypeEnum data_type;
    int data_len;
    AtomDataValueUnion data_storage;
    char data_description[64];
}VariantData;

class cpl_ParameterBuffer {
public:
    /** Set Parameter */
    int SetParameter(int index, void * data, int len, AtomDataTypeEnum type);

    /** Get Parameter */
    int GetParameter(int index, void *& data, int &len, AtomDataTypeEnum type);

    /** Set Parameter */
    int SetParameter(int index, void * data, int len, AtomDataTypeEnum type, char* str);

    /** Get Parameter */
    int GetParameter(int index, void *& data, int &len, AtomDataTypeEnum type, char*& str);

    /** Check Parameter Type */
    int CheckType(int index, AtomDataTypeEnum type);
    
    /** get type */
    int GetType(int index, AtomDataTypeEnum& type);

    /** set Parameter description */
    int SetDescription(int index, char* str);
    
    /** get Parameter descripiton */
    int GetDescription(int index, char*& str);

    /** Return Parameter Number */
    int GetNumber(int &num);

    /** Clear Parameters */
    void Clear();

    /** Check if Parameters continued storage  */
    /** This function only used in debug      */
    /** To avoid program error                */
    void CheckContinueStorage();

public:
    /** constructor. */
    cpl_ParameterBuffer();

    /** destructor. */
    virtual ~cpl_ParameterBuffer();
    
private:
    //Get a storage of parameter */
    VariantData * GetParameterStorage(int index);

    //Clear a storage of parameter */
    void ClearParameterStorage(int index);

    //Initialize the parStorage */
    void Initialize();

    // Parameters */
    VariantData parmStorage[NUM_AVAILABLE_STORAGE];

    // How many parameters we have */
    int parmNum;
};

#endif //CPL_PARAMETERBUFFER_H
