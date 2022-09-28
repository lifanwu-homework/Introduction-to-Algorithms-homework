#include <stdio.h>
#include <string.h>
#include<algorithm>
using namespace std;
#define MAX_STRING 1020


int main()
{
    char x[MAX_STRING] = {0}, y[MAX_STRING] = {0};
    int c[2][MAX_STRING] = {0};
    int m, n;
    int LCS_length=0;
    scanf("%s", x + 1);
    scanf("%s", y + 1);
    m = strlen(x + 1), n = strlen(y + 1);
    for (int i = 1; i <= m; i++)//将所有的c[i][j]替换为c[i % 2][j]即可
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == y[j])
            {
                c[i % 2][j] = c[(i - 1) % 2][j - 1] + 1;
            }
            else
            {
                if (c[(i - 1) % 2][j] >= c[i % 2][j - 1])
                {
                    c[i % 2][j] = c[(i - 1) % 2][j];
                }
                else
                {
                    c[i % 2][j] = c[i % 2][j - 1];
                }
            }
            LCS_length=max(LCS_length,c[i%2][j]);
        }
    }
    printf("\nLCS length:%d\n", LCS_length);
}
