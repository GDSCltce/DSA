#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k)
{
    priority_queue<int> pq_max;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        pq_max.push(arr[i]);
        if (pq_max.size() > k)
        {
            pq_max.pop();
        }
    }
    return pq_max.top();
}

int findKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq_min;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        pq_min.push(arr[i]);
        if (pq_min.size() > k)
        {
            pq_min.pop();
        }
    }
    return pq_min.top();
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
    cout << kthSmallest(arr, 3);
    cout << findKthLargest(arr, 3);
    return 0;
}
