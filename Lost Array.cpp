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
    int n;
    cin>>n;
    vector<ll>a(n+1,0);
    vector<ll>x(n+1);
    for(int i=0;i<n;i++)
        cin>>a[i];
    bool false;
    for(int k=1;k<=n;k++)
    {
        for(int i=0;i<n;i++)
        {
            int idx=j%k;
            int j=i;
            int x[j%k]=a[j+1]-a[j];
            while(j+k<n)
            {
                int prev=x[j%k];
                j+=k;
                idx=(j%k);
                if(prev!=x[j%k])
                   {ex=true; break;}
            }
            if(ex)
                x.clear(),break;
        }

    }
}
