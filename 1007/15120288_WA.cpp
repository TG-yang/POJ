#include<iostream>
#include<map>
#include<string>

using namespace std;
#define MAX 50

struct DNA{
	string s;
	int number;
};
int Mycompare(const DNA*n1, const DNA*n2)
{
	return n1->number - n2->number;
}
int main()
{
	int m, n;
	DNA a[MAX];
	while (cin >> n >> m)
	{
		if (n > 0 && n <= 50 && m > 0 && m <=100)
			break;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i].s;
		a[i].number = 0;
		for (int j = 0; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				if (a[i].s[j]>a[i].s[k])
					++a[i].number;
			}
		}
	}
	qsort(a, m, sizeof(DNA), (int(*)(const void*,const void*))Mycompare);
	for (int i = 0; i != n; ++i)
		cout << a[i].s << endl;
	return 0;
}