#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quick_sort(int array[], int x, int y)
{
    int i = x + 1, j = y, temp;
    if (x >= y)
        return;
    int keypos=x+rand()%(y-x);//随机选取x到y之间的数作为基准，将其与第一个元素交换，后面就可以复用前面的代码
    int key = array[keypos];
    temp=array[x];
    array[x]=array[keypos];
    array[keypos]=temp;
    
    while (true)
    {
        for (; array[i] <= key && i < y; i++);
        for (; array[j] > key && j > x; j--);
        if (i >= j)
            break;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    temp = array[j];
    array[j] = array[x];
    array[x] = temp;

    quick_sort(array, x, j - 1);
    quick_sort(array, j + 1, y);
}

int main()
{
    FILE *fp_in = fopen("data.txt", "rb");
    int num;
    int *array = NULL;
    fscanf(fp_in, "%d", &num);
    array = (int *)malloc(num * sizeof(int));

    for (int i = 0; i < num; i++)
    {
        fscanf(fp_in, "%d", &array[i]);
    }
    clock_t start=clock();
    quick_sort(array, 0, num);
    clock_t end=clock();
    printf("time:%fs\n",1.0*(end-start)/CLOCKS_PER_SEC);
    FILE *fp_out = fopen("sorted.txt", "wb");
    for (int i = 0; i < num; i++)
    {
        fprintf(fp_out,"%d ", array[i]);
    }
}