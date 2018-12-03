#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,key,j;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    key=arr[n-1];
    j=n-2;
    while(j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j=j-1;
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
    arr[j+1]=key;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

