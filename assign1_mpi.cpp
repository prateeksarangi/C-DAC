#include<stdio.h>
#include<mpi.h>
//#include<omp.h>
using namespace std;
int main() {

	char letter[36];

	letter[0] = 'a';

	for(int i = 1; i<36; i++) {
		letter[i] = letter[i-1] + 1;
		if(letter[i]=='z')
			letter[++i] = '0';
	}

	int n;
	printf("Enter the number of characters: ");
	scanf("%d", &n);

	int n_square = n*n, n_cube = n_square*n;

	int comm_sz;
	int my_rank;

	//double t1 = omp_get_wtime();

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	int m = n_cube/comm_sz;

	for(int i = my_rank*m; i<(my_rank+1)*m; i++)
		printf("%c%c%c\n", letter[(i/n_square)%n], letter[(i/n)%n], letter[i%n]);

	MPI_Finalize();

	//double t2 = omp_get_wtime();

	//cout<<"Time = "<<t2-t1;
}
