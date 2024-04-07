#include <iostream>
using namespace std;

class myHash
{
	int *arr;
	int cap, size;

public:
	myHash(int c)
	{
		cap = c;
		arr = new int[cap];
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
		while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
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
		}
		return false;
	}
	void print()
	{
		for (int i = 0; i < cap; i++)
		{
			if (arr[i] != -1 && arr[i] != -2)
				cout << i << " --> "
					 << arr[i] << endl;
			else
				cout << i << endl;
		}
	}
};

void solve()
{
	myHash h(7);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		h.insert(x);
	}
	if (h.search(49))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	h.erase(38);
	h.print();
	if (h.search(56))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	h.erase(40);
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
