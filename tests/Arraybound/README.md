# ArrayBoundChecker

## Configure Options

Z3Timeout = 600 ：使用Z3约束求解的时间阈值。单位为秒
Function_TIMEOUT = 600：检查每个函数的时间阈值，单位为秒,Function_TIMEOUT <=0 则表示不设置时间阈值。
checkdepth=1: 指检测的函数层数，设置为1则只做过程内越界检查。
SolvePathConstraints = true：设置为true将收集路径约束、通过z3求解路径约束是否满足数组越界检查条件。
ReportPathConstraints = false ：在xml中是否输出路径约束
ReportPath = false：在xml中是否输出路径中的语句（stmt）
CheckTaintArrayOnly = true：设置为true将只检查数组下标为污染的数组越界。
CheckVectorOutBoundEnable = true：设置为true将也检查vector数组越界
PointToAnalysis = true：设置为true将使用别名分析分析数组大小
AliasMaxPathLength = 10：别名分析的路径长度
AliasMaxPathNumber = 10：别名分析的路径数目
