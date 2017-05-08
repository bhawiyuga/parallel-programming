#include <stdio.h>
#include <mpi.h>

int main(){
	int rank, size;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int root_rank = 0;

	int b[4] = {0,0,0,0};

	MPI_Gather(&rank, 1, MPI_INT, &b, 1, MPI_INT, root_rank, MPI_COMM_WORLD);

	printf("Rank %d punya data : ", rank);
	for(int i=0;i<4;i++){
		printf("%d ", b[i]);
	}
	printf("\n");

	MPI_Finalize();
	return 0;
}

