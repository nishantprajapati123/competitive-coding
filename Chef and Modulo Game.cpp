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
    ll t;
    cin >> t;

    while(t--)
    {
        ll n,p;
        cin>>n>>p;
        if(n==1 || n==2)
            cout<<p*p*p<<"\n";
        else
        {
            //find number
            ll no=(n/2)+1;
            //find maximum modulo
             ll mx= n%no;
            cout<<((p-mx)*(p-mx))+((p-n)*(p-mx))+((p-n)*(p-n))<<"\n";
        }
    }
    return 0;
}

