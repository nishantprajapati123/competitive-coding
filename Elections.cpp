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
    int n;
    cin>>n;
    vector<int>a(n);
    int elo=0,awr=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        elo+=a[i];
    }
    int k=*max_element(all(a));
    while(1)
    {
        awr=0;
        for(int i=0;i<n;i++)
            awr+=k-a[i];
        if(awr>elo)
            break;
        else
            k++;
    }
    cout<<k<<"\n";
    return 0;
}

