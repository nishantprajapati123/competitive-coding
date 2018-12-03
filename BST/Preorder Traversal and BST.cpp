#include<bits/stdc++.h>
using namespace std;
bool ispreorder(vector<int>arr, int n, int &i, int min_, int max_)
{
    if(i==n)
        return true;
    if(arr[i]>min_ && arr[i]<max_)
    {
        i++;
        return ispreorder(arr,n,i,min_,arr[i-1]) ||
               ispreorder(arr,n,i,arr[i-1],max_);
    }
    else
        return false;
}
bool preorder(vector<int>arr, int n)
{
    int i=0;
    return ispreorder(arr,n,i,INT_MIN,INT_MAX);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        if(preorder(arr,n))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
}
