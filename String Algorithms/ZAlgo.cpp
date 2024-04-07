#include <bits/stdc++.h>
using namespace std;

void Z_algo(string &str, vector<int> &z)
{
    int n = str.length();
    for (int i = 1; i < n; i++)
    {
        int j = z[i - 1];
        while (j > 0 && str[i] != str[j])
            j = z[j - 1];
        if (str[i] == str[j])
            j++;
        z[i] = j;
    }
    return;
}

signed main()
{
    string str = "mopodot", pat = "pod";
    string total = pat + "$" + str;
    vector<int> z(total.length());
    Z_algo(total, z);
    int cnt = 0;
    for (int i = pat.length() + 1; i < z.size(); i++)
    {
        if (z[i] == pat.length())
            cnt++;
    }
    cout << cnt; // count of occurence
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

void Z_Algo(string &str, vector<int> &Z)
{
    int n = str.length();
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n and str[r] == str[r - l])
                r++;
            Z[i] = r - l;
            r--;
        }
        else
        {
            int idx = i - l;
            if (i + Z[idx] <= r)
                Z[i] = Z[idx];
            else
            {
                l = i;
                while (r < n and str[r] == str[r - l])
                    r++;
                Z[i] = r - l;
                r--;
            }
        }
    }
    return;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        string pat, str;
        getline(cin, str);
        getline(cin, pat);
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
                str.erase(i--, 1);
        }

        string total = pat + "$" + str;
        vector<int> Z(total.length());
        Z_Algo(total, Z);
        int n = str.length(), m = pat.length();
        for (int i = 0; i < Z.size(); i++)
        {
            if (Z[i] == pat.length())
                cout << i - pat.length() - 1 << " ";
        }
    }
    return 0;
}*/
