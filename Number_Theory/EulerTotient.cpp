#include <iostream>
#include <vector>
using namespace std;

vector<int> phi;
void eulerTotientN(int n = 1000000) // phi(n) from 1 to n, where n <= 10^6
{
    for (int i = 0; i <= n; ++i)
        phi.emplace_back(i);

    for (int i = 2; i <= n; i++)
        if (phi[i] == i)
        {
            phi[i] -= 1;
            for (int p = 2 * i; p <= n; p += i)
                phi[p] /= i, phi[p] *= i - 1;
        }
    return;
}

int eulerTotient(int n) // phi(n), where n <= 10^9
{
    int result = n;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }

    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    int n;
    // cin >> n;
    eulerTotientN();
    cout << phi.size() << endl;
    cout << eulerTotient(1000 * 1000 * 1000);
    return 0;
}
