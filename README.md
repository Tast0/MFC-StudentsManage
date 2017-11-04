 MFC-StudentsManage
 =======================
 
编译环境
-----------------------
VS2013

问题处理
---------------------
* 静态变量的使用，应该在CPP中全局式初始化；
* 原来可以编译过的工程，现在提示 IntelliSense: 应输入声明； 工具-〉选项-〉文本编辑器-〉c/c++->高级-〉禁用自动更新改为：TRUE
* Visual C++ 2012 使用了更加安全的 run-time library routines 。新的Security CRT functions（就是那些带有“_s”后缀的函数）<br>
   1. 在预编译头文件stdafx.h里（注意：一定要在没有include任何头文件之前）定义下面的宏：#define _CRT_SECURE_NO_DEPRECATE<br>
   2. 或声明 #param warning(disable:4996)<br>
   3. 更改预处理定义：项目->属性->配置属性->C/C++ -> 预处理器 -> 预处理器定义，增加：_CRT_SECURE_NO_DEPRECATE<br>
