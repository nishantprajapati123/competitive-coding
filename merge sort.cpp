#include<bits/stdc++.h>
using namespace std;
void mergeArray(int arr[], int l, int mid, int h)
{
    int i,j,k;
    //number of element into sub array
    int n1=mid-l+1;
    int n2=h-mid;
    //temporary array
    int t1[n1],t2[n2];
    //copy the content
    for(i=0;i<n1;i++)
        t1[i]=arr[l+i];
    for(j=0;j<n2;j++)
        t2[j]=arr[mid+1+j];
    //merge two array into arr
    i=0;//index of left sub array
    j=0;//index of right sub array
    k=l;//index of merged sub array
    while(i<n1 && j<n2)
    {
        if(t1[i]<=t2[j])
        {
            arr[k]=t1[i];
            i++;
        }
        else
        {
            arr[k]=t2[j];
            j++;
        }
        k++;
    }
    //copy remaining of left
    while(i<n1)
    {
        arr[k]=t1[i];
        i++;
        k++;
    }
    //copy remaining of left
    while(j<n2)
    {
        arr[k]=t2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int h)
{
    if(l<h)
    {
        //mid
        int mid=(l+h)/2;
        //divide left
        mergeSort(arr,l,mid);
        //divide right
        mergeSort(arr,mid+1,h);
        //merge two sorted array into arr[]
        mergeArray(arr,l,mid,h);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
