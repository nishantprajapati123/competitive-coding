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
    freopen("input.txt","r",stdin);
    int x,y,z,a,b,c;
    cin>>x>>y>>z;
    cin>>a>>b>>c;
    bool found = true;
    if(a>=x)
        a-=x;
    else
        found = false;
    int rem;
    if(found && (a+b)>=y)
        rem = (a+b)-y;
    else
        found = false;
    if(!found || (rem+c)<z)
        found = false;

    if(found)   cout<<"YES\n";
    else    cout<<"NO\n";

    return 0;
}
