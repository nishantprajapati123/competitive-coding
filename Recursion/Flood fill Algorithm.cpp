#include<bits/stdc++.h>
using namespace std;
bool isValid(int x, int y, int n, int m)
{
    return (x>=0 && y>=0 && x<n && y<m);
}
struct index
{
    int x,y;

};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int screen[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>screen[i][j];
        }
        int x,y,k;
        cin>>x>>y>>k;
        queue<index>q;
        //push 1st index in queue
        int temp=screen[x][y];

        index ind;
        ind.x=x;ind.y=y;
        q.push(ind);

        while(!q.empty())
        {
            index ind;
            ind=q.front();q.pop();
            //change the pixel of current object
            screen[ind.x][ind.y]=k;

            //check for up
            if(isValid(ind.x-1,ind.y,n,m) && screen[ind.x-1][ind.y]==temp)
            {
                ind.x--;
                //push into queue
                q.push(ind);
                ind.x++;//move back
            }
            //check for down
            if(isValid(ind.x+1,ind.y,n,m) && screen[ind.x+1][ind.y]==temp)
            {
                ind.x++;
                q.push(ind);
                ind.x--;
            }
            //check for left
            if(isValid(ind.x,ind.y-1,n,m) && screen[ind.x][ind.y-1]==temp)
            {
                ind.y--;
                q.push(ind);
                ind.y++;
            }
            //check for right
            if(isValid(ind.x,ind.y+1,n,m) && screen[ind.x][ind.y+1]==temp)
            {
                ind.y++;
                q.push(ind);
                ind.y--;
            }
        }
        //print
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<screen[i][j]<<" ";
        }
        cout<<"\n";
    }
}
