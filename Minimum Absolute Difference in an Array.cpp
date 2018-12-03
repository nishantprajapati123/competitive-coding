#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    int min_=INT_MAX;               //assign maximum value.
    for(int i=0;i<n-1;i++)
    {
        if(abs(arr[i]-arr[i+1])<min_)
            min_=abs(arr[i]-arr[i+1]);
    }
    cout<<min_;
}
