#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,nm,nt,cont=0;
        int max_m,min_t;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        nm=(n+1)/2;
        nt=n-nm;
        cout<<nm<<" "<<nt;
        vector<int>m(nm),t(nt);
        for(int i=0;i<n;i+=2)
            m.push_back(a[i]);
        for(int i=0;i<m.size();i++)
            cout<<m[i]<<" ";
        for(int i=1;i<n;i+=2)
            t.push_back(a[i]);
        if(accumulate(t.begin(),t.end(),0)>accumulate(m.begin(),m.end(),0))
        {
            cout<<"YES";
        }
        else
        {
            while(k--)
            {
                int temp;
                max_m=max_element(m.begin(),m.end())-m.begin();
                min_t=min_element(t.begin(),t.end())-t.begin();
                temp=m[max_m];
                m[max_m]=t[min_t];
                t[min_t]=temp;
                if(accumulate(t.begin(),t.end(),0)>accumulate(m.begin(),m.end(),0))
                {
                    cout<<"YES"<<endl;
                    cont++;
                    break;
                }
                m.erase(m.begin()+max_m);
                t.erase(t.begin()+min_t);
            }
            if(cont==0)
                cout<<"NO"<<endl;

        }
    }
}
