#include<iostream>
#include<omp.h>
#include<mpi.h>
#define MASTER 0
#define MAX_STRING 1000
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
    char greeting[MAX_STRING];

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if(my_rank != MASTER){
        div = (n*n*n) / comm_sz;

        for(id=1; id<comm_sz; id++){
            start = i*div + 1;
            end = (i+1)*div;

            if((n-end) < comm_sz)
                end = n-1;

            to_send = end - start + 1;
        }

        for(i=0; i < div; i++)
            sprintf(greeting, "Result:- %c%c%c\nExecution in thread number:- %d\n", ch[(i/(n*n))%n], ch[(i/n)%n], ch[i%n], omp_get_thread_num());
            MPI_Send(greeting, strlen(greeting)+1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }

    else{
        printf("Result:- %c%c%c\nExecution in thread number:- %d\n", ch[(i/(n*n))%n], ch[(i/n)%n], ch[i%n], omp_get_thread_num());
        for(int q=1; q < div; q++){
            MPI_Recv(greeting, MAX_STRING, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%s \n", greeting);
        } 
    }
    return 0;
}
