#include <bits/stdc++.h>
using namespace std;

char checkMate(const string &s)
{
    const int n = s.size();

    string ans = "AB";
    vector<int> c(2);
    vector<char> dir(n, '#');

    int current = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] != '.')
        {
            dir[i] = (current == 0 ? 'R' : 'L');
            current ^= 1;
        }
    }

    int pre = -1, ok = 0, grundy = 0;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] != '.')
        {
            if (pre == -1)
            {
                pre = i;
                continue;
            }
            if (dir[i] == 'L' && dir[pre] == 'R')
            {
                int dots = i - pre - 1;
                if (s[i] == s[pre])
                {
                    c[s[i] - 'A'] += dots;
                }
                else
                {
                    if (dots > 0)
                        ok = 1;
                    grundy ^= dots;
                }
            }
            pre = i;
        }
    }

    if (dir[pre] == 'R')
    {
        c[s[pre] - 'A'] += (n - pre - 1);
    }

    if (c[0] == c[1])
        return ans[grundy == 0];
    return ans[c[0] < c[1]];
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << checkMate(s) << '\n';
    }
    return 0;
}