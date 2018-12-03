#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,e,u,v;
        vector<ll>t1[n+5],t2[n+5];
        stack<ll>s1,s2;
        cin>>n>>e;
        //first tree
        for(int i=1;i<=e;i++)
        {
            cin>>u>>v;
            t1[u].push_back(v);
        }
        //second tree
        for(int i=1;i<=e;i++)
        {
            cin>>u>>v;
            t2[u].push_back(v);
        }
        s1.push(1);
        s2.push(1);
        int mirror=1;
        while(!s1.empty() && !s2.empty())
        {
            int top1=s1.top(); s1.pop();
            int top2=s2.top(); s2.pop();
            if(top1!=top2)
            {
                cout<<"0"<<endl;
                mirror=0;
                break;
            }
          //  vector<ll int>::iterator it;
           // vector<ll int>::reverse_iterator itr;
         /*   for(it=t1[top1].begin();it!=t1[top1].end();++it) //push all child of current node from beginning to end of t1
                s1.push(*it);
            for(itr=t2[top2].rbegin();itr!=t2[top2].rend();--itr)  //push all child of current node from end to beginning of t2
                s2.push(*itr);*/
            for(ll i=0;i<t1[top1].size();i++)
                       s1.push(t1[top1][i]);

				for(ll i=t2[top2].size()-1;i>=0;i--)
                       s2.push(t2[top2][i]);


        }
        if(mirror)
            cout<<"1"<<endl;
    }
    return 0;
}
