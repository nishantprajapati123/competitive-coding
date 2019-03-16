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
        int n;
        cin>>n;
        cin.ignore();
        vector<int>alpha(26,0);
        for(int j=0;j<n;j++)
        {
            vector<int>freq(26,0);
            string s;
            getline(cin,s);
            for(int i=0;i<s.length();i++)
            {
                if(freq[s[i]-'a']==0)
                    freq[s[i]-'a']++,alpha[s[i]-'a']++;
            }
        }
        int cnt = 0;
        for(int i:alpha)
            if(i==n) cnt++;
        cout<<cnt<<"\n";
    }
    return 0;
}
