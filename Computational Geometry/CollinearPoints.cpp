#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin >> t;
    int x1, y1;
    int x2, y2;
    int x3, y3;
    while (t--)
    {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;

        int determinant = (y2 - y1) * (x3 - x2) -
                          (y3 - y2) * (x2 - x1);

        if (determinant == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}