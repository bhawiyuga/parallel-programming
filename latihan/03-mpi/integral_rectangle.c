#include <stdio.h>
#include <mpi.h>

double fx(double x){
	return (x+5);
}

double rectangular_rule(double awal, double akhir, double delta){
	double sum = 0;
	for(double i=awal;i<akhir;i=i+delta){
		sum = sum + (fx(i)*delta)	;
	}
	return sum;
}

double trapesium_rule(double awal, double akhir, double delta){
	double sum = 0;
	for(double i=awal;i<akhir;i=i+delta){
		sum = sum + ( 0.5*(fx(i)+fx(i+delta)) )*delta	;
	}
	return sum;
}

int main(){
	int rank, size;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int batas_kiri = 0;
	int batas_kanan = 15;
	int selisih_batas = batas_kanan-batas_kiri;
	// Jumlah batas dibagi jumlah rank
	double bagian = selisih_batas/size;
	// Hitung awal dan akhir dari setiap rank
	double awal = batas_kiri+(bagian*rank);
	double akhir = awal+bagian;
	double delta = 1.0;
	
	double sum = 0;
	double local_sum = trapesium_rule(awal, akhir, delta);

	if(rank == 0) {		
		sum = sum + local_sum;
		double remote_sum=0;
		for(int i=1;i<size;i++){
			MPI_Recv(&remote_sum, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("- Menerima dari process %d : %.2f\n", i,remote_sum);
			sum = sum + remote_sum;
		}
		printf("Hasil akhirnya adalah : %.2f\n", sum);
	}else {
		MPI_Send(&local_sum, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
		printf("+ Mengirim dari process %d : %.2f awal %.2f akhir %.2f \n", rank, local_sum, awal, akhir);
	}

	MPI_Finalize();
	return 0;
}

