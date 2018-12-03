
#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        ll n,sum=0,mult=1;
        int t;
        cin>>n>>t;
        int i=1;
           for(int k=1;k<=t;k++)
           {
                mult=((mult%mod)*((i+k)%mod))%mod;
                if(k==t && i<=n)
                {
                    sum=((sum%mod) + (mult%mod))%mod;
                    mult=1;
                    i++;k=0;
                    continue;
                }
           }
           cout<<sum<<endl;
    }
}
