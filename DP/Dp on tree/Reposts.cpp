#include<bits/stdc++.h>
using namespace std;
typedef vector<int>   vi;
#define mod 1000000007
#define pb push_back
const int N=3e5;
vi g[N];
int uniqval=0;
map<string,int>mp;
int convert(string s)
{
    transform(s.begin(),s.end(),s.begin(),::tolower);
    if(mp.find(s)==mp.end())
    {
        uniqval++;
        mp.insert(make_pair(s,uniqval));
    }
    return mp[s];

}
int dfs(int u, int p)
{
    int ans=0;
    for(int child:g[u])
    {
        if(child==p)
            continue;
        //store maximum of left and right subtree
        ans=max(ans,1+dfs(child,u));
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a,b,c;
        cin>>a>>c>>b;
        int n1=convert(b);
        int n2=convert(a);
        g[n1].pb(n2);
        g[n2].pb(n1);
    }
    cout<<endl;
    cout<<1+dfs(1,0);
}
