#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Queue2Stacks
{
    stack<T> s1;
    stack<T> s2;

public:
    void push(T x)
    {
        s1.push(x);
    }
    T pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is Empty\n";
            return "null";
        }
        else if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            T x = s2.top();
            s2.pop();
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            return x;
        }
        return "null";
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif
    Queue2Stacks<string> q;
    q.push("is");
    q.push("dsd");
    q.push("sds");
    cout << q.pop() << endl;
    q.push("dsd");
    q.push("dsd");
    cout << q.pop() << endl;
    return 0;
}