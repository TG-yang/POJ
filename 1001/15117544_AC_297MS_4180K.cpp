#include<iostream>

using namespace std;

char R[10];
int n, pointer;
int mid[999999], a[999999], b[999999];
int lena, lenb, len;

void High_precision()
{
	int i, j;
	memset(mid, 0, sizeof(mid));
	for (i = 1; i <= lena; ++i)
	{
		for (j = 1; j <= lenb; ++j)
		{
			mid[j + i - 1] += a[i] * b[j];
			if (mid[i + j - 1]>9)
			{
				mid[i + j] += mid[i + j - 1] / 10;
				mid[i + j - 1] %= 10;
			}
		}
	}
	lena = lena + lenb;
	for (int i = 1; i <= lena; ++i)
		a[i] = mid[i];
}

int main()
{
	int i, j, up, down;
	while (cin >> R >> n)
	{
		pointer = -1;
		for (i = 5,j=1; i >= 0; --i)
		{
			if (R[i] != '.')
				a[j] = b[j++] = R[i] - '0';
			else
				pointer = i;
		}
		if (pointer == -1)
			lena =lenb= 6;
		else
			lena =lenb= 5;
		for (int i = 1; i <n; ++i)
			High_precision();
		if (pointer == -1)
		{
			for (i = lena ; i >= 1; --i)
				cout << a[i];
			cout << endl;
		}
		else
		{
			pointer = 5 - pointer;
			pointer *= n;
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
			if (up<pointer) i = pointer;
			j = down;
			if (j>pointer) j = pointer + 1;
			for (; i >= j; --i)
			{
				if (i == pointer)
					cout << ".";
				cout << a[i];
			}
			cout << endl;
		}
	}
	return 0;
}