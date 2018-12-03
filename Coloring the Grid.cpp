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
bool isValid(int x, int y,int n, int m)
{
    return (x>=0 && y>=0 && x<n && y<m);
}
int main()
{
    fastIO
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cin.ignore();
        vector<string>grid(n);
        int totalcolor=0;
        for(int i=0;i<n;i++)
        {
            string g;
            getline(cin,g);
            for(int i=0;i<m;i++)
            {
                if(g[i]=='.')
                    totalcolor++;
            }
            grid[i]=g;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isValid(i,j+1,n,m) && isValid(i+1,j,n,m) && !(grid[i][j]=='#' || grid[i][j+1]=='#' || grid[i+1][j]=='#' ||grid[i+1][j+1]=='#'))
                {
                    if(grid[i][j]=='.')
                        grid[i][j]='c',cnt++;
                    if(grid[i][j+1]=='.')
                        grid[i][j+1]='c',cnt++;
                    if(grid[i+1][j]=='.')
                        grid[i+1][j]='c',cnt++;
                    if(grid[i+1][j+1]=='.')
                        grid[i+1][j+1]='c',cnt++;
                }
            }
        }
        if(cnt==totalcolor)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }
}
