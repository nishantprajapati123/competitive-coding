#include<bits/stdc++.h>
using namespace std;
int steadyGene(string s)
{
    int n=s.length();
    int gene[4];
    memset(gene,0,sizeof(gene));
    int i,j,len=0;
    if(n%4==0)
    {
        i=0;
        while(i<s.length())
        {
            if(s[i]=='A')
                gene[0]++;
            else if(s[i]=='C')
                gene[1]++;
            else if(s[i]=='T')
                gene[2]++;
            else
                gene[3]++;
            if(gene[0]>(n/4) || gene[1]>(n/4) || gene[2]>(n/4) || gene[3]>(n/4))
                break;
            else
                i++;
            len++;
        }
        if(len!=s.length())
        {
            j=s.length()-1;
            while(j>=0)
            {
                if((s[j]=='A' && gene[0]>(n/4)) || (s[j]=='C' && gene[1]>(n/4))|| (s[j]=='T' && gene[2]>(n/4))|| (s[j]=='G' && gene[3]>(n/4)))
                    break;
                if (s[j]=='A')
                    gene[0]++;
                else if(s[j]=='C')
                    gene[1]++;
                else if(s[j]=='T')
                    gene[2]++;
                else
                    gene[3]++;

                j--;

            }
            return (j-i)+1;
        }
        else
            return 0;
    }
}
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    string s;
    getline(cin,s);
    cout<<steadyGene(s);
}
