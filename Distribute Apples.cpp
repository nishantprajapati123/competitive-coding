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
        ll N,K;
        cin>>N>>K;
        if(K==1)
            cout<<"NO\n";
        else if(K == N)
            cout<<"YES\n";
        else
        {
            ll each_box = N/K;
            if(each_box%K == 0)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
    return 0;
}

