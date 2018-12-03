#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long MOD = (long long) 1e9 + 7LL;

vector<vector<int> > adj;
int vis[100005];
int col[100005];
long long dp[100005][2];
int N;

void dfs(int u){
    vis[u] = 1;
    dp[u][0] = 1 - col[u];
    dp[u][1] = col[u];
    long long zero, one;
    for(int i=0;i<adj[u].size();++i){
        int v = adj[u][i];
        if(vis[v]) continue;
        dfs(v);
        zero = dp[u][0];
        one = dp[u][1];
        dp[u][0] = 0;
        dp[u][1] = 0;

        dp[u][0] = zero * dp[v][1];
        dp[u][0] %= MOD;
        dp[u][1] = one * dp[v][1];
        dp[u][1] %= MOD;

        dp[u][0] += zero * dp[v][0];
        dp[u][0] %= MOD;
        dp[u][1] += one * dp[v][0] + zero * dp[v][1];
        dp[u][1] %= MOD;

    }
}
int main(){
    scanf("%d", &N);
    adj = vector<vector<int> >(N+3);
    int v;
    for(int i=0;i<N-1;++i){
        scanf("%d", &v);
        adj[i+1].push_back(v);
        adj[v].push_back(i+1);
    }
    for(int i=0;i<N;++i){
        scanf("%d", &col[i]);
    }
    for(int i=0;i<N;++i){
        vis[i] = 0;
    }
    dfs(0);
    printf("%d\n", (int) dp[0][1]);
    return 0;
}
