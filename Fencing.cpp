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
bool isValid(ll i, ll j, ll n, ll m)
{
    return (i>=0 && j>=0 && i<n && j<m);
}
int main()
{
    fastIO
    int t;
    cin >> t;

    while(t--)
    {
        ll N,M,K;
        cin>>N>>M>>K;
        //int grid[N][M];
        //memset(grid,0,sizeof(grid));
        map<pair<ll,ll> , int>mp;
        vector<pair<ll,ll> >plant(K);
        for(ll i=0;i<K;i++)
        {
            ll r,c;
            cin>>r>>c;
            plant[i]=mk(r-1,c-1);
//            grid[r-1][c-1]=1;//mark as plant
            mp.insert(mk(mk(r-1,c-1),1));
        }
      //  set<pair<ll,ll> >adj_weed;
        ll counter=0;
        for(ll i=0;i<K;i++)
        {
            ll x = plant[i].first, y = plant[i].second;
            //check top
            if(!isValid(x-1,y,N,M) || (isValid(x-1,y,N,M) && mp.find(mk(x-1,y))==mp.end()))
                counter++;

            //check right
            if(!isValid(x,y+1,N,M) || (isValid(x,y+1,N,M) && mp.find(mk(x,y+1))==mp.end()))
                counter++;

            //check bottom
            if(!isValid(x+1,y,N,M) || (isValid(x+1,y,N,M) && mp.find(mk(x+1,y))==mp.end()))
                counter++;

            //check left
            if(!isValid(x,y-1,N,M) || (isValid(x,y-1,N,M) && mp.find(mk(x,y-1))==mp.end()))
                counter++;
        }
        //for(auto it=adj_weed.begin();it!=adj_weed.end();++it)
          //  cout<<it->first<<" "<<it->second<<endl;
        cout<<counter<<"\n";
    }
    return 0;
}

