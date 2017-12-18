#include<stdlib.h>
#include<string.h>
 
char s[7];
int len, len1, i, j, n, point, num;//len是s[]的长度
int ans[200], result[200], a[7], ok, d, m;
 
void F()                                     //乘法函数(与之前用过的模板原理相同)
{
       for ( i=0 ; i < len ; i++ )
              for( j = 0 ; j < len1 ; j++ )
              {
                     result[i + j] += ( a[i] * ans[j] % 10 );
                     result[ i + j + 1 ] += ( a[i] * ans[j] / 10 ) ;
              }
              for( i=0 ; i < len + len1 - 1 ; i++)
              {
            if( result[i] >= 10 )
            {
                            result[i+1] += result[i]/10;
                            result[i] %= 10;
            }
              }
              if( result[len + len1 - 1] != 0)                   //判断高位有没进位
            len1 = len1 + len;
              else
            len1 = len1 + len - 1;
              for( i=0 ; i < len1 ; i++)
            ans[i] = result[i];
}
 
int main()
{
       while( scanf("%s%d", s, &n) != EOF)//S存入的是小数R一共七位（从S[0]开始存入）
       {
              len = strlen(s);
              if( n == 1)           //若是一次方则直接输出
              {
                     printf("%g\n", atof(s));//n为1，情况特殊（把字符串转换成浮点数）
                     continue;
              }
              point = 0;
              ok = 0;
              i = 0;
              j = len - 1;
             
              for ( m=0 ; m < len ; m++)//没分什么小数部分整数部分，一起计算，只要记录小数点位置就Ok
              {
                     if( s[m] == '.' ) //找s[m]中是否是有'.'
                     {
                            ok = 1;        //找到小数点的位置
                            break;
                     }
              }
              if( ok == 1 )       //如果有小数点则执行（j=len-1）
              {
                     while( s[j] == '0' && j >= 0 )
                            j-- ;
                     while( s[j] != '.' && j >= 0)
                            a[i++] = s[j--] - 48;      //(i=0)字符与数字之间的转换
                     //从后往前找,将小数点剔除
                     point = i;
                     j-- ;
              }
             
              num = point * n ;//计算乘方后小数点应该在的位置
             
              for( m=0 ; m <= j ; m++)
                     if( s[m] != '0' )
                            break;
            while( j >= m )                     //从前往后找将整数部分取出
                a[ i++ ] = s[j--] - 48;
                    
                     len=i;
                     len1=len;
                    
                     memset( ans , 0 , sizeof(ans));
           
                     for( i=0 ; i<len ; i++ )
                            ans[i] = a[i];
                    
            for( int k=2 ; k<=n ; k++)//该题关键---计算乘方的次数
            {
                            memset( result , 0 , sizeof(result));//每次计算之后都要清零
                            F();
            }
            d = num - 1;
                    
            for( i = len1-1 ; i >= num ; i-- )  //len1=len
            {
                            if( result[i] != 0 )
                            {
                                   d=i;
                                   break;
                            }
            }
                    
            if( d >= num )               //输出部分是将完整的result分成前后两部分
            {                                        //控制好小数点输出的位置
                            for( i = len1-1 ; i >= num ; i-- )
                                   printf( "%d" , result[i] );
            }
                    
            if( point  != 0 && ok==1)//输出的要求较高
                            printf( "." );
            for( i = num-1 ; i >= 0 ; i--)
                            printf("%d", result[i] );
            putchar(10);
       }
       return 0;
}
