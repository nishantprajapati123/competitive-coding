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
vi maxDivisor;
void findMaxDiv(int n)
{
    maxDivisor.assign(n+1,0);
    maxDivisor[0] = INT_MAX;
    maxDivisor[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (maxDivisor[i]) continue;
        for (int j = i; j <= n; j += i) {
            if (maxDivisor[j]) continue;
            maxDivisor[j] = j / i;
        }
    }
}

void solve()
{
    int n;
    scanf("%d",&n);

    findMaxDiv(n);

    sort(maxDivisor.begin(),maxDivisor.end());

    for(int i=1;i<n;i++)
        // printf("%d ",maxDivisor[i]); 
        cout<<maxDivisor[i]<<" ";  
}
int main()
{
    fastIO
    solve();
    return 0;
}