#include <bits/stdc++.h>
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
        getline(cin, str);// temp string 
        getline(cin, str);
        cin >> pat;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
                str.erase(i--, 1);
        }
        // cout << str << pat;
        string total = pat + "$" + str;
        vector<int> Z(total.length());
        Z_Algo(total, Z);
        int n = str.length(), m = pat.length(), cnt = 0;
        for (int i = 0; i < Z.size(); i++)
        {
            if (Z[i] == pat.length()){
                cnt++;}
        }
        cout << cnt << endl;
    }
    return 0;
}