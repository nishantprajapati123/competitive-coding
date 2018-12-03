#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[],int n)
{
    int sum[n];
    //base condition
    sum[0]=arr[0];
    //bottom up approach
    for(int i=1;i<n;i++)
    {
        sum[i]=max(sum[i-1]+arr[i],arr[i]);     //add ith element with (i-1)th if less than ith then start new window

    }
    int m=sum[0];
    for(int i=0;i<n;i++)
    {
        if(sum[i]>m)
            m=sum[i];
    }
    return m;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<maxSubarraySum(arr,n);
}
