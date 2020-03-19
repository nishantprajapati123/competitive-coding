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

    vector<ll>B(n);
    for(int i=0;i<n;i++)    cin>>B[i];

    ll mx = INT_MIN;
    //a[0] = b[0]
    cout<<B[0]<<" ";
    mx = max(mx,B[0]);

    //now x[1] = a[0]
    cout<<(B[1] + B[0])<<" ";
    mx = max(mx, (B[1] + B[0]));

    for(int i=2;i<n;i++)
    {
        cout<<(B[i] + mx)<<" ";
        mx = max(mx, (B[i] + mx));
    }
    cout<<"\n";
    return 0;
}
