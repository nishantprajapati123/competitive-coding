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
const ll N = 6e7;
vector<ll> A(N,0);
ll tree[N];
void build(ll id, ll b, ll e)
{
    if(b==e)
    {
        tree[id] = 0;
        return;
    }
    ll mid = (b+e)/2;
    build(2*id,b,mid);
    build(2*id + 1,mid+1,e);

    tree[id] = tree[2*id]+tree[2*id+1];
}
void update(ll id, ll i, ll b, ll e, ll val)
{
    if(b>e||b>i||e<i) return;
    if(b==e)
    {
        if(val==1)
            tree[id] = 1;
        else
            tree[id] = 0;
        A[i] = val;
        return;
    }
    ll mid = (b+e)/2;
    update(2*id,i,b,mid,val);
    update(2*id+1,i,mid+1,e,val);

    tree[id] = tree[2*id]+tree[2*id+1];
//    for(int j=1;j<10;j++)
//            cout<<tree[j]<<" ";
//    cout<<endl;
}
ll query(ll id, ll l, ll r, ll b, ll e)
{
    if(b>e||l>r||b>r||l>e) return 0;
    if(b>=l && e<=r)
        return tree[id];
    ll mid = (b+e)/2;
    return (query(2*id,l,r,b,mid) + query(2*id+1,l,r,mid+1,e));
}
int main()
{
    fastIO
    ll n,q;
    cin>>n>>q;
    build(1,0,n-1);
    while(q--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            ll i;
            cin>>i;
            update(1,i-1,0,n-1,(2*A[i-1])+1);
        }
        else if(x==2)
        {
            ll i;
            cin>>i;
            update(1,i-1,0,n-1,floor(A[i-1]/2));
        }
        else if(x==3)
        {
            ll i,j;
            cin>>i>>j;
            cout<<query(1,i-1,j-1,0,n-1)<<"\n";
        }

    }

    return 0;
}

