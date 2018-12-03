#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>stick(n);
    for(int i=0;i<n;i++)
        cin>>stick[i];
    //sort in decreasing order
    sort(stick.begin(),stick.end(),greater<int>());
    bool done=false;
    for(int i=1;i<n-1;i++)
    {
        if((stick[i]+stick[i+1])>stick[i-1])
        {
            cout<<stick[i+1]<<" "<<stick[i]<<" "<<stick[i-1];
            done=true;
            break;
        }
    }
    if(!done)
        cout<<"-1";
}
