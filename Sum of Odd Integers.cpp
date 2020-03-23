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

string solve(int n, int k)
{
    if((n%2!=0) && (k==1))
        return "YES\n";

    else if(k == sqrt(n))
        return "YES\n";

    else if(n > 2 && n%2==0 && k == 2)
        return "YES\n";

    else if(n <= k)
        return "NO\n";



    else if(((n%2==0 && k%2==0) || (n%2!=0 && k%2!=0)) && (sqrt(n) > k))
        return "YES\n";

    else
        return "NO\n";

}
int main()
{
    fastIO
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;

        cout<<solve(n,k);

    }
    return 0;
}

