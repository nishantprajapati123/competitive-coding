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
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
        int n = s.length();
        int table[n][n],i,j,len;
        memset(table,0,sizeof(table));

        for(int len = 1;len<n;len++)
        {
            for(i = 0,j = len; j<n ; i++,j++)
            {
                if(s[i] == s[j])    table[i][j] = table[i+1][j-1];
                else table[i][j] = min(table[i][j-1],table[i+1][j])+1;
            }
        }
        cout<<table[0][n-1]<<"\n";
    }
    return 0;
}
