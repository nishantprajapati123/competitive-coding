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
int main()
{
    fastIO
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        ll n;
        cin>>n;
        cin.ignore();
        string p;
        getline(cin,p);
        string res="";
        for(int i=0;i<p.length();i++)
        {
            if(p[i]=='S')   res=res+"E";
            else if(p[i]=='E')  res=res+"S";
        }
        cout<<"Case #"<<k<<": "<<res<<"\n";
    }
    return 0;
}
