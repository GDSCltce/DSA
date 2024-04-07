#include <bits/stdc++.h>
using namespace std;

void combo(vector<int> &candidates, int target, int i, vector<vector<int>> &ans, vector<int> &a)
{
    if (i == candidates.size())
    {
        if (0 == target)
        {
            ans.push_back(a);
        }
        return;
    }
    if (candidates[i] <= target)
    {
        a.push_back(candidates[i]);
        combo(candidates, target - candidates[i], i, ans, a);
        a.pop_back();
    }
    combo(candidates, target, i + 1, ans, a);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    vector<vector<int>> ans;
    vector<int> a;
    combo(candidates, target, 0, ans, a);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> ans = combinationSum(candidates, 7);
    for (auto &i : ans)
    {
        for (auto &t : i)
            cout << t << " ";
        cout << endl;
    }

    return 0;
}