#include<iostream>
#include<string>
using namespace std;

string Haab[19] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax","zac", "ceh", "mac",
                  "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
string Tzokin[20] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen",
					"eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
struct Data
{
	int days;
	string mouths;
	int years;
};
int main()
{
	int num, days, years,number,mouth;
	int i, j;
	string mouths,pointer;
	Data data[10];
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		cin >> days >> mouths >> years;
		data[i].days = days; data[i].mouths = mouths; data[i].years = years;
	}
	cout << num << endl;
	for ( i = 0; i < num; ++i)
	{
		for ( j = 0; j < 19; ++j)
		{
			if (data[i].mouths == Haab[j])
				break;
		}
		number = data[i].years * 365 + j * 20 + data[i].days;
		years = number / 260; number = number % 260;
		mouth = number % 20; days = number % 13+1;
		cout << days << " " << Tzokin[mouth] << " " << years << endl;
	}
	return 0;
}
