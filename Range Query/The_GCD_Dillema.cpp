#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<pair<int, int>> crrstreak;
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> newGCDs;
        while (!crrstreak.empty())
        {
            pair<int, int> oldGCD = crrstreak.back();
            crrstreak.pop_back();
            int newGCD = __gcd(oldGCD.first, arr[i]);
            newGCDs[newGCD] += oldGCD.second;
        }
        newGCDs[arr[i]]++;
        for (auto it : newGCDs)
        {
            mp[it.first] += it.second;
            crrstreak.push_back(it);
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << mp[x] << endl;
    }

    return 0;
}