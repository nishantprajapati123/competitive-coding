#include<bits/stdc++.h>
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
bool perfectsquare(ll x)
{
    ll sr=sqrt(x);
    return (sr*sr==x);
}
int main()
{
    fastIO
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++)
    {
        bool found=true;
        //int cont=0;
        if(perfectsquare(a[i]) && a[i]!=1)
        {
            ll square = sqrt(a[i]);
            for(ll j=2;j*j<=square;j++)
            {
                if(a[i]%j==0)
                    {
                        found=false;
                        break;
                    }
            }
            if(found)
                cout<<"YES"<<"\n";
            else
                cout<<"NO"<<"\n";
        }
        else
            cout<<"NO"<<"\n";
    }

}
