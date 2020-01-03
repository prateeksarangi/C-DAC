//Write a C program to calculate the value of pi. (DartBoard Algorithm) hint- divide no of darts.
#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

#define R 97
#define NUM_SQUARE 1000

int main() {
	int px, py;
	int limit = 2*R + 1;

	int comm_sz;
	int my_rank;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	long ncircle = 0;
	for(long i=0; i<NUM_SQUARE/comm_sz; i++) {
		px = rand()%limit - R;
		py = rand()%limit - R;
		printf("(%d, %d)\n", px, py);
		if((px*px + py*py) < R*R)
			ncircle++;
	}

	if(my_rank==0) {
		int a[comm_sz];
		long num_circle = ncircle;
		for(int q=1; q < comm_sz; q++)
			MPI_Recv(&a[q], 1, MPI_INT, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		for(int i=1; i<comm_sz; i++)
			num_circle += a[i];
		printf("pi = %Lf\n", (long double) (4 * ((long double) num_circle/NUM_SQUARE)));
	}
	else
		MPI_Send(&ncircle, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	MPI_Finalize();
}
