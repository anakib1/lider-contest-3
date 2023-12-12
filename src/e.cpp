#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include <queue>
using namespace std;

long long Fib(long long n)
{
    long long ov=0;
    long long v=1;
    if(n==0)
        return 0;
    for(int i=1; i<n;i++)
    {
        int tmp=v;
        v+=ov;
        ov=tmp;
    }
    return v;
}
int main()
{
    long long n;
    cin>>n;
    n++;
    cout<<Fib(n);
}