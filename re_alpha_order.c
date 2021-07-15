#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //each capital and small letters has index and in this program's approach based on letters indices
    char capital[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char small[] = "abcdefghijklmnopqrstuvwxyz";

    char str[100];
    gets(str);

    size_t len = strlen(str);

    char s[len];
    int order[len]; // this is for storing location / index of alphabets

    int j = 0, k = 0, l = 0, cap_index, low_index;

    //storing index number of alphabets
    for(int i = 0; str[i]; i++)
    {
        while(capital[j])
        {
            if(capital[j] == str[i])
            {
                cap_index = j;
                order[l] = cap_index;
                break;
            }
            j++;
        }

        while(small[k])
        {
            if(small[k] == str[i])
            {
                low_index = k;
                order[l] = low_index;
                break;
            }
            k++;
        }

        l++;
        j = k = 0;
    }

    insertion_sort(order, len); // sort order[] elements increasing order

    j = k = l = 0;
    int m = 0, n = 0, p = 0;

  //comparisons of capital and small using order[] index
    while(str[j])
    {
      while(str[k])
      {
        if(str[k] == capital[order[l]]) // compare if order index[] same as str[] for capital
          {
            s[p] = str[k];
            str[k] = '0';
            p++;
            break;
          }
          k++;
      }

      while(str[m])
      {
        if(str[m] == small[order[l]]) // compare if order index[] same as str[] for small
          {
            s[p] = str[m];
            str[m] = '0';
            p++;
            break;
          }
          m++;
      }
      l++;
      j++;
      k = m = 0; // every time starts from beginning str[] for comparison capital and small
    }

    for(int i = 0; i < len; i++)
      printf("%c",s[i]);

    return 0;
}

void insertion_sort(int *arr, int size)
{
    int temp, j;
    for(int i = 1; i < size; i++)
    {
        j = i - 1;
        temp = arr[i];

        while(j > -1 && arr[j] > temp)
        {
                arr[j + 1] = arr[j];
                j--;
        }
        arr[j + 1] = temp;
    }
}
