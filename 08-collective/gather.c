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

	int penampung[4];

	MPI_Gather(&data, 1, MPI_INT, &penampung, 1, 
		MPI_INT, root_rank, MPI_COMM_WORLD);

	printf("Rank %d mengirimkan data %d \n", rank, data );

	if(rank == root_rank){
		for(int i=0;i<4;i++){
			printf("%d ", penampung[i]);
		}
	}
	printf("\n");

	MPI_Finalize();
	return 0;
}

