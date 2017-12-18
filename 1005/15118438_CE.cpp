#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n;
	double pi = acos(-1);
	double x, y,years;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		years = pi*(x*x + y*y) / 100;
		cout << "Property: " << i+1 << " This property will begin eroding in year " << (int)years + 1<<"."<< endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}