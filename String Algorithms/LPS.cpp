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

signed main()
{
    string str = "this is a test text", pat = "test";
    int n = str.length(), m = pat.length();

    return 0;
}