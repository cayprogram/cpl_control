#ifndef CPL_COMMANDINCLUDE_H
#define CPL_COMMANDINCLUDE_H

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
class cpl_CommandParameterProxy;
class cpl_Command;
class cpl_CommandNullInputParameter;
class cpl_CommandNullOutputParameter;
class cpl_CommandNullInputOutputParameter;
class cpl_CommandHandler;

class cpl_HashTableCmdOneKey;
class cpl_HashTableCmdHandlerOneKey;

class cpl_CommandHandler;
class cpl_CommandHandlerArray;
class cpl_CommandsManager10;
class cpl_CommandsManager15;
class cpl_CommandsManager;
class cpl_CommandsManagerObjectFactory;

//standard system includes.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <cpl_ctlcoreincludes.h>
#include "../cplparameterengine/cpl_parameterengineincludes.h"


//class includes.
#include "cpl_commandmacrodef.h"
#include "cpl_commandparameterproxy.h"
#include "cpl_command.h"
#include "cpl_commandinfo.h"
#include "cpl_commandlinkinfo.h"
#include "cpl_commandcommon.h"
#include "cpl_commandcollection.h"
#include "cpl_hashtablecommand.h"
#include "cpl_commandhandler.h"
#include "cpl_commandhandlerarray.h"
#include "cpl_hashtablecommandhandler.h"
#include "cpl_commandhandlercollection.h"
#include "cpl_commandsmanager10.h"
#include "cpl_commandsmanager15.h"
#include "cpl_commandsmanager.h"
#include "cpl_commandsmanagerobjectfactory.h"

#endif //CPL_COMMANDINCLUDE_H
