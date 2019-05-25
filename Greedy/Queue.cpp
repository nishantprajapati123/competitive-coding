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
    vector<ll>time(n);
    for(int i=0;i<n;i++)    cin>>time[i];
    sort(time.begin(),time.end());
    vector<ll>::iterator low;
    low = time.begin();
    ll t_time = time[0],not_diss = 1;
    time.erase(low);
    while(1)
    {
        low = lower_bound(time.begin(),time.end(),t_time);

        if(low==time.end()) break;
        //cout<<low-time.begin()<<" ";
        t_time+=time[low-time.begin()];
        not_diss++;
        time.erase(low);
    }
    //cout<<endl;
    cout<<not_diss<<"\n";
    return 0;
}
