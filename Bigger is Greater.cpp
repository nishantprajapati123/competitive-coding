#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string w,s1,s2,s3;
        bool found = false;
        getline(cin,w);
       int n=w.length();
        for(int i=n-1;i>0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(w[i]>w[j])
                {
                    s3=w.substr(i,n-i);
                    s2=w.substr(j,i-j);
                    s1=w.substr(0,j-0);
                    sort(w.begin()+)
                    found=true;
                    break;
                }
            }
            if(found)
                break;

        }
        if(found)
            cout<<s1+s3+s2<<endl;
        else
            cout<<"no answer"<<endl;
    }
}
