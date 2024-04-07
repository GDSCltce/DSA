#include <bits/stdc++.h>
// #include "../Cpplibrary/array.h"
using namespace std;

#define endl '\n'
#define space ' '
/*************************************/

class myStack
{
    int *arr;
    int cap;
    int top;

public:
    myStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }
    void push(int x)
    {
        if (top == cap - 1)
        {
            cout << "Overflow " << x << " cannot be push\n";
        }
        else
        {
            arr[++top] = x;
            cout << x << " is pushed\n";
        }
    }
    int pop()
    {
        int res = arr[top];
        if (top == -1)
        {
            cout << "underflow\n";
        }
        else
        {
            arr[top--] = 0;
        }
        return res;
    }
    int peek()
    {
        int res = arr[top];
        if (top == -1)
        {
            cout << "Underflow: stack is empty\n";
            res = 0;
        }
        return res;
    }
    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << space;
        }
        cout << endl;
    }
};

inline void solve()
{
    myStack s(5);
    cout << "top: " << s.peek() << endl;
    int x;
    for (int i = 0; i < 6; i++)
    {
        cin >> x;
        s.push(x);
    }
    for (int i = 0; i < 6; i++)
    {
        cout << s.pop() << " is pop\n";
    }

    s.print();
    if (s.isEmpty())
        cout << "stack is empty\n";
    else
        cout << "stack is not  empty\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif

    // int t;
    // scanf("%d", &t);
    // while (t--)
    {
        solve();
    }
    return 0;
}
