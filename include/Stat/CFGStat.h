#ifndef CFG_STAT_H
#define CFG_STAT_H
#include <unordered_set>
#include "framework/ASTManager.h"
#include "framework/CallGraph.h"
#include "framework/Config.h"
#include "Stat/AliasStat.h"
#include "Stat/FileParser.h"
using namespace std;

class CFGStat{
    ASTResource *resource;
    ASTManager *manager;
    CallGraph *callgraph;
    Config *configure;
    unsigned _dist;
    AliasStat _aliasStat;
    CSVParser _fileParser;
    unordered_set<const CFGBlock *> _visited;

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

    void dfsCFG(const CFGBlock *blockCur,const CFGBlock *blockEnd,unsigned distCur);

    unsigned computeDist(AliasPair & aliasPair);

    void dumpAlias();
};

#endif // end of CFG_STAT_H