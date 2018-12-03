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
        ll n;
        cin>>n;
        unordered_map<ll,ll>m;
        vector<ll>a(n);
        ll totalorder=0;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]++;
        }
        sort(all(a));
//        for(auto it=m.begin();m.end();++it)
//        {
//            if(it->first >= it->second)
//                totalorder++;
//        }
        for(auto it=m.begin();it!=m.end();++it)
        {
            ll times=it->second;
            ll value=it->first;
            while(times)
            {
                if(binary_search(all(a),times) && m[times]>=value)
                    totalorder++;
                times--;
            }
        }
        cout<<totalorder<<"\n";
    }
}
