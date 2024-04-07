#include <bits/stdc++.h>
// #include "../Cpplibrary/array.h"
using namespace std;

#define endl '\n'
#define space ' '
#define dbg(x) printf("%s = %d\n", #x, x);
typedef long long ll;
#define all(x) (x).begin(), (x).end()
// const int mod = 1e9+7;
inline void solve();

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
/*************************************/
class twoStack
{
    int *arr, cap, top1, top2;

public:
    twoStack(int n)
    {
        cap = n;
        top1 = -1;
        top2 = cap;
        arr = new int[cap];
    }
    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
    }
    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
    }
    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            exit(1);
        }
    }
    int pop2()
    {
        if (top2 < cap)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            exit(1);
        }
    }
    void print1()
    {
        for (int i = 0; i < cap / 2; i++)
        {
            cout << arr[i] << endl;
        }
    }
    void print2()
    {
        for (int i = cap - 1; i >= cap / 2; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

inline void solve()
{
    int n = 6, x;
    twoStack s(n);
    for (int i = 0; i < n / 2; i++)
    {
        cin >> x;
        s.push1(x);
        cin >> x;
        s.push2(x);
    }
    s.print1();
    s.print2();
}
