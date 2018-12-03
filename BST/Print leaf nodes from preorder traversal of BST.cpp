#include<bits/stdc++.h>
using namespace std;
void printLeafNode(vector<int>arr, int low, int high)
{
    if(arr.size()==0 || low>high)
        return ;
    if(low==high || low==high-1)
    {
        cout<<arr[high]<<" ";
        return ;
    }
    else
    {
        //find max index for sub array;
        int j=low+1;
        while(j<=high && arr[j]<arr[low])
            j++;
        printLeafNode(arr,low+1,j-1);
        printLeafNode(arr,j,high);
    }
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
        printLeafNode(arr,0,n-1);
        cout<<endl;
    }
}
