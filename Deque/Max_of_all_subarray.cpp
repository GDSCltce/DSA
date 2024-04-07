#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
freopen("out.in", "w", stdout);
#endif
    
    int n, k =3;
    cin >> n;

    deque <int> dq;
    vector <int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[dq.front()] << ' ';
        while (!dq.empty() && dq.front() <=i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()];

    return 0;
}