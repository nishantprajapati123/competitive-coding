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
//vector<int>index;
string s,t;

int main()
{
    fastIO
    freopen("input.txt","r",stdin);
    getline(cin,s);
    getline(cin,t);
    unordered_map<char,int>mp_t;
    unordered_map<char,int>window;
    for(char ch:t)  mp_t[ch]++;
    int i=0,j=0;
    int required = mp_t.size();
    int formed = 0;
    int ans_i,ans_j,ans = INT_MAX;
//    cout<<s.length();
    while(j<s.length())
    {
        window[s[j]]++;
        if(mp_t.find(s[j])!=mp_t.end() && mp_t[s[j]] == window[s[j]])
        {
            formed++;
//            cout<<s[j]<<" "<<mp_t[s[j]]<<endl;
        }

        //contracting
        while(i<=j && formed == required)
        {
            if(j-i+1 <= ans)
            {
                ans = j-i+1;
                ans_i = i;
                ans_j = j;
            }

            window[s[i]]--;
            if(mp_t.find(s[i])!=mp_t.end() && window[s[i]]<mp_t[s[i]])
                formed--;

            i++;
        }
        j++;
//        cout<<formed<<endl;
    }
//    cout<<ans_i<<" "<<ans_j;
//
    if(ans==INT_MAX) cout<<"";
    else    cout<<s.substr(ans_i,ans_j-ans_i+1);
}
