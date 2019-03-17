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
const ll N = 4e6;
vector<ll>tree(N,0),lazy(N,0);
//node = [b,e] and query = [l,r]
void build(ll id, ll b, ll e)
{
    if(b==e)
    {
        tree[id] = 0;
        return ;
    }
    ll mid = (b+e)/2;
    build(2*id+1,b,mid);
    build(2*id+2,mid+1,e);
    tree[id] = tree[2*id+1]+tree[2*id+2];
}
void updateRange(ll id, ll b, ll e, ll l, ll r, ll val)
{
    if(lazy[id]!=0) //pending updates
    {
        tree[id] += (e-b+1)*lazy[id];
        //if not leaf then postpone the update to its children
        if(b!=e)
        {
            lazy[2*id+1]+=lazy[id];
            lazy[2*id+2]+=lazy[id];
        }
        lazy[id]=0; //reset
    }
    //if out off range
    if(b>e || e<l || b>r)   return;
    //if completely inside
    if(b>=l && e<=r)
    {
        tree[id] += (e-b+1)*val; //update current node with val
        // if not leaf then postpone the update to its children
        if(b!=e)
        {
            lazy[2*id+1]+=val;
            lazy[2*id+2]+=val;
        }
        return ;
    }
    //if partially overlap then recur to both its children
    int mid = (b+e)/2;
    updateRange(2*id+1,b,mid,l,r,val);
    updateRange(2*id+2,mid+1,e,l,r,val);
    tree[id] = tree[2*id+1]+tree[2*id+2];

}
ll queryRange(ll id, ll b, ll e, ll l, ll r)
{
    //if any update required
    if(lazy[id]!=0)
    {
        tree[id]+=(e-b+1)*lazy[id];
        if(b!=e)
        {
            lazy[2*id+1]+=lazy[id];
            lazy[2*id+2]+=lazy[id];
        }
        lazy[id]=0;
    }
    if(b>e || e<l || b>r)   return 0;
    if(b>=l && e<=r)
        return tree[id];
    ll mid = (b+e)/2;
    ll q1 = queryRange(2*id+1,b,mid,l,r);
    ll q2 = queryRange(2*id+2,mid+1,e,l,r);
    return (q1+q2);
}
int main()
{
    fastIO
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        build(0,0,n-1);
        while(c--){
        ll q,l,r;
        cin>>q>>l>>r;
        if(q==0)
        {
         //   int l,r;
            ll v;
            cin>>v;
            updateRange(0,0,n-1,l-1,r-1,v);
        }
        else if(q==1)
        {
            cout<<queryRange(0,0,n-1,l-1,r-1)<<"\n";
        }
//        for(int i=0;i<n;i++)    cout<<tree[i]<<" ";
//        cout<<endl;
        }
    }
}

