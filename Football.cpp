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
        int n;
        cin>>n;
        vector<int>A(n),B(n);
        for(int i=0;i<n;i++)    cin>>A[i];
        for(int i=0;i<n;i++)    cin>>B[i];
        int res = INT_MIN;
        for(int i=0;i<n;i++)
        {
            int total = (A[i]*20 - B[i]*10)<0 ? 0:A[i]*20 - B[i]*10;
            res = max(res,total);
        }
        cout<<res<<"\n";
    }
    return 0;
}
