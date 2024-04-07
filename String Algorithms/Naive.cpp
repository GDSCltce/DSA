#include <bits/stdc++.h>
using namespace std;

int Naive(string &str, string &pattern)
{
    int j = 0, n = str.length(), m = pattern.length();
    for (int i = 0; i <= n - m; i++)
    {
        if (str[i] == pattern[j])
        {
            int lasti = i;
            while (str[i] == pattern[j])
            {
                i++, j++;
                if (j == m)
                    return i - m + 1;
            }
            i = lasti;
        }
    }
    return -1;
}

signed main()
{
    string str = "abcdefghi", pattern = "khi";
    cout << Naive(str, pattern);
    return 0;
}