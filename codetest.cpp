#include <bits/stdc++.h>
// long long count=0;
int g = 0;
void merge(long long *input, int s, int e)
{
    // cout<<g++;
    long long *output = new long long[10000000];
    // long long output[10000000];
    int mid = (s + e) / 2;

    int i = s;
    int j = mid + 1;

    int k = s;
    while (i <= mid && j <= s)
    {
        // cout << mid - i;
        if (input[i] < input[j])
        {
            output[k++] = input[i];
            i++;
        }
        else if (input[i] > input[j])
        {
            output[k++] = input[j];
            j++;
            // g++;
            g = g + mid - i;
        }
        else
        {
            output[k++] = input[j];
            j++;
            output[k++] = input[i];
            i++;
        }
    }
    while (j <= e)
    {
        output[k++] = input[j];
        j++;
    }

    while (i <= mid)
    {
        output[k++] = input[i];
        i++;
    }
    k = 0;
    for (int g = s; g <= e; g++)
    {

        input[g] = output[k++];
    }
}
void mergeSort(long long *input, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    else
    {
        int mid = (s + e) / 2;
        mergeSort(input, s, mid);
        mergeSort(input, mid + 1, e);
        merge(input, s, e);
    }
}

void mergeSort(long long *input, int size) { mergeSort(input, 0, size - 1); }

long long getInversions(long long *arr, int n)
{
    // long long output[n];
    mergeSort(arr, n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i];
    // }
    // return g;
}