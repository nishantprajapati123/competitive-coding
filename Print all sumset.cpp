#include<bits/stdc++.h>
using namespace std;

void calSubset(vector<int>&A, vector<int>&subset, vector<vector<int> >&powerSet, int idx)
{
    if(idx == A.size())
    {
        powerSet.push_back(subset);
        return;
    }
    subset.push_back(A[idx]);
    calSubset(A,subset,powerSet,idx+1);
    subset.pop_back();
    calSubset(A,subset,powerSet,idx+1);
}
int main()
{
    vector<int>subset;
    vector<vector<int> >powerSet;
    vector<double>A = {0,1,1.5,2,2.5,3};
//    calSubset(A,subset,powerSet,0);
//    for(int i=0;i<powerSet.size();i++)
//    {
//        for(int j=0;j<powerSet[i].size();j++)
//            cout<<powerSet[i][j];
//        cout<<endl;
//    }
    cout<<lower_bound(A.begin(),A.end(),2)-A.begin();
    return 0;
}
