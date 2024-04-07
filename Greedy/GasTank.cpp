#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 1000000000
#define lINF 100000000000000000
#define int long long
#define ld long double
#define ull unsigned long long
#define mod 1000000007
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define gri greater<int>()
#define all(x) (x).begin(), (x).end()
#define inarr(x)      \
    for (auto &i : x) \
        cin >> i;
#define printarr(x)   \
    for (auto &i : x) \
        cout << i << ' ';
bool pv(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
    return a.second < b.second;
}
/*------------ASIMARIES------------*/
void solve();
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif
    cout << fixed << setprecision(6);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n)
{
    for (int i = 0; i < n; i++)
    {
        int gasleft = 0;
        int j = 0;
        for (j = i; j <i+ n; j++)
        {
            gasleft += gas[j % n] - cost[j % n];
            if (gasleft < 0)
            {
                i = j % n;
                break;
            }
        }
        if (gasleft >= 0)
            return i;
        else if (j == i + n)
            return -1;
    }
    return -1;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> gas(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> gas[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cout << minimumStartingIndex(gas, cost, n);
}
int minimumStartingIndex(vector < int > & gas, vector < int > & cost, int n) {
  for (int i = 0; i < n; i++) {
    // Skip these stations immediately.
    if (gas[i] < cost[i]) {
      continue;
    }
    int gasLeft = 0;
    int j = 0;
    for (j = i; j < i + n; j++) {
      gasLeft += gas[j % n] - cost[j % n];
      // Not enough gas so quit.
      if (gasLeft < 0) {
        // Jump to the next possible station.
        i = j % n;
        break;
      }
    }
    // You can go through all station with non-negative gas left if start from 'i'.
    if (gasLeft >= 0) {
      return i;
    }
    // You cannot go through all stations.
    else if (j == i + n) {
      return -1;
    }
  }
  return -1;
}