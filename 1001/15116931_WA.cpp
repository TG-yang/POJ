#include<iostream>

using namespace std;

int main()
{
	long double R;
	int n;
	while (cin >> R >> n)
	{
		for (int i = 0; i < n; ++i)
			R = R*R;
		cout << R << endl;
	}
	return 0;
}