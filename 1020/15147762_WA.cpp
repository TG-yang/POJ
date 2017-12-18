#include<iostream>

using namespace std;

int BoxSize;
int n;
int SizeNum[11];
int col[4];

bool DFS(int FillNum)
{
	if (FillNum == n)
		return true;
	int min = 50;
	int prow;
	for (int i = 1; i <= BoxSize; ++i)
	{
		if (min > col[i])
		{
			min = col[i];
			prow = i;
		}
	}
	for (int size = 10; size >= 1; --size)
	{
		if (!SizeNum[size])
			continue;
		if (BoxSize - col[size] >= size&&BoxSize - prow + 1 >= size)
		{
			int wide = 0;
			for (int r = prow; r <= prow + size - 1; ++r)
			{
				if (col[r] <= col[prow])
				{
					++wide;
					continue;
				}
				break;
			}
			if (wide >= size)
			{
				int r;
				SizeNum[size]--;
				for (r = prow; r <= prow + size - 1; ++r)
					col[r] += size;
				if (DFS(FillNum + 1))
					return true;
				++SizeNum[size];
				for (r = prow; r <= prow + size - 1; ++r)
					col[r] -= size;
			}
		}
	}
	return false;
}

int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t)
	{
		memset(SizeNum, 0, sizeof(SizeNum));
		memset(col, 0, sizeof(col));
		cin >> BoxSize >> n;
		int cnt = 0;
		int area = 0;
		for (int i = 1; i <= n; ++i)
		{
			int size;
			cin >> size;
			area += size*size;
			SizeNum[size]++;
			if (size > BoxSize / 2)
				++cnt;
		}
		if (cnt > 1 || area != BoxSize*BoxSize)
		{
			cout << "HUTUTU!" << endl;
			continue;
		}
		if (DFS(0))
			cout << "KHOOOOB!" << endl;
		else
			cout << "HUTUTU!" << endl;
	}
	return 0;
}
