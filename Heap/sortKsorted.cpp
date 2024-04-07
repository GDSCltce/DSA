#include <bits/stdc++.h>
using namespace std;
void printArr(vector<int> &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

void kthSorted(vector<int> &nums, int k)
{
    int n = nums.size(), j = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(nums[i]);
        if (pq.size() > k)
        {
            nums[j++] = pq.top();
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        nums[j++] = pq.top();
        pq.pop();
    }

    /*
    int n = nums.size(), j, temp;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        temp = nums[i];
        while (j >= 0 && temp < nums[j])
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
    */
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
    kthSorted(arr, 4);
    printArr(arr);
    return 0;
}
