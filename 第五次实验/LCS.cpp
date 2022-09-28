#include <stdio.h>
#include <string.h>
#define MAX_STRING 1020
#define OBLIQUE_ARROW 1
#define VERTICAL_ARROW 2
#define HORIZONTAL_ARROW 3
int LCS_length=0;
int lcs_length(int c[MAX_STRING][MAX_STRING], char b[MAX_STRING][MAX_STRING], char x[], char y[], int m, int n)
{//由输入的x，y求出输出的c，b

    for (int i = 0; i < m; i++)
    {
        c[i][0] = 0;
    }
    for (int j = 0; j < n; j++)
    {
        c[0][j] = 0;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (x[i-1] == y[j-1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = OBLIQUE_ARROW;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = VERTICAL_ARROW;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = HORIZONTAL_ARROW;
            }
        }
    }
}

void print_LCS(char b[MAX_STRING][MAX_STRING], char x[], int m, int n)
{
    if (m == 0 || n == 0)
        return;
    // printf("%d %d %d*\n",b[m][n],m,n);
    if (b[m][n] == OBLIQUE_ARROW)
    {
        print_LCS(b, x, m - 1, n - 1);
        printf("%c ", x[m-1]);
        LCS_length++;
    }
    else if (b[m][n] == VERTICAL_ARROW)
    {
        print_LCS(b, x, m - 1, n);
    }
    else if (b[m][n] == HORIZONTAL_ARROW)
    {
        print_LCS(b, x, m, n - 1);
    }
}

int main()
{
    char x[MAX_STRING] = {0}, y[MAX_STRING] = {0};
    char b[MAX_STRING][MAX_STRING] = {0};
    int c[MAX_STRING][MAX_STRING] = {0};
    int m, n;

    scanf("%s", x);
    scanf("%s", y);
    m = strlen(x), n = strlen(y);
    lcs_length(c, b, x, y, m+1, n+1);
    print_LCS(b, x, m, n);
    printf("\nLCS length:%d\n",LCS_length);
}
