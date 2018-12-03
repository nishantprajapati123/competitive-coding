#include<bits/stdc++.h>
#define fo(i,n) for(int i=0;i<n;i++)
using namespace std;
long triplets(vector<int> a, vector<int> b, vector<int> c) {
   long res=0;
    int i=0,j=0,k=0;
    //sort all 3 vectors
    set<int> s1( a.begin(), a.end());
    a.assign( s1.begin(), s1.end() );
    int na=s1.size();
    sort(a.begin(),a.end(),greater<int>());

    set<int> s2( b.begin(), b.end());
    b.assign( s2.begin(), s2.end() );
    int nb=s2.size();
    sort(b.begin(),b.end(),greater<int>());

    set<int> s3( c.begin(), c.end());
    c.assign( s3.begin(), s3.end() );
    sort(c.begin(),c.end(),greater<int>());
    int nc=s3.size();

    while(j<nb)
    {
        while(k<nc && b[j]<c[k]){
            k++;
            }
        while(i<na && b[j]<a[i]){
            i++;
        }
        res+=(na-i)*(nc-k);
        j++;
    }
    return res;
}
int main()
{
    int na,nb,nc;
    cin>>na>>nb>>nc;
    vector<int>a(na),b(nb),c(nc);
    fo(i,na) cin>>a[i];
    fo(i,nb) cin>>b[i];
    fo(i,nc) cin>>c[i];
    cout<<triplets(a,b,c)<<endl;
}
