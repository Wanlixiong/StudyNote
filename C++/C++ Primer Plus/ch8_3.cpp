#include<iostream>
#include<string>
using namespace std;

void fun_str(string &s);
int main()
{
	string str;
	cout << "Enater a string (q to quit):";
	while (getline(cin, str) && str != "q")
	{
		fun_str(str);
		cout << str << endl;
		cout << "Enater a string (q to quit):";
	}
	return 0;
}

void fun_str(string &s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		s[i] = toupper(s[i]);
		i++;
	}
}