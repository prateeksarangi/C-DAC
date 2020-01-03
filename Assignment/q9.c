//WAP such that it should initilize an array of 1 - 25	and divide these values among 5 process equally	note:- use 2d array.
#include<stdio.h>
#include<string.h>
#include<mpi.h>
#define n 10
int main() {

	int comm_sz;
	int my_rank;
	int a[5][5], num[5];

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	if(my_rank==0) {
		printf("Enter the numbers:\n");
		for (int i = 0; i < 5; i++) {
			for(int j=0; j<5; j++) {
				scanf("%d", &a[i][j]);
			}
		}
	}

	//MPI_Barrier(MPI_COMM_WORLD);
	MPI_Scatter(a, 5, MPI_INT, num, 5, MPI_INT, 0, MPI_COMM_WORLD);

	for(int i=0; i<5; i++)
		printf("Process %d: %d\n", my_rank, num[i]);

	MPI_Finalize();
}