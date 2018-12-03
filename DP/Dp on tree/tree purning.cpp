#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
#include <cassert>
#include <climits>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define PI acos(-1)
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define LL long long

using namespace std;

#define maxn 100111

vector <int> adj[maxn];
int n, k, weight[maxn], cnt[maxn], dfs_order[maxn];
long long f[maxn], sum[maxn];
int __cnt;

bool getChar(char& c) {
    return (scanf("%c", &c) == 1);
}

void nextInt(long long& u, char endline, int l, int r) {
    int sign = 1;
    long long sum = 0;
    char c;
    assert(getChar(c));
    if (c == '-') sign = -1;
    else {
        assert('0' <= c && c <= '9');
        sum = (c - '0');
    }

    int cnt = 0;

    for (int i = 1; i <= 15; i++) {
        assert(getChar(c));
        if (c == endline) break;
        assert('0' <= c && c <= '9');
        sum = sum * 10 + (c - '0');
        cnt ++;
        assert(cnt <= 15);
    }

    sum = sign * sum;
    assert (l <= sum && sum <= r);
    u = sum;
}

void nextInt(int& u, char endline, int l, int r) {
    long long tmp;
    nextInt(tmp, endline, l, r);
    u = tmp;
}

void dfs(int u) {
    dfs_order[++__cnt] = u;
    cnt[u] = 1;

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];
        if (cnt[v]) continue;
        dfs(v);
        cnt[u] += cnt[v];
    }
}

int main() {
    nextInt(n, ' ', 2, (int)1e5);
    nextInt(k, '\n', 1, 200);

    for (int i = 1; i <= n; i++) {
        char c;
        c = ' ';
        if (i == n) c = '\n';

        nextInt(weight[i], c, (int) -(1e9), (int) (1e9));
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        nextInt(u, ' ', 1, n);
        nextInt(v, '\n', 1, n);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset (cnt, 0, sizeof(cnt));
    dfs(1);
    for (int i= 1; i <= n; i++) assert(cnt[i] > 0);

    for (int i = 1; i <= n; i++)
        sum[i] = weight[dfs_order[i]] + sum[i - 1];

    for (int i = 1; i <= n; i++) f[i] = sum[i];
    //for (int i = 1; i <= n; i++) cerr << dfs_order[i] << " " << cnt[i] << endl;
    for (int rep = 1; rep <= k; rep ++) {
        for (int i = n; i >= 1; i--) {
            int pos = i + cnt[dfs_order[i]] - 1;
            f[pos] = max(f[pos], f[i - 1]);
        }

        for (int i = 1; i <= n; i++)
            f[i] = max(f[i], f[i - 1] + weight[dfs_order[i]]);
    }

    //cout << f[n] << endl;
    for (int i = 1; i <= n; i++)
        cout<<cnt[i]<<" ";
    char __c;
    assert(!getChar(__c));
    return 0;
}
