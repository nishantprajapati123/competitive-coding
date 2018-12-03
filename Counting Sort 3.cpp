#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k=0;
    cin>>n;
    vector<int>freq(100,0);
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        string s;
        cin>>s;
        freq[no]++;
    }
    for(int i=0;i<100;i++)
    {
        k+=freq[i];
        cout<<k<<" ";
    }

}
