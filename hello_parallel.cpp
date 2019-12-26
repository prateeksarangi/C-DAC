#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
	#pragma omp parallel
	printf("Hello World, From thread number = %d\n", omp_get_thread_num());
	return 0;
}
