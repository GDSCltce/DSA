#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<pii> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() and dq.front().second <= (i - k))
        {
            dq.pop_front();
        }
        while (!dq.empty() and dq.back().first < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back({nums[i], i});
        if (i >= (k - 1))
        {
            ans.push_back(dq.front().first);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = maxSlidingWindow(arr, 3);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
