#include<stdio.h>
#include<mpi.h>
int main() {

	char letter[36];

	letter[0] = 'a';

	for(int i = 1; i<36; i++) {
		letter[i] = letter[i-1] + 1;
		if(letter[i]=='z')
			letter[++i] = '0';
	}

	int comm_sz;
	int my_rank;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	int n;

	if(my_rank==0) {
		printf("Enter the number of characters: ");
		scanf("%d", &n);
		for(int i=1; i<comm_sz; i++)
			MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);

	}

	else
		MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	int n_square = n*n, n_cube = n_square*n;

	int m = n_cube/comm_sz;

	for(int i = my_rank*m; i<(my_rank+1)*m; i++)
		printf("%c%c%c\n", letter[(i/n_square)%n], letter[(i/n)%n], letter[i%n]);
	
	MPI_Finalize();
}