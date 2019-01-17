#include "Student.h"

//—°‘Ò≈≈–ÚÀ„∑®
void SelectSort(Rate* arr, int len)
{
    int i, j, k;
    for (i = 1; i < len; i++)
    {
        k = i;
        for (j = i + 1; j <= len; j++)
        {
            if (arr[j].rate < arr[k].rate)
                k = j;
        }
        if (k != i)
        {
            arr[0] = arr[i];
            arr[i] = arr[k];
            arr[k] = arr[0];
        }
    }
}

void selectSort(stuRate* arr, int len)
{
    int i, j, k;
    for (i = 1; i < len; i++)
    {
        k = i;
        for (j = i + 1; j <= len; j++)
        {
            if (arr[j].rate < arr[k].rate)
                k = j;
        }
        if (k != i)
        {
            arr[0] = arr[i];
            arr[i] = arr[k];
            arr[k] = arr[0];
        }
    }
}