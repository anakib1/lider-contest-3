#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include <math.h>
#include <queue>
using namespace std;

unsigned long Count(unsigned long a)
{
    int c=1, k=0;

    while(!(a&1))
    {
        a>>=1;
        k++;
    }
    if(a==1)
        return k+1;
    else
        c=k+1;
    for(int i=3; i*i<=a;i+=2)
    {
        k=0;
        while(a%i==0)
        {
            k++;
            a/=i;
        }
        c*=(k+1);
    }
    if(a>1)
        c<<=1;
    return c;
}
int main()
{
    long long n;
    cin>>n;
    cout<<Count(n)-2;
}