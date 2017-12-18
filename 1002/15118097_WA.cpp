   
#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<string>  
#include<algorithm>  
#include<map>  
using namespace std;  
  
char fun(char a)  
{  
    switch(a)  
    {  
    case 'A':  
    case 'B':  
    case 'C': return '2';  
    case 'D':  
    case 'E':  
    case 'F': return '3';  
    case 'G':  
    case 'H':  
    case 'I': return '4';  
    case 'J':  
    case 'K':  
    case 'L': return '5';  
    case 'M':  
    case 'N':  
    case 'O': return '6';  
    case 'P':  
    case 'R':  
    case 'S': return '7';  
    case 'T':  
    case 'U':  
    case 'V': return '8';  
    case 'W':  
    case 'X':  
    case 'Y': return '9';  
    default: return a;  
    }  
}  
  
int main()  
{  
    int ncase;  
    int len;  
    char str[20];  
    scanf("%d", &ncase);  
    map<string, int>mp;  
    map<string, int>::iterator start, end;  
    string temp;  
    for(int i = 0;i < ncase; ++i)  
    {  
        string s = "";  
        string ans = "";  
        scanf("%s", str);  
        len = strlen(str);  
        for(int i = 0; i < len; ++i)  
            if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))  
                s += fun(str[i]);  
        mp[s] += 1;  
    }  
    for(start = mp.begin(), end = mp.end(); start != end; ++start)  
    {  
        if(start->second != 1)  
        {  
            for(int i = 0; i < 7; ++i)  
            {  
                cout<<start->first[i];  
                if(i == 2)  
                    printf("-");  
            }  
            printf(" %d\n", start->second);  
        }  
    }  
    return 0;  
}  