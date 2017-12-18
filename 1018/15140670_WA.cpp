#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

class info
{
public:
	int B;
	double P;
	int id;
};

int cmp(const void*a, const void*b)
{
	info*x = (info*)a;
	info*y = (info*)b;
	if ((x->B) == (y->B))
	{
		if ((x->P) == (y->B))
			return (x->id) - (y->id);
		return (x->P) - (y->P);
	}
	return (x->B) - (y->B);
}

double max(double a, double b)
{
	return a > b ? a : b;
}

int main(int i, int j)
{
	int test;
	int a[101] = { -1 };
	cin >> test;
	for (int t = 1; t <= test; ++t)
	{
		int n;
		int m = 0;
		cin >> n;
		int*MaxB = new int[n + 1];
		info*dev = new info[100 * 100 + 1];
		int pd = 0;
		for (i = 1; i <= n; ++i)
		{
			int mi;
			cin >> mi;
			m += mi;
			MaxB[i] = -i;
			for (j = 1; j <= mi; ++j)
			{
				++pd;
				cin >> dev[pd].B >> dev[pd].P;
				dev[pd].id = i;
				MaxB[i] = max(MaxB[i], dev[pd].B);
			}
		}
		qsort(dev, m + 1, sizeof(info), cmp);
		double ans = 0;
		for (i = 1; i <= m - (n - 1); ++i)
		{
			double price = 0;
			int pb = 0;
			memset(a, 0, sizeof(a));
			a[dev[i].id] = dev[i].P;
			for (j = i + 1; j <= m; ++j)
			{
				if (dev[j].id != dev[i].id)
					a[dev[j].id] = max(dev[j].P, a[dev[j].id]);
			}
			for (j =1; j <= n; ++j)
			{
				if (a[j] == -1)
				{
					break;
					pb = 1;
				}
				price += a[j];
			}
			if (pb == 1)
				break;
			ans = max(ans, (dev[i].B / price));
		}
		cout << fixed << setprecision(3) << ans << endl;
		delete MaxB;
		delete dev;
	}
	return 0;
}
