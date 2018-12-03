#include<iostream>
using namespace std;
int main()
{
    string s1="hackerrank";
    string s2,s3="";
    int q,i,j;
    char ch;
    cout<<"\n Enter test case: ";
    cin>>q;
    for(int c=1;c<=q;c++)
    {
        cout<<"\n Enter string: ";
        cin>>s2;
        if(s1.length()>s2.length())
            cout<<"NO";
        else{

            i=0;
            j=0;
            while(j<s2.length())
            {

                if(s1[i]==s2[j])
                {
                    ch=s2.at(j);
                    s3=s3+ch;
                    i=i+1;j=j+1;
                }
                else{
                    j=j+1;
                }
            }
            if(s1.compare(s3)==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;


        }
        s3="";
        s2="";
    }

}
