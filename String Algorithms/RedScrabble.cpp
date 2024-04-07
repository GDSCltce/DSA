#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<int> manacher(string s, bool odd)
{
    vector<int> ret(s.size());
    for (int i = 0, l = 0, r = -1; i < s.size(); ++i)
    {
        int k = (i > r) ? odd : min(ret[l + r - i + (!odd)], r - i + 1);
        while (i - k - (!odd) >= 0 && i + k < s.size() && s[i - k - (!odd)] == s[i + k])
            ++k;
        ret[i] = k--;
        if (i + k > r)
            l = i - k - (!odd), r = i + k;
    }
    return ret;
}

const int N = 1e6 + 5;
ll ans;
string s;
int pref_sum[N];
vector<int> pos[N];
int remi(int x)
{
    return ((x % 3) + 3) % 3;
}
void build_pref_sum()
{
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        pref_sum[i] = remi((i ? pref_sum[i - 1] : 0) + (s[i] - '0'));
        if (remi(s[i] - '0') == 0)
            ++ans;
        if (s[i] != '0')
            pos[pref_sum[i]].push_back(i);
    }
}

int main()
{
    cin >> s;
    int n = s.size();
    build_pref_sum();
    vector<int> v1 = manacher(s, 1);
    vector<int> v2 = manacher(s, 0);
    for (int i = 0; i < n; ++i)
    {
        int odd = v1[i], l = i - odd + 1, r = i + odd - 1, zero;
        int dig = s[i] - '0';
        if (l != r)
        {
            l = i + 1;
            zero = pref_sum[i];
            for (int j = 0; j < 3; ++j)
            {
                if (remi(dig + 2 * j) == 0)
                {
                    auto &t = pos[remi(zero + j)];
                    ans += upper_bound(t.begin(), t.end(), r) - lower_bound(t.begin(), t.end(), l);
                }
            }
        }
        int even = v2[i];
        l = i, r = i + even - 1;
        if (even)
        {
            zero = (i ? pref_sum[i - 1] : 0);
            for (int j = 0; j < 3; ++j)
            {
                if (remi(2 * j) == 0)
                {
                    auto &t = pos[remi(zero + j)];
                    ans += upper_bound(t.begin(), t.end(), r) - lower_bound(t.begin(), t.end(), l);
                }
            }
        }
    }
    cout << ans;
    return 0;
}