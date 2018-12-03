#include<bits/stdc++.h>
using namespace std;
int marsExploration(string s)
{
    int alter=0,k=0;
    string signal="SOS";
    if(s.length()%3==0)
    {
       // cout<<signal.length();

         for(int i=0;i<s.length();i++)
         {
             if(s[i]!=signal[k++]) alter++;

             if(k>=signal.length()) k=0;
         }

     }
     return alter;
}
int main()
{
    string s;
    getline(cin,s);
    cout<<marsExploration(s);
}

