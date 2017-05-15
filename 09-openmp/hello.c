#include <omp.h>
#include <stdio.h>

int main(){
	printf("Output programnya adalah : \n");

	int total = 0;

	#pragma omp parallel shared(total) num_threads(10)
	{
		printf("Hello world!!!\n");
	}	

	printf("Selesai\n");

	return 0;
}