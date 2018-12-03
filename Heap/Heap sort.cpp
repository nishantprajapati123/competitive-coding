#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n, int i)
{
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest=r;
    //if root is not largest then swap
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        //push that element in bottom by calling it recursively for left/right subtree
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n)
{
    //create max heap bottom to top
    //start with first non-leaf index
    for(int i=(n/2)-1;i>=0;i--)
        heapify(arr,n,i);
    //after heapify root is max
    //replace root with last element and reduce size by 1
    //call heapify again for root
    for(int i=n-1;i>=0;i--)
    {
        //swap 1st with last and reduce size by 1 (i--)
        swap(arr[0],arr[i]);
        //call heapify for root in reduced tree
        heapify(arr,i,0);
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    heapSort(arr,n);
}
