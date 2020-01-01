/*
WAP in MPI that should determine the partner process and then send and recieve a message with it.
*/

#include<stdio.h>
#include<mpi.h>
#define MASTER 0

int main(void){
	char st[100];
	int comm_sz, p_rank;

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &p_rank);

	if(p_rank != MASTER){
		sprintf(st, "Sending this message\n");
		MPI_Send(st, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
	}

	else{
		printf("Recieving message\n");
		for(int q=1; q < comm_sz; q++){
			MPI_Recv(st, 100, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("%s \n", st);
		}
	}

	MPI_Finalize();

}