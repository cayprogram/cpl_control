#include "cpl_parameterengineincludes.h"

//-----------------------------------------------------------------------------
// class cpl_ParameterEngineManager
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
cpl_ParameterEngineManager * cpl_ParameterEngineManager::New() {
    return new cpl_ParameterEngineManager;
}

//-----------------------------------------------------------------------------
void cpl_ParameterEngineManager::Delete() {
    delete this;
}

//-----------------------------------------------------------------------------
cpl_ParameterEngineManager::cpl_ParameterEngineManager(){
    this->inPE = new cpl_ParameterEngine;
    this->outPE = new cpl_ParameterEngine;
}

//-----------------------------------------------------------------------------
cpl_ParameterEngineManager::~cpl_ParameterEngineManager(){
    delete this->inPE;
    delete this->outPE;
}
