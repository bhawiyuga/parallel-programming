#include <omp.h>
#include <stdio.h>

int main(){
	printf("The output:\n");

	#pragma omp parallel num_threads(10)
	{
		int jml_thread = omp_get_num_threads();
		int id_thread = omp_get_thread_num();
		printf("Saya adalah thread dengan ID %d dari total %d thread\n", id_thread, jml_thread);
	}

	printf("Selesai\n");

	return 0;
}