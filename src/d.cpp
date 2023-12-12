#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<int> res;
	vector<int> minim;
	int N;
	cin >> N;
	int min = 0,prev_min=0;
	for (int y = 0; y < N; y++)
	{
		int t1;
		cin >> t1;
		if (t1 == 1)
		{
			int x;
			cin >> x;
			res.push_back(x);
			if(minim.size()==0)
				minim.push_back(x);
			else
			{
				minim.push_back(x<minim[minim.size() - 1] ? x : minim[minim.size() - 1] );
			}
			
		}
		else if (t1 == 2)
		{
			
			res.pop_back();
			minim.pop_back();
		}
		else if(t1==3)
		{
			
			cout << minim[minim.size()-1] << '\n';
		}

	}}