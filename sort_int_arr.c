#include <stdio.h>
#include <stdlib.h>

void  sort_arr(int arr[], int size)
{
    int   i;
    int     j;
    int   temp;
    int   *tab;

    tab = arr;
    i = 0;
    j = 1;
    while (i < (size - 1) && j < size)
    {
        if (i + j < size && tab[i] > tab[i + j])
        {
            temp = tab[i + j];
            tab[i + j] = tab[i];
            tab[i] = temp;
        }
        if (j != (size - 1))
            j++;
        else
            j = ++i;
    }
}

void    print_arr(int *arr, int size)
{
    int i;
    
    i = 0;
    while (i < size)
    {
        printf("%d", arr[i]);
        if (i + 1 != size)
            printf(", ");
        i++;
    }
    puts("");
}

int    main(void)
{
    int i;
    int j;
    int    arr[] = {5, 7, 4, -1, 1};
    int    copy[5];
    int rank[5];

    // copy = malloc(5 * sizeof(int));
    for (i = 0; i < 5; i++)
        copy[i] = arr[i];
    puts("Original");
    sort_arr(copy, 5);
    print_arr(arr, 5);
    i = 0;
    j = 0;
    while (i < 5)
    {
        j = 0;
        while (j < 5)
        {
            if (arr[i] == copy[j])
                rank[i] = j;
            j++;
        }
        i++;
    }
    print_arr(rank, 5);
    puts("Sorted");
    sort_arr(copy, 5);
    print_arr(copy, 5);
    return (0);
}
