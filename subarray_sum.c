#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int w;
    scanf("%d", &w);

    int a[w];
    int i, j, k, l, m, n;
    i = j = k = l = m = 0;

    for(i = 0; i < w; i++)
        scanf("%d", &a[i]);

    int que[2] = {0};
    int b[30] = {0};

    for(i = 0; i < w; i++) // for add two elements together
    {
        que[k] = a[i];

        for(j = i + 1; j < w; j++)
        {
            for(l = j + 1; l < w; l++)
            {
                if(que[k] + a[j] == a[l]) //add two element and compare each element
                {
                    b[m++] = a[i];
                    b[m++] = a[j];
                    b[m++] = a[l];
                    b[m++] = -1;
                }
            }
            break;
        }
    }

    i = j = k = l = n = 0;


    for(i = 0; i < w; i++) // for add three elements together
    {
        que[k] = a[i];

        for(j = i + 1; j < w; j++)
        {
            for(l = j + 1; l < w; l++)
            {
                for(n = 0; n < w; n++)
                {
                    if(que[k] + a[j] + a[l] == a[n]) //add three elements and compare each element
                    {
                        b[m++] = a[i];
                        b[m++] = a[j];
                        b[m++] = a[l];
                        b[m++] = a[n];
                        b[m++] = -1;
                    }
                }
                break;
            }
            break;
        }
    }

    j = 0;

    while(j < 30)
    {
        if(b[j] != -1 && b[j] != 0)
            printf("%d ", b[j]);

        if(b[j] == -1)
            printf("\n");
        j++;
    }

    return 0;
}
