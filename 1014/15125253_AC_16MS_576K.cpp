#include<iostream>

using namespace std;

int a[7];
bool flag;
int sum;
void dfs( int new_sum, int n2,int sum)
{
	if (flag)
		return;
	if (new_sum == sum / 2)
	{
		flag = true;
		return;
	}
	for (int i = n2;i>0 ; --i)
	{
		if (a[i])
		{
			if (new_sum + i <= sum/2)
			{
				--a[i];
				dfs(new_sum + i,i, sum);
				if (flag) break;
			}
		}
	}
}
int main()
{
	int m = 0;
	while (1)
	{
		int n = 0;
		int sum = 0;
		flag = false;
		cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];
		for (int i = 1; i < 7; ++i)
			sum += (a[i] * i);
		if (sum == 0)
			break;
		++m;
		if (sum % 2 != 0)
		{
			cout << "Collection #"<<m<<": " << endl;
			cout << "Can't be divided." << endl << endl;
			continue;
		}
		else
		{
			dfs(0,6,sum);
			if (flag)
			{
				cout << "Collection #" << m << ": " << endl;
				cout << "Can be divided." << endl << endl;
				continue;
			}
			else
			{
				cout << "Collection #" << m << ": " << endl;
				cout << "Can't be divided." << endl << endl;
				continue;
			}
		}
	}
	return 0;
}