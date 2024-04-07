#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 1000000000
#define lINF 100000000000000000
#define int long long
#define ld long double
#define ull unsigned long long
#define mod 1000000007
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define gri greater<int>()
#define all(x) (x).begin(), (x).end()
/*-------------------ASIMARIES--------------------*/
void asimaries();

signed main()
{
    freopen("in.in", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        asimaries();
        cout << endl;
    }
    return 0;
}
/*-----------------ASIMARIES----------------*/

void asimaries()
{
    int n;
    cin >> n;
    vector<int> sieve(n + 2);
    for (int i = 0; i <= n; i++)
    {
        sieve[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; i * j <= n; j++)
        {
            int el_ = i * j;
            if (sieve[el_] == el_)
            {
                sieve[el_] = i;
            }
        }
    }

    vector<int> mark(n + 2);
    for (int i = n; i >= 1; i--)
    {
        vector<int> v;
        int lpd = sieve[i];
        if (mark[i] == 0)
        {
            int n_bkp = i;
            v.emplace_back(n_bkp);
            mark[n_bkp] = 1;
            while (n_bkp != 1)
            {
                int n_temp = i;
                while (n_temp != lpd)
                {
                    n_temp -= lpd;
                    if (mark[n_temp] == 0)
                    {
                        mark[n_temp] = 1;
                        v.push_back(n_temp);
                    }
                }
                while (n_bkp % lpd == 0)
                {
                    n_bkp /= lpd;
                }
                lpd = sieve[n_bkp];
            }
            sort(all(v), gri);
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
        }
    }
}
