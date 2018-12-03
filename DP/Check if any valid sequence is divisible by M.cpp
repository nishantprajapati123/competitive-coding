#include<bits/stdc++.h>
using namespace std;

const int MAX=1000;

bool isPossible(int n, int index, int sum,
          int M, int arr[], int dp[][MAX])
{

    // Base case
    if (index == n) {

        // check if sum is divisible by M
        if ((sum % M) == 0)
            return true;
        return false;
    }

    // check if the current state
    // is already computed
    if (dp[index][sum] != -1)
        return dp[index][sum];

    // 1.Try placing '+'
    bool placeAdd = isPossible(n, index + 1,
               sum + arr[index], M, arr, dp);

    // 2. Try placing '-'
    bool placeMinus = isPossible(n, index + 1,
                sum - arr[index], M, arr, dp);

    // calculate value of res for recursive case
    bool res = (placeAdd || placeMinus);

    // store the value for res for current
    // states and return for parent call
    dp[index][sum] = res;
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cin>>m;
        int dp[n+1][MAX];
        memset(dp,-1,sizeof(dp));
        if(isPossible(n, 0, 0, m, a, dp))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
}
