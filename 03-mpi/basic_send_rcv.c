#include <stdio.h>
#include <mpi.h>

int main(){
	int size, rank;
	// Inisiasi MPI
	MPI_Init(NULL, NULL);
	// Mendapatkan jumlah rank dalam satu grup
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	// Mendapatkan ID dari rank kita
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if(rank == 0){
		int data = 1000;
		// Send
		MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}
	else if(rank == 1){
		int data_diterima = 0;
		// Receive
		MPI_Recv(&data_diterima, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		// Print data yang dikirim
		printf("Rank 1 menerima data dari rank 0 berupa angka : %d\n", data_diterima);
	}

	// Finalisasi
	MPI_Finalize();
}
