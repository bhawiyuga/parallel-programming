#include <omp.h>
#include <stdio.h>



int main(){
	printf("The output:\n");

	int NUM_THREAD = 10;
	int global_sum = 0;

	int N = 100;

	#pragma omp parallel num_threads(NUM_THREAD)
	{
		int jml_thread = omp_get_num_threads();
		int id_thread = omp_get_thread_num();
		int local_sum = 0;
		for (int i=id_thread*N/jml_thread; i<(id_thread+1)*N/jml_thread; i++){
			local_sum = local_sum + i;
		}

		#pragma omp critical
		{
			global_sum = global_sum + local_sum;
		}

	}


	printf("Hasil %d\n", global_sum);

	return 0;
}