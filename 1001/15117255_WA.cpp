#include<iostream>  
using namespace std;
char str[10];
int n, dot;
int res[999999], a[999999], b[999999];
int len, lena, lenb;

void High_precision()
{
	int i, j;
	for (i = 1; i <= lena; i++)
	{
		for (j = 1; j <= lenb; j++)
		{
			res[i + j - 1] += a[i] * b[j];
			if (res[i + j - 1]>9)
			{
				res[i + j] += res[i + j - 1] / 10;
				res[i + j - 1] %= 10;
			}
		}
	}
	if (res[lena + lenb - 1]>9)
	{
		res[lena + lenb] += res[lena + lenb - 1] / 10;
		res[lena + lenb - 1] %= 10;
	}
	lena = lena + lenb;
	for (i = 1; i <= lena; i++) a[i] = res[i];
}

int main()
{
	int i, j, up, down;
	while (cin>>str>>n)
	{
		dot = -1;
		for (i = 5, j = 1; i >= 0; i--)
		{
			if (str[i] != '.') a[j] = b[j++] = str[i] - '0';
			else dot = i;
		}
		if (dot == -1) lena = lenb = 6;
		else lena = lenb = 5;
		for (i = 1; i<n; i++)
			High_precision();
		if (dot == -1)
		{
			for (i = lena; i >= 1; i--) printf("%d", a[i]);
			printf("\n");
		}
		else
		{
			--dot;
			dot *= n;
			for (i = 1; i <= lena; i++)
			{
				if (a[i] != 0)
				{
					down = i;
					break;
				}
			}
			for (j = lena; j >= 1; j--)
			{
				if (a[j] != 0)
				{
					up = j;
					break;
				}
			}
			i = up;
			if (up<dot) i = dot;
			j = down;
			if (j>dot) j = dot + 1;
			for (; i >= j; i--)
			{
				if (i == dot) printf(".");
				printf("%d", a[i]);
			}
			printf("\n");
		}
	}
	return 0;
}