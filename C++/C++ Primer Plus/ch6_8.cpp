#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

int main()
{
	using namespace std;	
	
	ifstream inFile;
	inFile.open("test1.txt");		//�Ƚ���һ���Ѿ������ַ����ļ�test1.txt
	if (!inFile.is_open())		//����ļ��Ƿ���ڣ������ھ���ʾ����������
	{
		cout << "��򿪵��ļ�test1.txt������"<<endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	int count = 0;		//�����ַ���
	char ch;
	inFile >> ch;
	while (inFile.good())
	{
		count++;
		inFile >> ch;
	}

	cout<<"�ļ�test1.txt���ַ���Ϊ"<<count<<endl;
	inFile.close();
	system("pause");
	return 0;
}

