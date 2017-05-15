#include <omp.h>
#include <stdio.h>

int main(){
	printf("Output programnya adalah : \n");

	int total = 0;

	#pragma omp parallel shared(total) num_threads(10)
	{
		int jml_thread = omp_get_num_threads();
		int id_thread = omp_get_thread_num();
		printf("Thread %d dari total %d threads\n", 
			id_thread, jml_thread);
	}	

	printf("Selesai\n");

	return 0;
}