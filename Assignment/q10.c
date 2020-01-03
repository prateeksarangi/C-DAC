//WAP to decomposition simple data such that the master task should 1st initialize an array and then distribute an equal portion of that array to the other tasks. After the other task receive their portion of data, they should perform an ADDITION Operation on elements of array.

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

	MPI_Scatter(a, n/comm_sz, MPI_INT, num, n/comm_sz, MPI_INT, 0, MPI_COMM_WORLD);
	for(int i=0; i<n/comm_sz; i++)
		sum += num[i];
	int allsum[comm_sz];
	MPI_Gather(&sum, 1, MPI_INT, allsum, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if(my_rank==0) {
		for(int i=0; i<comm_sz; i++)
			printf("Process%d sum = %d\n", i, allsum[i]);
	}
	MPI_Finalize();
}