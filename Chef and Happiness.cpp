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
        unordered_map<int,vector<int> >mp;
        int n;
        cin>>n;
        vi g[n];
        vi A(n+1,0);
        for(int i=1;i<n+1;i++)
        {
            cin>>A[i];
            mp[A[i]].pb(i);
        }
        int cnt=0;
        for(auto it=mp.begin();it!=mp.end();++it)
        {
            cnt=0;
            int each=it->first;
            if(mp[each].size()>=2)
            {
                for(int i=0;i<mp[each].size();i++)
                {
                    if(mp.find(mp[each][i])!=mp.end()) cnt++;
                }
            }
            if(cnt>=2) break;
        }
        if(cnt>=2) cout<<"Truly Happy"<<"\n";
        else cout<<"Poor Chef"<<"\n";

    }
    return 0;
}
