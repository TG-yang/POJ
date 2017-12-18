#include<iostream>
#include<iostream>
#include<string>
#include<map>

using namespace std;

char Change_number(char a)
{
	switch (a)
	{
	case 'A':
	case 'B':
	case 'C':return '2';
	case 'D':
	case 'E':
	case 'F':return '3';
	case 'G':
	case 'H':
	case 'I':return '4';
	case 'J':
	case 'K':
	case 'L':return '5';
	case 'M':
	case 'N':
	case 'O':return '6';
	case 'P':
	case 'R':
	case 'S':return'7';
	case 'T':
	case 'U':
	case 'V':return '8';
	case 'W':
	case 'X':
	case 'Y':return '9'; 
	default:return a;
	}
}

int main()
{
	int n,len;
	map<string, int>mp;
	string s,str;
	cin >> n;
	map<string, int>::iterator start, end;
	if (n >= 0 && n <= 100000)
	{
		for (int i = 1; i <= n; ++i)
		{
			cin >> str;
			s = "";
			len = str.size();
			for (int i = 0; i < len; ++i)
			{
				if ((str[i] >= 'A'&&str[i] <= 'Y'&&str[i] != 'Q'&&str[i] != 'Z') || (str[i] >= '0'&&str[i] <= '9'))
					s += Change_number(str[i]);
			}
			mp[s] += 1;
		}
		for (start = mp.begin(), end = mp.end(); start != end; ++start)
		{
			if (start->second != 1)
			{
				for (int i = 0; i < 7; ++i)
				{
					cout << start->first[i];
					if (i == 2)
						cout << "-";
				}
				cout << " " << start->second << endl;
			}
		}
	}
	return 0;
}