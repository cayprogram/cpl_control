#include <cpl_ctlcoreincludes.h>
#include "cpl_commandhandlersimpleholderincludes.h"

//-----------------------------------------------------------------------------
int cpl_CommandHandlerSimple::Release() {
    cpl_CtlObject::Delete();
    return 0;
}

//-----------------------------------------------------------------------------
cpl_CommandHandlerSimple::cpl_CommandHandlerSimple() {  
}
