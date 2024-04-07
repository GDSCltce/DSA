#include <iostream>
using namespace std;

class N_Stacks
{
    int *arr, *top, *next;
    int k, freeTop, cap;

public:
    N_Stacks(int n, int k1)
    {
        k = k1;
        cap = n;
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        freeTop = 0;
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[cap - 1] = -1;
    }

    bool isFull()
    {
        return (freeTop == -1);
    }

    bool isEmpty(int sn)
    {
        return (top[sn] == -1);
    }

    void push(int x, int sn)
    {
        if (isFull())
        {
            cout << "\nStack OverFLow\n";
        }
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }
    int pop(int sn)
    {
        if (isEmpty(sn))
        {
            cout << "\nStack UnderFLow\n";
        }
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeTop;
        freeTop = i;
        return arr[i];
    }
};

int main()
{
    int k = 3;
    int n = 6;
    
    return 0;
}