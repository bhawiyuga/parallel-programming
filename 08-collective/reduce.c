#include <stdio.h>
#include <mpi.h>
#include <time.h>

int getRandom(int min, int max, int seed){
	srand(seed);
	int random = (rand(seed) % (max-min)) + min;
	return random;
}

int main(){
	int rank, size;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int root_rank = 0;

	int sum = 0;
	int data = getRandom(1,100,rank);

	MPI_Reduce (&data , &sum , 1, MPI_INT ,
		MPI_SUM, root_rank, MPI_COMM_WORLD);

	if(rank == root_rank) {
		printf("Process %d mengirim angka : %d \n", rank, data);
		printf("Hasil penjumlahan adalah : %d", sum);
	}else{
		printf("Process %d mengirim angka : %d \n", rank, data);
	}

	MPI_Finalize();
	return 0;
}

