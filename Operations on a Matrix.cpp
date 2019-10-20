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
        int N, M, Q;
        cin>>N>>M>>Q;
        unordered_map<int,int>row_freq;
        unordered_map<int,int>col_freq;
        while(Q--)
        {
            int X, Y;
            cin>>X>>Y;
            row_freq[X]++;
            col_freq[Y]++;
        }
        ll tot_odd = 0, tot_even = 0, no_odd_row = 0, no_even_row = 0;
        //rows
        for(auto it:row_freq)
        {
            if((it.second)&1)
            {
                tot_odd += M;
                no_odd_row++;
            }
            else
            {
                tot_even += M;
                no_even_row++;
            }
        }
        //col
        ll extra = N - row_freq.size();
        for(auto it:col_freq)
        {
            if((it.second)&1)
                tot_odd += extra - no_odd_row + no_even_row;
        }
        cout<<tot_odd<<"\n";
    }
    return 0;
}
