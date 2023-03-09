#include "Stat/CFGStat.h"

void CFGStat::statCFGs() {
    for(auto fun : callgraph->getTopLevelFunctions()){
        auto& cfg=manager->getCFG(fun);
        if(cfg==NULL){
            continue;
        }
        // dumpCFG(cfg);
        auto FD=fun->getFunctionDecl();
        auto &srcMgr=FD->getASTContext().getSourceManager();
        auto sourceRange=FD->getSourceRange();
        auto srcBegin=sourceRange.getBegin();
        auto fileName=srcMgr.getFilename(srcBegin);
        unsigned line=srcMgr.getSpellingLineNumber(srcBegin);
        llvm::outs()<<"file name: "<<fileName<<" and line: "<<line<<'\n';
        for (auto I = cfg->begin(); I != cfg->end() ; I++) {
            // Skip the entry block, because we already printed it.
            if (&(**I) == &cfg->getEntry() || &(**I) == &cfg->getExit())
                continue;
            unsigned offset=0;
            const CFGBlock *block=*I;
            for(auto eleIt=block->begin(); eleIt!=block->end(); eleIt++){
                auto& ele=*eleIt;
                auto kind=ele.getKind();
                std::cout<<"block element is : ";
                eleIt->dump();
                if(kind==CFGElement::Kind::Statement){
                    CFGStmt cfgStmt = ele.castAs<CFGStmt>();
                    const Stmt *stmt = cfgStmt.getStmt();
                    assert(stmt != nullptr && "Expecting non-null Stmt");
                    auto beginLoc=stmt->getBeginLoc();
                    unsigned stmtLine=srcMgr.getSpellingLineNumber(beginLoc);

                    MyStmt myStmt(stmtLine,offset,block);
                    if (const BinaryOperator* binOp = dyn_cast<BinaryOperator>(stmt)) {                        
                        if(binOp->getOpcodeStr()=="="){
                            std::cout<<"assign op: "<<stmtLine<<'\n';
                            _aliasStat.insert(fileName.data(),stmtLine,myStmt);
                            // auto lhs=binOp->getLHS();
                            // auto rhs=binOp->getRHS();
                            // std::cout<<"lhs is: ";
                            // lhs->dump();
                            // std::cout<<"rhs is: ";
                            // rhs->dump();                        
                        }
                    }
                    else if(const DeclStmt* declStmt = dyn_cast<DeclStmt>(stmt)){                        
                        for(auto it=declStmt->decl_begin(); it!=declStmt->decl_end(); it++){
                            std::cout<<"decl stmt item: "<<stmtLine<<'\n';
                            _aliasStat.insert(fileName.data(),stmtLine,myStmt);
                            // auto decl=*it;
                            // decl->dump();
                            // cout<<decl->getName()<<'\n';
                        }
                    }                    
                }
                offset++;
                cout<<"end of block item\n";
            } 

        }
    }
}

void CFGStat::computeDist(AliasPair & aliasPair){
    MyStmt *myStmt1=_aliasStat.getMyStmt(aliasPair.defuse1);
    MyStmt *myStmt2=_aliasStat.getMyStmt(aliasPair.defuse2);
    if (!myStmt1 || !myStmt2){
        return;
    }
    aliasPair.distance=myStmt1->getOffset()-myStmt2->getOffset();
}

void CFGStat::dumpAlias(){
    vector<string> list;
    _fileParser.readLine(list); // skip the header
    while(_fileParser.readLine(list)){
        AliasPair aliasPair(list);
        computeDist(aliasPair);
        _fileParser.writeLine(aliasPair);
    }
}