#include<iostream>
#include<cmath>

using namespace std;

const double e = 2.7182818284590452354, pi = 3.141592653589793239;
double strling_digits_num(int n)
{
	return log10(2 * pi*n) / 2.0 + n*(log10(n / e));
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		double m = 0;
		m = strling_digits_num(n);
		int answer = (int)m;
		answer++;
		cout << answer << endl;
	}
	return 0;
}