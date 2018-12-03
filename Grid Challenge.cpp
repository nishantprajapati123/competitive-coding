#include<bits/stdc++.h>
using namespace std;
string gridChallenge(vector<string>grid, int n)
{
    for(int i=0;i<n;i++)
    {
        sort(grid[i].begin(),grid[i].end());
    }
    //check for column
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(grid[j][i]>grid[j+1][i])
                return "NO";
        }
    }
    return "YES";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cin.ignore();
        vector<string>grid(n);
        for(int i=0;i<n;i++)
        {
            string str;
            getline(cin,str);
            grid[i]=str;
        }
        cout<<gridChallenge(grid,n)<<endl;

    }
}
