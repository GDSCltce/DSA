#include <bits/stdc++.h>
using namespace std;

void getlps(string &pat, vector<int> &lps)
{
    int len = pat.length();
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < len)
    {
        if (pat[i] == pat[j])
        {
            lps[i++] = ++j;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                lps[i++] = 0;
        }
    }
}
int ans = 0;
bool kmp(string &str, string &pat)
{
    int n = str.size(), m = pat.size();
    vector<int> lps(m);
    getlps(pat, lps);
    int i = 0, j = 0;
    bool flag = false;
    while (i < n)
    {
        if (str[i] == pat[j])
        {
            i++, j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == m)
        {
            flag = true; // return true;
            j = lps[j - 1];
            ans++;
        }
    }
    return flag;
}

signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s, p;
    cin >> s >> p;
    string pattern = "";
    for (int i = 0; i < k; i++)
        pattern += p[i];

    bool flag = kmp(s, pattern);
    if (flag)
    {
        cout << ans << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}