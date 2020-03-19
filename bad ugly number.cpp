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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n == 1)
            cout<<"-1\n";
        else{
            string s = "2";
            for(int i=2;i<=n;i++)
                s += "3";

            cout<<s<<"\n";
        }
    }
    return 0;
}
