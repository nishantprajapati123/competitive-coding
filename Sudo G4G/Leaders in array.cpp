#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c=0;
        cin>>n;
        vector<int>a(n);
        //int temp[101];
        //memset(temp,0,sizeof(temp));
        vector<int>temp(101,0);
        for(int i=0;i<n;i++)
            cin>>a[i];
       // int j=0;
        //int current;
        for(int i=0;i<n-1;i++)
        {
            c=0;
            for(int j=i+1;j<n;j++)
            {
                if(a[i]<a[j])
                {
                    c++;
                    break;
                }
            }
            if(!c)
            {
                if(!temp[a[i]])
                {
                    temp[a[i]]++;
                    cout<<a[i]<<" ";
                }

            }
            //if(i==n-1 && temp[a[i]]==0)
              //  cout<<a[i];
        }
        if(temp[a[n-1]]==0)
            cout<<a[n-1];
        cout<<endl;
        //cout<<a[n-1]<<endl;
    }
}
