#include<bits/stdc++.h>
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
ll prime(ll X, ll Y, ll N)
{
        vector<bool>isPrime(N+1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(ll i = 2; i * i <= N; ++i) {
             if(isPrime[i] == true) {
                 for(ll j = i * i; j <= N ;j += i)
                     isPrime[j] = false;
            }
        }
        for(ll i=N;i>=0;i--)
        {
            if(isPrime[i] && Y%i==0 && X%i==0)
                return i;
        }
}
int main()
{
    fastIO
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        map<ll,ll>mp;
        ll n,l;
        cin>>n>>l;
        vector<ll>A(l),res(l+1);
        for(ll i=0;i<l;i++) cin>>A[i];
//        cout<<prime(3292937,175597,n);
        res[1] = prime(A[0],A[1],n);
        res[0] = A[0]/res[1];
        res[2] = A[1]/res[1];
        for(ll i=2;i<l;i++)
            res[i+1] = A[i]/res[i];
//        for(auto i:res) cout<<i<<" ";
        vector<ll>temp=res;
        sort(temp.begin(),temp.end());
//        for(auto i:temp) cout<<i<<" ";
        int k=0;
        for(ll i=0;i<temp.size();i++)
        {
            if(mp.find(temp[i])==mp.end())
                mp.insert(mk(temp[i],k++));
        }
//        for(auto it=mp.begin();it!=mp.end();++it)
//            cout<<it->first<<" "<<it->second<<"\n";
        string ans="";
        for(ll i=0;i<res.size();i++)
        {
            char ch=mp[res[i]]+65;
            ans+=ch;
        }
        cout<<"Case #"<<z<<": "<<ans<<"\n";
    }
}
