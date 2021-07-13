#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x;
    scanf("%d", &x);
    int a[x + 1];

    for(int l = 0; l < x; l++)
        scanf("%d", &a[l]);

    int large = f_max(a, x); //find max
    int count[large + 1];

    for(int l = 0; l < large + 1; l++) // initialized to 0
        count[l] = 0;

    for(int l = 0; l < x + 1; l++) // count all elements occurrence from a to count
        count[a[l]]++;

    count[0] = 0; // count array larger than its size coz we count[0] to 0 and rest all occurrence its position

    int b[2][large]; // make 2d array for storing occurrence and their element
    int c[x]; // for storing 2d array to this array by occurrence

    for(int l = 0; l < 2; l++) //initialized by 0
        for(int u = 0; u < large; u++)
            b[l][u] = 0;


    int i = 0, j = 0, k = 0, n = 0, max, flag = 0;

    for(int l = 0; l < large; l++)
    {
        max = count[l];

        for(int m = 0; m <= large; m++)
        {
            if(max < count[m])
            {
                max = count[m];
                n = m;
                flag = 1;
            }
        }
        if(flag) //if max found from inner loop then take its information
        {
            b[0][j] = max;
            b[1][i] = n;
            count[n] = 0; // every time initialized 0 when found that element
            flag = 0;
        }
        else //if max not found from inner loop then consider outer loop
        {
            b[0][j] = max;
            b[1][i] = l;
            count[l] = 0; // every time initialized 0 when found that element
        }
        j++;
        i++;
    }

    k = n = j = i = 0;
    int y = large, r;

    //copying elements from 2d array to 1d array
    while(y)
    {
        for(r = b[0][j]; r > 0; r--)
        {
            c[k] = b[1][i];
            k++;
        }
        i++;
        j++;
        y--;
    }

    for(j = 0; j < x; j++)
        printf("%d ", c[j]);

    return 0;
}

int f_max(int *arr, int size)
{
    int i, max = arr[0];
    for(i = 1; i < size; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}
