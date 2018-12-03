#include<bits/stdc++.h>
#define l long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<l>arr(n);
        priority_queue<l,vector<l>,greater<l> >minHeap; //min heap
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            minHeap.push(arr[i]);
        }
        int cnt=0;
        bool f=false;
        if(n==1)
        {
            if(arr[n-1]>=k)
                cout<<"0"<<endl;
            else
                cout<<"-1"<<endl;;
        }
        else
        {
            while(minHeap.size()!=1)
            {
                int top1=minHeap.top();minHeap.pop();
                if(top1<k)
                {
                    int top2=minHeap.top();minHeap.pop();
                    minHeap.push(top1+top2);
                    cnt++;
                }
                else
                {
                    f=true;
                    break;
                }

            }
            if(f || minHeap.top()>=k)
                cout<<cnt<<endl;
            else
                cout<<"-1"<<endl;
        }

    }
}
