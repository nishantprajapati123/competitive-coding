#include<bits/stdc++.h>
using namespace std;
int longestIncSub(int arr[], int n)
{
    int LIS[n];
    //memset(LIC,1,sizeof (LIC));
    for(int i=0;i<n;i++)
        LIS[i]=1;
    //bottom up approach
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>=arr[j])
            {
               // LIS[i]=max(LIS[i],LIS[j]+1); //recursive formula
               if(LIS[i]< LIS[j]+1)    //if current value is less than after adding element
                    LIS[i]=1+LIS[j];   //then update it
            }
        }
    }
    int ma=LIS[0];
    for(int k=0;k<n;k++)
    {
        if(LIS[k]>ma)
            ma=LIS[k];
    }

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
        cout<<longestIncSub(arr,n)<<endl;
    }
}

