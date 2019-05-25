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
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>villian(n),player(n);
        for(int i=0;i<n;i++)    cin>>villian[i];
        for(int j=0;j<n;j++)    cin>>player[j];
        sort(villian.begin(),villian.end());
        sort(player.begin(),player.end());
        bool found = true;
        for(int i=0;i<n;i++)
        {
            if(villian[i]>=player[i])
            {
                found = false;
                break;
            }
        }
        if(found)
            cout<<"WIN\n";
        else
            cout<<"LOSE\n";
    }
    return 0;
}

