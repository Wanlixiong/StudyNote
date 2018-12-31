## 1.C++中常用的字符串处理函数
### 1.1求字符串长度：
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;C++中提供了三种计算字符串长度的解决方案size()、lengh()和strlen()。 </p>
#### 1.1.1方法一：size()  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;这个函数主要是用与计算string的字符长度，包含在头文件string中，字符串中的'\0'不计算在内，即计算的是字符串实际长度。
```c++
#include<iostream>
#include<string>
using namespace std;

int main()
{	//C++中字符串的三种定义法
	string str1 = "abcde fg1";
	char str2[10] = "abcde fg2";
	char str3[10] = { 'a','b','c','d','e',' ','f','g','3','\0' };

	cout << "使用size()计数长度" << endl;
	cout << "str1=" << str1.size() << endl
		<< "str2=" << string(str2).size() << endl		//char类型需要使用string强制转换
		<< "str3=" << string(str3).size() << endl;

	return 0;
}
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;运行效果：
```
使用size()计数长度
str1=9
str2=9
str3=9
```
#### 1.1.2方法二：length()  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;这个函数获取字符串长度的功能和size()一样，都是为string类型而设定的，计算的是字符串实际长度。
```c++
#include<iostream>
#include<string>
using namespace std;

int main()
{	//C++中字符串的三种定义法
	string str1 = "abcde fg1";
	char str2[10] = "abcde fg2";
	char str3[10] = { 'a','b','c','d','e',' ','f','g','3','\0' };

	cout << "使用length()计数长度" << endl;
	cout << "str1=" << str1.length() << endl
		<< "str2=" << string(str2).length() << endl		//char类型需要使用string强制转换
		<< "str3=" << string(str3).length() << endl;

	return 0;
}
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;运行效果：
```
使用length()计数长度
str1=9
str2=9
str3=9
```

#### 1.1.3方法三：strlen()  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;这个函数从C延用到C++，在C中包含在string.h头文件下，在C++中则包含在string头文件下（如果你是老式的编译器，试试string.h头文件）。计算字符串实际长度。  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;该函数在C++使用到涉及string类型时非常麻烦，需要你定义一个char指针常量，如我这里定义char类型指针c，然后将该指针指向string类型字符串，而且指向的还是需要经过c_str()函数转换的字符，说白了就是将string类型的字符串转换成char数组定义类型字符串。

```c++
#include<iostream>
#include<string>
using namespace std;

int main()
{

	const char *c;
	//C++中字符串的三种定义法
	string str1 = "abcde fg1";
	c = str1.c_str();
	char str2[10] = "abcde fg2";
	char str3[10] = {'a','b','c','d','e',' ','f','g','3','\0'};

	cout << "使用strlen()计数长度" << endl;
	cout <<"str1="<< strlen(c) <<endl
		<< "str2="<< strlen(str2) <<endl
		<< "str3=" << strlen(str3) <<endl;

	return 0;
}
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;运行效果：
```
使用size()计数长度
str1=9
str2=9
str3=9
```
