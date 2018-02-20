#ifndef CPL_FUNCTIONDEFINEINCLUDE_H
#define CPL_FUNCTIONDEFINEINCLUDE_H

#ifdef WIN32
#pragma warning( push ) // memorize the warning status
#pragma warning( disable : 4305 ) // disable "initializing : truncation from 'const double' to 'float'" warning
#pragma warning( disable : 4244 ) // disable "double to float conversion possible loss of data" warning
#pragma warning( disable : 4136 ) // disable "conversion between different floating-point types" warning
#pragma warning( disable : 4309 ) // disable " 'conversion' : truncation of constant value" warning
#pragma warning( disable : 4051 ) // disable " 'type conversion' ; possible loss of data" warning
#pragma warning( disable : 4100 ) // disable  unreferenced formal parameter
#pragma warning( disable : 4169 ) // disable  unreferenced formal parameter
#endif

//check function.
typedef void (*PFUNC) (void*);

//..
#define FUNC_WINNAME(name) #name

//-----------------------------------------------------------------------------
//function data structure
//-----------------------------------------------------------------------------
//
typedef struct {
    int  id;                     //id
    int  async;                  //sync function or async function.
    int  record;                 //record
    int  refresh;                //refresh gui.
    char strid[64];              //display id.
    char description[64];        //description info.
} FUNC_COMMAND_DATA;

//-----------------------------------------------------------------------------
//function embed macro definition.
//-----------------------------------------------------------------------------
//
#define FUNC_CLASS(thisClass) \
public: \
    /** create instance */ \
    static thisClass * New() { return new thisClass; } \
    /** deep copy */ \
    virtual thisClass* DeepCopy() { return thisClass::New(); }; 

#define FUNC_COMMAND_MAP_BEG(thisClass) \
    static FUNC_COMMAND_DATA * GetFuncCommandDataMap_##thisClass() \
    {\
	    static FUNC_COMMAND_DATA pCmdDataMap[] = \
	    {

#define FUNC_COMMAND_ENTRY(commandId) \
        {commandId, 0, 1, 1, #commandId, #commandId},

#define FUNC_COMMAND_ENTRY_NORECORD(commandId) \
        {commandId, 0, 0, 0, #commandId, #commandId},

#define FUNC_COMMAND_ENTRY_NOREFRESH(commandId) \
        {commandId, 0, 1, 0, #commandId, #commandId},

#define FUNC_COMMAND_ENTRY_NOREFRESH_ASYNC(commandId) \
        {commandId, 1, 1, 0, #commandId, #commandId},

#define FUNC_COMMAND_MAP_END() \
			{0, 0, 0, 0, "", ""} \
		}; \
		return pCmdDataMap; \
	} 

#define FUNC_COMMAND_MAP_DEL(thisClass, superclass) \
public: \
    virtual int IsAsyncCommand(int id); \
    virtual int GetCommandNameFromID(int id, const char*& name); \
    virtual int GetCommandIDFromName(const char* name, int& id); \
    virtual int GetCommandNeedRecord(int id); \
    virtual int GetCommandNeedRefreshGUI(int id);

#define FUNC_COMMAND_MAP_IMP(thisClass, superclass) \
    typedef superclass Superclass; \
    int thisClass::IsAsyncCommand(int id) { \
        FUNC_COMMAND_DATA* map = GetFuncCommandDataMap_##thisClass(); \
        assert(map != NULL); \
        for (int i = 0; strlen(map[i].strid) > 1; ++i) { \
            if (map[i].id == id) { \
                return map[i].async; \
            } \
        } \
        return superclass::IsAsyncCommand(id); \
    } \
    int thisClass::GetCommandNameFromID(int id, const char*& stringID) { \
        FUNC_COMMAND_DATA* map = GetFuncCommandDataMap_##thisClass(); \
        assert(map != NULL); \
        for (int i = 0; strlen(map[i].strid) > 1; ++i) { \
            if (map[i].id == id) { \
                stringID = map[i].strid; \
                return 1; \
            } \
        } \
        return superclass::GetCommandNameFromID(id, stringID); \
    } \
    int thisClass::GetCommandIDFromName(const char* stringID, int& id) { \
        FUNC_COMMAND_DATA* map = GetFuncCommandDataMap_##thisClass(); \
        assert(map != NULL); \
        for (int i = 0; strlen(map[i].strid) > 1; ++i) { \
            if (strcmp(map[i].strid, stringID) == 0) { \
                id = map[i].id; \
                return 1; \
            } \
        } \
        return superclass::GetCommandIDFromName(stringID, id); \
    } \
    int thisClass::GetCommandNeedRecord(int id) { \
        FUNC_COMMAND_DATA* map = GetFuncCommandDataMap_##thisClass(); \
        assert(map != NULL); \
        for (int i = 0; strlen(map[i].strid) > 1; ++i) { \
            if (map[i].id == id) { \
                return map[i].record; \
            } \
        } \
        return superclass::GetCommandNeedRecord(id); \
    } \
    int thisClass::GetCommandNeedRefreshGUI(int id) { \
        FUNC_COMMAND_DATA* map = GetFuncCommandDataMap_##thisClass(); \
        assert(map != NULL); \
        for (int i = 0; strlen(map[i].strid) > 1; ++i) { \
            if (map[i].id == id) { \
                return map[i].refresh; \
            } \
        } \
        return superclass::GetCommandNeedRefreshGUI(id); \
    } 

#endif //CPL_FUNCTIONDEFINEINCLUDE_H
