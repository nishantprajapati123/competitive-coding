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
    cin>>t;
    while(t--)
    {
        int n;
        ll q;
        cin>>n>>q;
        vector<ll>B(n-1);
        for(int i=0;i<n-1;i++)
            cin>>B[i];

        unordered_map<int,pair<int,int> >mp;
        while(q--)
        {
            int p,q;
            cin>>p>>q;

            int sign1;
            int sign2;
            ll sum1= 0;
            ll sum2 = 0,j = 1;
            if(mp.find(p-1)!=mp.end())
            {
                sum1 = mp[p-1].first;
                sign1 = mp[p-1].second;
            }
            else
            {
                for(int i = p-1;i<B.size();i++)
                {
                    sum1 += j*B[i];
                    j = -j;
                }
                sign1 = pow(-1,n-p);
                mp[p-1] = mk(sum1,sign1);
            }
            j = 1;
            if(mp.find(q-1)!=mp.end())
            {
                sum2 = mp[q-1].first;
                sign2 = mp[q-1].second;
            }
            else
            {
                for(int i = q-1;i<B.size();i++)
                {
                    sum2 += j*B[i];
                    j = -j;
                }
                sign2 = pow(-1,n-q);
                mp[q-1] = mk(sum2,sign2);
            }
            if(sign1 == sign2)
                cout<<"UNKNOWN\n";
            else
                cout<<sum1+sum2<<"\n";
        }

    }
    return 0;
}
