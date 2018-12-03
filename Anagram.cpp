#include<bits/stdc++.h>
using namespace std;
int anagram(string s)
{
    int sum=0;
    int n=s.length();
    if(n%2!=0)
        return -1;
    else
    {
        map<string,int>m,q;
        string s1="",s2="";
        s1=s.substr(0,(n/2));
        s2=s.substr((n/2),(n/2));
        vector<int>alpha(26,0);

        for(int i=0;i<s1.length();i++)
        {
            alpha[s1[i]-'a']++;
        }
        for(int i=0;i<s2.length();i++)
            alpha[s2[i]-'a']--;
        for(int i=0;i<26;i++)
        {
            sum+=abs(alpha[i]);
        }
    }
    return sum/2;
}
int main()
{
    int q;
    cin>>q;
    cin.ignore();
    while(q--)
    {
        string s;
        getline(cin,s);
        cout<<anagram(s)<<endl;
    }
}
