//c[n][k]=c[n-1][k-1]+c[n-1][k]
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    long long int c[n+1][k+1];
    //bottom up manner
    for(int i=0;i<=n;i++)      //loop for n
    {
        for(int j=0;j<=min(i,k);j++)    //min because we don't calculate for value greater than k
        {
            if(j==0 || j==i)    //base condition
                c[i][j]=1;
            else
                c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    cout<<c[n][k];
}
