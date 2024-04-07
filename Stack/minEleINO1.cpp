#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int minELE = 0;
void push(int x)
{
    if (s.empty())
    {
        s.push(x);
        minELE = x;
    }
    else if (x <= minELE)
    {
        s.push(2 * x - minELE);
        minELE = x;
    }
    else
    {
        s.push(x);
    }
}

int getMIN() { return minELE; }

int top()
{
    int t = s.top();
    return (t <= minELE) ? minELE : t;
}
void pop()
{
    if (s.empty())
    {
        return;
    }
    int t = s.top();
    if (t <= minELE)
    {
        int res = minELE;
        minELE = 2 * minELE - t;
    }
    else
    {
        s.pop();
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif

    return 0;
}
