### const指针
在C++中规定const指针的指向值是不可以通过const指针修改的，即：
```c++
int a=39;
const int * pt=&a;
```
上面的声明指出，pt指向const int值，因此不能用pt指针来修改它指向的值。但现实编程环境中C++却有多种方法来改变pt指向值的问题。
#### 方法一：将const变量地址赋给const指针
```c++
int a=39;
const int * pt=&a;
cosnt int b=40;
pt=&b;    
```
在这段代码执行完pt=&b之后，pt指向的不再是a变量，而是b变量。

#### 方法二：const_cast的应用
const_cast用来将数据中的const属性去除，不具备const属性的指针可以直接修改指向值
 ```c++
 void fun(const int *pt)
 {
   int *p=const_cast<int *>(pt)
   (*p)=40;   
 }
 ```
 这段代码的用途是将cp指针的const属性去除，并转换成普通的p指针后修改它指向的数据。

__更多解决方法后期补充__