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
int main()
{
    fastIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
      //  unordered_map<int,int>index;
        cin>>n;
        vi A(n),index(n+1,0);
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            index[A[i]]=i;
        }
        int temp,sorted=0,keyindex;
        //i indicate index after sorted element
        for(int i=0;i<n;i++)
        {
            if((n-1)-i==1 && A[i]!=i+1 && A[i+1]!=i+2)
                break;
            if(i+1!=A[i])
            {
                while(i+1!=A[i])
                {
//                    k++;
                    keyindex=index[i+1];
                    if(keyindex-i >=2)
                    {
                        temp=A[keyindex-2];
                        A[keyindex-2]=A[keyindex-1];
                        A[keyindex-1]=A[keyindex];
                        A[keyindex]=temp;
                        index[A[keyindex-1]]--;
                        index[A[keyindex]]+=2;
                        index[A[keyindex-2]]--;
                    }
                    else if(keyindex-i==1)
                    {
                        temp=A[keyindex-1];
                        A[keyindex-1]=A[keyindex];
                        A[keyindex]=A[keyindex+1];
                        A[keyindex+1]=temp;
                        index[A[keyindex]]--;
                        index[A[keyindex+1]]+=2;
                        index[A[keyindex-1]]--;
                    }
                }
            }
            sorted++;
        }

        if(sorted!=n)
            cout<<"NO"<<"\n";
        else
            cout<<"YES"<<"\n";
    }
}

