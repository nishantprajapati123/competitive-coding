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
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
        vector<int>freq(26,0);
        for(char ch:s)  freq[ch-'a']++;
        int no_odd=0,cnt=0;
        for(int x:freq)
        {
            if(x)   cnt++;
            if(x&1) no_odd++;
        }
        if(no_odd==0 || no_odd>3)   cout<<"!DPS\n";
        else if(no_odd == 1 && cnt<26)  cout<<"DPS\n";
        else if(no_odd == 2)    cout<<"DPS\n";
        else if(no_odd == 3)    cout<<"DPS\n";
        else cout<<"!DPS\n";
    }
    return 0;
}
