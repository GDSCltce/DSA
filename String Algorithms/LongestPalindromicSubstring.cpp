#include <bits/stdc++.h>
using namespace std;

int LPS(string &s)
{
    int n = s.length(), mx = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            mx = max(mx, r - l + 1);
            l--;
            r++;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            mx = max(mx, r - l + 1);
            l--;
            r++;
        }
    }
    return mx;
}

signed main()
{
    string s;
    cin >> s;
    int ans = LPS(s);
    cout << ans << endl;

    return 0;
}