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
    int N,c,y=1,q;
    bool found = false;
    cin>>N>>c;
    cout<<"1"<<" "<<y<<endl;
    while(true)
    {
        cin>>q;

        if(q==0)
        {
            if(y+600 >N)
            {
                int i=y+2;
                while(true)
                {
                    if(q==0 && i<=N)
                        cout<<"1"<<" "<<i<<endl;
                    else if(q==0 && i>N)
                    {
                        cout<<"1"<<" "<<N<<endl;
                        cin>>q;
                        cout<<"2"<<endl;
                        cout<<"3"<<" "<<N<<endl;
                        found = true; break;
                    }
                    else if(q==1)
                    {
                        cout<<"2"<<endl;
                        cout<<"1"<<" "<<i-3<<endl;
                        cin>>q;
                        if(q==1)
                            cout<<"2"<<endl<<"3"<<" "<<i-3<<endl;
                        else if(q==0)
                            cout<<"3"<<" "<<i-2<<endl;
                        found = true;break;
                    }
                    cin>>q;
                    i+=2;
                }
            } else {
            y+=600;
            cout<<"1"<<" "<<y<<endl;
            }
        }
        else if(q==1 && y!=1)
        {
            cout<<"2"<<endl;
            cout<<"1"<<" "<<y-598<<endl;
            for(int i=y-596;i<=y+2;i+=2)
            {
                cin>>q;
                if(q==0)
                {
                    cout<<"1"<<" "<<i<<endl;
                }
                else if(q==1)
                {
                    cout<<"2"<<endl;
                    cout<<"1"<<" "<<i-3<<endl;
                    cin>>q;
                    if(q==1)
                        cout<<"2"<<endl<<"3"<<" "<<i-3<<endl;
                    else if(q==0)
                        cout<<"3"<<" "<<i-2<<endl;
                    found = true;break;
                }

            }
        }
        else if(q==1 && y==1)
        {
            cout<<"2"<<endl;
            cout<<"3"<<" "<<y<<endl;
            found = true; break;
        }
        if(found) break;
    }

}

