#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
        int n=s.length();
        vector<int>alpha(26,0);
        for(int i=0;i<n;i++)
            alpha[s[i]-'a']++;
        int maxf=alpha[0];
        for(int i=0;i<26;i++)
        {
            if(alpha[i]>maxf)
                maxf=alpha[i];
        }
        if(maxf<=(n/2))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
}
