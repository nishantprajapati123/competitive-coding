#include<bits/stdc++.h>
using namespace std;
int magic_no[8][9]={{8,1,6,3,5,7,4,9,2},
            {2,9,4,7,5,3,6,1,8},
            {8,3,4,1,5,9,6,7,2},
            {2,7,6,9,5,1,4,3,8},
            {4,3,8,9,5,1,2,7,6},
            {6,7,2,1,5,9,8,3,4},
            {4,9,2,3,5,7,8,1,6},
            {6,1,8,7,5,3,2,9,4}};
int main()
{
    int temp_min=0,min_=INT_MAX;
    int s[9];
    for(int i=0;i<9;i++)
        cin>>s[i];
    for(int i=0;i<8;i++)
    {
        temp_min=0;
        for(int j=0;j<9;j++)
            temp_min+=abs(s[j]-magic_no[i][j]);
        if(min_>temp_min)
            min_=temp_min;
    }
    cout<<min_<<endl;
}

