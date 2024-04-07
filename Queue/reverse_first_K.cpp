#include <iostream>
#include <queue>
#include <stack>
// #include "../Cpplibrary/array.h"
using namespace std;

int main()
{
    queue<int> q;
    stack<int> s;

    int n, x, k = 3;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    for (int i = 0; i < k; i++)
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < n-k; i++)
    {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << q.front() << ' ';
        q.pop();
    }
    

    return 0;
}
