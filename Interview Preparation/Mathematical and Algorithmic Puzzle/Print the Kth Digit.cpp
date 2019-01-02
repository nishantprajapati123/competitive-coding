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
ll power(int a, int n)
{
    if(n==0)
        return 1;
    else if(n%2==0)
        return power(a*a,n/2);
    else
        return a*power(a*a,(n-1)/2);
}
int main()
{
    fastIO
    int t;
    cin >> t;

    while(t--)
    {
        int a,b,k;
        int rem;
        cin>>a>>b>>k;
        unsigned ll num;
        num = power(a,b);
        cout<<num<<"\n";
        while(k--)
        {
            rem = num%10;
            num=num/10;
        }
        cout<<rem<<"\n";
    }
}
