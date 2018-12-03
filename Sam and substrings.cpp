#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
    string s="";
    getline(cin,s);
    int n=s.length();
    long long int sum=0;
    long long m=1;
    for(int i=n-1;i>=0;i--)
    {
        sum+=(s[i]-'0')*(i+1)*m;
        m=(m*10 +1)%mod;
    }
    cout<<sum;
}
