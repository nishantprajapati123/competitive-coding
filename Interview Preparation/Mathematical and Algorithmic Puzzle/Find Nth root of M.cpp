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
ll binaryExponentiation(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2.0);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2.0);
}
int main()
{
    fastIO
    int t;
    cin>>t;
    while(t--)
    {
       // ll n,m;
       // cin>>n>>m;
//        float x = pow(m,1.0/n);
//        if(floor(x) == ceil(x))
//            cout<<int(x)<<"\n";
//        else
//            cout<<"-1"<<"\n";
        cout<<binaryExponentiation(4,4);
    }

}
