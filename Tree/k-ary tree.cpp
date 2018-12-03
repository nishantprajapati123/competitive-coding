#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll k,m,res;
        cin>>k>>m;
        res=k;
        for(ll i=1;i<m;i++)
        {
            res=((res%MOD)*(k%MOD))%MOD;
        }
        cout<<res<<endl;
    }
}
