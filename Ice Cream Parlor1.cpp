#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n,i,j,k=0;
        cin>>m;
        cin>>n;
        vector<int>arr(n);
        for(i=0;i<n;i++)
            cin>>arr[i];
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if((m-arr[i])==arr[j])
                {
                    k++;
                    break;
                }

            }
            if(k>0) break;

        }
        if(i<j)
            cout<<i+1<<" "<<j+1<<endl;
        else
            cout<<j+1<<" "<<i+1<<endl;
    }
}
