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
    int n, m;
    cin>>n>>m;
    int t = 0;
    while(n<m)
    {
        if(!(m&1))
            m = m/2;
        else
            m++;
        t++;
    }
    cout<<(t+n-m);
    return 0;
}
