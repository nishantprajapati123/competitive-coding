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
        int n;
        ll x;
        cin>>n>>x;
        cin.ignore();
        string s;
        getline(cin,s);
        ll dis = 1;
        map<int,int>mp;
        mp[x]++;
        if(n==1)    cout<<dis<<"\n";
        else
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]=='L')
                    x--;
                else if(s[i]=='R')
                    x++;
                if(!mp[x]) mp[x]++,dis++;

            }
            cout<<dis<<"\n";
        }

    }
    return 0;
}
