# cctype字符处理函数库
<p>C++中的字符处理函数包含在头文件cctype中，c语言在头文件ctype.h中  </p>
``isalnum(ch)``: 检查ch是字母或数字，是返回true,不是返回false  
``isalpha(ch)``: 检查ch是否为字母，是返回true,不是返回false  
``isdigit(ch)``: 检查ch是否为**（0~9）** 的数字，是返回true,不是返回false  
``isgraph(ch)``: 检查ch是否为ASCII值中33~126之间的字符（或称可打印字符），是返回true,不是返回false  
``islower(ch)``: 检查ch是否为小写字母，是返回true,不是返回false  
``isupper(ch)``: 检查ch是否为大写字母，是返回true,不是返回false  
``tolower(ch)``: ch会被转换为相应的小写字母  
``toupper(ch)``: ch会被转换为相应的大写字母

____
_参考:《C++ Primer Plus (第五版)》_
