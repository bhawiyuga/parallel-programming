#include <stdio.h>

int penjumlahan(int a, int b){
	return (a+b);
}

void main(){
	int a = 10;
	int b = 100;

	int c = penjumlahan(a, b);
	printf("Hasil penjumlahannya adalah %d\n", c);

	
}