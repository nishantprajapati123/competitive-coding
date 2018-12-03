#include<bits/stdc++.h>
using namespace std;

vector<int> partiton(vector<int> arr, int n)
{
    int p=arr[0];
    int pi=n-1,i;
    for(i=n-1;i>=1;i--)
    {
        if(arr[i]>=p)
        {
            swap(arr[i],arr[pi]);
            pi-=1;
        }


    }
    swap(arr[pi],arr[0]);
    return arr;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> result=partiton(arr,n);
    for(int cont=0;cont<n;cont++)
        cout<<result[cont]<<" ";
    return 0;
}

