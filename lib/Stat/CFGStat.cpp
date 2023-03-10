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
        if(srcMgr.isInSystemHeader(srcBegin) || fileName.empty())
            continue;
        
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
                std::cout<<"block element is : \n";
                // eleIt->dump();
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

unsigned CFGStat::computeDist(AliasPair & aliasPair){
    MyStmt *myStmt1=_aliasStat.getMyStmt(aliasPair.defuse1); // line num is bigger
    MyStmt *myStmt2=_aliasStat.getMyStmt(aliasPair.defuse2); // line num is smaller
    if (!myStmt1 || !myStmt2){
        return 0;
    }
    
    _visited.clear();
    auto block1=myStmt1->getCFGBlock();
    auto block2=myStmt2->getCFGBlock();
    _dist=myStmt1->getOffset()-myStmt2->getOffset();
    dfsCFG(block2,block1,_dist);
    aliasPair.distance=_dist;
    return _dist;
    // aliasPair.distance=myStmt1->getOffset()-myStmt2->getOffset();
}

void CFGStat::dfsCFG(const CFGBlock *blockCur,const CFGBlock *blockEnd,unsigned distCur){
    if(_visited.count(blockCur)){
        return;
    }
    if(blockCur==blockEnd){
        _dist=distCur;
        return;
    }
    _visited.insert(blockCur);
    distCur+=blockCur->size();
    for(auto sIt=blockCur->succ_begin();sIt!=blockCur->succ_end();sIt++){
        dfsCFG(*sIt,blockEnd,distCur);
    }
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