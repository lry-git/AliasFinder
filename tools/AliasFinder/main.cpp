#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/JSONCompilationDatabase.h>
#include <llvm-c/Target.h>
#include <llvm/Support/CommandLine.h>

#include "framework/ASTManager.h"

#include "framework/Config.h"
// #include "framework/Logger.h"

#include "CFG/InterProcedureCFG.h"
#include "Stat/CFGStat.h"

using namespace clang;
using namespace llvm;
using namespace std;

string midCsvPrefix="middle/";
vector<pair<string,string>> worklist;

// void parseAlias(int index, char *configPath){
void parseAlias(int index, string configPath, string outPath){
  string which=worklist[index].first;
  string astList=worklist[index].second;
  std::vector<std::string> ASTs = initialize(astList);

  Config configure(configPath);

  ASTResource resource;
  ASTManager manager(ASTs, resource, configure);
  CallGraph callgraph(manager, resource, configure.getOptionBlock("CallGraph"));;
  string csvIn=CSVParser::joinPath(midCsvPrefix,which+".csv");
  string csvOut=CSVParser::joinPath(outPath,which+".csv");
  CFGStat cfgStat(&resource, &manager, &callgraph, &configure, csvIn, csvOut);
  // cfgStat.dumpCFGs();
  cfgStat.statCFGs();
  cfgStat.dumpAlias();
}

int main(int argc, const char *argv[])
{
  // ofstream process_file("time.txt");
  // if (!process_file.is_open())
  // {
  //   cerr << "can't open time.txt\n";
  //   return -1;
  // }
  clock_t startCTime, endCTime;
  startCTime = clock();

  LLVMInitializeNativeTarget();
  LLVMInitializeNativeAsmParser();
  vector<thread> threads;
  ifstream fin("worklist.txt");
  string line;
  while(getline(fin,line)){
    auto pos=line.find(' ');
    string which=line.substr(0,pos);
    string astList=line.substr(pos+1);
    worklist.emplace_back(which,astList);
  }
  // int n=8;
  for(int i = 0; i < worklist.size(); i++){
      // thread t(parseAlias, i, argv[1]);
      // thread t(parseAlias, i, ' ');
      threads.push_back(move(thread(parseAlias, i, argv[1], argv[2])));
      // threads.emplace_back(move(t));
  }
  for(int i = 0; i < worklist.size(); i++){
    threads[i].join();
  }
  // std::vector<std::string> ASTs = initialize(argv[1]);

  // Config configure(argv[2]);

  // ASTResource resource;
  // ASTManager manager(ASTs, resource, configure);
  // CallGraph callgraph(manager, resource, configure.getOptionBlock("CallGraph"));;

  // CFGStat cfgStat(&resource, &manager, &callgraph, &configure);
  // // cfgStat.dumpCFGs();
  // cfgStat.statCFGs();

  
  
  // if (enable.find("CallGraphChecker")->second == "true")
  // {
  //   cout << "Starting CallGraphChecker check" << endl;
  //   process_file << "Starting CallGraphChecker check" << endl;
  //   clock_t start, end;
  //   // record the time of generating call graph
  //   start = clock();

  //   call_graph =
  //       new CallGraph(manager, resource, configure.getOptionBlock("CallGraph"));
  //   end = clock();
  //   if (configure.getOptionBlock("CallGraph").find("printToConsole")->second ==
  //       "true")
  //     call_graph->printCallGraph(cout);

  //   unsigned sec = unsigned((end - start) / CLOCKS_PER_SEC);
  //   unsigned min = sec / 60;
  //   process_file << "Time: " << min << "min" << sec % 60 << "sec" << endl;
  //   process_file
  //       << "End of CallGraphChecker "
  //          "check\n-----------------------------------------------------------"
  //       << endl;
  //   cout << "End of CallGraphChecker check\n";
  // }

  // // Test CFG
  // if (enable.find("CFGTest")->second == "true")
  // {
  //   cout << "Starting CFGTest check" << endl;
  //   process_file << "Starting CFGTest check" << endl;
  //   clock_t start, end;
  //   start = clock();

  //   // TemplateChecker checker(&resource, &manager, call_graph, &configure);
  //   // checker.check();

  //   end = clock();
  //   unsigned sec = unsigned((end - start) / CLOCKS_PER_SEC);
  //   unsigned min = sec / 60;
  //   process_file << "Time: " << min << "min" << sec % 60 << "sec" << endl;
  //   process_file
  //       << "End of CFGTest "
  //          "check\n-----------------------------------------------------------"
  //       << endl;
  //   cout << "End of CFGTest check\n";
  // }

  // // ICFG
  // if (enable.find("ICFG") != enable.end() &&
  //     (enable.find("ICFG")->second == "true"))
  // {
  //   cout << "Starting ICFG" << endl;
  //   process_file << "ICFG" << endl;
  //   clock_t start_icfg, end_icfg;
  //   start_icfg = clock();

  //   InterProcedureCFG *icfgPtr =
  //       new InterProcedureCFG(&manager, &resource, call_graph, &configure);
  //   end_icfg = clock();
  //   unsigned sec_icfg = unsigned((end_icfg - start_icfg) / CLOCKS_PER_SEC);
  //   unsigned min_icfg = sec_icfg / 60;
  //   process_file << "Time: " << min_icfg << "min" << sec_icfg % 60 << "sec"
  //                << endl;
  //   process_file << "End of ICFG "
  //                   "\n------------------------------------------------"
  //                   "-----------"
  //                << endl;
  //   cout << "End of ICFG\n";
  // }


  endCTime = clock();
  unsigned sec = unsigned((endCTime - startCTime) / CLOCKS_PER_SEC);
  unsigned min = sec / 60;
  // process_file << "-----------------------------------------------------------"
  //                 "\nTotal time: "
  //              << min << "min" << sec % 60 << "sec" << endl;
  return 0;
}
