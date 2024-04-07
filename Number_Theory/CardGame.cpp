#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF 1000000000
#define int long long
vector<int> primes;
void __sieve(int n = 1000009)
{
    vector<bool> __PRIME;
    __PRIME.resize(n + 1, true);
    __PRIME[0] = __PRIME[1] = 0;
    int sqtn = sqrt(n);
    for (int p = 2; p <= sqtn; p++)
        if (__PRIME[p])
            for (int i = p * p; i <= n; i += p)
                __PRIME[i] = false;

    for (int i = 0; i < n; i++)
        if (__PRIME[i])
            primes.emplace_back(i);

    return;
}

signed main()
{
    // freopen("in.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<pair<int, int>> kp;
    int k_bkp = k;
    for (int i = 2; i * i <= k_bkp; i++)
    {
        if ((k_bkp % i) == 0)
        {
            int cnt = 0;
            while (k_bkp % i == 0)
            {
                k_bkp /= i;
                cnt++;
            }
            kp.push_back({i, cnt});
        }
    }

    if (k_bkp != 1)
        kp.push_back({k_bkp, 1});

    vector<pair<int, int>> ep = kp;
    for (int i = 0; i < ep.size(); i++)
    {
        ep[i].second = 0;
    }
    int ans = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < ep.size(); x++)
        {
            if ((arr[i] % ep[x].first) == 0)
            {
                int f = ep[x].first;
                int num = arr[i];
                int cnt = 0;
                while (num % f == 0)
                {
                    num /= f;
                    cnt++;
                }
                ep[x].second += cnt;
            }
        }

        while (j <= i)
        {
            int flag = 0;
            for (int x = 0; x < kp.size(); x++)
            {
                if (ep[x].second < kp[x].second)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                ans += n - i;
                for (int x = 0; x < ep.size(); x++)
                {
                    if (arr[j] % ep[x].first == 0)
                    {
                        int f = ep[x].first;
                        int num = arr[j];
                        int cnt = 0;
                        while (num % f == 0)
                        {
                            num /= f;
                            cnt++;
                        }
                        ep[x].second -= cnt;
                    }
                }
            }
            else
            {
                break;
            }
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}
Let's use two pointers.

Firstly you need to learn to factorize any number in no more than . We don't actually need any of their prime divisors except for those that are presented in k. So let's factorize k in . After that check for the maximum power of each useful prime will work in  for each number.

Now notice that if some segment [l, r] has its product divisible by k then all segments [l, i] for (r ≤ i ≤ n) will also have products divisible by k.

Now we have to find the smallest r for each l out there. That's where two pointers kick in. Let's maintain the current product of the segment in factorized form (only useful primes), as in normal form its enormous. The power of some prime in this form is the sum of powers of this prime in all the numbers in the segment.

We firstly move the left border of the segment one step to the right and then keep moving the right border to the right until power of at least one prime number in the product is smaller than in k. It means that it is not divisible by k. Moving the left border means subtracting all the powers of useful primes of number al from the product and moving the right border is adding all the powers of useful primes of ar.

The first time we reach such a segment, we add (n - r) to answer (consider r 0-indexed).

Overall complexity: , where MAXN is up to 109.