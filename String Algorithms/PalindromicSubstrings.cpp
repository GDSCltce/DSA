#include <bits/stdc++.h>
using namespace std;

int countPalindrome(string &s)
{
    int n = s.length(), cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            cnt++;
            l--;
            r++;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            cnt++;
            l--;
            r++;
        }
    }
    return cnt;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int ans = countPalindrome(s);
        cout << ans << endl;
    }
    return 0;
}