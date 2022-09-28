#include <stdio.h>
#include <string.h>
#include<algorithm>
using namespace std;
#define MAX_STRING 1020


int main()
{
    char x[MAX_STRING] = {0}, y[MAX_STRING] = {0};
    int c[MAX_STRING] = {0};
    int m, n;
    int temp;
    int LCS_length=-1;
    scanf("%s", x + 1);
    scanf("%s", y + 1);
    m = strlen(x + 1), n = strlen(y + 1);
    for(int i=1;i<=m;i++)
    {//使用O(min(m,n))的空间求出最长公共子序列长度
        temp=0;
        for(int j=1;j<=n;j++)
        {
            int temp2;
            if(x[i]==y[j])
            {
                temp2=c[j-1]+1;
            }
            else if(c[j]>=temp)
            {
                temp2=c[j];
            }else{
                temp2=temp;
            }
            LCS_length=max(LCS_length,temp2);
            c[j-1]=temp;
            temp=temp2;
        }
        c[m]=temp;
    }
    printf("\nLCS length:%d\n", LCS_length);
}
