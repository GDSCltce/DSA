#include <iostream>
#include <queue>

using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif
    queue<string> q;
    q.push("5");
    q.push("6");
    for (int i = 0; i < 10; i++)
    {
        string curr = q.front();
        cout << curr << " ";
        q.pop();
        q.push(curr.append("5"));
        q.push(curr.append("6"));
    }
    return 0;
}
