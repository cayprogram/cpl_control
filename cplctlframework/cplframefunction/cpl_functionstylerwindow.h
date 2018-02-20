#ifndef CPL_STYLERFUNCTIONWINDOW_H
#define CPL_STYLERFUNCTIONWINDOW_H

class cpl_StylerFunctionWindow {       
public:
    /** set window handler */
    void SetFuncWindowHandler(void* winHandler);    

    /** get window handler */
    void* GetFuncWindowHandler();

    /** set window handler */
    void SetToolWindowHandler(void* winHandler);    

    /** get window handler */
    void* GetToolWindowHandler();

public:
    //constructor.
    cpl_StylerFunctionWindow();
    
    //destructor.
    virtual ~cpl_StylerFunctionWindow();     
    void* funcWinHandler;  
    void* toolWinHandler;    
};

#endif //CPL_STYLERFUNCTIONWINDOW_H
