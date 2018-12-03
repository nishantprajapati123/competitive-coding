#include<bits/stdc++.h>
using namespace std;
void palindrome(string s)
{
    string res="";
    for(int i=0;i<s.length();i++)
    {
        if(isalpha(s[i]))
        {
            if(isupper(s[i]))
                res.push_back(tolower(s[i]));
            else
                res.push_back(s[i]);

        }
        else if(isdigit(s[i]))
            res.push_back(s[i]);

    }
    string rev=res;
    reverse(rev.begin(),rev.end());
    if(!res.compare(rev))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s="";
        cin.ignore();
        getline(cin,s);
        palindrome(s);
    }
}
