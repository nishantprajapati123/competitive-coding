#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
bool jump(vector<int>A, int last_i)
{
    if(A.size()==1)
        return true;
    if(last_i==-1)
        return true;
    else
    {
        int j = last_i-1,minm = 2;
        while(j>=0)
        {
            if(A[j] >= minm)
                last_i = j, minm = 0;
            j--;
            minm++;
        }
        return (last_i==0 && A[last_i]);
    }
}
int main()
{
    fastIO
    freopen("input.txt","r",stdin);
    int last_i = -1,n;
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(A[i]==0 && i!=A.size()-1) last_i = i;
    }
    if(jump(A,last_i))
        cout<<"true\n";
    else
        cout<<"false\n";
    return 0;
}

