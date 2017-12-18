#include<stdio.h>
#include<string.h>
#define N 500
void quling(char str[])
{
    int n;
    n=strlen(str)-1;
    while(str[n]=='0')
        n--;
    str[n+1]='\0';
}
void Strrev(char str[])
{
    int i,j=0;
    char s[1009];
    for(i=strlen(str)-1;i>=0;i--)
        s[j++]=str[i];
    s[j]='\0';
    strcpy(str,s);
}
int range(char str[])
{
    int i=0,num=0;
    while(str[i]!='.'){
  i++;
  if(str[i]=='\0')
   break;
 }
    if(str[i]!='\0')num--;
    for(;str[i];i++)
    {
        str[i]=str[i+1];
        num++;
    }
    return num;
}
void mul(char str_a[N], char str_b[N], char str_c[N])
{   
    char a[N],b[N];
    int c[2*N];
    char C[2*N];
    int i,j,len_a,len_b;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(C,0,sizeof(C));
    strcpy(a,str_a);strcpy(b,str_b);
    Strrev(a);Strrev(b);
    len_a=strlen(a);len_b=strlen(b);
    for(i=0;i<len_a;i++)
        a[i]=a[i]-'0';
    for(i=0;i<len_b;i++)
        b[i]=b[i]-'0';
    for(i=0;i<len_b;i++)
        for(j=0;j<len_a;j++)
            c[i+j]+=b[i]*a[j];
        for(i=0;i<len_a+len_b;i++)
        {
            c[i+1]=c[i+1]+c[i]/10;
            c[i]=c[i];
        }
        for(i=0;i<len_a+len_b;i++)
            C[i]=c[i]+'0';
        while(C[i]==0||C[i]=='0')i--;
        C[i+1]=0;
        Strrev(C);
        strcpy(str_c,C);
}
int main()
{
    int num,i,len,carry,zeronum;
    char R[20];
    char str_a[500],str_b[500],str_c[500];
    while(scanf("%s %d",R,&num)!=EOF)
    {
  if(strstr(R,".")!=NULL)quling(R);
  zeronum=0;
  if(num==0){printf("1\n");continue;}
        carry=range(R);
  if(carry==0){i=strlen(R)-1;while(R[i]=='0'){i--;zeronum++;}}
        sprintf(str_a,"%s",R);
        str_b[0]='1';
        str_b[1]='\0';
        for(i=1;i<=num;i++)
        {
            mul(str_b,str_a,str_c);
            strcpy(str_b,str_c);
        }
        len=strlen(str_c);
        quling(str_c);
        if(str_c[0]==0){printf("0\n");continue;}
        if(carry*num>len)
        {
            printf(".");
            for(i=0;i<carry*num-len;i++)
                printf("0");
            printf("%s\n",str_c);
        }
        else {
            for(i=0;str_c[i];i++)
            {
                if(i==len-carry*num)printf(".");
                printf("%c",str_c[i]);
            }
   for(i=0;i<zeronum*num;i++)
    printf("0");
            printf("\n");
        }
    }
    return 0;
}