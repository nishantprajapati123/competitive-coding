#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,daycount=2,curr=0;
        cin>>n;
        ll nBit=1,nNibble=0,nByte=0;
        while(daycount<n)
        {
            if(daycount-curr==2)
            {
                nNibble=nBit;
                nBit=0;
                curr=daycount;
                daycount+=8;
            }
            else if(daycount-curr==8)
            {
                nByte=nNibble;
                nNibble=0;
                curr=daycount;
                daycount+=16;
            }
            else if(daycount-curr==16)
            {
                nBit=2*nByte;
                nByte=0;
                curr=daycount;
                daycount+=2;
            }
//            daycount+=2;

        }
        cout<<nBit<<" "<<nNibble<<" "<<nByte<<"\n";
    }
}


