#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    string s;
    cin >> s;
    const int n = s.length();
    vector<int> points(n);
    for (int &i : points)
        cin >> i;

    int ans = 0;
    int x = 0, y = 0, prev;
    for (int i = 0; i < n; i++)
    {
        prev = x;
        if (s[i] == 'N')
            y += points[i];
        else if (s[i] == 'S')
            y -= points[i];
        else if (s[i] == 'E')
            x += points[i];
        else
            x -= points[i];

        ans += (x - prev) * y;
    }
    cout << ans;
    return 0;
}