#include<bits/stdc++.h>
using namespace std;
string panagram(string s)
{
    vector<int>alpha(26,0);
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ')
            continue;
        if(isupper(s[i]))
           s[i]= tolower(s[i]);
        alpha[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(alpha[i]==0)
            return "not pangram";
    }
    return "pangram";
}
int main()
{
    string s;
    getline(cin,s);
    cout<<panagram(s);
}
