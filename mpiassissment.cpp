#include<iostream>
#include<mpi.h>
#define MASTER 0
#define send_tag 2001
#define return_tag 2002

using namespace std;

int main(int argc, char const *argv[])
{
    int n, i, j, k, id, sender;
    char ch[36], t = 'a';
    MPI_Status status;

    for(i = 0; i<36; i++){
        ch[i] = t;
        t++;
        if(t == '{')
            t = '0';
    }

    cout<<"Enter the numbers of characters:- ";
    cin>>n;

    int comm_sz;
    int my_rank, div, end, start, to_send, to_recieve, ierr, partial_ans;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

/*
    for(i = 0; i < n*n*n; i++)
        printf("Result:- %c%c%c\nExecution in thread number:- %d\n", ch[(i/(n*n))%n], ch[(i/n)%n], ch[i%n], omp_get_thread_num());
    
*/

    if(my_rank == MASTER){
        div = (n*n*n) / comm_sz;

        for(id=1; id<comm_sz; id++){
            start = i*div + 1;
            end = (i+1)*div;

            if((n-end) < comm_sz)
                end = n-1;

            to_send = end - start + 1;

            ierr = MPI_Send(&to_send, 1, MPI_INT, id, send_tag, MPI_COMM_WORLD); 
        }

        for(i=0; i < div; i++)
            printf("Result:- %c%c%c\nExecution in thread number:- %d\n", ch[(i/(n*n))%n], ch[(i/n)%n], ch[i%n], omp_get_thread_num());

        for(id = 1; id < div; id++){
            ierr = MPI_Recv(&partial_ans, 1, MPI_LONG, MPI_ANY_SOURCE, return_tag, MPI_COMM_WORLD, status);
            sender = status.MPI_SOURCE;
        }


    }

    else{
        ierr = MPI_Recv(&to_recieve, 1, MPI_INT, MASTER, send_tag, MPI_COMM_WORLD, &status);
        ierr = 
    }
    return 0;
}
