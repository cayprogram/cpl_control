#ifndef CPL_COMMANDMACRODEF_H
#define CPL_COMMANDMACRODEF_H

#define NEWCOMMAND(cmdname, cmdhandlername) \
    static cmdname* New(cmdhandlername* cmdHandler) { \
    cmdname* newCmd = new cmdname; \
    newCmd->cmdData.userdata = (void*) cmdHandler; \
    return newCmd; \
};

#define NEWCOMMAND2(cmdname) \
    static cmdname* New() { \
    cmdname* newCmd = new cmdname; \
    return newCmd; \
};

#endif //CPL_COMMANDMACRODEF_H
