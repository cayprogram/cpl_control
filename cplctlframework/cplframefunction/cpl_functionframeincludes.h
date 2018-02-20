#ifndef CPL_FUNCTIONINCLUDE_H
#define CPL_FUNCTIONINCLUDE_H

#ifdef WIN32
#pragma warning( push ) // memorize the warning status
#pragma warning( disable : 4305 ) // disable "initializing : truncation from 'const double' to 'float'" warning
#pragma warning( disable : 4244 ) // disable "double to float conversion possible loss of data" warning
#pragma warning( disable : 4136 ) // disable "conversion between different floating-point types" warning
#pragma warning( disable : 4309 ) // disable " 'conversion' : truncation of constant value" warning
#pragma warning( disable : 4051 ) // disable " 'type conversion' ; possible loss of data" warning
#pragma warning( disable : 4100 ) // disable  unreferenced formal parameter
#endif

//-----------------------------------------------------------------------------
//function data structure
//-----------------------------------------------------------------------------
//
typedef struct {
    int dataID;
    union {
        void* p;   //some message need more info.
        int v;
    } Data;
} FUNC_DATA;

typedef struct {
    int createMode;              //process data create mode(new, attach,....)
    int processType;             //process type.
    int graphicHandle;           //graphic window Id.
    int attachProcess;           //attached function process Id.
    int applicationType;         //process data(rendersite, view, domain) application type.
    const char* domainID;        //domain ID string.
    const char* domainCommandID; //domain Command ID string
} FUNCPROCESS_CONTEXT;

//-----------------------------------------------------------------------------
//function data id macro definition.
//-----------------------------------------------------------------------------
//
#define FUNC_DATA_NULL 0
#define FUNC_DATA_INT  1

#define FUNC_SERIALDATA_MACRO   0
#define FUNC_SERIALDATA_PROJECT 1

class cpl_IFunctionDataExchange;

//class definitions
class cpl_FunctionSerialDataProxy;
class cpl_FunctionSerialDataCoder;
class cpl_FunctionSessionDataProxy;
class cpl_FunctionParameter; 
class cpl_FunctionParameterStack;
class cpl_FunctionParameterProxyInterface;
class cpl_FunctionParameterProxy;
class cpl_FunctionCommandProxy;
class cpl_FunctionContextProxy;
class cpl_Function;
class cpl_FunctionStack;

class cpl_IFunctionProcess;
class cpl_FunctionProcessInfo;
class cpl_FunctionProcess10;
class cpl_FunctionProcess15;
class cpl_FunctionProcess20;
class cpl_FunctionProcess;
class cpl_FunctionProcessArray;
class cpl_FunctionProcessManager;
class cpl_FunctionProcessParameter;
class cpl_FunctionsManager;

class cpl_HashTableFuncOneKey;

class cpl_FunctionNullInputParameter;
class cpl_FunctionNullOutputParameter;
class cpl_FunctionNullInputOutputParameter;

class cpl_FunctionExecute;
class cpl_FunctionExecuteImp;

class cpl_FunctionExecuteInvokerImp;

class cpl_StylerFunction;
class cpl_StylerFunctionProxy;
class cpl_StylerFunctionDataExchange;
class cpl_StylerFunctionStack;
class cpl_StylerFunctionFrameData;
class cpl_StylerFunctionStateMachine;
class cpl_StylerFunctionWindow;

//standard system includes.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <izzzincludes.h>
#include <cpl_ctlcoreincludes.h>

#include "../cplparameterengine/cpl_parameterengineincludes.h"
#include "../cplframecontextformatter/cpl_contextformatterincludes.h"
#include "../cplframedomain/cpl_domainframeincludes.h"
#include "../cplframeview/cpl_viewframeincludes.h"
#include "../cplframerendersite/cpl_rendersiteframeincludes.h"
#include "../cplframecommand/cpl_commandframeincludes.h"

//class includes.
#include "cpl_functioncollection.h"
#include "cpl_functiondefine.h"
#include "cpl_functiongroupinfo.h"
#include "cpl_functionserialdataproxy.h"
#include "cpl_functionserialdatacoder.h"
#include "cpl_functionsessiondataproxy.h"
#include "cpl_functionparameterproxy.h"
#include "cpl_functioncommandproxyinterface.h"
#include "cpl_functioncommandproxy.h"
#include "cpl_functioncontextproxy.h"
#include "cpl_functionexecute.h"
#include "cpl_functionexecuteinvokerimp.h"
#include "cpl_function.h"
#include "cpl_functioncommon.h"
#include "cpl_functionstyler.h"
#include "cpl_functionstylerdataexchangeinterface.h"
#include "cpl_functionstylerdataexchange.h"
#include "cpl_functionstylerwindow.h"
#include "cpl_functionstylercommon.h"
#include "cpl_functionstylerstack.h"
#include "cpl_functionstylerstatemachine.h"
#include "cpl_functionstylerproxy.h"
#include "cpl_functionstylerwrapper.h"
#include "cpl_functionstack.h"
#include "cpl_functionparameter.h"
#include "cpl_functionparameterstack.h"
#include "cpl_functionprocessinterface.h"
#include "cpl_functionprocessinfo.h"
#include "cpl_functionprocess10.h"
#include "cpl_functionprocess15.h"
#include "cpl_functionprocess20.h"
#include "cpl_functionprocess.h"
#include "cpl_functionprocessarray.h"
#include "cpl_functionprocessmanager.h"
#include "cpl_functionprocessparameter.h"
#include "cpl_functionsmanager.h"

#endif //CPL_FUNCTIONINCLUDE_H
