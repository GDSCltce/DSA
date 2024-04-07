#ifndef SORTING_h
#define SORTING_H
#include <bits/stdc++.h>
using namespace std;

// BUBBLE SORT
void bubbleSort(vector<int> &arr, int n)
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// SELECTION SORT
void selectionSort(vector<int> &arr, int n)
{

    for (int i = 0; i < n; ++i)
    {
        int mn = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[mn])
            {
                mn = j;
            }
        }
        swap(arr[i], arr[mn]);
    }
}

// INSERTION SORT
void intsertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

// QUICKSORT
int partition(vector<int> &arr, int l, int h)
{
    int i = l, pi = arr[h];

    for (int j = l; j < h; j++)
    {
        if (arr[j] <= pi)
        {
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[i], arr[h]);
    return i;
}

void quickSort(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int pivot = partition(arr, l, h);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, h);
    }
}

// MERGE SORT
void merge(int *arr, int start, int mid, int end, int *temp)
{
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for (int i = start, k = 0; i <= end; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void mergeSort(int *arr, int start, int end, int *temp)
{
    int mid;
    if (start < end)
    {
        mid = start + (end - start) >> 1;
        mergeSort(arr, start, mid, temp);
        mergeSort(arr, mid + 1, end, temp);
        merge(arr, start, mid, end, temp);
    }
}

// DNF SORT
void dnfSort(vector<int> &v, int n)
{
    int l = 0, h = n - 1, m = 0;

    while (m <= h)
    {
        if (v[m] == 0)
        {
            swap(v[l], v[m]);
            m++;
            l++;
        }
        else if (v[m] == 1)
        {
            m++;
        }
        else if (v[m] == 2)
        {
            swap(v[h], v[m]);
            h--;
        }
    }
}

// WAVE SORT
void wavesort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
        }
        if (arr[i] > arr[i + 1] && i <= n - 2)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

// CYCLE SORT
void cycleSort(vector<int> &arr, int n)
{
    for (int cs = 0; cs < n - 1; cs++)
    {
        int item = arr[cs], pos = cs;
        for (int i = cs + 1; i < n; i++)
        {
            if (arr[i] < item)
            {
                pos++;
            }
        }
        if (pos == cs)
        {
            continue;
        }
        while (item == arr[pos])
        {
            pos += 1;
        }
        if (pos != cs)
        {
            // write++;
            swap(item, arr[pos]);
        }

        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; i++)
            {
                if (arr[i] < item)
                {
                    pos++;
                }
                swap(item, arr[pos]);
            }
        }
    }
}

// COUNT SORT
void countSort(vector<int> &v, int mx, int mn)
{
    vector<int> freq(mx - mn + 1);

    for (int i = 0; i < v.size(); i++)
    {
        freq[v[i] - mn]++;
    }

    for (int i = 1; i < freq.size(); i++)
    {
        freq[i] += freq[i - 1];
    }

    vector<int> ans(v.size());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans[--freq[v[i]]] = v[i];
    }

    for (int i = 0; i < v.size(); i++)
    {
        v[i] = ans[i];
    }
    return;
}

// RADIX SORT
int getMAX(vector<int> &arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        mx = max(arr[i], mx);
    }
    return mx;
}

void countSortRDX(vector<int> &v, int n, int exp)
{
    int k = 10;
    vector<int> freq(10);

    for (int i = 0; i < n; i++)
    {
        freq[(v[i] / exp) % 10]++;
    }
    for (int i = 1; i <= k; i++)
    {
        freq[i] += freq[i - 1];
    }
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[--freq[(v[i] / exp) % 10]] = v[i];
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = ans[i];
    }
}

void radixSort(vector<int> &arr, int n)
{
    int mx = getMAX(arr, n);
    for (int exp = 1; (mx / exp) > 0; exp *= 10)
    {
        countSortRDX(arr, n, exp);
    }
}

#endif