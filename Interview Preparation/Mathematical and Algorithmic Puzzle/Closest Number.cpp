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
        int n,m;
        cin>>n>>m;
        int i,j;
        i=j=n;
        while(true)
        {
            if(i%m==0 && j%m==0)
            {
                int x = abs(i)>=abs(j)?i:j;
                cout<<x<<"\n";
                break;
            }
            else if(i%m==0)
            {
                cout<<i<<"\n";
                break;
            }
            else if(j%m==0)
            {
                cout<<j<<"\n";
                break;
            }
            else
                i--,j++;
        }
    }
    return 0;
}
