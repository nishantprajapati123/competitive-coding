#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long> number(n);
    for(int i=0;i<n;i++)
        cin>>number[i];
    sort(number.begin(),number.end());
    for(int i=0;i<n;i++)
        cout<<number[i];
}
