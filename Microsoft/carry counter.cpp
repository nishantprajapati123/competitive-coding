#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a="",b="",c="";
        cin>>a>>b;
        reverse(a.begin(),a.end()); //reverse string a
        reverse(b.begin(),b.end()); //reverse string b
        ll carry=0,cntcarry=0,i=0,j=0,r;
        while(i<a.length() && j<b.length())
        {
            //carry=0;
            int temp=int(a[i]-'0')+int(b[j]-'0')+carry;
            if(temp>=10)
            {
                cntcarry++;
                carry=1;
                r=temp-10;
            }
            else
            {
                carry=0;
                r=temp;
            }
            c+=char(r+'0');
            i++;j++;
        }
        //cout<<cntcarry<<endl;
        while(i<a.length())
        {
            int temp=int(a[i]-'0')+carry;
            if(temp>=10)
            {
                cntcarry++;
                carry=1;
                r=temp-10;
            }
            else
            {
                carry=0;
                r=temp;
            }
            c+=char(r+'0');
            i++;
        }
        while(j<b.length())
        {
            int temp=int(b[j]-'0')+carry;
            if(temp>=10)
            {
                cntcarry++;
                carry=1;
                r=temp-10;
            }
            else
            {
                carry=0;
                r=temp;
            }
            c+=char(r+'0');
            j++;
        }
        reverse(c.begin(),c.end());
        cout<<cntcarry<<endl;

    }
}

