#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stacks2Queue
{
    queue<T> q1;
    queue<T> q2;
    int s_ize;

public:
    Stacks2Queue()
    {
        s_ize = 0;
    }
    void push(T x)
    {
        q1.push(x);
        s_ize++;
    }

    int pop()
    {
        if (empty())
        {
            return -1;
        }
        int tsize = --s_ize;
        while (tsize--)
        {
            q2.push(q1.front());
            q1.pop();
        }
        T x = q1.front();
        q1.pop();
        tsize = s_ize;
        while (tsize--)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }

    int top()
    {
        return q1.back();
    }

    bool empty()
    {
        return (q1.empty() && q2.empty());
    }
};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
    #endif
    Stacks2Queue<int> s;
    s.push(23);
    s.push(24);
    s.push(25);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    s.push(21);
    cout << s.top() << endl;
    cout << s.pop() << endl;

    return 0;
}