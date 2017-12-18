#include<iostream>

using namespace std;
const int Maxlen = 200;
struct
{
	int child[Maxlen];
	int chNum;
}tree[Maxlen];

int cmp(const void*a, const void*b)
{
	return *(int*)b - *(int*)a;
}
int min(int a, int b)
{
	return a > b ? b : a;
}
int least(int f)
{

	int i, j, result;
	int node[200];
	if (!tree[f].chNum)
		return 1;
	for (j = i = 0; i < tree[f].chNum; ++i)
	{
		node[j++] = least(tree[f].child[i]);
	}
	qsort(node, j, sizeof(int), cmp);
	result = node[0];
	for (i = 1; i < j; ++i)
	{
		result = result + node[i] - min(result - i, node[i]);
	}
	return result;
}

int main()
{
	int n, id, m, num_node, i;
	cin >> n;
	while (n--)
	{
		cin >> m;
		while (m--)
		{
			cin >> id >> num_node;
			tree[id].chNum = num_node;
			for (i = 0; i < num_node; ++i)
				cin >> tree[id].child[i];
		}
		cout << least(1) << endl;
	}
	return 0;
}