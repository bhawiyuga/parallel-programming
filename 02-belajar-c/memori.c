#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
	char *nama_mahasiswa_satu = "Tes 123";

	char *nama_mahasiswa_dua = malloc(sizeof(nama_mahasiswa_satu));

	printf("Sebelum dicopy : %s\n", nama_mahasiswa_dua);

	strcpy(nama_mahasiswa_dua, nama_mahasiswa_satu);

	printf("Setelah dicopy : %s\n", nama_mahasiswa_dua);

}