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
        int n, m;
        cin>>n>>m;
        vector<int>seq(m);
        unordered_set<int>cat_set;
        for(int i=0;i<m;i++)
        {
            cin>>seq[i];
            cat_set.insert(seq[i]);
        }

        vector<int>freq(n+1,0);

        int temp = 0;
        bool valid = true;
        for(int cat:seq)
        {
            temp++;
            freq[cat]++;

            if(temp == min(n,m))
            {
                auto it = cat_set.begin();
                int check = freq[*it];
                for(it=cat_set.begin();it!=cat_set.end();++it)
                {
                    if(check!=freq[*it])
                    {
                        valid = false;
                        break;
                    }
                }
                temp=0;
            }

        }
        if(valid)   cout<<"YES\n";
        else    cout<<"NO\n";
    }
    return 0;
}

