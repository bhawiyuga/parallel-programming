#include <omp.h>
#include <stdio.h>

int main(){
	printf("Output programnya adalah : \n");

	int total = 0;

	int batas = 100;

	#pragma omp parallel num_threads(10)
	{
		int jml_thread = omp_get_num_threads();
		int id_thread = omp_get_thread_num();
		int jml_hitung_tiap_thread = batas/jml_thread;

		int local_total = 0;

		for(int i=(id_thread*jml_hitung_tiap_thread+1); 
			i<=(id_thread+1)*jml_hitung_tiap_thread;
			i++ ){
			local_total = local_total + i;
		}

		#pragma omp critical
		{
			total = total + local_total;	
		}		
	}	

	printf("Hasil akhir %d\n", total);

	return 0;
}