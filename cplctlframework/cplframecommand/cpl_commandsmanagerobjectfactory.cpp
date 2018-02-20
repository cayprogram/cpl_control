#include "cpl_commandframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_CommandsManagerObjectFactory
//-----------------------------------------------------------------------------
//
cpl_CommandsManagerObjectFactory * cpl_CommandsManagerObjectFactory::instance = NULL;

//-----------------------------------------------------------------------------
cpl_CommandsManagerObjectFactory * cpl_CommandsManagerObjectFactory::Instance() {
    return cpl_CommandsManagerObjectFactory::instance;
}

//-----------------------------------------------------------------------------
void cpl_CommandsManagerObjectFactory::Delete() {
    if (cpl_CommandsManagerObjectFactory::instance) {
        delete cpl_CommandsManagerObjectFactory::instance;
        cpl_CommandsManagerObjectFactory::instance = NULL;
    }
}

//-----------------------------------------------------------------------------
void cpl_CommandsManagerObjectFactory::SetFactory(cpl_CommandsManagerObjectFactory* factory) {
    //@@preconditions
    assert(factory != NULL);
    //@@end preconditions

    cpl_CommandsManagerObjectFactory::instance = factory;
}

//-----------------------------------------------------------------------------
cpl_CommandsManagerObjectFactory::cpl_CommandsManagerObjectFactory() {
}

//-----------------------------------------------------------------------------
cpl_CommandsManagerObjectFactory::~cpl_CommandsManagerObjectFactory(){
}
