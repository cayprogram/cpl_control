#ifndef CPL_PARAMETERENGINEINCLUDE_H
#define CPL_PARAMETERENGINEINCLUDE_H

#ifdef WIN32
#pragma warning( push ) // memorize the warning status
#pragma warning( disable : 4305 ) // disable "initializing : truncation from 'const double' to 'float'" warning
#pragma warning( disable : 4244 ) // disable "double to float conversion possible loss of data" warning
#pragma warning( disable : 4136 ) // disable "conversion between different floating-point types" warning
#pragma warning( disable : 4309 ) // disable " 'conversion' : truncation of constant value" warning
#pragma warning( disable : 4051 ) // disable " 'type conversion' ; possible loss of data" warning
#pragma warning( disable : 4100 ) // disable  unreferenced formal parameter
#pragma warning( disable : 4514 ) // disable  unreferenced formal parameter
#endif

//
//----includes------------------------------------
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "cpl_parameterenginedefine.h"
#include "cpl_parameteriointerface.h"
#include "cpl_parameterengineinterface.h"
#include "cpl_parameterbuffer.h"
#include "cpl_parameterengine.h"
#include "cpl_parameterenginemanager.h"

#endif //CPL_PARAMETERENGINEINCLUDE_H

