#ifndef CFG_STAT_H
#define CFG_STAT_H

#include "framework/ASTManager.h"
#include "framework/CallGraph.h"
#include "framework/Config.h"

class CFGStat{
    ASTResource *resource;
    ASTManager *manager;
    CallGraph *callgraph;
    Config *configure;
public:
    CFGStat(ASTResource *resource, ASTManager *manager,
            CallGraph *callgraph, Config *configure){
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
        // for (auto fun : topLevelFuncs) {
        //     const FunctionDecl *funDecl = manager->getFunctionDecl(fun);
        //     callgraph->getChildren(fun);
        //     if (funDecl->getQualifiedNameAsString() == "main") {
        //     entryFunc = fun;
        //     return;
        //     }
        // }
        // entryFunc = nullptr;
    }

    void statCFGs() {
        for(auto fun : callgraph->getTopLevelFunctions()){
            auto& cfg=manager->getCFG(fun);
            if(cfg==NULL){
                continue;
            }
            dumpCFG(cfg);
            for (auto I = cfg->begin(), E = cfg->end() ; I != E ; ++I) {
                // Skip the entry block, because we already printed it.
                if (&(**I) == &cfg->getEntry() || &(**I) == &cfg->getExit())
                    continue;
                const CFGBlock *block=*I;
                for(auto eleIt=block->begin(); eleIt!=block->end(); eleIt++){
                    auto& ele=*eleIt;
                    auto kind=ele.getKind();
                    eleIt->dump();
                    if(kind==CFGElement::Kind::Statement){
                        CFGStmt cfgStmt = ele.castAs<CFGStmt>();
                        const Stmt *stmt = cfgStmt.getStmt();
                        assert(stmt != nullptr && "Expecting non-null Stmt");
                        if (const BinaryOperator* binOp = dyn_cast<BinaryOperator>(stmt)) {
                            std::cout<<"bin op\n";
                        }
                        else if(const DeclStmt* declStmt = dyn_cast<DeclStmt>(stmt)){
                            std::cout<<"decl stmt\n";
                        }

                    }
                    
                }               
            }
        }
    }

};

#endif