#include <stdio.h>
#include <stdlib.h>

int main()
{
    //call below function here and execute that
    return 0;
}

void countSwapOperation(char *s, char *p)
{
    int i, j, count = 0;
    char c, d;

    scanf("%s", s);
    fflush(stdin);
    scanf("%s", p);

    if (strlen(s) == strlen(p))
    {
        for (i = 0; i < strlen(s); i++)
        {
            c = s[i];
            d = p[i];
            for (j = i; j < strlen(s); j++)
            {
                if (c == d)
                    continue;

                if (c == p[j])
                {
                    p[i] = c;
                    p[j] = d;
                    count++;
                }
            }
        }
        printf("%d", count);
    }
}

int reduceToZeroByGivenNumber(int *arr, int n, int x)
{
    int i, j, min, temp, c;
    min = temp = c = 0;

    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    temp = x;
    for (i = 0; i < 8; i++)
    {
        for (j = i; j < 8; j++)
        {
            temp = temp - a[j];
            min++;
            if (temp == 0)
                c = min;
            if (temp < 0)
                break;
        }
        min = 0;
        temp = x;
    }

    if (c)
        return c;
    else
        return -1;
}

void findInvalidTerms(int *arr, int n)
{
    int i, j, c, flag = 0;
    int arr[n];

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    c = arr[1] - arr[0];

    for (i = 2; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (c == arr[j] - arr[i])
                break;
            else
            {
                flag++;
                printf("%d ", arr[j]);
                break;
            }
        }
    }

    if (flag == 0)
        printf("0");

    return 0;
}

void swap(int *a, int *b, int *c, int *d)
{
    int arr[4];

    arr[0] = *a;
    arr[1] = *b;
    arr[2] = *c;
    arr[3] = *d;

    *b = arr[0];
    *c = arr[1];
    *d = arr[2];
    *a = arr[3];

    printf("%d %d %d %d", *a, *b, *c, *d);
}

void findMaxAndMin(int *arr, int size)
{
    int i, min, max;

    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]); //3 2 4 8 9

    max = min = arr[0];

    for (i = 0; i < size; i++)
    {
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }

    printf("%d %d", max, min);
}

int anagramStrings(char *s, char *t)
{
    int i, j, count = 0;

    gets(s);
    gets(t);

    if (strlen(s) == strlen(t))
    {
        for (i = 0; i < strlen(s); i++)
            for (j = 0; j < strlen(t); j++)
                if (s[i] == t[j])
                {
                    count++;
                    break;
                }
    }

    if (count == strlen(s))
        return 1;
    else
        return 0;
}

void capitalFirstAndLastLetter(char *s)
{
    int i;

    if (s[0] >= 'a' && s[0] <= 'z')
        s[0] = s[0] - 32;

    for (i = 1; s[i]; i++)
    {
        if (s[i] == ' ')
        {
            if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
                s[i + 1] = s[i + 1] - 32;
            if (s[i - 1] >= 'a' && s[i - 1] <= 'z')
                s[i - 1] = s[i - 1] - 32;
        }
    }

    if (s[i] == '\0')
        s[i - 1] = s[i - 1] - 32;
    puts(s);
}

void convertOppositeCase(char *str)
{
    int i;
    for(i = 0; str[i]; i++)
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        else if(str[i] >= 'A' && str[i] <='Z')
            str[i] = str[i] + 32;
    puts(str);

}

void indexBasedRearrangement(int n, int *a, int *b, int *c)
{
    int i, j;

    for(i = 0; i < n; i++)
        scanf("%d",&a[i]);

    for(i = 0; i < n; i++)
        scanf("%d",&b[i]);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(b[i] == j)
            {
                c[i] = a[j];
                break;
            }

    for(i = 0; i < n; i++)
        printf("%d ",c[i]);
}

void rearrange_array_after_deletion()
{
    int i, j, n, k, n1, count = 0;

    scanf("%d", &n);

    int a[n];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &n1);

    int b[n1], c[n];

    for(i = 0; i < n1; i++)
        scanf("%d", &b[i]);


    for(i = 0; i < n1; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(b[i] == a[j])
            {
                count++;
            }
        }
    }

    if(count == n1)
    {
        for(i = 0; i < n1; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(b[i] == a[j])
                {
                    a[j] = 0;
                    break;
                }
            }
        }

        for(i = 0; i < n; i++)
            c[i] = 0;

        k = 0;

        for(i = 0; i < n; i++)
        {
            for(j = i; j < n; j++)
            {
                if(a[j] != 0)
                {
                    c[k] = a[j];
                    k++;
                    break;
                }
                break;
            }
        }

        for(i = 0; i < n; i++)
            printf("%d ", c[i]);
    }
}

void rearrange_array()
{
     int i,j, temp, size = 0;

    scanf("%d", &size);

    if(size % 2 == 0 && size > 0)
    {
        int a[size], b[size / 2], c[size / 2];

        for(i = 0; i < size; i++)
            scanf("%d", &a[i]);

        for(i = 0; i < size; i++)
        {
            for(j = i + 1; j < size; j++)
            {
                if(a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        for(i = 0; i < size/2; i++)
        {
            b[i] = a[size - i - 1];
            c[i] = a[i];
        }

        for(i = 0; i < size/2; i++)
            printf("%d ",b[i]);

        for(i = 0; i < size/2; i++)
            printf("%d ",c[i]);
    }
}

void print_reverse_prime(int n)
{
    int n, n1 = -1, n2 = 1, n3, i = 0;

    scanf("%d", &n);

    int arr[n];

    while(i < n)
    {
        arr[i] = n1 + n2;

        n1 = n2;
        n2 = arr[i];

        i++;
    }

    for(i = n - 1; i >= 0; i--)
            printf("%d ", arr[i]);
}

void find_special_divisor(int n)
{
    int q, i = 2;

    scanf("%d", &n);

    if(n > 0)
    {
        while(n != i)
        {
            if(n % i == 0)
            {
                q = n / i; //25 = 50 / 2;
                if(q % i == 0)
                {
                    printf("%d", i);
                    break;
                }
                else
                {
                    printf("%d", -1);
                    break;
                }
            }
            i++;
        }
    }

    return;
}

void decison_control()
{
int n;

    scanf("%d", &n);

    if(n % 2 == 1 && n > 5)
        printf("OPGT5");
    else if(n % 2 == 1 && n <= 5)
        printf("OPLTE5");
    else if(n % 2 == 1 && n < 0)
        printf("ON");
    else if(n % 2 == 0 && n <= 50)
        printf("EPLTE50");
    else if(n % 2 == 0 && n > 50)
        printf("EPGT50");
    else if(n % 2 == 0 && n < 0)
        printf("EN");
}

void convert_digits_to_number_name()
{
        int n, temp = 0, rev = 0;

    scanf("%d", &n);
    if(n >= 10000)
    {
        do
        {
            temp = n % 10;
            n /= 10;
            rev = rev * 10 + temp;
        }
        while(n);

        temp = 0;
        n = 0;


        do
        {
            temp = rev % 10;
            rev /= 10;

            switch(temp)
            {
            case 0:
                printf("Zero ");
                break;
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
            }
        }
        while(rev);
    }
}

void printNearestFibonicciNumber(int n)
{
    int n1 = -1, n2 = 1, n, n3;
    while (n)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;

        if (n - 1 == n3)
        {
            printf("%d ", n3);
        }

        if (n3 > n)
        {
            printf("%d", n3);
            break;
        }
    }
}

void print_prime_factorization()
{
    int n, i = 2;

    scanf("%d", &n);

    while(i <= n)
    {
        if(n % i == 0)
        {
            printf("%d ", i);
            n = n / i;
            i = 2;
        }
        else
            i++;
    }
    return;
}

void print_factors()
{
    int n1, i = 1;
    scanf("%d", &n1);

    while(i <= n1)
    {
        if(n1 % i == 0)
        {
            printf("%d ",i);
        }
        i++;
    }
    return;
}

void lcm_two_num()
{
    int n1, n2, val, i;
    scanf("%d %d", &n1, &n2);

    val = (n1 > n2) ? n1 : n2;

    for(i = 1; i <= val; i++)
    {
        if(val % n1 == 0 && val % n2 == 0)
        {
            printf("%d ", val);
            break;
        }

        ++val;
    }
    return;
}

void print_n_prime()
{
    int i = 1, j, count = 0, n, l;
    scanf("%d", &n);

    for(l = 1; l <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                count++;
            }
        }
        if(count == 2)
        {
            printf("%d ", i);
            l++;
        }
        count = 0;
    }
    return;
}

void count_currency_notes_num()
{
    int n, t, fh, h, ft, tw, tn;

    if(n < 10)
        printf("Enter valid amount");

    else
    {
        scanf("%d", &n);

        t = n / 1000;
        n = n % 1000;

        fh = n / 500;
        n = n % 500;

        h = n / 100;
        n = n % 100;

        ft = n / 50;
        n = n % 50;

        tw = n / 20;
        n = n % 20;

        tn = n / 10;

        printf("1000 %d\n", t);
        printf("500 %d\n", fh);
        printf("100 %d\n", h);
        printf("50 %d\n", ft);
        printf("20 %d\n", tw);
        printf("10 %d\n", tn);
    }
    return;
}

void find_attendance_percentage()
{
    int daysOfAttendance, jul, aug, sep, oct, nov;
    float attendacePercentage;

    scanf("%d %d %d %d %d", &jul, &aug, &sep, &oct, &nov);

    if(jul >= 0 && jul <= 31 &&
            aug >= 0 && aug <= 31 &&
            sep >= 0 && sep <= 31 &&
            oct >= 0 && oct <= 31 &&
            nov >= 0 && nov <= 31)
    {
        daysOfAttendance = jul + aug + sep + oct + nov;
        attendacePercentage = ((float) daysOfAttendance / 153) * 100;
        printf("%.2f", attendacePercentage);
    }
    return;
}

void diff_n_and_rev()
{
    int n, t, diff, r, revNum = 0;

    scanf("%d", &n);
    t = n;
    while(n != 0)
    {
        r = n % 10;
        revNum = revNum * 10 + r;
        n = n / 10;
    }
    diff = t - revNum;

    printf("%d", diff);
    return;
}

void perfect_number()
{
    int n, i, sum = 0;

    scanf("%d", &n);

    for(i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            sum = sum + i;
        }
    }
    if(n == sum)
        printf("%d ", 1);
    else
    {
        printf("%d ", -1);
    }
    return;
}

void prime_number_decresing_order()
{
    int n1, n2, i, j, count = 0, t;

    scanf("%d %d", &n1, &n2);

    if(n1 > n2)
    {
        t = n2;
        n2 = n1;
        n1 = t;
    }

    for(i = n2; i >= n1; i--)
    {
        for(j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                count++;
            }
        }

        if(count == 2)
        {
            printf("%d ", i);
        }
        count = 0;
    }
    return;
}
