#ifndef CPL_PARAMETERENGINEMANAGER_H
#define CPL_PARAMETERENGINEMANAGER_H

class cpl_ParameterEngineManager {

public:
    /** Get the Instance of cpl_ParameterEngineManager */
    static cpl_ParameterEngineManager * New();
    
    /** Delete */
    void Delete();

public:
    //get input read right.    
    IParameterEngineReadRight* GetInputReadRight() { 
        return (IParameterEngineReadRight*)inPE; 
    }

    //get input write right.    
    IParameterEngineWriteRight* GetInputWriteRight() { 
        return (IParameterEngineWriteRight*)inPE; 
    }

    //get input check right.    
    IParameterEngineCheckRight* GetInputCheckRight() { 
        return (IParameterEngineCheckRight*)inPE; 
    }

    //get output read right.    
    IParameterEngineReadRight* GetOutputReadRight() { 
        return (IParameterEngineReadRight*)outPE; 
    }

    //get output write right.    
    IParameterEngineWriteRight* GetOutputWriteRight() { 
        return (IParameterEngineWriteRight*)outPE; 
    }

    //get output check right.    
    IParameterEngineCheckRight* GetOuputCheckRight() { 
        return (IParameterEngineCheckRight*)outPE; 
    }

public:
    /** get input parameter buffer */
    cpl_ParameterBuffer* GetInputParamBuffer() {
        return this->inPE->GetParamBuffer(); 
    }

    /** get output parameter buffer */
    cpl_ParameterBuffer* GetOutputParamBuffer() {
        return this->outPE->GetParamBuffer();
    }

protected:
    /** Constructor */
    cpl_ParameterEngineManager();

    /** Destructor */
    virtual ~cpl_ParameterEngineManager();

    /** input parameterEngine */
    cpl_ParameterEngine* inPE;

    /** output parameterEngine */
    cpl_ParameterEngine* outPE;
};

#endif //CPL_PARAMETERENGINEMANAGER_H
