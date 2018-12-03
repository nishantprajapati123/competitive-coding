#include<bits/stdc++.h>
using namespace std;
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
        priority_queue<int,vector<int>,greater<int> >minHeap(arr.begin(),arr.end());
        long long int num1=0,num2=0;
        while(1)
        {
            if(minHeap.size()==0)
                break;
            else
            {
                num1=(num1*10)+(minHeap.top());minHeap.pop();
            }
            if(minHeap.size()==0)
                break;
            else
            {
                num2=(num2*10)+(minHeap.top());minHeap.pop();
            }

        }
        cout<<num1+num2<<endl;
    }
}
