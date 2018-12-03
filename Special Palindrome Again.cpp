#include<bits/stdc++.h>
using namespace std;
bool isValid(int k, int j, int n)
{
    return (k>=0 && j<n);
}
long substrCount(int n, string s)
{
    int i,j,k;
    i=0;
    long cnt=0;
    //for forward only
    while(i<n)
    {
        j=k=i;
        while(isValid(k,j,n) && s[k]==s[j])
        {
            cnt++;
            //cout<<s.substr(k,j-k+1)<<endl;
            j++;

        }
        //for both direction
        j=k=i;
        k--;j++;
        char state;
        if(isValid(k,j,n) && s[i]!=s[j])
        {
            state=s[j];
            while(isValid(k,j,n) && s[k]==s[j] && s[j]==state)
            {
                cnt++;
               // cout<<s.substr(k,j-k+1)<<endl;
                k--;
                j++;

            }
        }
            i++;
    }
    return cnt;
}
int main()
{
    int n;
    string s;
    cin>>n;
    cin.ignore();
    getline(cin,s);
    cout<<substrCount(n,s);
}
