#include <stdio.h>
#include <mpi.h>

int main(){
	int rank, size;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int number;
	int jumlah_data = 5;
	int root_rank = 0;

	if(rank == root_rank) {
		int arr_number[5]={12,11,10,5,6};
		MPI_Bcast ( &arr_number, 5, MPI_INT , root_rank , MPI_COMM_WORLD );
	}else{
		int arr_number_terima[5];
		MPI_Bcast ( &arr_number_terima, 5, MPI_INT , root_rank , MPI_COMM_WORLD );
		int total = 0;
		for(int i=0;i<jumlah_data;i++){
			total = total + arr_number_terima[i];
		}
		printf("Process %d menjumlahkan hasil broadcast : %d \n", rank, total);
	}

	MPI_Finalize();
	return 0;
}

