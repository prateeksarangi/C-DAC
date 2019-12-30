#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
	int a[1000000], s = 0;
	omp_set_num_threads(2);
	double bf = omp_get_wtime();
	#pragma omp parallel for
	for(int i=0; i<1000000; i++)
		a[i] = rand()%100;
	#pragma omp parallel for
	for(int i=0; i<1000000; i++)
		s += a[i];
	double af = omp_get_wtime();
	
	printf("Sum:- %d    Time:- %f\n", s, af-bf);
}
