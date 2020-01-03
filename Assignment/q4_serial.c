#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define R 97
#define NUM_SQUARE 10000000000

int main() {
	int px, py;
	int limit = 2*R + 1;
	long num_circle = 0;
	#pragma omp parallel
	{
		long ncircle = 0;
		#pragma omp for
			for(long i=0; i<NUM_SQUARE; i++) {
				px = rand()%limit - R;
				py = rand()%limit - R;
				printf("(%d, %d) %d\n", px, py, omp_get_thread_num());
				if((px*px + py*py) < R*R)
					ncircle++;
			}
		#pragma omp atomic
			num_circle += ncircle;
	}
	printf("pi = %Lf\n", (long double) (4 * ((long double) num_circle/NUM_SQUARE)));
}