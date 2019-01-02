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
    cin.ignore();
    while(t--)
    {
        string b;
        getline(cin,b);
        unsigned long decimal = bitset<8>(b).to_ulong();
        cout<<decimal<<"\n";
    }
    return 0;
}

