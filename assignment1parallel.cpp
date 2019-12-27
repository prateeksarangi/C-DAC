#include<iostream>
#include<stdio.h>
#include<omp.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n = 3, m;
    cout<<"Enter the number of characters:- ";
    cin>>m;
    char ch[m], t = 'a';
    int i, j, k;
    for(i = 0; i<m; i++){
        ch[i] = t;
        t++;
    }

    double before = omp_get_wtime();
    #pragma omp parallel
    for(i=0; i<m; i++)
        for(j=0; j<m; j++)
            #pragma omp for
            for(k=0; k<m; k++)
                printf("Executing in thread number:- %d\nResult:- %c%c%c\n", omp_get_thread_num(), ch[i], ch[j], ch[k]);
                
    double after = omp_get_wtime();
    cout<<"Time total:- "<<after - before<<endl;
    return 0;
}