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
    int n,k;
    cin>>n>>k;
    int time = 0,i = 0;
    while((time+(5*i)+k <= 240) && i<=n)
    {
        time+=5*i;
        i++;
    }
//    cout<<i<<endl;
    if(i>n) cout<<n;
    else cout<<i-1;
    return 0;
}
