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
        unsigned int n;
        cin>>n;
        int evenbit = n & 0xAAAAAAAA;
        int oddbit  = n & 0x55555555;
        evenbit  = evenbit>>1;
        oddbit = oddbit<<1;
        cout<<(evenbit|oddbit)<<"\n";
    }
    return 0;
}

