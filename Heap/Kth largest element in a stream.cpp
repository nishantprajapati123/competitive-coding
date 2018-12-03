#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;
        vector<int>stream(n);
        for(int i=0;i<n;i++)
            cin>>stream[i];
        int i=0;
        int invalid=1;
        while(i<n)
        {
            if(invalid<k)
            {
                cout<<"-1 ";
            }
            else
            {
                priority_queue<int>maxHeap(stream.begin(),stream.begin()+i+1);
                //int j=stream.begin()+i;
                //cout<<j-stream.begin()<<endl;
                int s=k;
                int u;
                while(s)
                {
                    u=maxHeap.top();maxHeap.pop();
                    s--;
                }
                cout<<u<<" ";
            }
            invalid++;i++;
        }
        cout<<endl;
    }
}

