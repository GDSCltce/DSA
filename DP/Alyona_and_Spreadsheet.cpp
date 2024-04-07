#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for (int j = 1; j <= m; j++)
    {
        for (int i = 2; i <= n; i++)
        {
            if (arr[i][j] >= arr[i - 1][j])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = i;
            }
        }
    }
    vector<int> ans(n + 1);
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int mn = INT_MAX;
        for (int j = 1; j <= m; j++)
        {
            mn = min(dp[i][j], mn);
        }
        ans[i] = mn;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (ans[b] <= a)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        int m;
        cin>>n>>m;
        int** arr = new int*[n+1];
        for(int i = 0; i <= n; i++){
            arr[i] = new int[m+1];
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin>>arr[i][j];
            }
        }
        int** dp = new int*[n+1];
        for(int i = 0; i <=n; i++){
            dp[i] = new int[m+1];
         }
        for(int i = 1; i <= m; i++){
            dp[0][i]=0;
            for(int j = 2; j <= n; j++){
                if(arr[j][i] >= arr[j-1][i]){
                    dp[j][i] = dp[j-1][i];
                }else{
                    dp[j][i] = j;
                }
            }
        }
        int* ans = new int[n+1];
        ans[1] = 1;
        for(int i = 2; i <= n; i++){
            int min = INT_MAX;
            for(int j = 1; j <= m; j++){
                if(dp[i][j] < min){
                    min = dp[i][j];
                }
            }
            ans[i] = min;
        }
        int Q;
        cin>>Q;
        for(int i = 1; i <= Q; i++){
            int start;
            int end;
            cin>>start>>end;
            if(ans[end] <= start){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}


*/