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
    freopen("input.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    vector<int>height(n);
    for(int z=0;z<n;z++)    cin>>height[z];
    int i=0,j,ans_i,ans;
    ll sum=0;
    for(j=0;j<k;j++)
        sum+=height[j];
    ans = sum;
    ans_i = 0;
    for(int l = j;l<n;l++)
    {
        sum = sum+height[l]-height[i];
        i++;
        if(ans>sum)
        {
            ans = sum;
            ans_i = i;
        }
    }
    cout<<ans_i+1<<"\n";
    return 0;
}
