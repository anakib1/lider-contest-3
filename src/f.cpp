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
ll pw(ll a, ll pws, ll mod)
{
	a %= mod;
	if (pws== 0)
		return 1;
	if (pws == 1)
		return a;
	if (pws % 2 == 0)
	{
		ll vr = pw(a, pws / 2, mod);
		return ((vr % mod) * (vr % mod)) % mod;
	}
	return (a * pw(a, pws - 1, mod)) % mod;

}
bool test(int n, int d)
{
	int a = 2 + rand() % (n - 4);
	ll x = pw(a, d, n);
	if (x == 1 || x == n - 1)
		return true;
	while (d != n - 1)
	{
		x = (x * x) % n;
		d <<= 1;
		if (x == 1)
			return false;
		if (x == n - 1)
			return true;
	}
	return false;
}
bool prime(int a)
{
	if (a == 1)return false;
	if (1 < a && a < 4)
		return true;
	if (a % 2 == 0)
		return false;
	int d = a - 1;
	while (d % 2 == 0)
		d /= 2;
	for (int _ = 0; _ < 100; _++)
		if (!test(a, d))
			return false;
	return true;
}
bool has(ll a)
{
	int last = 0;
	while (a > 0)
	{
		if (a % 10 == 1 && last == 3)
			return true;
		last = a % 10;
		a /= 10;
	}
	return false;
}
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	srand(time(NULL));
	int a, b;
	cin >> a >> b;
	vector<int> ans;
	for (int i = a; i <= b; i++)
		if (prime(i))
			ans.push_back(i);
	if (ans.empty())
		return 0;
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++)
		cout << ' ' << ans[i];
	cout << '\n';
	
}