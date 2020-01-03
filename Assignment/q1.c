//Write a MPI program that should print your name only if number of processes is even otherwise return error message.
#include<stdio.h>
#include<mpi.h>
int main() {

	int comm_sz;
	int my_rank;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	if(comm_sz%2==0 && my_rank==0)
		printf("Subrat\n");
	else if(my_rank==0)
		printf("Error\n");

	MPI_Finalize();
}