#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
	int s = 0, a[1000000];
	double bf = omp_get_wtime();
	for(int i=0; i<1000000; i++)
		a[i] = rand()%100;
	for(int i=0; i<1000000; i++)
		s+= a[i];
	double af = omp_get_wtime();
	
	printf("Sum:- %d    Time:- %f\n", s, af-bf);
}
