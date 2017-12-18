#include<iostream>

using namespace std;

int main()
{
	int a[6];
	while (1)
	{
		int i,j,n=0,n1=0,n2=0,sum=0;
		for (i = 0; i < 6; ++i)
		{
			cin >> a[i];
			sum += a[i];
		}
		if (sum == 0)
			break;
		for (i = 5; i >= 0; --i)
		{
			if (i == 5)
				n += a[i];
			else if (i == 4)
			{
				n += a[i];
				n1 += (a[i] * 11);
			}
			else if (i == 3)
			{
				n += a[i];
				n2 += (a[i] * 5);
			}
			else if (i == 2)
			{
				if (a[i] % 4 == 0)
					n += a[i] / 4;
				else
				{
					n += (a[i] / 4 + 1);
					if (a[i] % 4 == 1)
					{
						n1 += 7; n2 += 5;
					}
					else if (a[i] % 4 == 2)
					{
						n1 += 6; n2 += 3;
					}
					else if (a[i] % 4 == 3)
					{
						n1 += 5; n2 += 1;
					}
				}
			}
			else if (i == 1)
			{
				if (n2 >= a[i])
					n1 += (n2 - a[i]) * 4;
				else
				{
					if ((a[i] - n2) % 9 == 0)
						n += ((a[i] - n2) / 9);
					else
					{
						n += ((a[i] - n2) / 9 + 1);
						n1 += (36 - ((a[i] - n2) % 9) * 4);
					}
				}
			}
			else
			{
				if (n1 < a[i])

				{
					if (a[i] % 36 == 0)
						n += ((a[i] - n1) / 36);
					else
						n += ((a[i] - n1) / 36 + 1);
				}
			}
		}
		cout << n << endl << endl;
	}
	return 0;
}