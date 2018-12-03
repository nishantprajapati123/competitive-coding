#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n;
    cin>>n;
    vector<long>arr;
    long x;
    priority_queue<long,vector<long>,greater<long> >minHeap
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr.


    }
    for(int i=0;i<n;i++)
    {
        priority_queue<long,vector<long>,greater<long> >minHeap(x.begin(),x.begin()+i+1);
        long heap_size=minHeap.size();
        if(heap_size%2==0)
        {
            int m=heap_size;
            long u;
            while(m>(heap_size/2))
            {
                u=minHeap.top();minHeap.pop();
                m--;
            }
            u+=minHeap.top();minHeap.pop();
            cout<<u/2<<endl;
        }
        else
        {
            int m=heap_size;
            long u;
            while(m>(heap_size/2))
            {
                u=minHeap.top();minHeap.pop();
                m--;
            }
            cout<<u<<endl;
        }

    }
}
