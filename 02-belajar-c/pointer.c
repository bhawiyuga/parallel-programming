#include <stdio.h>

void ubahVariabel(int a, int b){
	a = 5;
	b = 9;
}

void ubahVariabelByReference(int *a, int *b){
	*a = 5;
	*b = 9;
}

void main(){
	int a = 10;
	int b = 100;

	//printf("Variabel a alamat memorinya adalah %x\n", &a);

	ubahVariabel(a,b);

	printf("a = %d\nb = %d\n",a,b);

	ubahVariabelByReference(&a, &b);

	printf("a = %d\nb = %d\n",a,b);
	
}