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
vector<string> digits = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
 
int convertDigit(string& digit1, string& digit2) {
    int cost = 0;
    for(int i = 0; i < 7; i++) {
        if(digit1[i] == '1' && digit2[i] == '0') {
            return -1;
        }
        cost += (digit1[i] != digit2[i]);
    }
    return cost;
}
 
int main()
{
    int n, k;
    cin.sync_with_stdio( false );
    cin >> n >> k;
    vector<string> d(n + 1);
    vector<vector<int>> dp(n + 2, vector<int>(k + 1, -1));
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    dp[n + 1][0] = 0;
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= k; j++) {
            for(int cif = 9; cif >= 0; cif--) {
                int cost = convertDigit(d[i], digits[cif]);
                if(cost == -1 || cost > j) continue;
                if(dp[i + 1][j - cost] != -1) {
                    dp[i][j] = cif;
                    break;
                }
            }
        }
    }
    if(dp[1][k] == -1) {
        cout << "-1\n";
    }
    else {
        for(int i = 1; i <= n; i++) {
            cout << dp[i][k];
            k -= convertDigit(d[i], digits[dp[i][k]]);
        }
        cout << "\n";
    }
    return 0;
}