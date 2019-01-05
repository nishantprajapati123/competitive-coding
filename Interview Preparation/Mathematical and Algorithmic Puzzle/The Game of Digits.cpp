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
        vector<ll>res;
        if(n>=1 && n<=9)
            cout<<n<<"\n";
        else
        {
            for(int i=9;i>=2;i--)
            {
                while(n%i==0)
                {
                    res.pb(i);
                    n/=i;
                }
            }
            ll num = 0;
            if(n==1)
            {
                for(int i=0;i<res.size();i++)
                    num = num*10 + res[i];
                cout<<num<<"\n";
            }
            else
                cout<<"-1"<<"\n";
        }
    }
    return 0;
}

