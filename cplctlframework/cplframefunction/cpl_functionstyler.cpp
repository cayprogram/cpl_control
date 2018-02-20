#include "cpl_functionframeincludes.h"
#include "cpl_functionstylerexecute.h"
#include "cpl_functionsessiondataproxy.h"

//-----------------------------------------------------------------------------
//macro definitions.
//-----------------------------------------------------------------------------
//
#define CMD_EXIT      -1  //match with FUNC_CMD_EXIT
#define CMD_CTXREADY  -3  //match with FUNC_CMD_CTXREADY
//-----------------------------------------------------------------------------
//macro mapping tables.
//-----------------------------------------------------------------------------
//
FUNC_COMMAND_MAP_BEG(cpl_StylerFunction)
FUNC_COMMAND_ENTRY_NOREFRESH(CMD_EXIT)
FUNC_COMMAND_ENTRY_NORECORD(CMD_CTXREADY)
FUNC_COMMAND_ENTRY_NORECORD(FUNC_CMD_UPDATE)
FUNC_COMMAND_ENTRY_NORECORD(FUNC_CMD_ACTIVE)
FUNC_COMMAND_ENTRY_NORECORD(FUNC_CMD_SYNC)
FUNC_COMMAND_ENTRY_NORECORD(FUNC_CMD_ENDRESTORE)
FUNC_COMMAND_MAP_END()

//-----------------------------------------------------------------------------
//@!!!don't change this code.
//-----------------------------------------------------------------------------
FUNC_COMMAND_MAP_IMP(cpl_StylerFunction,cpl_Function);

//-----------------------------------------------------------------------------
// class cpl_StylerFunction
//-----------------------------------------------------------------------------
//
void cpl_StylerFunction::DoInitialization() {
    //@@preconditions
    assert(this->winProxy != NULL);
    assert(this->pDataExchange == NULL);
    assert(this->ExecuteImp != NULL);
    //@@end preconditions
        
    this->functionData.process->ExecuteFunctionCallback(this, 0);
    
    this->pDataExchange = new cpl_StylerFunctionDataExchange;
    assert(this->pDataExchange != NULL);

    this->ExecuteImp->SetDataExchange(this->pDataExchange->GetFunctionParameter());

    //initialize window styler.
    if (this->windowStyler != NULL) {
        this->windowStyler->DoInitialization();
    }
    
    this->funcStatus = FUNC_STATUS_RUNNING;
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::DoCleanup() {
    //@@preconditions
    assert(this->winProxy != NULL);
    assert(this->pDataExchange != NULL);
    assert(this->windowStylerCollection != NULL);
    //@@end preconditions
    
    //shutdown window styler
    if (this->windowStyler != NULL) {
        this->windowStyler->DoCleanup();
    }
    this->funcStatus = FUNC_STATUS_UNKNOWN;

    delete this->pDataExchange;
    this->pDataExchange = NULL;
    this->ExecuteImp->SetDataExchange(NULL);

    //remove window styler.    
    if (this->windowStyler != NULL) {
        this->windowStylerCollection->RemoveWindowStyler(this->windowStyler);
    }

    //execute callback.
    this->functionData.process->ExecuteFunctionCallback(this, 1);
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::Suspend() {
    //@@preconditions
    assert(this->winProxy != NULL);
    //@@end preconditions

    this->funcStatus = FUNC_STATUS_SUSPEND;

    //!!! don't delete this code.
    if (this->windowStyler != NULL) {
        this->windowStyler->Suspend();
    }
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::Resume()  {
    //@@preconditions
    assert(cpl_StylerFunction::winProxy != NULL);
    //@@end preconditions
    
    //short cut.
    this->funcStatus = FUNC_STATUS_RUNNING;

    //!!! don't delete this code.
    if (this->windowStyler != NULL) {
        this->windowStyler->Resume();
    }
}

//-----------------------------------------------------------------------------
int cpl_StylerFunction::CanSuspend() {
    //@@preconditions
    assert(cpl_StylerFunction::winProxy != NULL);
    //@@end preconditions

    return 1;
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::Interrupt() {
    //@@preconditions
    assert(this->winProxy != NULL);
    //@@end preconditions
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::ExecuteDirect() {
    this->exeFuncStatus = 1;
    this->winProxy->EnterWindowFunction(this);  
    this->exeFuncStatus = 0;
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::UpdateShortCutMenu() {
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::UpdateShortCutMenuDirect() {

}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::SetWindowStylerCollection(IWindowStylerCollection* stylerCollection) {
    //@@preconditions
    assert(stylerCollection != NULL);
    //@@end preconditions

    this->windowStylerCollection = stylerCollection; 
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::SetSessionProxy(cpl_SessionProxy* sessionProxy) {
    //@@preconditions
    //@@end preconditions
    
    this->pSessionProxy = sessionProxy;
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::SetWindowFunctionProxy(cpl_StylerFunctionProxy* proxy) {
    //@@preconditions
    assert(proxy != NULL);
    //@@end postconditions
    
    this->winProxy = proxy;
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionProxy* cpl_StylerFunction::GetWindowFunctionProxy() {
    return this->winProxy;
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::SetWindowStyler(IWindowStyler* styler) {
    //@@preconditions
    assert(styler != NULL);
    //@@end preconditions

    this->windowStyler = styler;    
    this->windowStyler->SetFunctionExecute(this->GetFunctionExecuteImp());
}

//-----------------------------------------------------------------------------
IWindowStyler* cpl_StylerFunction::GetWindowStyler() {
     return this->windowStyler;
}

//-----------------------------------------------------------------------------
IWindow* cpl_StylerFunction::GetAttachWindow() {
    //@@preconditions
    assert(this->windowStyler != NULL);
    //@@end preconditions

    return this->windowStyler->GetWindowImp();
}

//-----------------------------------------------------------------------------
cpl_FunctionExecuteInvokerImp* cpl_StylerFunction::GetFunctionExecuteImp() {
    //@@preconditions
    assert(this->ExecuteImpInvoker != NULL);
    //@@end preconditions

    return this->ExecuteImpInvoker;
}

//-----------------------------------------------------------------------------
cpl_StylerFunctionDataExchange* cpl_StylerFunction::GetFunctionDataExchange() {
    //@@preconditions
    assert(this->pDataExchange != NULL);
    //@@end preconditions

    return this->pDataExchange;
}

//-----------------------------------------------------------------------------
const int cpl_StylerFunction::GetInlineFunctionCode() {
    return this->InlineCode;
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::SetInlineFunctionCode(int code) {
    //@@preconditions
    assert(code >= 0);
    //@@end preconditions

    this->InlineCode = code;
}

//-----------------------------------------------------------------------------
int cpl_StylerFunction::DoCommandId(int cmdId) {
    //@@preconditions
    assert(this->GetFunctionProcess() != NULL);
    assert(this->pSessionProxy != NULL);
    //@@end preconditions

    this->exeCmdRet = 1;

    int sessionRecOnOff = this->pSessionProxy->IsRecordSessionEnabled();
    if (this->exeCmdStatus == 1 || sessionRecOnOff == 0 || this->GetCommandNeedRecord(cmdId) == 0) {
        this->cpl_Function::DoCommandId(cmdId);
        this->DoGlobalCommand(cmdId);
    }
    else {
        //disable record function before execute command id.
        if (sessionRecOnOff == 1) {
            this->pSessionProxy->DisableRecordSession();
        }

        //record session.
        if (this->exeFuncStatus == 0) {
            this->RecordSessionFuncCommand(cmdId);
        }

        this->exeCmdStatus = 1;
        this->cpl_Function::DoCommandId(cmdId);
        this->DoGlobalCommand(cmdId);
        this->exeCmdStatus = 0;

        //enable record function after execute command id.
        if (sessionRecOnOff == 1) {
            this->pSessionProxy->EnableRecordSession();
        }
    }

    //clear input parameters.
    if (this->pDataExchange != NULL) {
        this->pDataExchange->GetFunctionParameter()->GetParamEngine()->GetInputReadRight()->Clear();
    }

    //remove inline function.
    if (cmdId == FUNC_CMD_EXIT && this->IsInlineFunction() == 1) {
        this->Delete();
    }

    return this->exeCmdRet;
}

//------------------------------------------------------------------------
void cpl_StylerFunction::DoGlobalCommand(int cmdId) {
    //@@preconditions 
    assert(this->winProxy              != NULL);
    assert(this->functionData.process  != NULL);
    assert(this->functionData.ctxProxy != NULL);
    //@@end preconditions

    this->functionData.process->EnterProcess();

    switch (cmdId) {
        case FUNC_CMD_EXIT:
            {
                this->Exit();
                this->winProxy->LeaveWindowFunction(this);
            }
            break;
        case FUNC_CMD_UPDATE:
            this->DoUpdateAction();
            break;
        case FUNC_CMD_ACTIVE:
            this->DoActiveAction();
            break;
        case FUNC_CMD_SYNC:
            {
                char* funString = this->functionData.ctxProxy->GetFunctionKeyString();
                if (funString != NULL) {
                    if (strcmp(funString, this->GetStringId()) == 0) {
                        this->DoSynchronizationAction();
                    }
                }
            }
            break;
        case FUNC_CMD_ENDRESTORE:
            this->DoEndRestoreAction();
            break;
        case FUNC_CMD_CTXREADY:
            {
                int flag = 0;
                char* funString = this->functionData.ctxProxy->GetFunctionKeyString();
                if (funString != NULL) {
                    if (strcmp(funString, this->GetStringId()) == 0) {
                        flag = 1;
                    }
                }

                assert(this->pDataExchange != NULL);
                this->pDataExchange->PrepareWrite();
                this->pDataExchange->SetParamAsINT(0, flag);
                this->pDataExchange->EndWrite();
            }
            break;
        default:
            break;
    }

    this->functionData.process->LeaveProcess();
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::AttachShortCutMenu() {
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::DettachShortCutMenu() { 
}

//-----------------------------------------------------------------------------
void cpl_StylerFunction::SetSuspendFunction(cpl_Function* contextFunction) {
	this->StylerFuncData.suspendFunction = contextFunction;
}

//------------------------------------------------------------------------
int cpl_StylerFunction::RecordSessionFuncCommand(int cmdId) {
    //@@preconditions
    assert(this->pSessionProxy != NULL);
    assert(this->funcSessionData != NULL);
    //@@end preconditions

    if (this->pSessionProxy->IsValidRecordSession() == 0) {
        return 0;
    }
    if (this->pSessionProxy->IsRunningSession() == 1) {
        return 0;
    }

    char* sessionStr = NULL;
    if (this->pDataExchange != NULL) {
        assert(this->pDataExchange->GetFunctionParameter() != NULL);
        assert(this->pDataExchange->GetFunctionParameter()->GetParamEngine() != NULL);
        assert(this->pDataExchange->GetFunctionParameter()->GetParamEngine()->GetInputParamBuffer() != NULL);

        cpl_CtlDataTextFormatter* textFormater = cpl_CtlDataTextFormatter::New();

        char* paramStr = NULL;
        textFormater->FormatCtlActionText(NULL, this->pDataExchange->GetFunctionParameter()->GetParamEngine()->GetInputParamBuffer(), paramStr);

        int paramStrLen = (paramStr == NULL) ? 0 : (int)strlen(paramStr);
        sessionStr = new char[paramStrLen+256];

        const char* cmdName = NULL;
        if (this->GetCommandNameFromID(cmdId, cmdName) == 1) {
            sprintf(sessionStr, "%s", cmdName);
        }
        else {
            sprintf(sessionStr, "%d", cmdId);
        }
        if (paramStrLen > 0) {
            strcat(sessionStr, "|");
            strcat(sessionStr, paramStr);
        }
        textFormater->Delete();
    }
    else {
        sessionStr = new char[256];
        const char* cmdName = NULL;
        if (this->GetCommandNameFromID(cmdId, cmdName) == 1) {
            sprintf(sessionStr, "%s", cmdName);
        }
        else {
            sprintf(sessionStr, "%d", cmdId);
        }
    }

    char* modSessionStr = this->funcSessionData->SegmentParameterString(sessionStr);
    assert(modSessionStr != NULL);

    this->pSessionProxy->WriteCommandSession(modSessionStr);
    delete[] sessionStr;  
    return 1;
}

//-----------------------------------------------------------------------------
cpl_StylerFunction::cpl_StylerFunction() {  
    this->windowStyler           = NULL;
    this->winProxy               = NULL;
    this->windowStylerCollection = NULL;
    this->pSessionProxy          = NULL;
    this->funcStatus             = FUNC_STATUS_UNKNOWN;
    this->funcSessionData        = cpl_FunctionSessionDataProxy::New();
    this->ExecuteImp             = new cpl_FunctionExecuteImp(this);
    this->ExecuteImpInvoker      = new cpl_FunctionExecuteInvokerImp(this->ExecuteImp);
    this->pDataExchange          = NULL;
    this->InlineCode             = 0;
    this->exeFuncStatus          = 0;
    this->exeCmdStatus           = 0;
    this->exeCmdRet              = 1;

    //context.
    this->StylerFuncData.suspendFunction = NULL;
}

//-----------------------------------------------------------------------------
cpl_StylerFunction::~cpl_StylerFunction() {
    if (this->ExecuteImp != NULL) {
        delete this->ExecuteImp;
        this->ExecuteImp = NULL;
    }
    if (this->ExecuteImpInvoker != NULL) {
        delete this->ExecuteImpInvoker;
        this->ExecuteImpInvoker = NULL;
    }
    if (this->funcSessionData != NULL) {
        this->funcSessionData->Delete();
        this->funcSessionData = NULL;
    }
}
