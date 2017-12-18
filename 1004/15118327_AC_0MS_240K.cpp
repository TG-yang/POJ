#include<iostream>

using namespace std;

int main()
{
	double a[12];
	double average=0.0;
	for (int i = 0; i < 12; ++i)
	{
		cin >> a[i]; average += a[i];
	}
	cout <<"$"<< average / 12.0 << endl;
	return 0;
}
