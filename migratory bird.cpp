#include<bits/stdc++.h>
using namespace std;
int freq[6]={0};
int migratoryBird(int n)
{
    int id,max_,pos;
    for(int i=0;i<n;i++)
    {
        cin>>id;
        freq[id]+=1;
    }
    max_=freq[0];
    for(int i=0;i<6;i++)
    {
        if(max_<freq[i])
        {
            max_=freq[i];
            pos=i;
        }
    }
    return pos;

}
int main()
{
    int n;
    cin>>n;
    cout<<migratoryBird(n);
    return 0;
}
