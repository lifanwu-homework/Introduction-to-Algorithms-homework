#include <vector>
#include <stdio.h>
#include <queue>
#include <time.h>
using namespace std;
#define MODULE 200000
struct E
{
    int V1;
    int V2;
};
std::vector<E> Edges[MODULE];//边的值的hash表，Edges[3]表示起始点的hash值为2的边的信息，使用vector将产生hash碰撞的边存放在一起
std::vector<int> points[MODULE];//点的值的hash表，points[2]表示hash值为2的点的信息，使用vector将产生hash碰撞的点存放在一起
std::vector<int> visited[MODULE];//已经访问过的点的值的hash表，visited[2]表示hash值为2的已经访问过的点的信息，使用vector将产生hash碰撞的点存放在一起
queue<int> wait_for_visit;
bool point_exist(int point_id)//判断值为point_id的点是否存在
{
    for (int i = 0; i < points[point_id % MODULE].size(); i++)
    {
        if (points[point_id % MODULE][i] == point_id)
            return true;
    }
    return false;
}

bool point_visited(int point_id)//判断是否访问过值为point_id的点
{
    for (int i = 0; i < visited[point_id % MODULE].size(); i++)
    {
        if (visited[point_id % MODULE][i] == point_id)
            return true;
    }
    return false;
}
int bfs_p_num=0;
void BFS()
{
    FILE *fp_out=fopen("sequence.txt","wb");
    int p = 0;
    E E_temp;
    for (int i = 0; i < MODULE; i++)//遍历points
    {
        for (int j = 0; j < points[i].size(); j++)//遍历points中所有hash值为i的点
        {
            if(!point_visited(points[i][j]))//若没有访问过
            {
                wait_for_visit.push(points[i][j]);
                while (!wait_for_visit.empty())
                {
                    p=wait_for_visit.front();
                    wait_for_visit.pop();
                    visited[p%MODULE].push_back(p);
                    fprintf(fp_out,"%d\n",p);
                    bfs_p_num++;
                    for(int x=0;x<Edges[p%MODULE].size();x++)//将与点p相邻的点加入队列中
                    {
                        E_temp=Edges[p%MODULE][x];
                        if(E_temp.V1==p)//判断是否有hash碰撞
                        {
                            if(!point_visited(E_temp.V2))//如果没有访问过，将其加入队列
                            {
                                wait_for_visit.push(E_temp.V2);
                                visited[E_temp.V2%MODULE].push_back(E_temp.V2);
                            }
                        }
                    }
                }
                
            }
        }
    }
}

int main()
{
    int p1, p2;
    E temp_E;
    FILE *fp = fopen("twitter_small.txt", "rb");
    while (fscanf(fp, "%d %d", &p1, &p2) != EOF)
    {
        temp_E.V1 = p1;
        temp_E.V2 = p2;
        Edges[p1 % MODULE].push_back(temp_E);
        // temp_E.V1 = p2;
        // temp_E.V2 = p1;
        // Edges[p2 % MODULE].push_back(temp_E);
        if(!point_exist(p1))
        points[p1 % MODULE].push_back(p1);
        if(!point_exist(p2))
        points[p2 % MODULE].push_back(p2);
    }
    clock_t start=clock();
    BFS();
    clock_t end=clock();
    printf("time:%fs\n",1.0*(end-start)/CLOCKS_PER_SEC);
    int sum=0;
    printf("%d ",bfs_p_num);
    for(int i=0;i<MODULE;i++)
    {
        sum+=points[i].size();
    }
    printf("%d ",sum);
}