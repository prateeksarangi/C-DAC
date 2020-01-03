//Write a MPI program that should return the sum of all processes involved note:-reduceall.
#include<stdio.h>
#include<string.h>
#include<mpi.h>
#define n 10
int main() {

	int comm_sz;
	int my_rank;
	int sum = 0, num[100], a[1000];

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	if(my_rank==0) {
		printf("Enter the numbers:\n");
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
	}

	//MPI_Barrier(MPI_COMM_WORLD);
	MPI_Scatter(a, n/comm_sz, MPI_INT, num, n/comm_sz, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Allreduce(num, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

	if(my_rank==0) {
		printf("Sum = %d\n", sum);
	}

	MPI_Finalize();
}