#include "cpl_functionframeincludes.h"

//----------------------------------------------------------
void cpl_StylerFunctionWindow::SetFuncWindowHandler(void* winHandler) {
    //@@preconditions
    assert(winHandler != NULL);
    //@@end preconditions
    
    this->funcWinHandler = winHandler;         
}

//----------------------------------------------------------
void* cpl_StylerFunctionWindow::GetFuncWindowHandler() {
    return this->funcWinHandler;
}

//----------------------------------------------------------
void cpl_StylerFunctionWindow::SetToolWindowHandler(void* winHandler) {
    //@@preconditions
    assert(winHandler != NULL);
    //@@end preconditions
    
    this->toolWinHandler = winHandler;         
}

//----------------------------------------------------------
void* cpl_StylerFunctionWindow::GetToolWindowHandler() {
    return this->toolWinHandler;
}

//----------------------------------------------------------
cpl_StylerFunctionWindow::cpl_StylerFunctionWindow() {
    this->funcWinHandler = NULL;
    this->toolWinHandler = NULL;
}

//----------------------------------------------------------
cpl_StylerFunctionWindow::~cpl_StylerFunctionWindow() {
    this->funcWinHandler = NULL;
    this->toolWinHandler = NULL;
}
