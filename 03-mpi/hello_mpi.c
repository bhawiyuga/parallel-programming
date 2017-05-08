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
	// Cetak ID
	printf("Saya adalah rank ke-%d dari %d rank\n",rank,size);
	// Finalisasi
	MPI_Finalize();
}
