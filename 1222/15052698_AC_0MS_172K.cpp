#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int MAXN=40;

//有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
int equ,var;
int a[MAXN][MAXN];//增广矩阵
int x[MAXN];//解集


int  Gauss()
{
    int i,j,k;
    int max_r;
    int col;
    int temp;

    col=0;
    for(k=0;k<equ&&col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
        {
            if(abs(a[i][col])>abs(a[max_r][col]))max_r=i;
        }
        if(max_r!=k)
        {
            for(j=col;j<var+1;j++)swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0)
        {
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++)
        {
            if(a[i][col]!=0)
            {
                for(j=col;j<var+1;j++)
                  a[i][j]^=a[k][j];
            }
        }
    }
    for(i=var-1;i>=0;i--)
    {
        x[i]=a[i][var];
        for(j=i+1;j<var;j++)
          x[i]^=(a[i][j]&&x[j]);
    }
    return 0;
}

void init()
{
    memset(a,0,sizeof(a));
    equ=30;
    var=30;
    for(int i=0;i<5;i++)
       for(int j=0;j<6;j++)
       {
           int t=i*6+j;
           a[t][t]=1;
           if(i>0)a[(i-1)*6+j][t]=1;
           if(i<4)a[(i+1)*6+j][t]=1;
           if(j>0)a[i*6+j-1][t]=1;
           if(j<5)a[i*6+j+1][t]=1;
       }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   int T;
   scanf("%d",&T);
   int iCase=0;
   while(T--)
   {
       iCase++;
       init();
       for(int i=0;i<30;i++)scanf("%d",&a[i][30]);
       Gauss();
       printf("PUZZLE #%d",iCase);
       for(int i=0;i<30;i++)
       {
           if(i%6==0)printf("\n%d",x[i]);
           else printf(" %d",x[i]);
       }
       printf("\n");
   }
   return 0;
}