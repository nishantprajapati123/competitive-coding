#include<bits/stdc++.h>
using namespace std;
int good[1010];
int p[1010][10];
bool cross(int a,int b,int c)
{
	int res=0;
	for(int i=1;i<=5;i++) 
		res+=(p[b][i]-p[a][i])*(p[c][i]-p[a][i]);
	return res>0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>p[i][j];
		} 
	}	
	int cnt=0;
	if(n>11) return 0*printf("0\n");
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int k=1;k<=n;k++){
				if(k==j||k==i) continue;
				if(cross(i,j,k)){
					j=n+1,k=n+1;
					flag=0;
				}
			}
		}
		if(flag){
			good[i]=i;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		if(good[i]) cout<<i<<endl;
}