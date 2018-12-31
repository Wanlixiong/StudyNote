#### extern
extern用于重新声明已经定义过的变量。  
__示例：__
```c++
#include<iostream>

void fun1();
void fun2();
void fun3();

int n=10;		//全局变量
int main()
{	
	fun1();
	std::cout << "1: n=" << n<<std::endl;
	fun2();
	std::cout << "2: n=" << n << std::endl;
	fun3();
	std::cout << "3: n=" << n << std::endl;
	return 0;
}

void fun1()
{
	int n;
	n = 20;
}

void fun2()
{
	extern int n;		//对n变量重新声明
	n = 30;
}

void fun3()
{
	int n = 40;	
}
```
```
1: n=10
2: n=30
3: n=30
```
main函数中调用fun1时，由于fun1中声明的变量n作用域只在fun1函数中，所以第一次输出使用的是全局变量n=10。调用fun2时，fun2中使用了extern变量重新定义n变量，使n=30,在fun2编译完后n=30已经替代了n=10的全局作用。   

__注意__：extern不可以在声明时初始化变量，这是错误的做法，如：
```c++
extern int n=30;    //错误声明方式
```

