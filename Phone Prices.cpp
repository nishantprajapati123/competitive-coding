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
int prices(vector<int>P)
{
    int count = 1, n = P.size();
    bool flag = true;
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=max(0,i-5);j--)
        {
            if(P[i]>=P[j])  {flag = false; break;}
        }
        if(flag)    count++;
        flag = true;
    }
    return count;
}
int main()
{
    fastIO
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>P(n);
        for(int i=0;i<n;i++)    cin>>P[i];

        cout<<prices(P)<<"\n";
    }
    return 0;
}

