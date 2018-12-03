#include<bits/stdc++.h>
using namespace std;
long stockMax(vector<int>prices, int n)
{
    //get maximum from end and sell the stock at that day(max day)
    //after maximum their is always stock price decreasing
    long profit=0;
    int maxfromend=0;
    for(int i=n-1;i>=0;i--)
    {
        //goes on calculating max from end
        if(prices[i]>=maxfromend)
            maxfromend=prices[i];   //when max found from end
        profit+=maxfromend-prices[i];  //sell current stock at that day
    }
    return profit;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>prices(n);
        for(int i=0;i<n;i++)
            cin>>prices[i];
        cout<<stockMax(prices,n)<<endl;
    }
}
