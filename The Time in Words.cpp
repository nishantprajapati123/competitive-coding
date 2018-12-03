#include<bits/stdc++.h>
#define add(a,b) insert(pair<int,string>(a,b))
using namespace std;
unordered_map<int,string>mp;

int main()
{
    mp.add(1,"one");
mp.add(2,"two");
mp.add(3,"three");
mp.add(4,"four");
mp.add(5,"five");
mp.add(6,"six");
mp.add(7,"seven");
mp.add(8,"eight");
mp.add(9,"nine");
mp.add(10,"ten");
mp.add(11,"eleven");
mp.add(12,"twelve");
mp.add(13,"thirteen");
mp.add(15,"quarter");
mp.add(20,"twenty");
mp.add(30,"thirty");
mp.add(40,"forty");
mp.add(50,"fifty");

    int h,m;
    cin>>h>>m;
    if(m==0)
        cout<<mp[h]<<" o' clock";
    else if(m>=1 &&  m<=30)
    {
        if(m>=1 && m<=10)
        {
            if(m%10==1)
                cout<<mp[m%10]<<" minute past "<<mp[h];
            else if(m%10==0)
                cout<<mp[10]<<" minutes past "<<mp[h];
            else
                cout<<mp[m%10]<<" minutes past "<<mp[h];
        }
        else if(m>=11 && m<=20)
        {
            if(m%20==0)
                cout<<mp[20]<<" minutes past "<<mp[h];
            else if(m%20==15)
                cout<<mp[15]<<" past "<<mp[h];
            else if(mp.find(m%20)!=mp.end())
                cout<<mp[m%20]<<" minutes past "<<mp[h];
            else if(m%20==18)
                cout<<mp[m%10]<<"een minutes past "<<mp[h];
            else
                cout<<mp[m%10]<<"teen minutes past "<<mp[h];
        }
        else
        {
            if(m%30==0)
                cout<<"half past "<<mp[h];
            else
                cout<<"twenty "<<mp[m%10]<<" minutes past "<<mp[h];
        }
    }
    else
    {
        int sub=60-m;
        if(h+1>12)
            h=1;
        else
            h=h+1;
        if(sub>=1 && sub<=10)
        {
            if(sub%10==1)
                cout<<mp[sub%10]<<" minute to "<<mp[h];
            else if(sub%10==0)
                cout<<mp[10]<<" minutes to "<<mp[h];
            else
                cout<<mp[sub%10]<<" minutes to "<<mp[h];
        }
        else if(sub>=11 && sub<=20)
        {
            if(sub%20==0)
                cout<<mp[20]<<" minutes to "<<mp[h];
            else if(sub%20==15)
                cout<<mp[15]<<" to "<<mp[h];
            else if(mp.find(sub%20)!=mp.end())
                cout<<mp[sub%20]<<" minutes to "<<mp[h];
            else if(sub%20==18)
                cout<<mp[sub%10]<<"een minutes past "<<mp[h];
            else
                cout<<mp[sub%10]<<"teen minutes to "<<mp[h];
        }
        else
        {
            cout<<"twenty "<<mp[sub%10]<<" minutes to "<<mp[h];
        }
    }
}
