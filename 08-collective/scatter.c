#include <stdio.h>
#include <mpi.h>

int main(){
	int rank, size;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int root_rank = 0;

	int data[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	int penampung[4];

	MPI_Scatter(&data, 4, MPI_INT, &penampung, 4, 
		MPI_INT, root_rank, MPI_COMM_WORLD);

	printf("Rank %d menerima data : ", rank);
	for(int i=0;i<4;i++){
		printf("%d ", penampung[i]);
	}
	printf("\n");
	

	MPI_Finalize();
	return 0;
}

