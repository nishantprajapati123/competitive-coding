#include<bits/stdc++.h>
#define ll long long
using namespace std;
int checkString(string str1, string str2)
{
    ll n=str1.length(),m=str2.length(),i=0,j=0;
    while(i<n && j<m)
    {
        if((str1[i]==str2[j])&&(str1[i]!='n'))
        {
            i++;j++;
        }
        else if(str1[i]!=str2[j])
        {
            if(str1[i]>str2[j])
                return 1;
            else if(str1[i]<str2[j])
                return -1;
            else
                return 0;
        }
        else if(i<n-1 && j<m-1 && str1[i]==str2[j] && str1[i+1]==str2[j+1] && str1[i]=='n' && str1[i+1]=='g')
        {
            i+=2;j+=2;
        }
        else if(i<n-1 && str1[i]=='n' && str1[i+1]=='g')
        {
            if('o'>str2[j])
                return 1;
            else
                return -1;
        }
        else if(j<m-1 && str2[j]=='n' && str2[j+1]=='g')
        {
            if('o'<=str1[i])
                return 1;
            else
                return -1;
        }
        else
        {
            i++;j++;
        }

    }
    if(n>m)
        return 1;
    else if(n<m)
        return -1;
    else
        return 0;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout<<checkString(str1,str2)<<endl;
    }

}
