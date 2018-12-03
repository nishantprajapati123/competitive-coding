#include<bits/stdc++.h>
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
    ll n;
    cin>>n;
    if(n>0)
        cout<<n;
    else
    {
        int last[2],t=2;
        ll rem,num=-1*n;
        while(t--)
        {
            last[t]=num%10;
            num=num/10;
        }
        if(last[1]>=last[0])
            cout<<((n+last[1])/10);
        else
            cout<<-1*((num*10)+last[1]);
    }
}
