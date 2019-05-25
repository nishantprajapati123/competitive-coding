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
        char s[n+1];
        char x;
        cin>>s>>x;
        vector<ll>occur;
        for(int i=0;i<n;i++)
        {
            if(s[i]==x) occur.pb(i);
        }
        ll j=0,i=0,counter=0;
        if(occur.size()>=1)
        {
           while(j<occur.size() && i<n)
           {
               if(i<=occur[j])
                    counter+=1+(n-1)-occur[j];
               if(i==occur[j])
                    j++;
               i++;
           }
        }
        cout<<counter<<"\n";

    }
}
