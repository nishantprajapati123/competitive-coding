#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>freq(100,0);
    vector<int>::iterator it;
    int n,no;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>no;
        freq[no]++;
    }
    for(it=freq.begin();it!=freq.end();it++)
        cout<<*it<<" ";


}
