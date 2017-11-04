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
   错误原因解释：<br>
这种微软的警告，主要因为那些C库的函数，很多函数内部是不进行参数检测的（包括越界类的），微软担心使用这些会造成内存异常，所以就改写了同样功能的函数，改写了的函数进行了参数的检测，使用这些新的函数会更安全和便捷。关于这些改写的函数你不用专门去记忆，因为编译器对于每个函数在给出警告时，都会告诉你相应的安全函数，查看警告信息就可以获知，在使用时也再查看一下MSDN详细了解。
* CString->LPTSTR;CString strText( _T("This is a test") );LPTSTR lpszText =(LPTSTR)(LPCTSTR)strText;
