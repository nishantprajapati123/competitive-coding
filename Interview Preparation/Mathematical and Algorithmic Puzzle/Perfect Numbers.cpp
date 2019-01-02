#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
int main()
{
    fastIO
    int t;
    cin>>t;
    while(t--)
    {
        ll sum=0;
        ll n;
        cin>>n;
        for(ll i=1;i*i<=n;i++)
        {
            if(n%i==0 && n!=1)
            {
                sum+=i;
                if((n/i)!=n)
                    sum+=(n/i);
            }
        }
        if(sum==n)
            cout<<"1"<<"\n";
        else
            cout<<"0"<<"\n";
    }
}
