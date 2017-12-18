#include<iostream>  
#include<cstdio>  
#include<cmath>  
using namespace std;
int value[100], customer[1000], n, m;
typedef struct fun
{
	int type, amout, Max;//种类，数量，最大价值
	int sign;
	int t[5];
}rr;
fun a[100];
int q[5];
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void dfs(int i, int s, int sum, int type, int amout, int Max, int p)
{
	int j;
	if (sum == s)//已经拼满了  
	{
		if (type>a[i].type)
		{
			a[i].sign = 0;
			a[i].type = type; a[i].amout = amout; a[i].Max = Max;
			for (j = 1; j <= a[i].amout; j++)
				a[i].t[j] = q[j];
		}
		else if (type == a[i].type)
		{
			if (amout<a[i].amout)
			{
				a[i].sign = 0;
				a[i].type = type; a[i].amout = amout; a[i].Max = Max;
				for (j = 1; j <= a[i].amout; j++)
					a[i].t[j] = q[j];
			}
			else if (amout == a[i].amout)
			{
				if (Max>a[i].Max)
				{
					a[i].sign = 0;
					a[i].type = type; a[i].amout = amout; a[i].Max = Max;
					for (j = 1; j <= a[i].amout; j++)
						a[i].t[j] = q[j];
				}
				else if (Max == a[i].Max)
				{
					a[i].sign = 1;
				}
			}
		}
		return;
	}
	if (amout == 4)//总的已经有四个了  
		return;
	int e;
	for (j = p; j<n; j++)
	{
		if (sum + value[j]>s)//已经放不下了  
		{
			return;
		}
		if (j == p && type != 0)
		{
			e = q[amout + 1];
			q[amout + 1] = value[j];
			dfs(i, s, sum + value[j], type, amout + 1, Max>value[j] ? Max : value[j], j);
			q[amout + 1] = e;
		}
		else
		{
			e = q[amout + 1];
			q[amout + 1] = value[j];
			dfs(i, s, sum + value[j], type + 1, amout + 1, Max>value[j] ? Max : value[j], j);
			q[amout + 1] = e;
		}
	}
}
int main()
{
	int i, j;
	while (scanf_s("%d", &value[0]) != EOF)
	{
		i = 1;
		while (scanf_s("%d", &value[i]))
		{
			if (value[i] == 0)
				break;
			i++;
		}
		n = i;
		i = 0;
		while (scanf_s("%d", &customer[i]))
		{
			if (customer[i] == 0)
				break;
			i++;
		}
		m = i;//顾客的人数  
		qsort(value, n, sizeof(int), cmp);//对价值进行升序排列的   

		for (i = 0; i<m; i++)
		{
			a[i].amout = INT_MAX; a[i].Max = 0; a[i].type = 0;
			a[i].sign = 0;
			dfs(i, customer[i], 0, 0, 0, 0, 0);
			if (a[i].sign == 1)
				printf("%d (%d): tie\n", customer[i], a[i].type);
			else if (a[i].amout == INT_MAX && a[i].Max == 0 && a[i].type == 0)
			{
				printf("%d ---- none\n", customer[i]);
			}
			else
			{
				printf("%d (%d):", customer[i], a[i].type);
				for (j = 1; j <= a[i].amout; j++)
					printf(" %d", a[i].t[j]);
				printf("\n");
			}
		}
	}
	return 0;
}