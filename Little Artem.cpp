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
#define INF (int)1e9
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
    int n, m;
    scanf("%d%d", &n, &m);

    int total = n*m;
    vector<vector<char> >A(n, vector<char>(m));
    bool black = true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0 && i>0)
            {
                black = A[i-1][j] == 'B'?false:true;
            }

            if(black)
            {
                A[i][j] = 'B';
                black = !black;
            }
            else
            {
                A[i][j] = 'W';
                black = !black;
            }
            
        }
    }
    if(!(total&1))
    {
        for(int i=0;i<n;i++)
        {
            if(A[i][m-1] == 'W')
            {
                A[i][m-1] = 'B';
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%c", A[i][j]);
        printf("\n");
    }


}
int main()
{
    fastIO
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase<=T; testcase++)
    {
        solve();
        // printf("\n");
    }
    return 0;
}