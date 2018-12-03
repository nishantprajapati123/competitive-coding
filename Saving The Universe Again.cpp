#include<bits/stdc++.h>
using namespace std;
int main()
{
    int total=0,damage=0,st=1;
    int T,D,testcase,i,j;
    int l;
    string p;
    cin>>T;
    for(testcase=1;testcase<=T;testcase++)
    {
        cin>>D;
        getline(cin,p);
        l=p.length();
        for(i=0;i<l;i++)
        {
            if(p[i]=='C')
            {
                st=st*2;
            }else
            {
                damage+=st;
            }
            total=damage;
            cout<<total;
        }

    }


}
