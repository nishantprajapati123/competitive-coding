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
    int n,q;
    ll m;
    cin>>n;
    vector<int>price(n);
    for(int i=0;i<n;i++) cin>>price[i];
    cin>>q;
    sort(price.begin(),price.end());
    while(q--)
    {
        cin>>m;
        auto upper = upper_bound(price.begin(),price.end(),m);
        cout<<upper-price.begin()<<"\n";
    }
    return 0;
}
