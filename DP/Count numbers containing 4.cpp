#include "bits/stdc++.h"
#define ll long long
using namespace std;
ll dp[2][2][20][200];
vector<ll>number;
ll funCal(bool isstart=true, bool isrestrict=false, ll pos=0, ll k=0)
{
    ll i,lmt;
    //base condition
    if(pos==number.size())
        return k;
    if(dp[isstart][isrestrict][pos][k]!=-1)
        return dp[isstart][isrestrict][pos][k];
    ll res=0; //store current value;
    lmt=isrestrict?9:number[pos];
    if(isstart)     //if starting
    {
        for(i=1;i<=lmt;i++)         // go to depth
        {

                if(i==4)
                    res+=funCal(0,isrestrict||(i<number[pos]),pos+1,k+1); //if found
                else
                    res+=funCal(0,isrestrict||(i<number[pos]),pos+1,k);

        }
    }
    else{       //not starting
            for(i=0;i<=lmt;i++)
            {
                if(i==4)
                    res+=funCal(0,isrestrict||(i<number[pos]),pos+1,k+1); //if found
                else
                    res+=funCal(0,isrestrict||(i<number[pos]),pos+1,k);
            }

    }
    if(isstart)res+=funCal(1,1,pos+1,0);//limit always 9
    return dp[isstart][isrestrict][pos][k]=res;
}
ll cal(ll a)
{
    //if(k>81) return 0;
    memset(dp,-1,sizeof(dp));
    number.clear(); //clear previous number
    while(a!=0)
    {
        number.push_back(a%10);
        a=a/10;
    }
    reverse(number.begin(),number.end());
    return funCal();
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<cal(n)<<endl;
    }
}
