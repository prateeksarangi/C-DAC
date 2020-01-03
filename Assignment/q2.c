//Write a MPI program that should determine partner process and then send and receive message (Your name and number) with it.
#include<stdio.h>
#include<string.h>
#include<mpi.h>
int main() {

	int comm_sz;
	int my_rank;
	char name[100];

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	if(my_rank==0) {
		int n;
		strcpy(name, "Subrat");
		for(int i=1; i<comm_sz; i++) {
			MPI_Send(name, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD);
			MPI_Recv(&n, 1, MPI_INT, i, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("%d\n", n);
		}
	}
	else {
		MPI_Recv(name, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Send(&my_rank, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
		printf("%s\n", name);
	}

	MPI_Finalize();
}