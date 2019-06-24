#include<bits/stdc++.h>
using namespace std;
bool rotation(string s1, string s2)
{
    s2 = s2+s2;
    string s3;
    int n = s1.length();
    for(int i=0;i<=n;i++)
    {
        s3 = s2.substr(i,n);
        if(s1.compare(s3)==0)
            return true;
    }
    return false;
}
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    bool ans = rotation(s1,s2);
    if(ans) cout<<"Strings are rotations of each other\n";
    else    cout<<"Strings are not rotations of each other\n";
    return 0;
}
