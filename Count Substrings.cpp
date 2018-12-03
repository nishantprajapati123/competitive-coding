#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int cont=0,l=0;
        vector<int>freq(123,0);
        string s1,s2;
        int k,k1;
        cin>>s1>>k;
        for(int i=0;i<s1.length();i++)
        {
            k1=k;
            while(k1+i<=s1.length())
            {
                char c;
                s2=s1.substr(i,k1);   //getting substring
                for(int j=0;j<s2.length();j++)      //each character of substring
                {
                    c=s2.at(j);
                    freq[int(c)]++;             //calculating its
                }
                cont=freq[int(c)];
                l=0;
                for(int i=97;i<123;i++)
                {
                    if(freq[i]==cont)       //check for equal frequency
                        l++;
                }
                if(l==s2.length())          //
                    cout<<s2<<" ";

                k1++;
            }
        }
    }
}
