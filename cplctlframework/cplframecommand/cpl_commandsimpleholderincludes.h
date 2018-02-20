#ifndef CPL_COMMANDSIMPLEHOLDERINCLUDES_H
#define CPL_COMMANDSIMPLEHOLDERINCLUDES_H

#ifdef WIN32
#pragma warning( push ) // memorize the warning status
#pragma warning( disable : 4305 ) // disable "initializing : truncation from 'const double' to 'float'" warning
#pragma warning( disable : 4244 ) // disable "double to float conversion possible loss of data" warning
#pragma warning( disable : 4136 ) // disable "conversion between different floating-point types" warning
#pragma warning( disable : 4309 ) // disable " 'conversion' : truncation of constant value" warning
#pragma warning( disable : 4051 ) // disable " 'type conversion' ; possible loss of data" warning
#pragma warning( disable : 4100 ) // disable  unreferenced formal parameter
#endif

//class definitions
class cpl_IFunctionCommandProxy;

//standard system includes.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
//..
#include <cplparameterengine/cpl_parameterenginedefine.h>
#include <cplparameterengine/cpl_parameterengineinterface.h>

//includes...
#include "cpl_commanddefine.h"
#include "cpl_commandsimpleinterface.h"
#include "cpl_commandsimple.h"
#include "cpl_commandsimplecommon.h"

#endif //CPL_COMMANDSIMPLEHOLDERINCLUDES_H
