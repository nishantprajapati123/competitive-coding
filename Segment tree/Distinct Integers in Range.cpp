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
const int N = 3e5;
vi A(N),B(N);
bitset<5001>tree1[N],tree2[N];
void build(int id, int b, int e)
{
    if(b==e)
    {
        tree1[id].set(A[b]);
        tree2[id].set(B[b]);
        return;
    }
    int mid = (b+e)/2;
    build(2*id,b,mid);
    build(2*id + 1,mid+1,e);

    tree1[id] = tree1[2*id]|tree1[2*id+1];
    tree2[id] = tree2[2*id]|tree2[2*id+1];
}
bitset<5001>query1(int id, int l, int r, int b, int e)
{
    if(b>e||l>r||b>r||l>e) return 0;
    if(b>=l && e<=r)
        return tree1[id];
    int mid = (b+e)/2;
    return (query1(2*id,l,r,b,mid) | query1(2*id+1,l,r,mid+1,e));
}
bitset<5001>query2(int id, int l, int r, int b, int e)
{
    if(b>e||l>r||b>r||l>e) return 0;
    if(b>=l && e<=r)
        return tree2[id];
    int mid = (b+e)/2;
    return (query2(2*id,l,r,b,mid) | query2(2*id+1,l,r,mid+1,e));
}
int main()
{
    fastIO
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    build(1,0,n-1);
    cin>>q;
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        bitset<5001>ans;
        ans = query1(1,a-1,b-1,0,n-1)| query2(1,c-1,d-1,0,n-1);
        cout<<ans.count()<<"\n";
    }
    return 0;
}
