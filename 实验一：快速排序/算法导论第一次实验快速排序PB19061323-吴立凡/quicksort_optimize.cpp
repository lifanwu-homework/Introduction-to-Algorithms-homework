#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define K 5

void insertsort(int a[],int n)//插入排序算法
{
    for(int i= 1; i<n; i++){
        if(a[i] < a[i-1]){
            int j= i-1;
            int x = a[i];
            while(j>-1 && x < a[j]){  
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = x;
        }
    }

}

void quick_sort(int array[], int x, int y)
{
    int i = x + 1, j = y, temp;
    int key = array[x];
    if (y-x<=K-1)//在数组长度小于k时，直接进行插入排序并返回
    {
        insertsort(&array[x],y-x);
        return;
    }
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