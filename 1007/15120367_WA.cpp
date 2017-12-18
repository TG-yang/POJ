#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#define MAX 50

struct DNA{
	string s;
	int number;
};
int Mycompare(const DNA*n1, const DNA*n2)
{
	return n1->number - n2->number;//一定是减法，如果不是int强制转换为int例如*(int*)a-*(int*)b
}
int main()
{
	int m, n;
	while (cin >> n >> m)
	{
		DNA a[MAX];
		for (int i = 0; i < m; ++i)
		{
			cin >> a[i].s;
			a[i].number = 0;
			for (int j = 0; j < n; ++j)
			{
				for (int k = j + 1; k < n; ++k)
				{
					if (a[i].s[j]>a[i].s[k])
						++a[i].number;
				}
			}
		}
		qsort(a, m, sizeof(DNA), (int(*)(const void*, const void*))Mycompare);//快拍的使用方法，第一实参为要排序的序列，第二实参为元素个数
		for (int i = 0; i != n; ++i)//第三实参为每个元素所占内存大小，第四实参为自己的排序准则，注意排序准则为（int(*)(const void*,const void*)
			cout << a[i].s << endl;//所以我们要自己手动转换类型
	}
	return 0;
}