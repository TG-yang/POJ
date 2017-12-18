#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
int p, e, i, d;
int gcd(int m, int n)//最大公约数，不停取两个数之间的较大者的余数，直到余数为零。
{
	int t;
	if (m < n)
	{
		t = m; m = n; n = t;
	}
	if (n == 0)
		return m;
	else
		return gcd(n, m%n);
}
int lcm(int a, int b)//最小公倍数，两个数乘积除以最大公约数
{
	return (a*b) / gcd(a, b);
}

int main(){
	int cas = 0;
	while (1){
		cin>>p>>e>>i>>d;
		if (p == -1)
			break;
		int pe = lcm(23, 28), pi = lcm(23, 33), ei = lcm(28, 33);

		while ((pe - 1) % 33 != 0)
			pe += lcm(23, 28);
		while ((pi - 1) % 28 != 0)
			pi += lcm(23, 33);
		while ((ei - 1) % 23 != 0)
			ei += lcm(28, 33);

		int sum = pe*i + pi*e + ei*p;
		int lcmt = 23 * 33 * 28;
		int ans = sum%lcmt - d;
		if (ans <= 0) ans += lcmt;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++cas, ans);
	}
}