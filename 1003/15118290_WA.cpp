#include<iostream>

using namespace std;

int main()
{
	double len2,len1;
	int i;
	while (cin >> len2)
	{
		len1 = 0.0;
		if (len2 == 0.0)
			return 0;
		for (i = 1;; ++i)
		{
			len1 += 1.0 / (i + 1);
			if (len1 >= len2)
				break;
		}
		cout << i<<endl;
	}
}