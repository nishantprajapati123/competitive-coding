#include<bits/stdc++.h>
using namespace std;
int anagram(string s1, string s2)
{
    vector<int>first(26,0),second(26,0);
    //since length of both string is equal
    int n=s1.length();
    for(int i=0;i<n;i++)
    {
        first[s1[i]-'a']++;
        second[s2[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(first[i]!=second[i])
            return 0;
    }
    return 1;
}
int main()
{
    int q;
    cin>>q;
    cin.ignore();
    while(q--)
    {
        int cnt=0;
        string s;
        getline(cin,s);
        int n=s.length();
        //generate all possible substring of all length and
        //check for its anagram
        for(int len=1;len<=n;len++)
        {
            string s1;
            for(int i=0;i<n-len;i++)
            {
                s1=s.substr(i,len);
                //cout<<s1<<endl;
                string s2;
                for(int j=i+1;j<n-len+1;j++)
                {
                    s2=s.substr(j,len);
                  //  cout<<s2<<endl;
                    {
                        if(anagram(s1,s2)==1)
                            cnt++;
                    }
                }
            }
        }
        cout<<cnt<<endl;

    }
}

