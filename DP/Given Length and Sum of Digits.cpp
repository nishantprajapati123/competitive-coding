#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mk make_pair
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define vi vector < int >
#define pii pair < int, int >
#define INF (int)1e9
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
int main (){
	int m,s,i,k;
	cin>>m>>s;
	if(s<1 && m>1 || s>m*9)
		cout<<-1<<' '<<-1<<endl;
	else {
		for(i=m-1,k=s;i>=0;i--){
			int j=max(0,k-9*i);
			if(j==0&&i==m-1&&k) j=1;
				cout<<j;
			k-=j;}
	    cout<<' ';
		for(i=m-1,k=s;i>=0;i--){
			int j=min(9,k);
			cout<<j;
			k-=j;}
	}
}
