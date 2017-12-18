#include<iostream>
#include<algorithm>
using namespace std;
const int Max = 65;

int n, len, stick[Max];
bool flag, vis[Max];

int Mycompany(const int*a, const int*b)
{
	return a - b;
}

void dfs(int dep, int now_len, int u)// dep为当前已被用过的小棒数，u为当前要处理的小棒。
{
	if (flag)return;
	if (now_len == 0)
	{
		int k = 0;
		while (vis[k])
			++k;
		vis[k] = true;
		dfs(dep + 1, stick[k], k + 1);
		vis[k] = false;
		return;
	}
	if (now_len == len)//某几个小木棍组合=len，接下来寻找下一组小木棍等于len的
	{
		if (dep == n) flag = true;
		else
			dfs(dep, 0, 0);//寻找下一组小木棍等于len的，所以讲now_len和u置为0；
		return;
	}
	for (int i = u; i < n; ++i)
	{
		if (!vis[i] && now_len + stick[i] <= len)
		{
			if (!vis[i - 1] && stick[i] == stick[i - 1])continue;//不重复的搜索，最重要的剪枝
			vis[i] = true;
			dfs(dep + 1, now_len + stick[i], i + 1);
			vis[i] = false;
		}
	}
}
int main()
{
	while (cin >> n&&n != 0)
	{
		int sum = 0;
		flag = false;
		for (int i = 0; i < n; ++i)
		{
			cin >> stick[i];
			sum += stick[i];
		}
		qsort(stick, n, sizeof(int), (int(*)(const void*, const void*))Mycompany);
		for (len = stick[0]; len < sum; ++len)
		{
			if (sum%len == 0)
			{
				memset(vis, 0, sizeof(vis));
				dfs(0, 0, 0);
				if (flag)
					break;
			}
		}
		cout << len << endl;
	}
	return 0;
}