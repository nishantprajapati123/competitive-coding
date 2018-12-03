#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        set<int>sum;
        int n,m,nth;
        cin>>n>>m;
        vector<int>a(n),b(m);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        cin>>nth;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum.insert(a[i]+b[j]);
            }
        }
        set<int>::iterator it;
        int cnt=0;
        for(it=sum.begin();it!=sum.end();++it)
        {
            cnt++;
            if(cnt==nth)
                cout<<*it;
        }
    }
}
