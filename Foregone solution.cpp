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
void digit4(int k, ll mid1, ll mid2)
{
    ll place=1,num1=0,num2=0;
    while(mid1>0 && mid2>0)
    {
        ll rem1,rem2;
        rem1=mid1%10;
        rem2=mid2%10;
        while(rem1==4 || rem2==4)
        {
            rem1++,rem2--;
        }
        mid1=mid1/10;
        mid2=mid2/10;
        num1+=(rem1*place);
        num2+=(rem2*place);
        place*=10;
    }
    cout<<"Case #"<<k<<": "<<num1<<" "<<num2<<"\n";
}
int main()
{
    fastIO
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        ll n;
        cin>>n;
        ll mid1,mid2;
        if(n%2==0)
            mid1=mid2=n/2;
        else
        {
             mid1=n/2;
             mid2=mid1+1;
        }
        digit4(k,mid1,mid2);
    }
}
