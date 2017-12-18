#include <iostream>  
#include <string>  
#include <algorithm>  
  
using namespace std;  
  
struct dna  
{  
    int num;  
    string s;  
}DNA[105];  
  
int inversionNum(string s)  
{  
    int ans = 0;  
    int A, C, G;  
    A = C = G = 0;  
    for(int i = s.length() - 1; i >= 0; i--)  
    {  
        switch (s[i]) {  
            case 'A':  
                A++;  
                break;  
            case 'C':  
                C++;  
                ans += A;  
                break;  
            case 'G':  
                G++;  
                ans += A;  
                ans += C;  
                break;  
            case 'T':  
                ans += A;  
                ans += C;  
                ans += G;  
        }  
    }  
    return ans;  
}  
  
bool operator < (struct dna a, struct dna b)  
{  
    return a.num < b.num;  
}  
  
int main()  
{  
    int n, m;  
    while (cin>>n>>m) {  
        for (int i = 0; i < m; i++) {  
            cin>>DNA[i].s;  
            DNA[i].num = inversionNum(DNA[i].s);  
        }  
        sort(DNA, DNA+m);  
        for (int i = 0; i < m; i++) {  
            cout << DNA[i].s << endl;  
        }  
    }  
} 