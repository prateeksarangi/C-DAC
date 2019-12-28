#include<iostream>
#include <omp.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, i, j, k;
    char ch[35], t = 'a';

    #pragma omp parallel for num_threads(8)
    for(i = 0; i<36; i++){
        ch[i] = t;
        t++;
        if(t == '{')
            t = '0';
    }

    for(i=0; i<36; i++)
        cout<<ch[i]<<" ";
    cout<<endl;

    cout<<"Enter the numbers of characters:- ";
    cin>>n;

    double before = omp_get_wtime();

    #pragma omp parallel for num_threads(32)
    for(i = 0; i < n*n*n; i++)
        printf("Result:- %c%c%c\nExecution in thread number:- %d\n", ch[(i/(n*n))%n], ch[(i/n)%n], ch[i%n], omp_get_thread_num());
    
    double after = omp_get_wtime();
    cout<<"Time total:- "<<after - before<<endl;

    return 0;
}