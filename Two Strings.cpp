#include<bits/stdc++.h>
using namespace std;
void twoString(string s1, string s2)
{
    int c=0;
    vector<int>alpha(26,0);
    for(int i=0;i<s1.length();i++)
    {
        if(alpha[s1[i]-'a']!=1)
            alpha[s1[i]-'a']++;
    }
    for(int i=0;i<s2.length();i++)
    {
        if(alpha[s2[i]-'a']==1)
        {
            c=1;
            break;
        }
    }
    if(c)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
int main()
{
    int p;
    cin>>p;
    cin.ignore();
    while(p--)
    {
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        twoString(s1,s2);
    }
}
