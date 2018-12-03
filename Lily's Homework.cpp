#include<bits/stdc++.h>
using namespace std;
long int lilly(long long int arr[],vector<long long int>arr1,long int n)
{
    long int swp=0,k;
    map<int,int> test;
    int ind=0;
    while(n>0)
    {
    test.insert(pair<int,int>(arr[ind],ind));
    ind++;
    n--;
    }
    for(int i=0;i<arr1.size();i++)
    {
        if(arr[i]!=arr1[i])
        {
            k=arr[i];
            swap(arr[i],arr[test[arr1[i]]]);
            swp++;
            test[k]=test[arr1[i]];
        }
    }
    return swp;
}
int main()
{
    long int n,swp1,swp2;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<long long int>ar(arr,arr+n);
    sort(ar.begin(),ar.end());
    swp1=lilly(arr,ar,n);
    sort(ar.begin(),ar.end(),greater<int>());
    swp2=lilly(arr,ar,n);
    cout<<min(swp1,swp2);
    return 0;
}


