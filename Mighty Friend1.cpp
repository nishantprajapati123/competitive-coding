#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,k,nm,nt,temp;
       cin>>n>>k;
       vector<int>a(n);
       vector<int>m,t;
       for(int i=0;i<n;i++)
            cin>>a[i];
       for(int i=0;i<n;i+=2)
          m.push_back(a[i]);
       for(int i=1;i<n;i+=2)
          t.push_back(a[i]);
       sort(m.begin(),m.end(),greater<int>());
       sort(t.begin(),t.end());
       int cont=0;
       for(int i=1;i<=k;i++)
       {
           if(cont>m.size() || cont>t.size())
           {
               break;
           }
           else{
            if(m[cont]>t[cont])
            {
                temp=m[cont];
                m[cont]=t[cont];
                t[cont]=temp;
            }
           }
           cont++;
       }
       if(accumulate(t.begin(),t.end(),0) > accumulate(m.begin(),m.end(),0))
           cout<<"YES"<<endl;
       else
           cout<<"NO"<<endl;
    }
}
