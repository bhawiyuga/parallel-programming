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

	int x = size*3;
	int data = 1;

	if(rank == 0){
		MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		while(data < x){
			// Send
			MPI_Recv(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);				
			printf("Rank 0 : %d\n", data);
		}
		
	}
	else if(rank == 1){
		while(data < x){
			// Receive
			MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			// Print data yang diterima
			printf("Rank 1 : %d\n", data);
			data=data+1;
			// Kirim balik ke rank 0
			MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		}
	}

	// Finalisasi
	MPI_Finalize();
}
