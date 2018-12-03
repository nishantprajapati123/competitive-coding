#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
void factDigitSum(ll x,int factorial[9],int i,vector<ll>&fact)
{
    if(i<0)
        cout<<"-1"<<endl;
   else if(x==0)
   {
       for(int j=fact.size()-1;j>=0;j--)
       {
           cout<<fact[j];
       }
        cout<<endl;
   }
   else
   {
       if(factorial[i]>x)
            factDigitSum(x,factorial,i-1,fact);
       else
       {
           fact.push_back(i+1);
           factDigitSum(x-factorial[i],factorial,i,fact);
       }
   }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        int factorial[]={1,2,6,24,120,720,5040,40320,362880};
        cin>>x;
        vector<ll>fact;
        factDigitSum(x,factorial,8,fact);
    }
    return 0;
}
