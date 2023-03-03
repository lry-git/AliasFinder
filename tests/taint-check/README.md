# taint-check

1. 修改linux_x86.mk文件中CC和CPLUS为编译器路径

2. 运行linux_x86.sh. 生成ast文件，存放在obj文件夹中，astList中是ast文件的路径。

3. 运行程序，生成xml文件

```shell
../../cmake-build-debug/tools/TemplateChecker/TemplateChecker astList.txt config.txt
```
