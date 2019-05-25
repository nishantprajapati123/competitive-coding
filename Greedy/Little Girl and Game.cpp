
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
    string s;
    getline(cin,s);
    vector<int>freq(26,0);
    for(char ch:s)
        freq[ch-'a']++;
//    for(int i:freq)
//        cout<<i<<" ";
    int odd=0;
    for(int x:freq)
    {
        if(x&1) odd++;
    }
    if(odd==0 || odd==1)    cout<<"First\n";
    else
    {
        bool first=false,second=true;
        while(odd>1)
        {
            first = !first;
            second = !second;
            for(int i=0;i<26;i++)
            {
                if(freq[i]&1)
                {
                    freq[i]--;
                    break;
                }
            }
            odd=0;
            for(int x:freq)
            {
                if(x&1) odd++;
            }
        }
        if(first)   cout<<"Second\n";
        else    cout<<"First\n";
    }
    return 0;
}
