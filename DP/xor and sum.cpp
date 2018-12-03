#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long getSum(long a, long b)
{
    long sum;
    long pow2;
    //cout<<"ok";
    //base case for power of 2;
    pow2=1;
//    for(int i=1;i<314160;i++)
//        pow2[i]=2*(pow2[i-1]%mod);
    //base case for sum;
    sum=a^(b*pow2);
    for(int i=1;i<314160;i++)
    {
        pow2=((2%mod)*(pow2%mod))%mod;
        sum=sum+(a^(b*pow2))%mod;

    }
    //for(int i=0;i<3;i++)
      //  cout<<sum[i]<<" ";
    //cout<<endl;
   // return sum[314159];
   return sum;
}
int main()
{
    int a=2,b=10;
//    cin>>a>>b;
    cout<<getSum(a,b);

}
