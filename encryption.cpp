#include<bits/stdc++.h>
using namespace std;
void encryption(string s)
{
    int i,j,k=0;
    int l=s.length();

    float sqrt_root=sqrt(l);
    int row=floor(sqrt_root);
    int col=ceil(sqrt_root);
    char ch[row][col];
    if(row*col<l)
    {
        row++;
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(k<l)
                ch[i][j]=s[k++];

      }
    }

    for(j=0;j<col;j++)
    {
        for(i=0;i<row;i++)
        {
            if(isalpha(ch[i][j]))
               cout<<ch[i][j];
        }
        cout<<" ";
    }

}

int main()
{
    string s;
    getline(cin,s);
    encryption(s);
    return 0;
}

