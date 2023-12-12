#include <bits/stdc++.h>
using namespace std;
int main() 
{
    long long a,b;
    cin>>a>>b;
    long long r=0;
    for(int j=a; j<=b;j++)
        r+=j;
    cout<<r;
}