/*
WAP in MPI that print your name only if number of processes is even, 
otherwise should return error message.
*/

#include<stdio.h>
#include<mpi.h>
#define MASTER 0

int main(void){
	int comm_sz, p_rank;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &p_rank);

	if(comm_sz % 2 == 0)
		printf("Hello! My name is Prateek\n");
	else
		printf("ERROR!");

	MPI_Finalize();
}