#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quick_sort(int array[], int x, int y)
{
    int i = x + 1, j = y, temp;
    int key = array[x];//基准选择为数组的第一个元素
    if (x >= y)
        return;//当数组只有一个元素的时候，直接返回
    while (true)//对整个数组按照第一个元素进行partion，将小于x的数放在最后返回的j的左边，大于x的数放在最后返回的j的右边
    {
        for (; array[i] <= key && i < y; i++);
        for (; array[j] > key && j > x; j--);
        if (i >= j)
            break;
        temp = array[i];//交换左边大于x的元素和右边小于x的元素
        array[i] = array[j];
        array[j] = temp;
    }
    temp = array[j];//将第一个指标元素与第j个元素交换，此时，第j个元素左边的元素均小于j，右边的元素均大于j
    array[j] = array[x];
    array[x] = temp;

    quick_sort(array, x, j - 1);//递归对左侧和右侧经行排序
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