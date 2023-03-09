#ifndef CFG_STAT_H
#define CFG_STAT_H

#include "framework/ASTManager.h"
#include "framework/CallGraph.h"
#include "framework/Config.h"
#include "Stat/AliasStat.h"
#include "Stat/FileParser.h"

class CFGStat{
    ASTResource *resource;
    ASTManager *manager;
    CallGraph *callgraph;
    Config *configure;
    AliasStat _aliasStat;
    CSVParser _fileParser;

public:
    CFGStat(ASTResource *resource, ASTManager *manager,CallGraph *callgraph, 
            Config *configure, string csvIn, string csvOut):_fileParser(csvIn,csvOut){
        this->resource=resource;
        this->manager=manager;
        this->callgraph=callgraph;
        this->configure=configure;
    }
    void dumpCFG(std::unique_ptr<CFG> &cfg) const {
        LangOptions LangOpts;
        LangOpts.CPlusPlus = true;
        if(cfg!=NULL){
            cfg->dump(LangOpts, true);
        }        
    }

    void dumpCFGs() {
        for(auto fun : callgraph->getTopLevelFunctions()){
            auto& cfg=manager->getCFG(fun);
            dumpCFG(cfg);
        }
    }

    const std::vector<ASTFunction *>& getFunctions(){
        return callgraph->getTopLevelFunctions();       
    }

    void statCFGs();

    void computeDist(AliasPair & aliasPair);

    void dumpAlias();
};

#endif // end of CFG_STAT_H