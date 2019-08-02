#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    cin.ignore();
    vector<string>words(n);
    string pattern;
    for(int i=0;i<n;i++)
    {
        string x;
        getline(cin,x);
        words[i] = x;
    }
    getline(cin,pattern);
    int pattern_len = pattern.length();
    for(auto str:words)
    {
        if(pattern_len != str.length()) continue;
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        bool match = true;
        for(int i=0;i<str.length();i++)
        {
            if(mp1.find(pattern[i]) == mp1.end())
                mp1.insert(make_pair(pattern[i],str[i]));
            if(mp2.find(str[i]) == mp2.end())
                mp2.insert(make_pair(str[i],pattern[i]));
            if(mp1.find(pattern[i]) != mp1.end() || mp2.find(str[i]) != mp2.end())
            {
                if(mp1[pattern[i]] != str[i] || mp2[str[i]] != pattern[i])
                {
                    match = false;
                    break;
                }
            }
        }
        if(match)
            cout<<str<<" ";
    }
//    for(auto x:words) cout<<x<<" ";
}
