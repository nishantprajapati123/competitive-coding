#include<bits/stdc++.h>
using namespace std;
typedef int ll;
int main(){
 ll n,m,i,j;
 cin>>n>>m;
 m*=2;
 ll arr[m][n];
 for(i=0;i<m;i++)
  for(j=0;j<n;j++)
   if(i==0||j==0)arr[i][j]=j+1;
   else arr[i][j]=(arr[i][j-1]+arr[i-1][j])%(1000000007);




 cout<<arr[m-1][n-1];
}