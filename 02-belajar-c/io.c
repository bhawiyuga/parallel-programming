#include <stdio.h>


void main(){
	int jumlah = 0;

	printf("Masukkan jumlah yang akan dicetak : ");

	scanf("%d", &jumlah);

	printf("Anda memasukkan jumlah %d\n", jumlah);

	for(int i = 0; i<jumlah; i++){
		for(int j = 0; j<jumlah; j++){
			printf("* ");
		}
		printf("\n");
	}
	
}