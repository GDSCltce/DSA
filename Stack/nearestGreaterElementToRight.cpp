#include <bits/stdc++.h>
// #include "../Cpplibrary/array.h"
using namespace std;

#define endl '\n'
#define space ' '
#define dbg(x) printf("%s = %d\n", #x, x);
typedef long long ll;
#define all(x) (x).begin(), (x).end()
// const int mod = 1e9+7;
inline void solve();

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}
/*************************************/

inline void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // BruteForce
    cout << "BruteForce:\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         if (arr[i] < arr[j])
    //         {
    //             cout << arr[i] << space << arr[j] << endl;
    //             break;
    //         }
    //     }
    //     if (i == n - 1)
    //     {
    //         cout << arr[i] << space << -1 << endl;
    //     }
    // }

    // Optimal o(n)
    cout << "Optimal o(n)\n";
    vector<int> nums1 = {4, 1, 2};
    stack<int> s;
    vector<int> ans(n);
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (!s.empty())
    //     {
    //         while (!s.empty() && s.top() <= arr[i])
    //         {
    //             s.pop();
    //         }
    //     }
    //     ans[i] = (s.empty() ? -1 : s.top());
    //     s.push(arr[i]);
    // }
    for (int i = 0; i < n; i++)
	{
		while (!s.empty() && arr[s.top()]>arr[i])
		{
			ans[s.top()] = i-s.top()-1;
			s.pop();
		}
		s.push(i);
	}
    // reverse(all(ans));
    for (auto i : ans)
    {
        cout << i << space;
    }
    cout << "\nanswer ";
    vector<int> answer;

    for (int i = 0; i < nums1.size(); i++)
    {
        
        if(nums1[i] == arr[i]){
            answer.emplace_back(ans[i]);
        }
    }
    for (auto i : answer)
    {
        cout << i << space;
    }
}
