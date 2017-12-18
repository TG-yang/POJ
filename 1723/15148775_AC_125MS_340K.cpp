#include<iostream>
#include<cmath>

using namespace std;

int N;
int sx[10001];
int sy[10001];

int Mycompany(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> sx[i] >> sy[i];
	qsort(sx, N, sizeof(int), Mycompany);
	qsort(sy, N, sizeof(int), Mycompany);
	for (int i = 0; i < N; ++i)
		sx[i] -= i;
	qsort(sx, N, sizeof(int), Mycompany);
	int fy = sy[N / 2];
	int fx = sx[N / 2];
	int move = 0;
	for (int i = 0; i < N; ++i)
	{
		move += abs(sy[i] - fy);
		move += abs(sx[i] - fx);
	}
	cout << move;
	return 0;
}