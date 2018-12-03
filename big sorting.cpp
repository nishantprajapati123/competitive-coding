#include<bits/stdc++.h>
using namespace std;
bool comp(string s1, string s2)
{
    if(s1.length()!=s2.length())
    {
        return (s1.length() < s2.length());
    }
    else{
        return s1<s2;
    }
}
int main()
{
    int n;
    string s;
    cin>>n;
    vector<string>unsorted(n);
    for(int i=0;i<n;i++)
        cin>>unsorted[i];
    sort(unsorted.begin(),unsorted.end(),comp);
    for(int i=0;i<n;i++)
        cout<<unsorted[i]<<endl;


}
