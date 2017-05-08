#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
	
	char nama_mahasiswa[] = "Tes 123";

	char *nama_mahasiswa_dua = "Tes 123 Pointer";

	short nilai_mahasiswa = 90;

	char *alamat = "Malang";

	//printf("Nama mahasiswa %s nilainya %d berasal dari %s\n", nama_mahasiswa_dua, nilai_mahasiswa, alamat);

	char *tes = malloc(100);

	sprintf(tes, "Hello world");

	printf("%s", tes);
	
}