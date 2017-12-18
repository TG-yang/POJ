#include<iostream>  
#include<cmath>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; ++i)
	{
		char left[3][6], right[3][6], status[3][6];
		int times['L' + 1] = { 0 };//**********
		bool zero['L' + 1] = { false };//***********w
		for (int j = 0; j < 3; ++j)
			cin >> left[j] >> right[j] >> status[j];//***************
		for (int k = 0; k < 3; ++k)
		{
			switch (status[k][0])
			{
			case 'u':
				for (int j = 0; left[k][j]; ++j)//此处判断条件为left..是因为用空格的存在
				{
					times[left[k][j]]++;
					times[right[k][j]]--;
				}
				break;
			case 'd':
				for (int j = 0; left[k][j]; ++j)
				{
					times[left[k][j]]--;
					times[right[k][j]]++;
				}
				break;
			case 'e':
				for (int j = 0; left[k][j]; ++j)
				{
					zero[left[k][j]] = true;
					zero[right[k][j]] = true;
				}
				break;
			}
		}
		int max = -1;
		char the_end;
		for (int j = 'A'; j <= 'L'; ++j)
		{
			if (zero[j])
				continue;
			if (max <= abs(times[j]))
			{
				max = abs(times[j]);
				the_end = j;
			}
		}
		cout << the_end << " is the counterfeit coin and it is ";
		if (times[the_end] > 0)
			cout << "heavy." << endl;
		else
			cout << "light." << endl;
	}
	return 0;
}
	