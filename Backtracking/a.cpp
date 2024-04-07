#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long int
#define ld long double
#define ull unsigned long long
#define mod 1000000007
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define gri greater<int>()
#define all(x) (x).begin(), (x).end()
#define debug(x)                    \
    cout << #x << " = ", _print(x); \
    cout << endl;
/*-------------------ASIMARIES--------------------*/
void _print(int t) { cout << t; }
void _print(ll t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(ld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) { cout << "{", _print(p.first), cout << " ,", _print(p.second), cout << "}"; }
template <class T>
void _print(vector<T> v)
{
    cout << "[ ";
    for (T i : v)
        _print(i), cout << " ";
    cout << "]";
}
template <class T>
void _print(set<T> v)
{
    cout << "[ ";
    for (T i : v)
        _print(i), cout << " ";
    cout << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cout << "[ ";
    for (T i : v)
        _print(i), cout << " ";
    cout << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cout << "[ ";
    for (auto i : v)
        _print(i), cout << "\n";
    cout << "]";
}
template <class T>
void printArr(vector<T> v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}
/*----------------ASIMARIES-----------------*/
void asimaries();

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif

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
    cout << ceil(5 / 2);
}
