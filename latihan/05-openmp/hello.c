#include <omp.h>
#include <stdio.h>

int main(){
	printf("The output:\n");

	#pragma omp parallel num_threads(10)
	{
		printf("Hello World\n");
	}

	printf("Selesai\n");

	return 0;
}