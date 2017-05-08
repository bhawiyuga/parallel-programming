#include <stdio.h>

void main(){
	int nilai_mahasiswa = 10;

	int a = 1000;
	int b = 2000;

	int c = a + b;

	printf("%d ditambah dengan %d hasilnya : %d\n", a, b, c);

	a = 1000;
	b = 2000;

	c = a - b;

	printf("%d dikurangi dengan %d hasilnya : %d\n", a, b, c);
	
	double d = 10.5;
	int e = 20;
	double f = d + e;

	printf("%f dijumlah dengan %d hasilnya : %f\n", d, e, f);

	char g = 'A';
	int h = e + g;
	printf("%c dijumlah dengan %d hasilnya : %d\n", g, e, h);	
}