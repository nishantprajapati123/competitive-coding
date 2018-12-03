#include<bits/stdc++.h>
using namespace std;
string isValid(string s)
{
    int n=s.length();
    vector<int>alpha(26,0);
    for(int i=0;i<n;i++)
        alpha[s[i]-'a']++;
    set<int>st;
    for(int i=0;i<26;i++)
    {
        if(alpha[i]!=0)
            st.insert(alpha[i]);
    }
    map<int,int>mp;
    for(int i=0;i<26;i++)
    {
        if(alpha[i]!=0)
            mp[alpha[i]]++;
    }
    if(st.size()==1)
        return "YES";
    else if(st.size()>2)
        return "NO";
    else
    {
        int arr[2];
        map<int,int>::iterator it;
        int j=0;
        for(it=mp.begin();it!=mp.end();++it)
        {
            arr[j]=it->second;
            j++;
        }
        if(abs(arr[0]-arr[1])==(max(arr[0],arr[1])-1))
            return "YES";
        else
            return "NO";
    }
}
int main()
{
    string s;
    getline(cin,s);
    cout<<isValid(s);
}
