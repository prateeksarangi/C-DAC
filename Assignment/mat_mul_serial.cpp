/*
WAP to multipy two matrix.
*/

#include<iostream>
using namespace std;

int main(){
	int n, m, p, q;
	int i, j, k;
	
	cout<<"Enter the dimension of the first matrix:-\n";
	cin>>m>>n;

	cout<<"Enter the dimension of the second matrix:-\n";
	cin>>p>>q;

	if(n == p){
		int a[m][n], b[p][q], c[m][q];
		cout<<"Enter the elements of the first matrix:-\n";
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				cin>>a[i][j];

		cout<<"Enter the elements of the second matrix:-\n";
		for(i=0; i<p; i++)
			for(j=0; j<q; j++)
				cin>>b[i][j];

		for(i=0; i<m; i++)
			for(j=0; j<q; j++)
			{
				c[i][j]=0;
				for(k=0; k<n; k++)
					c[i][j] += a[i][k]*b[k][j];
			}
		cout<<"The result matrix is:-\n";
		for(i=0; i<m; i++){
			for(j=0; j<q; j++)
				cout<<c[i][j]<<" ";
			cout<<endl;
		}
	}

	cout<<endl;
}
