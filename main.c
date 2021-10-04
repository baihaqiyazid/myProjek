#include <stdio.h> //Library untuk input dan otput, ex : printf dan scanf
#include <stdlib.h> // standar Library di bahasa c 


int main(int argc, char *argv[]) {
	
	//------------------------- tipe data  char
	char name[10]; 
	
	printf("Nama : ");
	
	scanf("%s", &name);
	printf("Nama anda %s", name);
	
	//------------------------- tipe data  int
	float a,b, sum;
	
	printf("\n\n \tPENJULAHAN \n\n"); //ket : (\n) untuk pindah baris dan (\t) untuk tab di layar
	
	printf("Input a: ");
	scanf("%f", &a);
	
	printf("Input b: ");
	scanf("%f", &b);
	
	sum = a+b;
	
	printf("\nHasil = %.2f", sum);
		
	
	return 0;
}

	//-------------------------- Pasangan format pencetakan (% dengan tipe data)
	
	/*
	char => %s
	float => %f => %.2f (untuk mengambil 2 angka dibelakang koma
	int => %d, %i
	*/ 
	
	//------------------------- Rekomendasi Situs untuk belajar Pemrograman
	
	/*
	https://www.geeksforgeeks.org/c-language-set-1-introduction/
	https://www.tutorialspoint.com/cprogramming/index.htm
	https://www.w3schools.in/c-tutorial/
	https://www.w3schools.com/
	*/
