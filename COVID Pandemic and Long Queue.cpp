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
        int n;
        cin>>n;
        vector<int>A(n);
        int x;
        bool valid = true;
        int prev = -1, next = -1;

        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            if(A[i] && prev == -1)
                prev = i;
        }

        for(int i=0;i<n;i++)
        {
            if(i == prev) continue;
            if(A[i])
                next = i;

            if(next != -1)
            {
                if(next - prev < 6)
                {
                    valid = false;
                    break;
                }
                prev = next;
                next = -1;
            }
        }
        if(valid)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

