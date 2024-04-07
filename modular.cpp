const int mod = 1e9 + 7;
int modAdd(int n, int m)
{
    return ((n % mod) + (m % mod)) % mod;
}
int modSubtract(int n, int m)
{
    return ((n % mod) - (m % mod)) % mod;
}
int modMultiple(int n, int m)
{
    return ((n % mod) * (m % mod)) % mod;
}
