//Input starts with an integer T (≤ 200), denoting the number of test cases.
//Each case contains three positive integers A, B and K (1 ≤ A ≤ B < 231 and 0 < K < 10000).
//For each case, output the case number and the number of integers in the range [A, B] which are divisible by K and the sum of its digits is also divisible by K.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2][2][10][81][81];
ll k;
vector<ll>number;
ll funCal(bool isstart=true, bool isrestrict=false, ll pos=0, ll digitsum=0, ll num=0)
{
    ll i,lmt;
    if(pos==number.size())      //if exceed from given length of no. then check for condition
    {                           //if condition true return value
       return  digitsum%k==0 && num%k==0;
    }
    if(dp[isstart][isrestrict][pos][digitsum][num]!=-1)
        return dp[isstart][isrestrict][pos][digitsum][num];
    ll res=0; //store current value of any state;
    lmt=isrestrict?9:number[pos]; //starting limit
    if(isstart)     //if starting
    {
        for(i=1;i<=lmt;i++)         // go to depth
        {
                //isrestrict= (i<number[pos])?1:0;// new limit by current[pos]<number[pos] then new limit is 9
                res+=funCal(0,isrestrict||(i<number[pos]),pos+1,digitsum+i,(num*10 +i)%k);

        }
    }
    else{       //not starting
            for(i=0;i<=lmt;i++)
            {
                //isrestrict= (i<number[pos])?1:0;
                res+=funCal(0,isrestrict||(i<number[pos]),pos+1,digitsum+i,(num*10 +i)%k);
            }

    }
    //calling the next position as (isStart=1) stating
    //position and it will find the 2 digit numbers after
    //3 digit numbers and so on. Sending isrestrict=1 as we know
    //if the number of digits decrease it’s certain that
    //thenumber will be less than the targeted number(n)
    if(isstart)res+=funCal(1,1,pos+1,0,0);//limit always 9
    return dp[isstart][isrestrict][pos][digitsum][num]=res;

}
ll cal(ll a)
{
    if(k>81) return 0;
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
        ll a,b,x,y;
        cin>>a>>b>>k;
        x=cal(a-1);
        y=cal(b);
        cout<<y-x<<endl;
    }
}
