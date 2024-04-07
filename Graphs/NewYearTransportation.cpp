#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        vector<int> vis(n, 0);
        int index = 1;
        while (index < n)
        {
            vis[index] = true;
            index += a[index];
        }
        int q; cin >> q;
        while (q--)
        {
            int x; cin >> x;
            if (vis[x])cout << "YES\n";
            else cout << "NO\n";
        }
        
        
    }
    return 0;
}