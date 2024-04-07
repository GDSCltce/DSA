#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int *arr, capacity, heap_size;

public:
    MaxHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        arr = new int[cap];
    }
    MaxHeap(int makearr[], int n)
    {
        heap_size = n;
        arr = makearr;
        buildMaxHeap(arr, n);
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int height() { return ceil(log2(heap_size + 1)) - 1; }
    int top() { return arr[0]; }
    void buildMaxHeap(int arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            max_heapify(i);
        }
    }
    void insert(int x)
    {
        if (heap_size == capacity)
            return;
        arr[heap_size++] = x;
        for (int i = heap_size - 1; i != 0 && arr[i] > arr[parent(i)]; i = parent(i))
        {
            swap(arr[i], arr[parent(i)]);
        }
    }

    void max_heapify(int i)
    {
        int lt = left(i), rt = right(i);
        int largest = i;
        if (lt < heap_size && arr[lt] > arr[largest])
            largest = lt;
        if (rt < heap_size && arr[rt] > arr[largest])
            largest = rt;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            max_heapify(largest);
        }
    }

    int extract()
    {
        if (heap_size == 0)
        {
            return INT_MAX;
        }
        if (heap_size == 1)
        {
            heap_size--;
            return arr[0];
        }
        swap(arr[0], arr[--heap_size]);
        max_heapify(0);
        return arr[heap_size];
    }

    void increaseKey(int i, int neww_x);
    void deleteKey(int i);
    void printHeap();
};

void MaxHeap::increaseKey(int i, int neww_x)
{
    if (neww_x > arr[i])
    {
        arr[i] = neww_x;
        while (i != 0 && arr[i] > arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
}

void MaxHeap::deleteKey(int i)
{
    increaseKey(i, INT_MAX);
    extract();
}

void MaxHeap::printHeap()
{
    for (int i = 0; i < heap_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr[7];
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }
    MaxHeap h(arr, 7);
    h.printHeap();
    return 0;
}
