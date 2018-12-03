#include<bits/stdc++.h>
#define ll long long
//#define add(a,b) insert(pair<long long,int>(a,b))
using namespace std;
int main()
{
    ll q;
    int Q;
    map<ll,ll>m;
    map<ll,ll>::iterator it;
    vector<int>store;
    cin>>q;
    while(q--)
    {
        cin>>Q;
        if(Q==1)    //query 1
        {
            ll x;
            cin>>x;
            //if(m[x]==0) //if no such element present then add it to map with value 1
               m[x]++;// m.insert(pair<ll,int>(x,1));
           // else        //else increment its value
                //m[x]++;
        }
        else if(Q==2)   //query 2
        {
            ll y;
            cin>>y;
            if(m[y]!=0) //if occur of y found 1 or more decrement its value by 1
                m[y]--;

        }
        else
        {
            ll z;
            cin>>z;
            int c=0;
            for(it=m.begin();it!=m.end();++it)
            {
               // cout<<it->second<<endl;
                if(it->second == z)
                {

                    store.push_back(1);
                    c++;
                    break;
                }
            }
            if(c==0)
                store.push_back(0);
        }
    }
    for(int i=0;i<store.size();i++)
        cout<<store[i]<<endl;
}

