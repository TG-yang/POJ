#include<iostream>

using namespace std;

int main()
{
	int a[12];
	int average=0;
	for (int i = 0; i < 12; ++i)
	{
		cin >> a[i]; average += a[i];
	}
	cout <<"$"<< average / 12 << endl;
	return 0;
}
