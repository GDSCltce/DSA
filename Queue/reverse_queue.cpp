#include <bits/stdc++.h>
using namespace std;

void reverse_queue_it(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

// queue<int> reverse_queue_rec(queue<int> &q)
// {
//     if(q.empty()){
//         return q;
//     }
//     int x = q.front();
//     q.pop();
//     reverse_queue_rec(q);
//     q.push(x);
// }

int main()
{
    queue<int> q;
    q.push(12);
    q.push(134);
    q.push(112);
    cout << q.front() << endl;
    reverse_queue_it(q);
    cout << q.front() << endl;
    // q = reverse_queue_rec(q);
    cout << q.front() << endl;
    return 0;
}