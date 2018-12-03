#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,key,j,k=0;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    for(int cont=1;cont<n;cont++)
    {
    key=arr[cont];
    j=cont-1;
    while(j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j=j-1;
        k++;

    }
    arr[j+1]=key;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    }
    cout<<"\n No. of comparisions";
    cout<<k;

    return 0;
}

