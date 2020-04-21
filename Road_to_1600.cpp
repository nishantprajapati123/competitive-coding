#include<cstdio>
int a[510][510];
int main(){
	int n, i, j, c = 0;
	scanf("%d",&n);
	if(n<=2){
		printf("-1\n");
		return 0;
	}
	a[1][n-1]=n*n;
    a[n][n]=n*n-1;
    for(i=1;i<=n;i++)
        for(j=1;j<n;j++)
            if(a[i][j]==0) a[i][j] = ++c;
    for(i=n-1;i>0;i--) a[i][n]=++c;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
