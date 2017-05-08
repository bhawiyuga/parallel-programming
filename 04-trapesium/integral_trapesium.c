#include <stdio.h>
#include <mpi.h>

double fx(double x){
	return x+5;
}

double luas_trapesium(double x, double y, double t){
	double a = fx(x);
	double b = fx(y);
	double luas = 0.5*(a+b)*t;
	return luas;
}

int main(){
	int size, rank;
	// Inisiasi MPI
	MPI_Init(NULL, NULL);
	// Mendapatkan jumlah rank dalam satu grup
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	// Mendapatkan ID dari rank kita
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// Definisikan batas kiri
	double batas_kiri = 0;
	// Definisikan batas kanan
	double batas_kanan = 15;
	// Definisikan delta = berapa kenaikan sumbu-x nya
	double delta = 1;
	// Hitung jumlah bagian masing-masing rank
	double bagian_per_rank = (batas_kanan-batas_kiri)/delta/size;

	// Batas kiri per rank
	double x = batas_kiri + rank*bagian_per_rank;
	// Batas kanan per rank
	double y = x + bagian_per_rank;

	double luas_per_rank = luas_trapesium(x,y,bagian_per_rank);

	// Jika saya adalah rank 0
	// - Menghitung luas untuk rank 0
	// - Receive semua luas yang dihitung oleh tiap rank
	// - Saya jumlahkan, kemudian tampilkan hasilnya

	// Jika saya BUKAN rank 0
	// - Menghitung luas rank
	// - Kirim ke rank 0

	// Finalisasi
	MPI_Finalize();
}
