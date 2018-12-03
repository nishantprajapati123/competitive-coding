#include<iostream>
#include<cstring>
#include<cctype>
#include<vector>
using namespace std;
int main()
{
    vector<int>v(4,0);
    string s;
    int n,result=0;
    char ch;
    cin>>n;
    cin>>s;
    //if(n<6)
      //  cout<<(6-n);

        for(int i=0;i<n;i++)
        {
            ch=s.at(i);
            if(isalpha(ch))
            {
                if(isupper(ch))
                    v[0]++;
                else
                    v[1]++;
            }
            else if(isdigit(ch))
                 v[2]++;
             else
                 v[3]++;

        }
        for(int j=0;j<v.size();j++)
        {
            if(v[j]==0)
                result+=1;
        }
        if((n+result)>=6)
            cout<<result;
        else
            cout<<(6-n);


    return 0;
}
