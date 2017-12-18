#include<stdio.h>  
char map[21][21];  
int c;  
int n,m;  
void count(char map[21][21],int i,int j){  
    map[i][j]='#';  
    if(i+1< m&&map[i+1][j]=='.'){  
        c++;  
        count(map,i+1,j);  
    }  
    if(i-1>-1&&map[i-1][j]=='.'){  
        c++;  
        count(map,i-1,j);  
    }  
    if(j+1<n&&map[i][j+1]=='.'){  
        c++;  
        count(map,i,j+1);  
    }  
    if(j-1>-1&&map[i][j-1]=='.'){  
        c++;  
        count(map,i,j-1);  
    }  
}  
int main(){  
  
    int i,j;  
    //freopen("in.txt","r",stdin);  
    while(scanf("%d%d",&n,&m)&&n){  
        for(i=0;i<m;i++){  
            scanf("%s",map[i]);  
        }  
        for(i=0;i<m;i++){  
            for(j=0;j<n;j++){  
                if(map[i][j]=='@'){  
                    c=1;  
                    count(map,i,j);  
                    printf("%d\n",c);  
                }  
  
            }  
        }  
    }  
}  