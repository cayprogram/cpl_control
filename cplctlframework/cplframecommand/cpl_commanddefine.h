#ifndef CPL_COMMANDDEFINEINCLUDE_H
#define CPL_COMMANDDEFINEINCLUDE_H

#ifdef WIN32
#pragma warning( push ) // memorize the warning status
#pragma warning( disable : 4305 ) // disable "initializing : truncation from 'const double' to 'float'" warning
#pragma warning( disable : 4244 ) // disable "double to float conversion possible loss of data" warning
#pragma warning( disable : 4136 ) // disable "conversion between different floating-point types" warning
#pragma warning( disable : 4309 ) // disable " 'conversion' : truncation of constant value" warning
#pragma warning( disable : 4051 ) // disable " 'type conversion' ; possible loss of data" warning
#pragma warning( disable : 4100 ) // disable  unreferenced formal parameter
#pragma warning( disable : 4169 ) // disable  unreferenced formal parameter
#endif

//-----------------------------------------------------------------------------
//class function.
//-----------------------------------------------------------------------------
class cpl_ICommand {
public:
    /** release */
    virtual int Release() = 0;

    /** get string cmd */
    virtual const char* GetStringId() = 0;    

    /** set command handler */
    virtual void SetCommandHandler(const char* stringId, void* commandHandler) = 0;

public:
    /** deep copy */
    virtual cpl_ICommand* DeepCopy() = 0;

public:
    /** check parameter */
    virtual int CheckInputParameter (IParameterEngineCheckRight *check) = 0;
    virtual int CheckOutputParameter(IParameterEngineCheckRight *check) = 0;
    virtual int ReadInputParameter  (IParameterEngineReadRight *read)   = 0;
    virtual int WriteOutputParameter(IParameterEngineWriteRight *write) = 0;
};

#endif //CPL_COMMANDDEFINEINCLUDE_H
