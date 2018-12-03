#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,d,counter=0,n,num;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
       num=n;
       counter=0;
       while(num>0)
       {
           d=num%10;
           if(d!=0)
           {
               if(n%d==0)
                  counter++;
           }
           num=num/10;
       }
       cout<<counter<<endl;
    }
}
