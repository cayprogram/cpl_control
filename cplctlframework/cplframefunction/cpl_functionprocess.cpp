#include "cpl_functionframeincludes.h"

//------------------------------------------------------------------------------
// class cpl_FunctionProcess
//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void cpl_FunctionProcess::SetRenderSite(cpl_RenderSite* renderSite) {
    //@@preconditions
    assert(renderSite != NULL);
    //@@end preconditions

    this->uRenderSite = renderSite;
}

//------------------------------------------------------------------------------
cpl_RenderSite* cpl_FunctionProcess::GetRenderSite() {
    return this->uRenderSite;
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::SetWindowFunctionProxyWinHandler(void* pWinHandler) {
    //@@preconditions
    assert(this->winFunctionProxy != NULL);
    //@@end preconditions

    if (pWinHandler) {
        this->winFunctionProxy->SetFuncWindowProxyWinHandler(pWinHandler);
    }    
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::SetToolFunctionProxyWinHandler(void* pWinHandler) {
    //@@preconditions
    assert(this->winFunctionProxy != NULL);
    //@@end preconditions

    if (pWinHandler) {
        this->winFunctionProxy->SetToolWindowProxyWinHandler(pWinHandler);
    }
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcess::SetShortCutFunctionProxyWinHandler(void* pWinHandler) {
    //@@preconditions
    assert(this->winFunctionProxyShortCut != NULL);
    //@@end preconditions

    if (pWinHandler) {
        this->winFunctionProxyShortCut->SetFuncWindowProxyWinHandler(pWinHandler);
    }
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcess::SetWindowStylerCollection(IWindowStylerCollection* pCollection) {
    //@@preconditions
    //@@end preconditions
    
    this->windowStylerCollection = pCollection;
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcess::SetSessionProxy(cpl_SessionProxy* sessionProxy) {
    //@@preconditions
    //@@end preconditions
    
    this->pSessionProxy = sessionProxy;
}

//------------------------------------------------------------------------------
cpl_Function* cpl_FunctionProcess::GetCurrentFunction() {
    //@@preconditions
    assert(this->winFunctionProxy != NULL);
    //@@end preconditions
    
    if (this->functionCurrent != NULL) {
        return this->functionCurrent;
    }
    return this->winFunctionProxy->GetStylerFunction();
}

//------------------------------------------------------------------------------
cpl_Function* cpl_FunctionProcess::GetStylerFunction() {
    //@@preconditions
    assert(this->winFunctionProxy != NULL);
    //@@end preconditions
    
    return this->winFunctionProxy->GetStylerFunction();
}

//------------------------------------------------------------------------------
cpl_Function* cpl_FunctionProcess::GetStylerFunctionShortCut() {
    //@@preconditions
    assert(this->winFunctionProxyShortCut != NULL);
    //@@end preconditions

    return this->winFunctionProxyShortCut->GetStylerFunction();
}

//------------------------------------------------------------------------------
cpl_FunctionCommandProxy* cpl_FunctionProcess::GetCommandProxy() {
    //@@preconditions
    assert(this->functionCommandProxy != NULL);
    //@@end preconditions

    return this->functionCommandProxy;
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::SetStateMachine(cpl_StylerFunctionStateMachine* stateMachine) {
    //@@preconditions
    assert(stateMachine != NULL);
    assert(this->winFunctionProxy != NULL);
    assert(this->winFunctionProxyShortCut != NULL);
    //@@end preconditions

    this->stateMachine = stateMachine;    
    this->winFunctionProxy->SetStateMachine(stateMachine->DeepCopy());
    this->winFunctionProxyShortCut->SetStateMachine(stateMachine->DeepCopy());
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::SetFunctionProcessManager(cpl_FunctionProcessManager* processManager) {
    //@@preconditions
    assert(processManager != NULL);
    //@@end preconditions

    this->functionProcessManager = processManager;
}

//------------------------------------------------------------------------------
cpl_FunctionProcessManager* cpl_FunctionProcess::GetFunctionProcessManager() {
    return this->functionProcessManager;
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::SetLocalStatus(int status) {
    //@@preconditions
    //@@end preconditions
    
    this->processData.lockStatus = status;
}

//------------------------------------------------------------------------------
int  cpl_FunctionProcess::GetLocalStatus() {
    //@@postconditions
    //@@end postconditions
    
    return this->processData.lockStatus;
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::SetFunctionWindow(int fid) {
    //@@postconditions
    assert(fid >= 0);
    //@@end postconditions

    this->processData.funWinid = fid;
}

//------------------------------------------------------------------------------
int cpl_FunctionProcess::GetFunctionWindow() {
    //@@postconditions
    //@@end postconditions

    return this->processData.funWinid;
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::SetGraphicWindow(int wid) {
    //@@postconditions
    assert(wid >= 0);
    //@@end postconditions

    this->processData.graphicWid = wid;
}

//------------------------------------------------------------------------------
int cpl_FunctionProcess::GetGraphicWindow() {
    //@@postconditions
    //@@end postconditions

    return this->processData.graphicWid;
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::SetProcessId(int pId) {
    //@@preconditions
    assert(pId > 0);
    //@@end preconditions

    this->processData.processId = pId;
}

//------------------------------------------------------------------------------
int  cpl_FunctionProcess::GetProcessId() {
    //@@preconditions
    assert(this->processData.processId > 0);
    //@@end preconditions

    return this->processData.processId;
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::SetProcessName(char* pname) {
    //@@postconditions
    assert(pname != NULL);
    //@@end postconditions

    size_t slen = strlen(pname);
    assert(slen > 0 && slen < 64);
    
    strncpy(this->processData.nameText, pname, slen);
    this->processData.nameText[slen] = '\0';
}

//------------------------------------------------------------------------------
char* cpl_FunctionProcess::GetProcessName() {
    //@@postconditions
    //@@end postconditions
    
    return this->processData.nameText;
}

//-----------------------------------------------------------------------------
void cpl_FunctionProcess::SetProcessTypeName(char* tname) {
    //@@postconditions
    assert(tname != NULL);
    //@@end postconditions

    size_t slen = strlen(tname);
    assert(slen > 0 && slen < 64);
    
    strncpy(this->processData.typeText, tname, slen);
    this->processData.typeText[slen] = '\0';
}

//-----------------------------------------------------------------------------
char* cpl_FunctionProcess::GetProcessTypeName() {
    //@@postconditions
    //@@end postconditions

    return this->processData.typeText;
}

//-----------------------------------------------------------------------------
int cpl_FunctionProcess::InsertFunction(cpl_Function * funcObject) {
    //@@preconditions
    assert(funcObject != NULL);
    assert(this->functionCommandProxy != NULL);
    assert(this->functionContextProxy != NULL);
    //@@end preconditions
    
    funcObject->SetFunctionProcess(this);
    funcObject->SetCommandProxy(this->functionCommandProxy);
    funcObject->SetContextProxy(this->functionContextProxy);
    funcObject->GetFuncSerialDataProxy()->AllocateFuncSerialData(10, 10);
    
    return this->cpl_FunctionProcess15::InsertFunction(funcObject);
}

//------------------------------------------------------------------------------
int cpl_FunctionProcess::ExecuteFunctionCallback(cpl_Function* func, int mode) {
    //@@preconditions
    assert(func != NULL);
    assert(mode == 0 || mode == 1);
    assert(this->functionProcessManager != NULL);
    //@@end preconditions
    
    this->functionProcessManager->ExecuteFunctionCallback(this, func, mode);
    return 0;
}

//------------------------------------------------------------------------------
int cpl_FunctionProcess::ExecuteFunctionDirect(cpl_Function* func) {
    //@@preconditions
    assert(func != NULL);
    assert(this->functionCommandProxy != NULL);
    //@@end preconditions
    
    if (func == this->GetCurrentFunction()) {
        return 0;
    }
        
    //check styler function.
    if (func->IsSynchorizedFunction() == 0) {
        if (this->windowStylerCollection == NULL) {
            return 0;
        }

        const char* funcId = func->GetStringId();
        if (funcId[0] == '*') { //tree view function, need to deal with in different way.
            assert(this->winFunctionProxyShortCut != NULL);
            assert(this->windowStylerCollection != NULL);
            this->stateMachine->SetFunctionProxy(this->winFunctionProxyShortCut);

            cpl_StylerFunction* pStylerFunc = (cpl_StylerFunction*)func;
            assert(pStylerFunc != NULL);

            cpl_StylerFunction* pFunc = NULL;
            pFunc = (pStylerFunc->IsInlineFunction() == 0) ? pStylerFunc : (cpl_StylerFunction*)pStylerFunc->DeepCopy();
            pFunc->SetFunctionProcess(this);
            pFunc->SetCommandProxy(this->functionCommandProxy);
            pFunc->SetContextProxy(this->functionContextProxy);            
            pFunc->SetSessionProxy(this->pSessionProxy);
            if (this->winFunctionProxyShortCut->IsFunctionOnStack(pFunc) == 0) {
                pFunc->SetWindowFunctionProxy(this->winFunctionProxyShortCut);                
                pFunc->SetWindowStylerCollection(this->windowStylerCollection);
            }
            return this->cpl_FunctionProcess15::ExecuteFunctionDirect(pFunc);
        }
        else {
            assert(this->winFunctionProxy != NULL);
            assert(this->windowStylerCollection != NULL);
            this->stateMachine->SetFunctionProxy(this->winFunctionProxy);

            cpl_StylerFunction* pStylerFunc = (cpl_StylerFunction*)func;
            assert(pStylerFunc != NULL);

            cpl_StylerFunction* pFunc = NULL;
            pFunc = (pStylerFunc->IsInlineFunction() == 0) ? pStylerFunc : (cpl_StylerFunction*)pStylerFunc->DeepCopy();
            pFunc->SetFunctionProcess(this);
            pFunc->SetCommandProxy(this->functionCommandProxy);
            pFunc->SetContextProxy(this->functionContextProxy);
            pFunc->SetSessionProxy(this->pSessionProxy);

            if (this->winFunctionProxy->IsFunctionOnStack(pFunc) == 0) {
                pFunc->SetWindowFunctionProxy(this->winFunctionProxy); 
                const char* winType = pFunc->GetAttachWindowType();
                if (winType != NULL) {
                    IWindowStyler* pStyler = this->windowStylerCollection->CreateWindowStyler((char*)winType);
                    assert(pStyler != NULL);

                    pFunc->SetWindowStyler(pStyler);
                    pFunc->SetWindowStylerCollection(this->windowStylerCollection);
                }           
            }
            return this->cpl_FunctionProcess15::ExecuteFunctionDirect(pFunc);
        }
    }
    else {
        //link command proxy
        func->SetCommandProxy(this->functionCommandProxy);
        func->SetContextProxy(this->functionContextProxy);

        this->functionProcessManager->ExecuteFunctionCallback(this, func, 0);
        int ret = this->cpl_FunctionProcess15::ExecuteFunctionDirect(func);
        this->functionProcessManager->ExecuteFunctionCallback(this, func, 1);
        return ret;
    }    
}

//------------------------------------------------------------------------------
int cpl_FunctionProcess::OnCommandExecuted(int commandId, cpl_Function* func, cpl_StylerFunctionProxy* proxy) {
    return 0;
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::StopProcess() {
    if (this->winFunctionProxy != NULL) {
        this->winFunctionProxy->StopFunction();
    }
    if (this->winFunctionProxyShortCut != NULL) {
        this->winFunctionProxyShortCut->StopFunction();
    }
}

//------------------------------------------------------------------------------
void cpl_FunctionProcess::SynchronizeFunctionOnStack() {
    if (this->winFunctionProxy != NULL) {
        this->winFunctionProxy->SynchronizeFunctionOnStack();
    }
    if (this->winFunctionProxyShortCut != NULL) {
        this->winFunctionProxyShortCut->SynchronizeFunctionOnStack();
    }
}

//-----------------------------------------------------------------------------
char* cpl_FunctionProcess::GetDomainId() {
    //@@preconditions
    //@@end preconditions

    cpl_RenderSite* pSite = this->GetRenderSite();
    assert(pSite != NULL);

    cpl_DataDomain* pDomain = pSite->GetDomain();
    assert(pDomain != NULL);

    cpl_DomainData* pDomainData = NULL;
    pDomain->GetDomainData(pDomainData);
    assert(pDomainData != NULL);

    return (char*)pDomainData->GetDomainDataID();
}

//------------------------------------------------------------------------------
cpl_FunctionProcess::cpl_FunctionProcess() {
    this->stateMachine                  = NULL;
    this->uRenderSite                   = NULL;
    this->windowStylerCollection        = NULL;
    this->functionProcessManager        = NULL;
    this->winFunctionProxy              = new cpl_StylerFunctionProxy;
    this->winFunctionProxyShortCut      = new cpl_StylerFunctionProxy;
    this->functionCommandProxy          = new cpl_FunctionCommandProxy(this);
    this->functionContextProxy          = new cpl_FunctionContextProxy;
    this->processData.lockStatus        = FUNC_CONTEXT_NODATABASE;
    this->processData.nameText[0]       = '\0';
    this->processData.typeText[0]       = '\0';
    this->processData.processId         = 0;
    this->processData.funWinid          = -1;
    this->processData.graphicWid        = -1;
    this->processData.processInfo       = cpl_FunctionProcessInfo::New();
}

//------------------------------------------------------------------------------
cpl_FunctionProcess::~cpl_FunctionProcess() {
    if (this->stateMachine != NULL) {
        delete this->stateMachine;
        this->stateMachine = NULL;            
    }
    if (this->winFunctionProxy != NULL) {
        delete this->winFunctionProxy;
        this->winFunctionProxy = NULL;
    }
    if (this->winFunctionProxyShortCut != NULL) {
        delete this->winFunctionProxyShortCut;
        this->winFunctionProxyShortCut = NULL;
    }
    if (this->functionCommandProxy != NULL) {
        delete this->functionCommandProxy;
        this->functionCommandProxy = NULL;
    }
    if (this->functionContextProxy != NULL) {
        delete this->functionContextProxy;
        this->functionContextProxy = NULL;
    }
    if (this->processData.processInfo != NULL) {
        this->processData.processInfo->Delete();
        this->processData.processInfo = NULL;
    }
}
