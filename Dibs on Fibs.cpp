#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j,m,n;
        unsigned long long int M=1000000007;
        unsigned long long int result=0;
        cin>>m>>n;
        vector<long long int>a(m);
        vector<long long int>b(m);
        for(i=0;i<m;i++)
            cin>>a[i];
        for(j=0;j<m;j++)
            cin>>b[j];
        i=0;
        for(j=0;j<m;j++)
        {
            vector<long long int>fib(max(2,n));
            fib[0]=a[i];
            fib[1]=b[j];
            for(int k=2;k<n;k++)
                fib[k]=fib[k-1]+fib[k-2];
            result=((result%M)+(fib[n-1]%M))%M;
            if(j==m-1)
            {
                i++;
                j=-1;
            }
            if(i==m)
                break;
        }
       cout<<result<<endl;
    }
}
