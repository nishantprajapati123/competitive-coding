#include<bits/stdc++.h>
using namespace std;
string getXorChiper(string s)
{
    int n=s.length();
    string ans="";
    if(n==0)
        return NULL;
    else if(n==1)
        return s;
    else{
        ans=ans+s[0];
        string temp="";
        temp=temp+s[0];
        for(int i=1;i<n;i++)
        {
            string t="";
            t+=s[i];
            temp=temp^t;
            ans=ans+temp;
        }
        string ans2="";
        temp=s[n-1];
        ans2=ans2+s[n-1];
        for(int i=n-2;i>0;i--)
        {
            temp=temp^s[i];
            ans2=ans2+temp;
        }
        reverse(ans2.begin(),ans2.end());
        ans+=ans2;
        return ans;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s="";
        getline(cin,s);
        cout<<getXorChiper(s);
    }
}
