#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int minCostPath(int **input, int m, int n)
{
	// creating an output array 
	int **output=new int*[m];
	for(int i=0; i<m; i++){
		output[i]=new int[n];
	}

	// fill the destination i.e, m-1,n-1
	output[m-1][n-1]=input[m-1][n-1];
	// the the last row  from the right to left --row is fixed and column is varying
	for(int i=n-2; i>=0; i--){
		output[m-1][i]=output[m-1][i+1]+input[m-1][i];
	}
	// fill the last column
    // column is fixed , and row will vary
	for(int i=m-2; i>=0; i--){
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
	}
	// fill the rest box
	for(int i=m-2; i>=0; i--){
		for(int j=n-2; j>=0; j--){
			output[i][j]=min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]))+input[i][j];
		}
	}
	return output[0][0];
}
int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}