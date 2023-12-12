#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    int N, k;
    cin>>N>>k;
    long long min,max;
    long long a;
    cin>>a;
    min=max=a;
    for(int i=1; i<N;i++)
    {
        long long b;
        cin>>b;
        if(b>max)
            max=b;
        if(b<min)
            min=b;
    }
    cout<<max-min;
}