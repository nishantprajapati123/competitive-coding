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
const int N = 5005;
vector<int>F(N);
string loveTri(int n)
{
    for(int i=1;i<=n;i++)
    {
        int a = F[i];
        int b = F[a];
        int c = F[b];

        if(i == c)
            return "YES";
    }
    return "NO";
}
int main()
{
    fastIO
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>F[i];
    cout<<loveTri(n)<<"\n";
    return 0;
}


