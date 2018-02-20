#include "cpl_parameterengineincludes.h"

//-----------------------------------------------------------------------------
//class cpl_VariantDataConverter
//-----------------------------------------------------------------------------

class cpl_VariantDataConverter {
public:
    static int IntegerToVariantData(int * idata, VariantData * vdata, int len, AtomDataTypeEnum type);
    static int VariantDataToInteger(VariantData *& vdata,  int *& idata, int &len, AtomDataTypeEnum type);

    static int FloatToVariantData(float * fdata, VariantData * vdata, int len, AtomDataTypeEnum type);
    static int VariantDataToFloat(VariantData *& vdata, float *& fdata, int &len, AtomDataTypeEnum type);

    static int StringToVariantData(char ** cdata, VariantData * vdata, int len, AtomDataTypeEnum type);
    static int VariantDataToString(VariantData *& vdata, char **& cdata, int &len, AtomDataTypeEnum type);
    
    /** void* to variant data */
    static int VoidToVariantData(void * idata, VariantData * vdata, AtomDataTypeEnum type);    
    static int VariantDataToVoid(VariantData * & vdata, void * & idata, AtomDataTypeEnum type);
    
    static int FuncToVariantData(FuncPointer* fdata, VariantData * vdata, AtomDataTypeEnum type);    
    static int VariantDataToFunc(VariantData * & vdata, FuncPointer*& fdata, AtomDataTypeEnum type);
};

//-----------------------------------------------------------------------------
int cpl_VariantDataConverter::StringToVariantData(char **  cdata, VariantData *  vdata, int len, AtomDataTypeEnum type) {
    //@@preconditions
    assert(vdata != NULL);
    assert((type == AtomSTRING)||(type == AtomSTRINGArray));    
    //@@end preconditions

    if (len > 0) {
        char **temp = new char*[len];
        int i;
        for(i=0;i<len;i++) {
            int slen = strlen(cdata[i]);
            temp[i] = new char[slen+1];
            memcpy(temp[i], cdata[i], sizeof(char)*slen);
            temp[i][slen] = '\0';
        }

        vdata->data_len = len;
        vdata->data_type = type;
        vdata->data_storage.charValue = temp;
    }
    else {
        vdata->data_len = len;
        vdata->data_type = type;
        vdata->data_storage.charValue = NULL;
    }

    return 1;
}

//-----------------------------------------------------------------------------
int cpl_VariantDataConverter::VariantDataToString(VariantData *&vdata, char **& cdata, int &len, AtomDataTypeEnum type) {
    //@@preconditions
    assert(vdata != NULL);
    assert(cdata == NULL);
    assert((vdata->data_type == AtomSTRING)||(vdata->data_type == AtomSTRINGArray));
    assert(type == vdata->data_type);
    //@@end preconditions

    cdata = vdata->data_storage.charValue;
    len = vdata->data_len;

    return 1;
}

//-----------------------------------------------------------------------------
int cpl_VariantDataConverter::FloatToVariantData( float *  fdata, VariantData *  vdata, int len, AtomDataTypeEnum type) {
    //@@preconditions
    assert(vdata != NULL);
    assert(len >= 0);
    assert((type == AtomFLOATArray) ||(type == AtomFLOAT));
    //@@end preconditions

    if (len > 0) {
        float *temp = new float[len];
        memcpy(temp, fdata, sizeof(float)*len);

        vdata->data_len = len;
        vdata->data_type = type;
        vdata->data_storage.floatValue = temp;
    }
    else {
        vdata->data_len = len;
        vdata->data_type = type;
        vdata->data_storage.floatValue = NULL;
    }    
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_VariantDataConverter::VariantDataToFloat(VariantData *& vdata, float *& fdata, int &len, AtomDataTypeEnum type) {
    //@@preconditions
    assert(vdata != NULL);
    assert(fdata == NULL);
    assert((vdata->data_type == AtomFLOAT) || (vdata->data_type == AtomFLOATArray));
    assert(type == vdata->data_type);
    //@@end preconditions

    fdata = vdata->data_storage.floatValue;
    len = vdata->data_len;

    return 1;
}

//-----------------------------------------------------------------------------
int cpl_VariantDataConverter::IntegerToVariantData( int *  idata, VariantData *  vdata, int len, AtomDataTypeEnum type) {
    //@@preconditions
    assert(vdata != NULL);
    assert(len >= 0);
    assert((type == AtomINTEGER)||(type == AtomINTEGERArray)||(type == AtomIDArray));
    //@@end preconditions

    if (len > 0) {
        int *temp = new int[len];
        memcpy(temp, idata, sizeof(int)*len);

        vdata->data_len = len;
        vdata->data_type = type;
        vdata->data_storage.intValue = temp;
    }
    else {
        vdata->data_len = len;
        vdata->data_type = type;
        vdata->data_storage.intValue = NULL;
    }
    
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_VariantDataConverter::VariantDataToInteger(VariantData *& vdata, int *& idata, int &len, AtomDataTypeEnum type) {
    //@@preconditions
    assert(vdata != NULL);
    assert(idata == NULL);
    assert((vdata->data_type == AtomINTEGER) || (vdata->data_type == AtomINTEGERArray) || (vdata->data_type == AtomIDArray));
    assert(type == vdata->data_type);
    //@@end preconditions

    idata = vdata->data_storage.intValue;
    len = vdata->data_len;

    return 1;
}

//-----------------------------------------------------------------------------
int cpl_VariantDataConverter::VoidToVariantData(void * idata, VariantData * vdata, AtomDataTypeEnum type) {
    //@@preconditions
    assert(idata != NULL);
    assert(vdata != NULL);
    assert((type == AtomVOID));
    //@@end preconditions
    
    vdata->data_type = type;
    vdata->data_storage.voidValue = idata;
    
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_VariantDataConverter::VariantDataToVoid(VariantData * & vdata, void * & idata, AtomDataTypeEnum type) {
    //@@preconditions
    assert(vdata != NULL);
    assert(idata == NULL);
    assert(vdata->data_type == AtomVOID);
    assert(type == vdata->data_type);
    //@@end preconditions
    
    idata = vdata->data_storage.voidValue;    
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_VariantDataConverter::FuncToVariantData(FuncPointer* fdata, VariantData * vdata, AtomDataTypeEnum type) {
    //@@preconditions
    assert(vdata != NULL);
    assert(fdata != NULL);
    assert((type == AtomFUNC));
    //@@end preconditions
    
    FuncPointer* temp = new FuncPointer;
    temp->funcValue = fdata->funcValue;
    
    vdata->data_type = type;
    vdata->data_storage.funcValue = temp;
    
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_VariantDataConverter::VariantDataToFunc(VariantData * & vdata, FuncPointer*& fdata, AtomDataTypeEnum type) {
    //@@preconditions
    assert(vdata != NULL);
    assert(fdata == NULL);
    assert(vdata->data_type == AtomFUNC);
    assert(type == vdata->data_type);
    //@@end preconditions
    
    fdata = vdata->data_storage.funcValue;
    
    return 1;
}


//-----------------------------------------------------------------------------
//class cpl_ParameterBuffer
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
cpl_ParameterBuffer::cpl_ParameterBuffer() {
    this->Initialize();
}

//-----------------------------------------------------------------------------
cpl_ParameterBuffer::~cpl_ParameterBuffer() {
    this->Clear();
}

//-----------------------------------------------------------------------------
int cpl_ParameterBuffer::SetParameter(int index,  void *  data, int len, AtomDataTypeEnum type) {
    //@@preconditions
    assert(type != AtomINVALID);
    assert(len >= 0);
    //@@end preconditions

    /** clear this storage if it had been used before */
    this->ClearParameterStorage(index);

    /** get the storage */
    VariantData *temp = this->GetParameterStorage(index);
    assert(temp != NULL);
    
    int result = 0; 
    switch(type) {
    case AtomIDArray:
    case AtomINTEGER:
    case AtomINTEGERArray: {
            result = cpl_VariantDataConverter::IntegerToVariantData((int *)data, temp, len, type);
        }
        break;
    case AtomFLOAT:
    case AtomFLOATArray: {
            result = cpl_VariantDataConverter::FloatToVariantData((float *)data, temp, len, type);
        }
        break;
    case AtomSTRING:
    case AtomSTRINGArray: {
            result = cpl_VariantDataConverter::StringToVariantData((char **)data, temp, len, type);
        }
        break;
    case AtomVOID: {
            result = cpl_VariantDataConverter::VoidToVariantData((void *) data, temp, type);
        }
        break;
    case AtomFUNC: {
            result = cpl_VariantDataConverter::FuncToVariantData((FuncPointer*) data, temp, type);
        }
        break;
    default: {
            assert(0);
        }
        break;
    }
    
    if (result == 1) {
        if((index+1) > this->parmNum) this->parmNum = index + 1;
    }    
    return result;
}

//-----------------------------------------------------------------------------
int cpl_ParameterBuffer::SetParameter(int index,  void *  data, int len, AtomDataTypeEnum type, char* vdecl) {
    //@@preconditions
    assert(type != AtomINVALID);
    assert(len >= 0);
    //@@end preconditions

    /** clear this storage if it had been used before */
    this->ClearParameterStorage(index);

    /** get the storage */
    VariantData *temp = this->GetParameterStorage(index);
    assert(temp != NULL);
    
    int result = 0; 
    switch(type) {
    case AtomIDArray:
    case AtomINTEGER:
    case AtomINTEGERArray: {
            result = cpl_VariantDataConverter::IntegerToVariantData((int *)data, temp, len, type);
        }
        break;
    case AtomFLOAT:
    case AtomFLOATArray: {
            result = cpl_VariantDataConverter::FloatToVariantData((float *)data, temp, len, type);
        }
        break;
    case AtomSTRING:
    case AtomSTRINGArray: {
            result = cpl_VariantDataConverter::StringToVariantData((char **)data, temp, len, type);
        }
        break;
    case AtomVOID: {
            result = cpl_VariantDataConverter::VoidToVariantData((void *) data, temp, type);
        }
        break;
    case AtomFUNC: {
            result = cpl_VariantDataConverter::FuncToVariantData((FuncPointer*) data, temp, type);
        }
        break;
    default: {
            assert(0);
        }
        break;
    }
    
    if (result == 1) {
        strcpy(temp->data_description, vdecl);
        if((index+1) > this->parmNum) this->parmNum = index + 1;
    }    
    return result;
}

//-----------------------------------------------------------------------------
int cpl_ParameterBuffer::GetParameter(int index,  void *& data, int &len, AtomDataTypeEnum type) {
    //@@preconditions
    assert(data == NULL);
    assert(index < this->parmNum);
    assert(type != AtomINVALID);
    //@@end preconditions

    VariantData *temp = this->GetParameterStorage(index);
    assert(temp != NULL);
    assert(temp->data_type == type);

    int result = 0; 

    switch(type) {
    case AtomIDArray:
    case AtomINTEGER:
    case AtomINTEGERArray: {
            result = cpl_VariantDataConverter::VariantDataToInteger(temp, (int *&)data, len, type);
        }
        break;
    case AtomFLOAT:
    case AtomFLOATArray: {
            result = cpl_VariantDataConverter::VariantDataToFloat(temp, (float *&)data, len, type);
        }
        break;
    case AtomSTRING:
    case AtomSTRINGArray:
        result = cpl_VariantDataConverter::VariantDataToString(temp, (char **&)data, len, type);
        break;
    case AtomVOID:
        result = cpl_VariantDataConverter::VariantDataToVoid(temp, (void * &) data, type);
        break;
    case AtomFUNC:
        result = cpl_VariantDataConverter::VariantDataToFunc(temp, (FuncPointer* &) data, type);
        break;
    default:
        assert(0);
        break;
    }
    return result;
}

//-----------------------------------------------------------------------------
int cpl_ParameterBuffer::GetParameter(int index,  void *& data, int &len, AtomDataTypeEnum type, char*& vdecl) {
    //@@preconditions
    assert(data == NULL);
    assert(index < this->parmNum);
    assert(type != AtomINVALID);
    //@@end preconditions

    VariantData *temp = this->GetParameterStorage(index);
    assert(temp != NULL);
    assert(temp->data_type == type);

    int result = 0; 

    switch(type) {
    case AtomIDArray:
    case AtomINTEGER:
    case AtomINTEGERArray: {
            result = cpl_VariantDataConverter::VariantDataToInteger(temp, (int *&)data, len, type);
        }
        break;
    case AtomFLOAT:
    case AtomFLOATArray: {
            result = cpl_VariantDataConverter::VariantDataToFloat(temp, (float *&)data, len, type);
        }
        break;
    case AtomSTRING:
    case AtomSTRINGArray:
        result = cpl_VariantDataConverter::VariantDataToString(temp, (char **&)data, len, type);
        break;
    case AtomVOID:
        result = cpl_VariantDataConverter::VariantDataToVoid(temp, (void * &) data, type);
        break;
    case AtomFUNC:
        result = cpl_VariantDataConverter::VariantDataToFunc(temp, (FuncPointer* &) data, type);
        break;
    default:
        assert(0);
        break;
    }
    vdecl = temp->data_description;
    return result;
}

//-----------------------------------------------------------------------------
int cpl_ParameterBuffer::CheckType(int index, AtomDataTypeEnum type) {
    //@@preconditions
    assert(index < this->parmNum);
    //@@end preconditions

    if (this->parmStorage[index].data_type == type) {
        return 1;
    }
    else {
        return 0;
    }
}

//-----------------------------------------------------------------------------
int cpl_ParameterBuffer::GetType(int index, AtomDataTypeEnum& type) {
    //@@preconditions
    assert(index < this->parmNum);
    //@@end preconditions
    
    type = this->parmStorage[index].data_type;
    return type;
}

//-----------------------------------------------------------------------------
int cpl_ParameterBuffer::SetDescription(int index, char* string) {
    //@@preconditions
    assert(string != NULL);
    assert(strlen(string) > 1);
    assert(strlen(string) < 64);
    assert(index < this->parmNum);
    //@@end preconditions

    strcpy(this->parmStorage[index].data_description, string);
    return 1;
}

//-----------------------------------------------------------------------------
int cpl_ParameterBuffer::GetDescription(int index, char*& string) {
    //@@preconditions
    assert(string == NULL);
    assert(index < this->parmNum);
    //@@end preconditions
    
    string = this->parmStorage[index].data_description;
    return (strlen(string) > 1);
}

//-----------------------------------------------------------------------------
VariantData * cpl_ParameterBuffer::GetParameterStorage(int index) {
    //@@preconditions
    assert(index < NUM_AVAILABLE_STORAGE);
    //@@end preconditions

    return &(this->parmStorage[index]);
}

//-----------------------------------------------------------------------------
void cpl_ParameterBuffer::ClearParameterStorage(int index) {
    //@@preconditions
    assert(index < NUM_AVAILABLE_STORAGE);
    //@@end preconditons
    
    switch(this->parmStorage[index].data_type) {
    case AtomIDArray:
    case AtomINTEGER:
    case AtomINTEGERArray: {
            if(this->parmStorage[index].data_storage.intValue) {
                delete[] this->parmStorage[index].data_storage.intValue;
            }
            this->parmStorage[index].data_storage.intValue = NULL;
        }
        break;
    case AtomFLOAT:
    case AtomFLOATArray: {
            if(this->parmStorage[index].data_storage.floatValue) {
                delete[] this->parmStorage[index].data_storage.floatValue;
            }
            this->parmStorage[index].data_storage.floatValue = NULL;
        }
        break;
    case AtomSTRING: 
    case AtomSTRINGArray: {
            if(this->parmStorage[index].data_storage.charValue) {
                for(int i=0;i<this->parmStorage[index].data_len;i++) {
                    delete[] this->parmStorage[index].data_storage.charValue[i];
                }
                delete[] this->parmStorage[index].data_storage.charValue;
            }
            this->parmStorage[index].data_storage.charValue = NULL;
        }
        break;
    case AtomVOID: {
            this->parmStorage[index].data_storage.voidValue = NULL;
        }
        break;
    case AtomFUNC: {
            if (this->parmStorage[index].data_storage.funcValue) {
                delete this->parmStorage[index].data_storage.funcValue;
            }
            this->parmStorage[index].data_storage.funcValue = NULL;
        }
        break;
    case AtomINVALID: {
        }
        break;
    default:
        assert(0);
        break;
    }
    this->parmStorage[index].data_type = AtomINVALID;
    this->parmStorage[index].data_len = 0;
    this->parmStorage[index].data_description[0] = '\0';        
}

//-----------------------------------------------------------------------------
int cpl_ParameterBuffer::GetNumber(int &num) {
    num = this->parmNum;
    return 1;
}

//-----------------------------------------------------------------------------
void cpl_ParameterBuffer::Clear() {
    for(int i=0;i<this->parmNum;i++) {
        this->ClearParameterStorage(i);
    }
    this->parmNum = 0;
}

//-----------------------------------------------------------------------------
void cpl_ParameterBuffer::Initialize() {
    for(int i=0;i<NUM_AVAILABLE_STORAGE;i++) {
        this->parmStorage[i].data_type = AtomINVALID;
        this->parmStorage[i].data_len = 0;
        this->parmStorage[i].data_storage.floatValue = NULL;
        this->parmStorage[i].data_storage.charValue  = NULL;
        this->parmStorage[i].data_storage.floatValue = NULL;
        this->parmStorage[i].data_storage.intValue   = NULL;
        this->parmStorage[i].data_storage.voidValue  = NULL;
        this->parmStorage[i].data_description[0] = '\0';
    }
    this->parmNum = 0;
}

//-----------------------------------------------------------------------------
void cpl_ParameterBuffer::CheckContinueStorage() {
    for(int i=0;i<this->parmNum;i++) {
        assert(this->parmStorage[i].data_type != AtomINVALID);
    }
}
