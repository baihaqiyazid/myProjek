#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
		
    char  nama[20], ketik[20], nam[50];
	
	int a, b, c, d, e, f, g, h;
	a = 10;
	b = 20;
	c = 45;
	d = 80;
	e = 30;
	f = 50;
	g = 100;
	h = a+b+c+d+e+f+g;
	
    
    printf("Enter Your Name   :");
    scanf("%s", nama);
    printf("Welcome Mr.  %s!!!\n", nama);   
	printf("Good Health to you sir!!!\n");
	printf("=========================\n\n");
	
	printf("			             ***LAPORAN PENGAMATAN STOK BARANG GUDANG AL AZHAR***\n\n");
	printf("    *Stok Barang*\n");
	printf("    \n\n");

	printf("    Kemeja Putih :  %d\n", a);
	printf("    Celana Hitam :  %d\n", b);
	printf("    Meja belajar :  %d\n", c);
	printf("    Kursi panjang:  %d\n", d);
	printf("    Loker kelas  :  %d\n", e);
	printf("    Neraca       :  %d\n", f);
	printf("    Al Qur'an    : %d\n", g);
	printf("                      \n\n");
	printf("           |Total : %d|\n", h);
	printf("            \n\n");

	printf("_____________________________________________________________________________________________________________________");
	printf("\n\n");
	
	int tanggal, bulan, tahun;
	
	printf("*Bonus*\n\n");
	printf("    Siapa nama mu :");
	scanf("%s", nam);
	printf("    Tanggal lahir :");
	scanf("%d", &tanggal);
	printf("    Bulan lahir   :");
	scanf("%d", &bulan);
	printf("    Tahun lahir   :");
	scanf("%d", &tahun);
	printf("\n");
	printf("Hai %s nama kamu sangat bagus!!!\n", nam);
	printf("Wow sekarang kamu sudah berusia %d tahun, ", 2020-tahun);
	printf("%d bulan.\n\n\n", 10-bulan);
	printf("\n\n\n\n");

	
	printf("=========================================== THANK YOU FOR COMING TO MY PROJECT!!! ======================================");

	
	
    return 0;
}
