#ifndef CPL_FUNCTIONEXECUTE_H
#define CPL_FUNCTIONEXECUTE_H

#define FUNC_CMD_EXIT           -1
#define FUNC_CMD_UPDATE         -2
#define FUNC_CMD_CTXREADY       -3
#define FUNC_CMD_ACTIVE         -4
#define FUNC_CMD_SYNC           -5
#define FUNC_CMD_ENDRESTORE     -6

class cpl_FunctionExecute {
public:    
    /** get input write right. */
    virtual IParameterEngineWriteRight* GetInputWriteRight() = 0;
    
    /** get output read right. */   
    virtual IParameterEngineReadRight* GetOutputReadRight() = 0; 
    
    /** do command */
    virtual int DoCommandId(int cmdId) = 0;
};

#endif //CPL_FUNCTIONEXECUTE_H
