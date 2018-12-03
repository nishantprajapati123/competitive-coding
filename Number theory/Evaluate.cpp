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
ll k,l,d;
ll power(ll a, ll n, ll m)
{
    if(n==0)
        return 1;
    else if(n%2==0)
        return power((a*a)%m,n/2,m);
    else
        return (a*power((a*a)%m,(n-1)/2,m))%m;
}
void EEA(ll A, ll B)
{
    if(B==0){
        d=A,k=1,l=0;
    }
    else
    {
        EEA(B,A%B);
        ll temp=k;
        k=l;
        l=temp-((A/B)*l);
    }
}
ll modInverse(ll A, ll M)
{
    EEA(A,M);
    return (k%M+M)%M;
}
int main()
{
    fastIO
    ll A,B,C,M;
    cin>>A>>B>>C>>M;
//    ll A,B,C,M;
//    cin>>A,B,C,M;
    ll X=power(A,B,M);
    ll Y=modInverse(C,M);
//    cout<<k;
    cout<<((X%M)*(Y%M))%M;

    return 0;
}

