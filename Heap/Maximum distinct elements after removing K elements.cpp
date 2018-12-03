#include<bits/stdc++.h>
#define l long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        l n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        map<l,l>m;
        for(int i=0;i<n;i++)
            m[arr[i]]++;
        priority_queue<l>pq;  //max heap
        for(map<l,l>::iterator it=m.begin();it!=m.end();++it)
            pq.push(it->second);
        while(k!=0)
        {
            int top=pq.top();
            pq.pop();
            top-=1;
            if(top!=0)
                pq.push(top);
            k--;
        }
        cout<<pq.size()<<endl;
    }
    return 0;

}
