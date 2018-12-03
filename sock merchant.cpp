#include<iostream>
using namespace std;
int main()
{
    int n,result=0;
    cin>>n;
    int freq[101]={0};
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        freq[c]++;
    }
    for(int i=0;i<101;i++)
    {


            result+=freq[i]/2;

    }
    cout<<result;
    return 0;
}
