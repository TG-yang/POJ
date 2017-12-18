#include<iostream>
 7 #include<algorithm>
 8 #include<iomanip>
 9 using namespace std;
10 
11 void initial(int* ctoi)  //把字符ch转换为其在手机上对应的数字键
12 {
13     for(int i=0;i<=9;i++)
14         ctoi[i+'0']=i;
15 
16     ctoi['A'] = ctoi['B'] = ctoi['C'] = 2;
17     ctoi['D'] = ctoi['E'] = ctoi['F'] = 3;
18     ctoi['G'] = ctoi['H'] = ctoi['I'] = 4;
19     ctoi['J'] = ctoi['K'] = ctoi['L'] = 5;
20     ctoi['M'] = ctoi['N'] = ctoi['O'] = 6;
21     ctoi['P'] = ctoi['R'] = ctoi['S'] = 7;
22     ctoi['T'] = ctoi['U'] = ctoi['V'] = 8;
23     ctoi['W'] = ctoi['X'] = ctoi['Y'] = 9;
24     return;
25 }
26 
27 int main(int i)
28 {
29     int ctoi['Z'+1];
30     initial(ctoi);
31 
32     int n;  //号码数
33     while(cin>>n)
34     {
35         /*Initial*/
36 
37         int* sort_out=new int[n];  //按字典序存放待输出的电话号码
38 
39         /*Input*/
40 
41         for(i=0;i<n;i++)
42         {
43             int x=0;
44             char s[20];
45             cin>>s;
46 
47             for(int j=0;s[j]!='\0';j++)
48             {
49                 if(s[j]=='-' || s[j]=='Q' || s[j]=='Z')
50                     continue;
51                 x=x*10+ctoi[ s[j] ];
52             }
53             sort_out[i]=x;
54         }
55 
56         /*Sort & Output*/
57 
58         sort(sort_out,sort_out+n);
59 
60         bool flag=true;  //标记是否所有号码都是唯一的
61         for(i=0;i<n;)
62         {
63             int time=0;  //ort_out[i]出现的次数
64             int k=sort_out[i];
65             bool sign=false;  //标记k出现次数是否大于2
66 
67             while(k==sort_out[i] && i<n)
68             {
69                 time++;
70                 i++;
71 
72                 if(time==2)
73                 {
74                     flag=false;
75                     sign=true;
76                 }
77             }
78 
79             if(sign)
80             {
81                 cout<<setfill('0')<<setw(3)<<k/10000;
82                 cout<<'-';
83                 cout<<setfill('0')<<setw(4)<<k%10000;
84                 cout<<' '<<time<<endl;
85             }
86         }
87         if(flag)
88             cout<<"No duplicates."<<endl;
89 
90         delete sort_out;
91     }
92     return 0;
93 }