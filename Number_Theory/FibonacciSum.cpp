#include <bits/stdc++.h>
using namespace std;
#define int long long
int mans = -1, nans = -1;
const int mod = 1000*1000*1000+7;
void matMul(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                arr[i][j] += (A[i][k] * B[k][j]) % mod, arr[i][j] %= mod;

    A = arr;
}

void power(vector<vector<int>> &arr, int pow)
{
    vector<vector<int>> I = {{1, 1}, {1, 0}};
    while (pow > 1)
    {
        if (pow &1)
        matMul(arr, I), pow-=1;
        else
        matMul(arr, arr), pow/= 2;
    }

    // if (pow == 1 || pow == 0)
    //     return;
    // if (pow & 1)
    // {
    //     power(arr, pow - 1);
    //     matMul(arr, I);
    // }
    // else
    // {
    //     power(arr, pow / 2);
    //     matMul(arr, arr);
    // }
    // while (pow > 0)
    // {
    //     if (pow & 1)
    //     {
    //         vector<vector<int>> temp = {{1, 1}, {1, 0}};
    //         matMul(arr, temp);
    //     }
    //     pow = pow / 2;
    //     matMul(arr, arr);
    // }
}

int fiboSum(int x)
{
    if (x == 0)
        return 0;
    else if (x <= 2)
        return 1;
    vector<int> helper = {1, 0};
    vector<vector<int>> arr = {{1, 1}, {1, 0}};
    power(arr, x - 1);
    // int pow = x - 1;
    // while (pow > 1)
    // {
    //     if (pow & 1)
    //     {
    //         vector<vector<int>> temp = {{1, 1}, {1, 0}};
    //         matMul(arr, temp);
    //     }
    //     matMul(arr, arr);
    //     pow /= 2;
    // }
    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        ans = (ans + (arr[0][i] * helper[i]) % mod) % mod;
    }
    return ans;
}

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("D:\\_Program\\CF\\in.txt", "r", stdin);
// #endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int ans = fiboSum(m + 2) - fiboSum(n + 1);
        if (ans < 0)
            ans = (ans + mod) % mod;
        ans %= mod;
        cout << ans << endl;
    }
    return 0;
}

/*
   Time Complexity: O(Log(M))
   Space Complexity: O(1)

   Where ‘M’ reparrents the end of the range


// Function to multiply two matrices
void multiply(vector<vector<int>> &first, vector<vector<int>> &second)
{
    vector<vector<int>> arr(2, vector<int>(2, 0));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int x = 0; x < 2; x++)
            {
                arr[i][j] = (arr[i][j] + (1LL * first[i][x] * second[x][j]) % 1000000007) % 1000000007;
            }
        }
    }

    first = arr;
}

// Function to help in binary exponentiation
void power(vector<vector<int>> &mat, int pow)
{
    if (pow == 1 || pow == 0)
    {
        return;
    }

    vector<vector<int>> temp = {{1, 1}, {1, 0}};

    if (pow & 1)
    {
        power(mat, pow - 1);
        multiply(mat, temp);
    }
    else
    {
        power(mat, pow / 2);
        multiply(mat, mat);
    }
}

// Function to perform matrix exponentiation
int compute(int x)
{
    // If we want to return 0th fibonacci number
    if (x == 0)
    {
        return 0;
    }

    // 1st and 2nd fibonacci number
    if (x <= 2)
    {
        return 1;
    }

    // Create an matrix helper of size 2X1
    vector<int> helper = {1, 0};

    // Create a matrix transform of size 2X2
    vector<vector<int>> transform = {{1, 1}, {1, 0}};

    // Finding the (N-1)th power of transform matrix
    power(transform, x - 1);

    // Create a variable ans to store the answer
    int ans = 0;

    // Now the get the fibonacci number from the first row of powMatrix
    for (int k = 0; k < 2; k++)
    {
        ans = (ans + (1LL * transform[0][k] * helper[k]) % 1000000007) % 1000000007;
    }

    return ans;
}

int fiboSum(int n, int m)
{
    // Compute the answer
    int ans = compute(m + 2) - compute(n + 1);

    // If is answer is negative
    if (ans < 0)
    {
        ans = (ans + 1000000007) % 1000000007;
        return (ans % 1000000007);
    }
    else
    {
        return (ans % 1000000007);
    }
}*/