#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,miles=0;
    cin>>n;
    vector<int>calorie(n);
    for(int i=0;i<n;i++)
        cin>>calorie[i];
    sort(calorie.begin(),calorie.end(),greater<int>());
    for(int i=0;i<n;i++)
    {
        miles+=pow(2,i)*calorie[i];
    }
    cout<<miles;
}
