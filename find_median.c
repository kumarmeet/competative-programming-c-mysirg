#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a1;
    int b1;

    scanf("%d%d", &a1, &b1);

    int a[a1];
    int b[b1];

    for(int t = 0; t < a1; t++)
      scanf("%d", &a[t]);

    for(int t = 0; t < b1; t++)
      scanf("%d", &b[t]);

    size_t _a = sizeof(a) / sizeof(int);
    size_t _b = sizeof(b) / sizeof(int);

    //sort element (merging is possible when lists must be sorted)
    bubble_sort(a, _a);
    bubble_sort(b, _b);

    size_t _m = _a + _b;

    int merge[_m];
    int i, j, k;
    i = j = k = 0;

    //merge a[] and b[]
    while(i < _a && j < _b)
    {
        if(a[i] < b[j])
            merge[k++] = a[i++];
        else
            merge[k++] = b[j++];
    }

    for(; i < _a ; i++)
        merge[k++] = a[i];

    for(; j < _b ; j++)
        merge[k++] = b[j];

    int mid = merge[_m / 2];


    if(_m % 2 == 0) // if size of merge[] is even then it will got real number
      {
        for(i = 0; i < mid - 1; i++);
        float median1 = (float)(mid + i) / 2;
        printf("%.2f", median1);
      }
    else
      {
        for(i = 0; i < mid; i++);
        int median2 = (mid + i) / 2;
        printf("%d", median2);
      }

    return 0;
}

void bubble_sort(int *arr, int size)
{
    int flag;

    for(int i = 0; i < size -1; i++)
    {
        flag = 1;
        for(int j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 0;
            }
        }
        if(flag)
            break;
    }
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
