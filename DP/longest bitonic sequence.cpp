
#include<bits/stdc++.h>
using namespace std;
int longestBitSub(int arr[], int n)
{
    int LIS[n];
    int LDS[n];
    for(int i=0;i<n;i++)
    {
        LIS[i]=1;
        LDS[i]=1;
    }
    //bottom up approach for lis  left to right
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
               // LIS[i]=max(LIS[i],LIS[j]+1); //recursive formula
               if(LIS[i]< LIS[j]+1)    //if current value is less than after adding element
                    LIS[i]=1+LIS[j];   //then update it
            }
        }
    }
    //bottom up approach for lds right to left
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j])
            {
                if(LDS[i]<LDS[j]+1)
                    LDS[i]=LDS[j]+1;
            }
        }
    }
    int ma=LIS[0]+LDS[0]-1;
    for(int k=0;k<n;k++)
    {
        if(LIS[k]+LDS[k]-1>ma)
            ma=LIS[k]+LDS[k]-1;
    }
    /*for(int i=0;i<n;i++)
    {
        cout<<LIS[i]<<"\t"<<LDS[i]<<endl;
    }
    cout<<endl;*/

    return ma;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<longestBitSub(arr,n)<<endl;
    }
}

