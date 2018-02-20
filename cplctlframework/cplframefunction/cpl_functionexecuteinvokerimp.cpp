#include "cpl_functionframeincludes.h"

//-----------------------------------------------------------------------------
// class cpl_FunctionExecuteInvokerImp
//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::SetFunctionExecute(cpl_FunctionExecute* pExecuted) {
    this->FunctionExecute = pExecuted;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::SetInputAsINT(int index, int param0) {
    //@@preconditions
    assert(index >= 0);
    assert(this->FunctionExecute != NULL);
    //@@end preconditions

    if (this->OutputParamNum > 0) {
        assert(this->InputParamNum == 0);
        this->FunctionExecute->GetOutputReadRight()->EndRead();
        this->OutputParamNum = 0;
    }
    if (this->InputParamNum == 0) {
        this->FunctionExecute->GetInputWriteRight()->Clear();
        this->FunctionExecute->GetInputWriteRight()->PrepareWrite();
    }
    this->FunctionExecute->GetInputWriteRight()->SetParamAsINT(index, param0);
    this->InputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::SetInputAsREAL(int index, float data) {
    //@@preconditions
    assert(index >= 0);
    assert(this->FunctionExecute != NULL);
    //@@end preconditions
    
    if (this->OutputParamNum > 0) {
        assert(this->InputParamNum == 0);
        this->FunctionExecute->GetOutputReadRight()->EndRead();
        this->OutputParamNum = 0;
    }
    if (this->InputParamNum == 0) {
        this->FunctionExecute->GetInputWriteRight()->Clear();
        this->FunctionExecute->GetInputWriteRight()->PrepareWrite();
    }
    this->FunctionExecute->GetInputWriteRight()->SetParamAsREAL(index, data);
    this->InputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::SetInputAsSTRING(int index,  char *  data) {
    //@@preconditions
    assert(index >= 0);
    //assert(data != NULL);
    //assert(data[0] != '\0');
    assert(this->FunctionExecute != NULL);
    //@@end preconditions
    
    if (this->OutputParamNum > 0) {
        assert(this->InputParamNum == 0);
        this->FunctionExecute->GetOutputReadRight()->EndRead();
        this->OutputParamNum = 0;
    }
    if (this->InputParamNum == 0) {
        this->FunctionExecute->GetInputWriteRight()->Clear();
        this->FunctionExecute->GetInputWriteRight()->PrepareWrite();
    }
    this->FunctionExecute->GetInputWriteRight()->SetParamAsSTRING(index, data);
    this->InputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::SetInputAsINTArray(int index,  int *  data, int num) {
    //@@preconditions
    assert(index >= 0);
    //assert(data != NULL);
    assert(this->FunctionExecute != NULL);
    //@@end preconditions
    
    if (this->OutputParamNum > 0) {
        assert(this->InputParamNum == 0);
        this->FunctionExecute->GetOutputReadRight()->EndRead();
        this->OutputParamNum = 0;
    }
    if (this->InputParamNum == 0) {
        this->FunctionExecute->GetInputWriteRight()->Clear();
        this->FunctionExecute->GetInputWriteRight()->PrepareWrite();
    }
    this->FunctionExecute->GetInputWriteRight()->SetParamAsINTArray(index, data, num);
    this->InputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::SetInputAsIDArray(int index,  int *  data, int num) {
    //@@preconditions
    assert(index >= 0);
    //assert(data != NULL);
    assert(this->FunctionExecute != NULL);
    //@@end preconditions

    if (this->OutputParamNum > 0) {
        assert(this->InputParamNum == 0);
        this->FunctionExecute->GetOutputReadRight()->EndRead();
        this->OutputParamNum = 0;
    }
    if (this->InputParamNum == 0) {
        this->FunctionExecute->GetInputWriteRight()->Clear();
        this->FunctionExecute->GetInputWriteRight()->PrepareWrite();
    }
    this->FunctionExecute->GetInputWriteRight()->SetParamAsIDArray(index, data, num);
    this->InputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::SetInputAsREALArray(int index,  float *  data, int num) {
    //@@preconditions
    assert(index >= 0);
    //assert(data != NULL);
    assert(this->FunctionExecute != NULL);
    //@@end preconditions
    
    if (this->OutputParamNum > 0) {
        assert(this->InputParamNum == 0);
        this->FunctionExecute->GetOutputReadRight()->EndRead();
        this->OutputParamNum = 0;
    }
    if (this->InputParamNum == 0) {
        this->FunctionExecute->GetInputWriteRight()->Clear();
        this->FunctionExecute->GetInputWriteRight()->PrepareWrite();
    }
    this->FunctionExecute->GetInputWriteRight()->SetParamAsREALArray(index,  data, num);
    this->InputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::SetInputAsSTRINGArray(int index,  char **data, int num) {
    //@@preconditions
    assert(index >= 0);
    //assert(data != NULL);
    assert(this->FunctionExecute != NULL);
    //@@end preconditions
    
    if (this->OutputParamNum > 0) {
        assert(this->InputParamNum == 0);
        this->FunctionExecute->GetOutputReadRight()->EndRead();
        this->OutputParamNum = 0;
    }
    if (this->InputParamNum == 0) {
        this->FunctionExecute->GetInputWriteRight()->Clear();
        this->FunctionExecute->GetInputWriteRight()->PrepareWrite();
    }
    this->FunctionExecute->GetInputWriteRight()->SetParamAsSTRINGArray(index,  data, num);
    this->InputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::SetInputAsVOID(int index,  void* data) {
    //@@preconditions
    assert(index >= 0);
    //assert(data != NULL);
    assert(this->FunctionExecute != NULL);
    //@@end preconditions
    
    if (this->OutputParamNum > 0) {
        assert(this->InputParamNum == 0);
        this->FunctionExecute->GetOutputReadRight()->EndRead();
        this->OutputParamNum = 0;
    }
    if (this->InputParamNum == 0) {
        this->FunctionExecute->GetInputWriteRight()->Clear();
        this->FunctionExecute->GetInputWriteRight()->PrepareWrite();
    }
    this->FunctionExecute->GetInputWriteRight()->SetParamAsVOID(index,  data);
    this->InputParamNum++;
}

//-----------------------------------------------------------------------------
int cpl_FunctionExecuteInvokerImp::Execute(int funcId) {
    //@@precondition
    assert(this->FunctionExecute != NULL);
    //@@end preconditions
    
    if (this->InputParamNum > 0) {
        assert(this->OutputParamNum == 0);
        this->FunctionExecute->GetInputWriteRight()->EndWrite();
        this->InputParamNum = 0;
    }
    if (this->OutputParamNum > 0) {
        assert(this->InputParamNum == 0);
        this->FunctionExecute->GetOutputReadRight()->EndRead();
        this->OutputParamNum = 0;
    }
    return this->FunctionExecute->DoCommandId(funcId);
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::GetOutputAsINT(int index, int&  data) {
    //@@precondition
    assert(index >= 0);
    assert(this->FunctionExecute != NULL);
    assert(this->InputParamNum == 0);
    //@@end preconditions

    if (this->OutputParamNum == 0) {
        this->FunctionExecute->GetOutputReadRight()->PrepareRead();
    }
    this->FunctionExecute->GetOutputReadRight()->GetParamAsINT(index, data);
    this->OutputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::GetOutputAsREAL(int index, float & data) {
    //@@precondition
    assert(index >= 0);
    assert(this->FunctionExecute != NULL);
    assert(this->InputParamNum == 0);
    //@@end preconditions
    
    if (this->OutputParamNum == 0) {
        this->FunctionExecute->GetOutputReadRight()->PrepareRead();
    }
    this->FunctionExecute->GetOutputReadRight()->GetParamAsREAL(index, data);
    this->OutputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::GetOutputAsSTRING(int index,  char *& data) {
    //@@precondition
    assert(index >= 0);
    assert(this->FunctionExecute != NULL);
    assert(this->InputParamNum == 0);
    //@@end preconditions
    
    if (this->OutputParamNum == 0) {
        this->FunctionExecute->GetOutputReadRight()->PrepareRead();
    }
    this->FunctionExecute->GetOutputReadRight()->GetParamAsSTRING(index, data);
    this->OutputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::GetOutputAsINTArray(int index,  int *& data, int& num) {
    //@@precondition
    assert(index >= 0);
    assert(data == NULL);
    assert(this->FunctionExecute != NULL);
    assert(this->InputParamNum == 0);
    //@@end preconditions
    
    if (this->OutputParamNum == 0) {
        this->FunctionExecute->GetOutputReadRight()->PrepareRead();
    }
    this->FunctionExecute->GetOutputReadRight()->GetParamAsINTArray(index, data, num);
    this->OutputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::GetOutputAsIDArray(int index,  int *& data, int& num) {
    //@@precondition
    assert(index >= 0);
    assert(data == NULL);
    assert(this->FunctionExecute != NULL);
    assert(this->InputParamNum == 0);
    //@@end preconditions

    if (this->OutputParamNum == 0) {
        this->FunctionExecute->GetOutputReadRight()->PrepareRead();
    }
    this->FunctionExecute->GetOutputReadRight()->GetParamAsIDArray(index, data, num);
    this->OutputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::GetOutputAsREALArray(int index,  float *& data, int &num) {
    //@@precondition
    assert(index >= 0);
    assert(data == NULL);
    assert(this->FunctionExecute != NULL);
    assert(this->InputParamNum == 0);
    //@@end preconditions
    
    if (this->OutputParamNum == 0) {
        this->FunctionExecute->GetOutputReadRight()->PrepareRead();
    }
    this->FunctionExecute->GetOutputReadRight()->GetParamAsREALArray(index, data, num);
    this->OutputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::GetOutputAsSTRINGArray(int index,  char **& data, int &num) {
    //@@precondition
    assert(index >= 0);
    assert(data == NULL);
    assert(this->FunctionExecute != NULL);
    assert(this->InputParamNum == 0);
    //@@end preconditions
    
    if (this->OutputParamNum == 0) {
        this->FunctionExecute->GetOutputReadRight()->PrepareRead();
    }
    this->FunctionExecute->GetOutputReadRight()->GetParamAsSTRINGArray(index, data, num);
    this->OutputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::GetOutputAsVOID(int index, void*& data) {
    //@@precondition
    assert(index >= 0);
    assert(data == NULL);
    assert(this->FunctionExecute != NULL);
    assert(this->InputParamNum == 0);
    //@@end preconditions
    
    if (this->OutputParamNum == 0) {
        this->FunctionExecute->GetOutputReadRight()->PrepareRead();
    }
    this->FunctionExecute->GetOutputReadRight()->GetParamAsVOID(index, data);
    this->OutputParamNum++;
}

//-----------------------------------------------------------------------------
void cpl_FunctionExecuteInvokerImp::ResetParamBuffer() {
    if (this->InputParamNum > 0) {
        assert(this->OutputParamNum == 0);
        this->FunctionExecute->GetInputWriteRight()->EndWrite();
        this->InputParamNum = 0;
    }
    if (this->OutputParamNum > 0) {
        assert(this->InputParamNum == 0);
        this->FunctionExecute->GetOutputReadRight()->EndRead();
        this->OutputParamNum = 0;
    }
}

//-----------------------------------------------------------------------------
cpl_FunctionExecuteInvokerImp::cpl_FunctionExecuteInvokerImp() {
    this->FunctionExecute = NULL;
    this->InputParamNum  = 0;
    this->OutputParamNum = 0;
}

//-----------------------------------------------------------------------------
cpl_FunctionExecuteInvokerImp::cpl_FunctionExecuteInvokerImp(cpl_FunctionExecute* pExecute) {
    this->FunctionExecute = pExecute;
    this->InputParamNum  = 0;
    this->OutputParamNum = 0;
}

//-----------------------------------------------------------------------------
cpl_FunctionExecuteInvokerImp::~cpl_FunctionExecuteInvokerImp() {
}
