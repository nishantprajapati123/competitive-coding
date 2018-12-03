#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,left,right,p=0;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        left=0;                               //initializing initialing left =0 and right= sum of all element except first.
        right=accumulate(arr.begin()+1,arr.end(),0);
        for(int i=1;i<n;i++)                  // go on adding previous element on left and deleting present element from right.
        {
            left=left+arr[i-1];
            right=right-arr[i];
            if(left==right)                   //exit from loop if found.
                break;
        }
        if(left==right)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}
