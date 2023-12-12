#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <set>
#include <list>
#include <deque>
#include <iomanip>
#include <sstream>
#include <fstream>


#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
vector<int> tree;
void build(int v, int l, int r, vector<int> &arr)
{
	if (l == r)
	{
		tree[v] = arr[l];
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m, arr);
	build(v * 2 + 1, m + 1, r, arr);
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}
void upd(int v, int l, int r, int pos, int x)
{
	if (r < l)return;
	if (l == r)
	{
		tree[v] = x;
		return;
	}
	int m = (l + r) / 2;
	if (pos <= m)
		upd(v * 2, l, m, pos, x);
	else
		upd(v * 2 + 1, m + 1, r, pos, x);
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}
int sum(int v, int l, int r, int _l, int _r)
{
	if (_l > r || _r < l)
		return 0;
	if (_l <= l && r <= _r)
		return tree[v];
	int m = (l + r) / 2;
	return sum(v * 2, l, m, _l, _r) + sum(v * 2 + 1, m + 1, r, _l, _r);
}
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	tree.resize(n * 4);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build(1, 0, n - 1, a);
	while (q--)
	{
		char c;
		int l, r;
		cin  >> c>> l >> r;
		l--;
		if (c == '?')
			cout << sum(1, 0, n - 1, l, r - 1) << '\n';
		else
			upd(1, 0, n - 1, l, r);
	}
}