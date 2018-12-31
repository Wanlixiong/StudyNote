#### floor() 函数
向下取整，floor(x)获得不大于x参数且最靠近参数x的整数，x参数可以是整数（正负）和浮点数（正负）。  

- 示例：
  
```c++
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x = 10.99, result;
	result = floor(x);
	cout << "floor 1#: " << x << " = " << result << endl;

	x = -10.99;
	result = floor(x);
	cout << "floor 2#: " << x << " = " << result << endl;

	x = 0.99;
	result = floor(x);
	cout << "floor 3#: " << x << " = " << result << endl;

	x = 10;
	result = floor(x);
	cout << "floor 4#: " << x << " = " << result << endl;

	x = -10;
	result = floor(x);
	cout << "floor 5#: " << x << " = " << result << endl;

	return 0;
}
```
```
floor 1#: 10.99 = 10
floor 2#: -10.99 = -11
floor 3#: 0.99 = 0
floor 4#: 10 = 10
floor 5#: -10 = -10
```