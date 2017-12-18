#include<iostream>
using namespace std;

typedef struct {
int x,y;
}node;

node Node[100050];
int n,m; 

int cmp(const void* a,const void* b){
if((*((node*)a)).x!=(*((node*)b)).x) return (*((node*)a)).x-(*((node*)b)).x;
else return (*((node*)a)).y-(*((node*)b)).y;
}

int check(int y)
{
int count=0;
int r_x=Node[0].x-(Node[0].y-y);
int l_x=Node[0].x+(Node[0].y-y);
for(int i=1;i<n;i++){
int r=Node[i].x-(Node[i].y-y);
int l=Node[i].x+(Node[i].y-y);
if(l_x<r) { r_x=r;l_x=l; count++; if(count>=m) return 0;}
else{
if(r>=r_x&&r<=l_x&&l>l_x)  r_x=r;
else if(r>=r_x&&l<=l_x){ r_x=r;l_x=l;}
}
if(count>=m) return 0;
}
return 1;
}

int main()
{
int num,ans[10000];
scanf("%d",&num);
for(int j=0;j<num;j++){
scanf("%d%d",&n,&m);
for(int i=0;i<n;i++)
scanf("%d%d",&Node[i].y,&Node[i].x);
qsort(Node,n,sizeof(Node[0]),cmp);
int k=0;
for(int i=1;i<n;i++)
if(Node[k].y>Node[i].y) k=i;
int high=Node[k].y,low=-2000050;
int mid=(high+low)/2;
int g=0;
while(low<=high){
if(check(mid)) {ans[j]=mid;low=mid+1;}
else {high=mid-1;}
mid=(high+low)/2;
}
}
for(int j=1;j<=num;j++)
printf("Case %d: %d\n",j,ans[j-1]);
}