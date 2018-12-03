#include<bits/stdc++.h>
#define mk(a,b) make_pair(a,b)
#define pb(c) insert(c)
//#include<cstring>
using namespace std;
char c[101][101];
bool isValid(int i, int j, int n, int m)
{
    return (i>=0 && j>=0 && i<n && j<m);
}
void stringGrid(int n,int m,char x[])
{
    set< pair<int,int> >store;
    int len=strlen(x);
    int checklen,row,col;
    bool got=false;
    //check for each character that matches with 1st char of word
    //and check for all 8 direction
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(c[i][j]==x[0]) //check for 1st character match
            {
                //check for horizontal left
                checklen=1;
                row=i,col=j;
                for(int k=1;k<len;k++)
                {

                    if(isValid(row,col-1,n,m) && c[row][col-1]==x[k])
                    {
                        checklen++;
                        col--;
                        if(checklen==len)
                        {
                            //cout<<i<<" "<<j<<", ";
                            store.pb(mk(i,j));
                            got=true;
                            break;
                        }

                    }
                    else
                        break;

                }
                //check for horizontal right
                checklen=1;
                row=i,col=j;
                for(int k=1;k<len;k++)
                {
                    if(isValid(row,col+1,n,m) && c[row][col+1]==x[k])
                    {
                        checklen++;
                        col++; //increase column value
                        if(checklen==len)
                        {
                            //cout<<i<<" "<<j<<", ";
                            store.pb(mk(i,j));
                             got=true;
                            break;
                        }

                    }
                    else
                        break;
                }
                //check for vertically up
                checklen=1;
                row=i,col=j;
                for(int k=1;k<len;k++)
                {

                    if(isValid(row-1,col,n,m) && c[row-1][col]==x[k])
                    {
                        checklen++;
                        row--; //decrease row value
                        if(checklen==len)
                        {
                            //cout<<i<<" "<<j<<", ";
                            store.pb(mk(i,j));
                             got=true;
                            break;
                        }

                    }
                    else
                        break;
                }
                //check for vertically down
                checklen=1;
                row=i,col=j;
                for(int k=1;k<len;k++)
                {

                    if(isValid(row+1,col,n,m) && c[row+1][col]==x[k])
                    {
                        checklen++;
                        row++; //increase row value
                        if(checklen==len)
                        {
                            //cout<<i<<" "<<j<<", ";
                            store.pb(mk(i,j));
                            got=true;
                            break;
                        }

                    }
                    else
                        break;
                }
                //check for left diagonal up
                checklen=1;
                row=i,col=j;
                for(int k=1;k<len;k++)
                {

                    if(isValid(row-1,col-1,n,m) && c[row-1][col-1]==x[k])
                    {
                        checklen++;
                        row--;col--;
                        if(checklen==len)
                        {
                            //cout<<i<<" "<<j<<", ";
                            store.pb(mk(i,j));
                             got=true;
                            break;
                        }

                    }
                    else
                        break;
                }
                //check for left diagonal down
                checklen=1;
                row=i,col=j;
                for(int k=1;k<len;k++)
                {

                    if(isValid(row+1,col-1,n,m) && c[row+1][col-1]==x[k])
                    {
                        checklen++;
                        row++;col--; //increase row value
                        if(checklen==len)
                        {
                            //cout<<i<<" "<<j<<", ";
                            store.pb(mk(i,j));
                             got=true;
                            break;
                        }

                    }
                    else
                        break;
                }
                //check for right diagonal up
                checklen=1;
                row=i,col=j;
                for(int k=1;k<len;k++)
                {

                    if(isValid(row-1,col+1,n,m) && c[row-1][col+1]==x[k])
                    {
                        checklen++;
                        row--;col++;
                        if(checklen==len)
                        {
                            //cout<<i<<" "<<j<<", ";
                            store.pb(mk(i,j));
                             got=true;
                            break;
                        }

                    }
                    else
                        break;
                }
                //check for right diagonal down;
                checklen=1;
                row=i,col=j;
                for(int k=1;k<len;k++)
                {

                    if(isValid(row+1,col+1,n,m) && c[row+1][col+1]==x[k])
                    {
                        checklen++;
                        row++;col++; //increase row value
                        if(checklen==len)
                        {
                            //cout<<i<<" "<<j<<", ";
                            store.pb(mk(i,j));
                             got=true;
                            break;
                        }

                    }
                    else
                        break;
                }
                //check for length 1 of x
                if(len==1)
                {
                    //cout<<i<<" "<<j<<", ";
                    store.pb(mk(i,j));
                    got=true;
                }

            }

        }
    }
    set< pair<int,int> >::iterator it,itr;
    for(it=store.begin();it!=store.end();++it)
    {
        cout<<it->first<<" "<<it->second<<", ";
    }
    if(!got)
        cout<<"-1";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        char x[max(n,m)];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>c[i][j];
        }
        cin>>x;
        stringGrid(n,m,x);
        cout<<endl;
    }
}
