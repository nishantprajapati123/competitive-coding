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
        ll n;
        cin>>n;
        vector<ll>A(n);
        for(int i=0;i<n;i++)
            cin>>A[i];
        vector<ll>div;
        ll num = 0;
        sort(A.begin(),A.end());
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j*j<=A[i];j++)
            {
                if(A[i]%j==0)
                    div.pb(j);
                if(A[i]/j!=j) div.pb(A[i]/j);
            }
            if(div.size()==3)
                {num = num*10+A[i]; cout<<"0k";}
            div.clear();
        }
        cout<<num<<"\n";
    }
}

