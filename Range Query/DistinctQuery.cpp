#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;

struct event
{
    int first, second, index;
};

bool compare(event a, event b)
{
    return a.second < b.second;
}

int query(int r, vector<int> &BIT)
{
    int ans = 0;
    for (; r > 0; r -= (r & -r))
        ans += BIT[r];
    return ans;
}
void update(int i, int x, int n, vector<int> &BIT)
{
    for (; i <= n; i += i & -i)
        BIT[i] += x;
}

signed main()
{
    int n, q;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cin >> q;
    vector<event> quer(q);
    for (int i = 0; i < q; i++)
    {
        cin >> quer[i].first >> quer[i].second;
        quer[i].index = i;
    }
    sort(quer.begin(), quer.end(), compare);
    vector<int> BIT(n + 1), ans(q), last(1000001, -1);
    int total = 0, k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (last[arr[i]] != -1)
        {
            update(last[arr[i]], -1, n, BIT);
        }
        else
        {
            total++;
        }
        update(i, 1, n, BIT);
        last[arr[i]] = i;
        while (k < q && quer[k].second == i)
        {
            ans[quer[k].index] = total - query(quer[k].first - 1, BIT);
            k++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
