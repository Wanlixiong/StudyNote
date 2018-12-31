#include<iostream>
#include<cstring>
using namespace std;
struct stringy
{
	char * str;
	int ct;
};

void set(stringy &beany, char *tes1);
void show(const stringy b, int n = 1);
void show(const char *tes2, int n = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done! ");


	return 0;
}


void set(stringy &beany, char *tes1)
{
	beany.str = new char;
	beany.str = tes1;
	beany.ct = strlen(tes1);
	cout << "set()...: str= " << beany.str << " ct=" << beany.ct << endl;
}

void show(stringy b, int n)
{
	cout << "show()... beany: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "str = " << b.str << " "
			<< "str = " << b.ct << endl;
	}
}

void show(const char *tes2, int n)
{
	cout << "show()... testing: \n";
	for (int i = 0; i < n; i++)
	{
		cout << tes2 << endl;
	}
}