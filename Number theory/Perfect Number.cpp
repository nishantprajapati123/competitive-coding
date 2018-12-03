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
    int k;
    cin>>k;
    int small=19;
    while(k)
    {
        int n=0;
        int j=small;
        while(j)
        {
            n+=j%10;
            j/=10;
        }
        if(n==10)
            k--;
        small++;
    }
    cout<<small-1;
}
