#include<bits/stdc++.h>
using namespace std;
int chess[101][101];
bool valid(int x,int y,int n)
{
    return (x>=0 && y>=0 && x<n && y<n);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        bool equ=false;
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>chess[i][j];
        }
        //traversing
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                //up
                if(valid(i-1,j,n) && chess[i][j]==chess[i-1][j])
                {
                    equ=true;
                     break;
                }
                //right
                if(valid(i,j+1,n) && chess[i][j]==chess[i][j+1])
                {
                    equ=true;
                    break;
                }
                //down
                if(valid(i+1,j,n) && chess[i][j]==chess[i+1][j])
                {
                    equ=true;
                    break;
                }
                //left
                if(valid(i,j-1,n) && chess[i][j]==chess[i][j-1])
                {
                    equ=true;
                    break;
                }

            }
            if(equ)
                break;
        }
        if(equ)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
}
