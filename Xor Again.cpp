#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,result;
        cin>>n;
        vector<int>a(n),b(n*n);
        for(long int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                b[(i*n)+j]=a[i]+a[j];

        }

        result=b[0];
        for(int i=1;i<n*n;i++)
        {
            result=result^b[i];
        }
        cout<<result<<endl;

    }

}
