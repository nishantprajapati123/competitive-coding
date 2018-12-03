#include<bits/stdc++.h>
#define add(a,b) insert(pair<string,int>(a,b))
using namespace std;
string checkMagazine(vector<string>magazine, vector<string>note,int m, int n)
{
    map<string,int>trace;
    for(int i=0;i<m;i++)
    {
        trace[magazine[i]]++;
    }
     //map<string,int>::iterator it;
   // for(it=trace.begin();it!=trace.end();++it)
       // cout<<it->first<<" "<<it->second<<endl;
    for(int i=0;i<n;i++)
    {
        if(trace[note[i]]==0)
            return "NO";
        else
            trace[note[i]]--;
    }
    return "YES";
}
int main()
{
    int n,m;
    cin>>m>>n;
    cin.ignore();
    vector<string>magazine(m),note(n);
    for(int i=0;i<m;i++)
    {
        string s="";
        cin>>s;
        magazine[i]=s;
    }
    for(int i=0;i<n;i++)
    {
        string s="";
        cin>>s;
        note[i]=s;
    }
    cout<<checkMagazine(magazine,note,m,n);
}
