#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    vector<string> str(n);
    int no;
    for(int i=0;i<(n/2);i++)
    {
        cin>>no;
        string s;
        cin>>s;
        str[no]=str[no]+"-"+" ";
    }
    for(int i=n/2;i<n;i++)
    {
        cin>>no;
        string s;
        cin>>s;
        str[no]=str[no]+s+" ";
    }
    for(int i=0;i<n;i++)
    {
        cout<<str[i];
    }
}
