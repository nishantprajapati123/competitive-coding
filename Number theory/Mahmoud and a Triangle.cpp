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
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(all(a));
    bool found =false;
    int i;
    for(i=n-1;i>=2;i--)
    {
        if(a[i]<(a[i-1]+a[i-2]))
        {
            found=true;
            break;
        }
    }
    if(found)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
