#include<iostream>

using namespace std;

int a[6];
int b[2000];
bool zero[2000];
bool flag;
int sum,N_number;
void dfs( int new_sum, int n2,int sum)
{
	if (new_sum == 0)
	{
		zero[0]=true;
		dfs( b[0], 1,sum);
		zero[0] = false;
		return;
	}
	if (new_sum == sum / 2)
	{
		flag = true;
		return;
	}
	for (int i = n2;i<N_number ; ++i)
	{
		if (!zero[i] && new_sum + b[i] <= sum)
		{
			zero[i] = true;
			dfs( new_sum + b[i], i + 1,sum);
			zero[i] = false;
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
		cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
		N_number = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];
		if (N_number == 0)
			break;
		for (int i = 0; i < 6; ++i)
			sum += (a[i] * (i + 1));
		for (int i = 5; i >= 0; --i)
		{
			if (a[i] != 0)
			{
				for (int j = 0; j < a[i]; ++j)
				{
					zero[n] = false;
					b[n++] = i + 1;
				}
			}
		}
		++m;
		if (sum % 2 != 0)
		{
			cout << "Collection #"<<m<<": " << endl;
			cout << "Can't be divided"<<endl;
		}
		else
		{
			if (b[0]>sum/2)
			{
				cout << "Collection #" << m << ": " << endl;
				cout << "Can't be divided" << endl;
			}
			memset(zero, 0, sizeof(zero));
			dfs(0, 0,sum);
			if (flag)
			{
				cout << "Collection #" << m << ": " << endl;
				cout << "Can be divided"<<endl;
			}
			else
			{
				cout << "Collection #" << m << ": " << endl;
				cout << "Can't be divided"<<endl;
			}
		}
	}
	return 0;
}