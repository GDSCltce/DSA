#include <bits/stdc++.h>
using namespace std;

int func(vector<bool> &check, int open, int close, int n, vector<vector<int>> &dp)
{
    if (open > n || close > n)
        return 0;
    if (open == n && close == n)
        return 1;

    int ans;
    if (open == close || check[open + close])
        ans = func(check, open + 1, close, n, dp);
    else if (open == n)
        ans = func(check, open, close + 1, n, dp);
    else
        ans = func(check, open + 1, close, n, dp) + func(check, open, close + 1, n, dp);

    return ans;
}

int main()
{
    freopen("in.in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(k);
        vector<bool> check(n + n, 0);
        int x;
        for (int i = 0; i < k; i++)
            cin >> x, check[x - 1] = 1;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        cout << func(check, 0, 0, n, dp) << endl;
    }
    return 0;
}
/*
int squareBrackts(bool *arr, int o, int c, int n, int **dp)
{
    if (o > n || c > n)
    {
        return 0;
    }
    if (o == n && c == n)
    {
        return 1;
    }
    if (dp[o][c] != -1)
    {
        return dp[o][c];
    }
    if (o == c || arr[o + c] == true)
    {
        dp[o][c] = (squareBrackts(arr, o + 1, c, n, dp)) % m;
    }
    else if (o == n)
    {
        dp[o][c] = (squareBrackts(arr, o, c + 1, n, dp)) % m;
    }
    else
    {
        dp[o][c] = (squareBrackts(arr, o + 1, c, n, dp) + squareBrackts(arr, o, c + 1, n, dp)) % m;
    }
    return dp[o][c];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        bool *arr = new bool[2 * n];
        for (int i = 0; i < 2 * n; i++)
        {
            arr[i] = false;
        }
        while (k--)
        {
            int pos;
            cin >> pos;
            arr[pos - 1] = true;
        }
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << squareBrackts(arr, 0, 0, n, dp) << endl;
    }
    // write your code here
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;

long long squareBrackets(bool* arr, int n, int nob, int ncb){
    if(nob > n && ncb > n){
        return 0;
    }
    if(nob == n && ncb == n){
        return 1;
    }
    long long option1 = 0;
    long long option2 = 0;
    long long option3 = 0;
    int cI = nob+ncb;
    if(nob == ncb || arr[cI] == true){
        option1 = 1 + squareBrackets(arr, n, nob+1, ncb);
    }else if(nob == n){
        option2 = 1 + squareBrackets(arr, n, nob, ncb+1);
    }else{
        option3 = option1 + option2;
    }
    return option1+option2+option3;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int* s = new int[k];
        for(int i = 0; i < k; i++){
            cin>>s[i];
        }
        bool* arr = new bool[2*n];
        int j = 0;
        for(int i = 0; i < 2*n; i++){
            if(s[j]-1 == i && j < k){
                arr[i] = true;
                j++;
            }else{
                arr[i] = false;
            }
        }
        cout<<squareBrackets(arr, n, 0, 0)<<endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
long long squareBrackets(bool* arr, int n, int nob, int ncb,int **dp){
    if(nob > n || ncb > n){
        return 0;
    }
    if(nob == n && ncb == n){
        return 1;
    }
    if(dp[nob][ncb]!=-1)
        return dp[nob][ncb];
    long long option1 = 0;
    long long option2 = 0;
    long long option3 = 0;
    int cI = nob+ncb;
    if(nob == ncb || arr[cI] == true){
        option1 = squareBrackets(arr, n, nob+1, ncb,dp);
    }else if(nob == n){
        option2 =  squareBrackets(arr, n, nob, ncb+1,dp);
    }else{
        option3 = squareBrackets(arr, n, nob+1, ncb,dp) + squareBrackets(arr, n, nob, ncb+1,dp);
    }
    return dp[nob][ncb] = (option1+option2+option3)%mod;
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        // int* s = new int[k];
        bool* arr = new bool[2*n];
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
        for(int i = 0; i < k; i++){
            int x;
            cin>>x;
            arr[x-1]=true;
        }

        // int j = 0;
        // for(int i = 0; i < 2*n; i++){
        //     if(s[j]-1 == i && j < k){
        //         arr[i] = true;
        //         j++;
        //     }else{
        //         arr[i] = false;
        //     }
        // }
        cout<<squareBrackets(arr, n, 0, 0,dp)<<endl;
    }
    return 0;
}*/