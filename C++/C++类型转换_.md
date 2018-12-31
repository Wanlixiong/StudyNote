#### static_cast
- static_cast是一种基于内容的转换。如：
```c++
int i=2;
float x=static_cast<float>(i);
```
整型的2和浮点型的2在内存中的二进制表示形式不同。执行static_cast<float>(i)操作时，编译器会生成目标代码，将i的整型二进制表示转换成浮点型二进制表示，这种称为基于内容的转换。

#### reinterpret_cast
- reinterpret_cast是指针类型的转换，它可以将一种指针转换为另一种指针(不同类型对象的指针之间的转换，不同类型函数指针之间的转换，不同类数据成员指针之间的转换，不同类函数指针之间的转换，不同类型引用之间的转换)，如：
```c++
int i=2;
float* p=reinterpret_cast<float* >(&i);
```
其原理是无论是哪种类型的指针，存储的都是一个地址，这些指针的区别只是相应地址中的数据被解释为不同的类型而已。因此这里的转换是把&i得到的地址值作为直接转换结果，并给这个结果赋予float*类型。这种转换把p作为浮点型指针，却指向了整型变量i。  

 __注意：__reinterpret_cast的操作有不确定性，如上面的例子中，p访问整型变量i所执行的操作只能针对浮点型，因避免用reinterpret_cast执行不同类型的指针转换行为。  

- 另一种代替reinterpret_cast的安全做法,：
```c++
int i=2;
void * vp=&i;
int *p=static_cast<int*>(vp);
```
void指针语义是指向所有对象内容不确定的指针，它可以指向任何类型的对象。但void指针vp不能对它所指向的对象进行任何操作，所以上面例子中，借助static_cast操作符将void指针vp转换为具体的类型;

#### const_cast
- const_cast用来将数据中的const属性去除，如：
 ```c++
 void foo(const int *cp)
 {
   int *p=const_cast<int *>(cp)
   (*p)++;   
 }
 ```
 这段代码的用途是将cp指针的const属性去除，并转换成普通的p指针后修改它指向的数据。
 
 #### dynamic_cast
