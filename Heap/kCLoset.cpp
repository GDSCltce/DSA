#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> kClosest(vector<int> &arr, int k, int x)
{
    int n = arr.size();
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({abs(arr[i] - x), i});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.emplace_back(arr[pq.top().second]);
        pq.pop();
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = kClosest(arr, 3, 4);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
