#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n >> i;
        cout << (n & ~(1 << i)) << endl;
    }
}