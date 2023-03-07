#include "Stat/CFGStat.h"



void CFGStat::statCFGs() {
    for(auto fun : callgraph->getTopLevelFunctions()){
        auto& cfg=manager->getCFG(fun);
        if(cfg==NULL){
            continue;
        }
        dumpCFG(cfg);
        for (auto I = cfg->begin(); I != cfg->end() ; I++) {
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
