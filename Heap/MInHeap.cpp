#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *arr, capacity, heap_size;

public:
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        arr = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int height() { return ceil(log2(heap_size + 1)) - 1; }
    int top() { return arr[0]; }

    void insert(int x)
    {
        if (heap_size == capacity)
            return;
        arr[heap_size++] = x;
        for (int i = heap_size - 1; i != 0 && arr[i] < arr[parent(i)]; i = parent(i))
        {
            swap(arr[i], arr[parent(i)]);
        }
    }

    void min_heapify(int i)
    {
        int lt = left(i), rt = right(i);
        int smallest = i;
        if (lt < heap_size && arr[lt] < arr[smallest])
            smallest = lt;
        if (rt < heap_size && arr[rt] < arr[smallest])
            smallest = rt;
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            min_heapify(smallest);
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
        min_heapify(0);
        return arr[heap_size];
    }

    void decreaseKey(int i, int neww_x);
    void deleteKey(int i);
    void printHeap();
};

void MinHeap::decreaseKey(int i, int neww_x)
{
    arr[i] = neww_x;
    while (i != 0 && arr[i] < arr[parent(i)])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extract();
}

void MinHeap::printHeap()
{
    for (int i = 0; i < heap_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.printHeap();
    h.deleteKey(1);
    h.insert(45);
    h.printHeap();
    cout << h.extract() << "\n";
    cout << h.top() << "\n";
    h.decreaseKey(2, 1);
    cout << h.top() << "\n";
    h.printHeap();
    return 0;
}
