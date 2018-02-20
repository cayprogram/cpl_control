#include <cpl_ctlcoreincludes.h>
#include "cpl_commandsimpleholderincludes.h"

//-----------------------------------------------------------------------------
int cpl_CommandSimple::Release() {
    cpl_CtlObject::Delete();
    return 0;
}

//-----------------------------------------------------------------------------
cpl_CommandSimple::cpl_CommandSimple() {  
}
