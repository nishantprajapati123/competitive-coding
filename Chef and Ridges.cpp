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

    while(t--)
    {
        int n;
        cin>>n;
        ll x_prev=1,y_prev=2;
        ll x=1,y=4;
        if(n==1)
            cout<<x_prev<<" "<<y_prev<<" ";
        else if(n==2)
            cout<<x<<" "<<y<<" ";
        else
        {
            ll x_temp,y_temp,y_temp1;
            for(;n-2;n--)
            {
             //   turn++;
             //   totalridgeswidth+=power(2,turn)+1;
//                ll x_temp,y_temp;
                y_temp1=(y_prev*y)/(__gcd(y_prev,y));
                x_temp=((y_temp1/y_prev)*x_prev)-((y_temp1/y)*x);
                if(x_temp<0) x_temp=-x_temp;
                y_temp=y_temp1;
                y_temp*=2;

                if(((float)x/(float)y) < ((float)x_prev/(float)y_prev))
                    y_temp1=(y*y_temp)/(__gcd(y,y_temp)),x_temp=((y_temp1/y)*x)+((y_temp1/y_temp)*x_temp);
                else
                    y_temp1=(y_prev*y_temp)/(__gcd(y_prev,y_temp)),x_temp=((y_temp1/y_prev)*x_prev)+((y_temp1/y_temp)*x_temp);
                y_temp=y_temp1;
                //copy
//                cout<<y_temp<<endl;
                x_prev=x,y_prev=y,x=x_temp,y=y_temp;
            }
            cout<<x<<" "<<y<<" ";
        }

    }
    return 0;
}

