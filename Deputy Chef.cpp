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
    cin >> t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n),d(n);
        for(int i=0;i<n;i++)    cin>>a[i];
        for(int i=0;i<n;i++)    cin>>d[i];
        ll ans = INT_MIN;
        if(d[0]>a[1] && d[0]>a[n-1] && (d[0]>(a[1]+a[n-1])))
        {
            if(d[0]>ans)    ans = d[0];
        }
        for(int i=1;i<n;i++)
        {
            if(d[i]>a[(i+1)%n] && d[i]>a[i-1] && (d[i]>(a[(i+1)%n]+a[i-1])))
            {
                if(d[i]>ans)    ans = d[i];
            }
        }
        if(ans==INT_MIN) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}

