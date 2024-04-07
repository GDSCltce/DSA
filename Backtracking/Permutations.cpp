#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(vector<T> &v)
{
    for (auto &i : v)
        cout << i << " ";
    cout << endl;
}
template <class T>
void printArr(vector<vector<T>> &v)
{
    for (auto &i : v)
    {
        printArr(i);
    }
    cout << endl;
}

void permutation(vector<int> &nums, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        permutation(nums, index + 1, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> a = nums;
    permutation(a, 0, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 0};
    vector<vector<int>> ans = permute(arr);
    printArr(ans);
    return 0;
}
