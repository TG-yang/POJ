include <stdio.h>
#include <string.h>
 
int len; // total length of exponentiation result
int product[126] = {0}; // storing result, at most length 5*25 + 1 = 126
 
void multiply(int a[], int n)
{
    int i;
    int carry = 0; // a carry number in multiplying
    for (i = 0; i < len; i++)
    {
        int temp = a[i]*n + carry;
        a[i] = temp % 10;
        carry = temp / 10;      
    }
    while (carry)
    {
        a[i++] = carry % 10;
        carry /= 10;
    }
    len = i;
}
 
int main(int argc, char* argv[])
{
    int n;  // power n
    char s[6]; // real number R, at most the length is 6
    while (scanf("%s %d", s, &n) != EOF)
    {
        int position=0, i=0, num=0, j=0;
        for (i=0; i<strlen(s); i++) 
        {
            if (s[i] == '.')
            {
                position = (strlen(s) - 1 - i) * n; // calculate decimal point position after R^n
            }
            else
            {
                num = num*10 + s[i] - 48; // transfer float to integer
            }       
        }
         
        // product calculation 
        product[0]=1;
        len = 1;
        for (i = 0; i < n; i++)
        {
            multiply(product, num);
        }
 
        // format output
        if (len <= position) // product is less than 1
        {
            printf("."); // print decimal point
            for (i=0; i<position-len; i++)
            {
                printf("0"); // print zero between decimal point and decimal
            }
 
            j = 0;
            //while (product[j] == 0) // trim trailing zeros
            //{
            //    j++;
            //}
            for (i=len-1; i>=j; i--)
            {
                printf("%d", product[i]);
            }
        }   
        else
        {
            j=0;
            while (product[j]==0 && j<position) // trim trailing zeros
            {
                j++;
            }
            for (i=len-1; i>=j; i--)
            {
                if (i+1 == position) // cause index in C language starts from 0
                {
                    printf(".");
                }
                printf("%d", product[i]);
            }
        }
        printf("\n");
    }