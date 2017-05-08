#include <stdio.h>
#include <mpi.h>

int main(){
	int rank, size;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int number;

	if(rank == 0) {
		int arr_number[5]={12,11,10,5,6};
		MPI_Send(&arr_number, 5, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}else if(rank == 1) {
		int arr_number_terima[5];
		MPI_Recv(&arr_number_terima, 5, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Process 1 received number %d from process 0\n", arr_number_terima[0]);
	}

	MPI_Finalize();
	return 0;
}

