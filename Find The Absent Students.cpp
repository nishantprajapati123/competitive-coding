#include<bits/stdc++.h>
using namespace std;
void findTheAbsentStudents(vector<int>freq, int n)
{
    int i=1,cont=0;
    while(i<=n)
    {
        if(freq[i]>1)
        {
            cont+=freq[i]-1;
        }

        i++;
    }
    i=1;
    cout<<cont<<endl;
    while(i<=n)
    {
        if(freq[i]==0)
            cout<<i<<" ";
        i++;
    }
}
int main()
{
    int n,a;
    cin>>n;
    vector<int>freq(101,0);
    for(int i=0;i<n;i++)
    {
        cin>>a;
        freq[a]++;
    }
    findTheAbsentStudents(freq,n);

}
