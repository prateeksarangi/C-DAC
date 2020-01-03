//Write a MPI program that take data(name or number), send that to all the processor and print them.
#include<stdio.h>
#include<string.h>
#include<mpi.h>
int main() {

	int comm_sz;
	int my_rank;
	char name[100];
	int num;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	if(my_rank==0) {
		strcpy(name, "Subrat");
		num = 1729;	
	}

	MPI_Bcast(name, 100, MPI_CHAR, 0, MPI_COMM_WORLD);
	MPI_Bcast(&num, 1, MPI_INT, 0, MPI_COMM_WORLD);	

	printf("Name: %s\nNum: %d\n", name, num);

	MPI_Finalize();
}