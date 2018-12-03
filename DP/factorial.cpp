#include<bits/stdc++.h>
#define MOD 1000000007
typedef long long int ll;
using namespace std;
int main()
{
    ll n;
    cin>>n;
    vector<ll>fact(n,0);
    //base condition
    fact[0]=fact[1]=1;
    //bottom up approach
    for(int i=2;i<n;i++)
    {
        fact[i]=((i%MOD)*(fact[i-1]%MOD))%MOD;
    }
    cout<<fact[n-1];
    return 0;
}
