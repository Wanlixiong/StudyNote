#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

int main()
{
	using namespace std;	
	
	ifstream inFile;
	inFile.open("test1.txt");		//先建立一个已经存在字符的文件test1.txt
	if (!inFile.is_open())		//检查文件是否存在，不存在就提示并结束程序
	{
		cout << "你打开的文件test1.txt不存在"<<endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	int count = 0;		//计算字符数
	char ch;
	inFile >> ch;
	while (inFile.good())
	{
		count++;
		inFile >> ch;
	}

	cout<<"文件test1.txt的字符数为"<<count<<endl;
	inFile.close();
	system("pause");
	return 0;
}

