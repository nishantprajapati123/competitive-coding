#include<iostream> 
using namespace std;
#define N 4
void cofacter(int mat[N][N], int temp[N][N], int p, int q, int n)
{
	int i = 0, j = 0;

	
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (row != p && col != q)
			{
				temp[i][j++] = mat[row][col];

				
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}


int det(int mat[N][N], int n)
{
	int D = 0; 

	
	if (n == 1)
		return mat[0][0];

	int temp[N][N]; 

	int sign = 1; 

	
	for (int f = 0; f < n; f++)
	{
		
		cofacter(mat, temp, 0, f, n);
		D += sign * mat[0][f] * det(temp, n - 1);

		
		sign = -sign;
	}

	return D;
}
int main()
{
	

	int mat[N][N] = {{1, -2, 6, 3},
					{7, 9, 2, -5},
					{2, 3, 8, 4},
					{-8, 2, 0, 3.}
					};

	cout<<"Determinant of the matrix is:"<<det(mat, N);
	
	return 0;
}

