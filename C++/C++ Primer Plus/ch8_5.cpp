#include<iostream>

using namespace std;

int main()
{
	int arr0[5] = { 1,2,3,4,5 };
	double arr1[5] = { 1.5,1.4,1.3,1.2,1.2 };
	cout << "Tnt max:" << Max5(arr0) << endl;
	cout << "double max:" << Max5(arr1) << endl;
	return 0;
}

template<class T>
T Max5(T array[5])
{
	T temp;
	temp = array[0];
	for (int i = 1; i < 5; i++)
	{
		if (array[i] > temp)
			temp = array[i];
	}
	return temp;
}