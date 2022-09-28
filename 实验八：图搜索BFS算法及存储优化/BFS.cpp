#include <stdio.h>
#include <map>
#include <vector>
#include<queue>
using namespace std;
#define MAX_POINT 100
std::map<char, int> point_index;
char Edges[MAX_POINT][MAX_POINT] = {0};
char point_name[MAX_POINT] = {0};
int point_num = 0;

void fileload()
{
    char temp[2 * MAX_POINT] = {0};
    char point1 = 0, point2 = 0;
    FILE *fp = fopen("data.txt", "rb");
    fscanf(fp, "%s", temp);
    for (int i = 0; temp[i] != 0; i++)
    {
        if (temp[i] <= 'Z' && temp[i] >= 'A')
        {
            point_name[point_num] = temp[i];
            point_index[temp[i]] = point_num;
            point_num++;
        }
    }
    while (fscanf(fp, "\n%c-%c", &point1, &point2) != EOF)
    {
        Edges[point_index[point1]][point_index[point2]] = 1;
    }
}

void print_graph()
{
    printf("  ");
    for (int i = 0; i < point_num; i++)
    {
        printf("%c ", point_name[i]);
    }
    printf("\n");
    for (int i = 0; i < point_num; i++)
    {
        printf("%c ", point_name[i]);
        for (int j = 0; j < point_num; j++)
        {
            printf("%d ", Edges[i][j]);
        }
        printf("\n");
    }
}

void BFS()
{
    int visited[MAX_POINT] = {0};
    int p=0;
    queue<int> wait_for_visit;
    wait_for_visit.push(0);
    while (!wait_for_visit.empty())
    {
        p=wait_for_visit.front();
        printf("%c ",point_name[p]);
        wait_for_visit.pop();
        for(int i=0;i<point_num;i++)
        {
            if(Edges[p][i]==1&&visited[i]==0)
            {
                wait_for_visit.push(i);
                visited[i]=1;
            }
        }
    }
    
}

int main()
{
    fileload();
    // print_graph();
    BFS();
}
