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

	int batas = 10;
	
	if(rank == 0){
		int awal = 1;
		int data = 1;
		while(data < batas){
			if(awal == 1){
				// Send
				MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
				awal= 0;
			}
			else{
				MPI_Recv(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);				
			}
			printf("Rank 0 : Mengirim data %d ke rank 1\n", data);
		}
		
	}
	else if(rank == 1){
		int data_diterima = 0;
		while(data_diterima < 10){
			// Receive
			MPI_Recv(&data_diterima, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			// Print data yang diterima
			printf("Rank 1 : Menerima data %d increment jadi %d\n", data_diterima, (data_diterima+1));
			data_diterima=data_diterima+1;
			// Kirim balik ke rank 0
			MPI_Send(&data_diterima, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		}
	}

	// Finalisasi
	MPI_Finalize();
}
