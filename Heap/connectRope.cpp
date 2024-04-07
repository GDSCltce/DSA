#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll minCost(ll arr[], ll n)
{
    priority_queue<ll, vector<ll>, greater<ll>> pq(arr, arr + n);
    ll sum = 0;
    while (pq.size() > 1)
    {
        ll val1 = pq.top();
        pq.pop();
        ll val2 = pq.top();
        pq.pop();
        sum += (val1 + val2);
        pq.push(val1 + val2);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minCost(arr, n);
    return 0;
}
