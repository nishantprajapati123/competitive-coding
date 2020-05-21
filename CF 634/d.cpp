#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define deb(x) cout << #x << "=" << x << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define INF (ll)1e30
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
void solve()
{
    // vector<vector<int> >s(9, vector<int>(9));
    vector<string>s(9);
    for(int i=0;i<9;i++)
    {
        cin>>s[i];
    }

    // for(int i=0;i<9;i++)
    // {
    //     for(int j=0;j<9;j++)
    //         cout<<s[i][j];
    //         cout<<"\n";
    // }
    // vector<int>row(10, 9), col(10, 9);
    int i=0;
    while(i<9)
    {
        if(i<=2)
        {
            int j=0;
            while(j < 9)
            {
                // deb(i);deb(j);
                // s[i][j] = (((s[i][j]-'0') + 1) >9)?49:(s[i][j]-'0')+1;
                s[i][j] = (s[i][j] == '9')?'1':(s[i][j]-'0' + 1 + 48);
                j += 3;
                i++;
            }
        }
        else if(i<=5)
        {
            int j=1;
            while(j < 9)
            {
                // deb(i);deb(j);
                s[i][j] = (s[i][j] == '9')?'1':(s[i][j]-'0' + 1 + 48);
                // s[i][j] = (((s[i][j]-'0') + 1) >9)?49:(s[i][j]-'0')+1;
                j += 3;
                i++;
            }
        }
        else
        {
            int j=2;
            while(j < 9)
            {
                // deb(i);deb(j);
                // s[i][j] = (((s[i][j]-'0') + 1) >9)?49:(s[i][j]-'0')+1;
                s[i][j] = (s[i][j] == '9')?'1':(s[i][j]-'0' + 1 + 48);
                j += 3;
                i++;
            }
        }
        
    }
    cout<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<s[i][j];
        cout<<"\n";
    }
}
int main()
{
    fastIO
    int T;
    cin>>T;
    cin.ignore();
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
        // cout<<"\n";
    }
    return 0;
}