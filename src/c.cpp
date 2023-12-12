#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long N, K;
	cin >> N >> K;
	long long avg = 0L;
	long long * l = new long long[N];


	for (long long i = 0; i < N; i++)
	{
		long long j;
		cin >> j;
		l[i] = j;
		avg += j;
	}
	avg /= K;
	long long _l = 0L;
	long long _r = avg;
	while (_l < _r)
	{
		long long mid = (_l + _r) / 2;

		if (_l == mid)
		{
			long long tmp1 = 0;
			long long mid2 = mid + 1;
			for (long long i = 0; i < N; i++)
			{
				tmp1 += l[i] / mid2;
			}
			if (tmp1 == K)
			{
				_l = mid2;
				break;
			}
			else
			{
				_l = mid;
				break;
			}
			
		}

		long long tmp = 0;
		for (long long i = 0; i < N; i++)
		{
			tmp += l[i] / mid;
		}
		if (tmp >= K)
		{
			_l = mid;
		}
		else
		{
			_r = mid;
		}
	}
	cout << _l;
}