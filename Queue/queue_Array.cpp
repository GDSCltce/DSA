#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    int qsize, cap, front;
    T *arr;

public:
    Queue(T c)
    {
        cap = c;
        qsize = 0;
        arr = new T[cap];
        front = 0;
    }

    bool isFull() { return (qsize == cap); }
    bool isEmpty() { return (qsize == 0); }
    int size() { return qsize; }

    void enque(T x)
    {
        if (isFull())
        {
            return;
        }
        else
        {

            arr[(((front + qsize++ - 1) % cap) + 1) % cap] = x;
        }
    }
    void deque()
    {
        if (isEmpty())
        {
            return;
        }
        else
        {
            // for (T i = 0; i < qsize - 1; i++)
            // {
            //     arr[i] = arr[i + 1];
            // }
            // qsize--;
            front = (front + 1) % cap;
            // arr[front % size - 1]
            qsize--;
        }
    }
    T getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
            return arr[front];
    }
    T getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
            return arr[(front + qsize - 1) % cap];
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif
    int n;
    cin >> n;
    Queue<int> q(n);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.enque(x);
    }
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
    cout << q.size() << endl;
    for (int i = 0; i < 3; i++)
    {
        q.deque();
    }

    // cin >> x;
    q.enque(43);
    cout << q.getFront() << endl;
    cout << q.getRear() << endl;
}