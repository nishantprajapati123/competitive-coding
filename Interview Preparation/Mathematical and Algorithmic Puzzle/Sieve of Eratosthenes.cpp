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
    cin >> t;

    while(t--)
    {
        int N;
        cin>>N;
        bool isPrime[N+1];
        for(int i = 0; i <= N;i++)
            isPrime[i] = true;

        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i <= N; ++i) {
             if(isPrime[i] == true) {
                 for(int j = i * i; j <= N ;j += i)
                     isPrime[j] = false;
            }
        }
        for(int i=2;i<=N;i++)
        {
            if(isPrime[i]==true)
                cout<<i<<" ";
        }
        cout<<"\n";

    }
    return 0;
}
