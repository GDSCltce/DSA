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
            lps[i++] = lps[j++]+1;
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

bool kmp(string &str, string &pat)
{
    int n = str.length(), m = pat.length();
    vector<int> lps(m);
    getlps(pat, lps);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (str[i] == pat[j])
        {
            i++, j++;
            if (j == m)
                return true;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    if (j == m)
        return true;
    return false;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        string str, pat;
        cin >> str >> pat;
        int n = str.length(), m = pat.length();
        if (kmp(str, pat))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}