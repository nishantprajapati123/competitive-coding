#include<bits/stdc++.h>
#define add(a,b) insert(pair<char,char>(a,b))
using namespace std;
int main()
{
    map<char,char>mapp;
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
        int j=122;
        for(int i=97;i<=122;i++)
        {
            mapp.add(char(i),char(j));
            j--;
        }
        j=90;
        for(int i=65;i<=90;i++)
        {
            mapp.add(char(i),char(j));
            j--;
        }
        string res="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
                res+=" ";
            else
                res+=mapp[s[i]];
        }
        cout<<res<<endl;;
       /* map<char,char>::iterator it;
        for(it=mapp.begin();it!=mapp.end();++it)
            cout<<it->first<<"\t"<<it->second<<endl; */
    }
}
