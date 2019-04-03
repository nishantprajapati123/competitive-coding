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
        ll n,k;
        cin>>n>>k;
        vector<ll>A(n);
        for(ll i=0;i<n;i++)    cin>>A[i];
        ll points;
        ll res = INT_MIN;
        vector<ll>B(n,0);
        if(k>n)
            cout<<*max_element(A.begin(),A.end())<<"\n";
        else
        {

        for(ll i=0;i<k;i++)
        {
            points = A[i];
            for(ll j=i+k;j<n;j+=k)
            {
                points+=A[j];
            }
            B[i] = points;
        }
        for(ll i=k;i<n;i++)
        {
            B[i] = B[i-k]-A[i-k];
        }
//                for(auto i:B)
//            cout<<i<<" ";
        cout<<*max_element(B.begin(),B.end())<<"\n";
        }
    }
}
