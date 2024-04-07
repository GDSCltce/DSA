#include <bits/stdc++.h>
#include "array.h"
using namespace std;

#define endl '\n'
#define ll long long int
#define space ' '
#define dbg(x) printf("%s = %d\n", #x, x);
// const int mod = 1000000007;
/*************************************/

class myHash
{
	// vector<int> arr;
	int *arr;
	int cap, size;

public:
	myHash(int c)
	{
		cap = c;
		size = 0;
		// arr(cap, -1);
		for (int i = 0; i < cap; i++)
		{
			arr[i] = -1;
		}
	}
	int hash(int key)
	{
		return key % cap;
	}

	bool search(int key)
	{
		int h = hash(key);
		int i = h;
		while (arr[i] != -1)
		{
			if (arr[i] == key)
			{
				return true;
			}
			i = (i + 1) % cap;
			if (i == h)
			{
				return false;
			}
		}
		return false;
	}

	bool insert(int key)
	{

		if (size == cap)
		{
			return false;
		}
		int i = hash(key);
		while (arr[i] != -1 || arr[i] != -2 || arr[i] != key)
		{
			i = (i + 1) % cap;
			if (arr[i] == key)
			{
				return false;
			}
			else
			{
				arr[i] = key;
				size++;
				return true;
			}
		}
		return false;
	}

	bool erase(int key)
	{
		int h = hash(key);
		int i = h;
		while (arr[i] != -1)
		{
			if (arr[i] == key)
			{
				arr[i] = -2;
				return true;
			}
			i = (i + 1) % cap;
			if (i == h)
			{
				return false;
			}
			return false;
		}
		return false;
	}
	void print()
	{
		for (int i = 0; i < cap; i++)
		{
			cout << i << " " << arr[i] << endl;
		}
	}
};

inline void solve()
{
	myHash h(7);
	h.insert(49);
	h.insert(56);
	h.insert(72);
	if (h.search(56))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "nO" << endl;
	}
	h.print();
	h.erase(56);
	if (h.search(56))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "nO" << endl;
	}
	h.print();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.in", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t;
	// scanf("%d", &t);
	// while (t--)
	{
		solve();
	}
	return 0;
}
