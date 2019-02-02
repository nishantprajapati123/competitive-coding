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
    fastIO
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
        string s1="",match="not";
        bool found =false;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch==32)
            {
                if(s1.compare(match)==0)
                {
                    found = true;
                    break;
                }
                s1="";
            }
            else
                s1+=ch;
        }
        s1="";
        if(!found)
        {
            for(int i=s.length()-1;i>=0;i--)
            {
           // cout<<s1<<endl;
                if(s[i]==32 || i==0)
                {
                    if(i==0)
                        s1+=s[i];
                    if(s1.compare("ton")==0)
                    {
                        found=true;
                        break;
                    }
                }
                else
                    s1+=s[i];
            }
        }
        //cout<<s1<<endl;
        if(found)
            cout<<"Real Fancy"<<"\n";
        else
            cout<<"regularly fancy"<<"\n";
    }
    return 0;
}
