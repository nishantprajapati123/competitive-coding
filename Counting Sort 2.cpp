
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>freq(100,0);
    int n,no;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        freq[no]++;
    }
    for(int i=0;i<100;i++)
    {
        while(freq[i]--)
        {
            cout<<i<<" ";
        }
    }


}
