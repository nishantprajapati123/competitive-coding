#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,cont=0;
    cin>>n>>k;
    vector<int>house(n);
    for(i=0;i<n;i++)
        cin>>house[i];
    i=0;
    int range;
    sort(house.begin(),house.end());
    while(i<n)
    {
        range=house[i]+k;
        while(i<n && house[i]<=range)
        {
            i++;
        }
        i--;
        cont++;
        range=house[i]+k;
        while(i<n && house[i]<=range)
        {
            i++;
        }
    }
    cout<<cont;
}
