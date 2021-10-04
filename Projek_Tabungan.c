#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NASABAH "nasabah.txt"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void nasabah_baru();
void transaksi();
void searchByNoRekeningPrintNama();
void simpan_data_nasabah(char no_rekening[10], char nama[]);
void simpan_saldo_akhir(char no_rekening[10], int setor_kah, int nilai, int saldo);

int main(int argc, char *argv[]) {
	int mode;
	do{
		printf("\n\n Nasabah Baru? \n 1. Ya \n 2. Tidak \n 3. Info Nasabah\n 0. exit aplikasi\n  input anda: ");
		mode=getche();
		if(mode=='1'){
			nasabah_baru();
		}else if(mode=='2'){
			transaksi();
		}
		else if(mode=='3'){
			searchByNoRekeningPrintNama();
		}
		
	}while(mode=='1' || mode=='2' || mode=='3');
	return 0;
}

void simpan_data_nasabah(char no_rekening[10], char nama[]){
	FILE * fp;
	// 
	fp= fopen(FILE_NASABAH,"a");
	fprintf(fp,"%s %s \n",no_rekening,nama);
	fclose(fp);
	
	//
	fp= fopen(no_rekening,"a");
	fprintf(fp,"%12s %10d %12d %12s\n","awal_saldo",0,0,nama);
	fclose(fp);
}
int baca_saldo_akhir(char no_rekening[10]){
	FILE * fp;
	char transaksi[12];
	int nilai,saldo,saldo_save;
	fp= fopen(no_rekening,"r");
	printf("\n");
	while(fscanf(fp,"%s %d %d",transaksi,&nilai,&saldo)!= EOF ){
		printf("%s %d %d\n",transaksi,nilai,saldo);
		saldo_save=saldo;
	}
	fclose(fp);
	return saldo_save;
}
void simpan_saldo_akhir(char no_rekening[10], int setor_kah, int nilai, int saldo){
	FILE * fp;
	fp= fopen(no_rekening,"a");
	
	if (setor_kah){
		saldo=saldo +nilai;
		fprintf(fp,"%12s %10d %12d \n","setor",nilai,saldo);
	} else{
		saldo=saldo -nilai;
		fprintf(fp,"%12s %10d %12d \n","tarik",nilai,saldo);
	}
	fclose(fp);
}
void nasabah_baru(){
	char no_rekening[10];
	char nama[50];
	int nilai;
	
	printf("\n\nMasukkan nama : ");
	scanf("%s",nama);
	
	printf("Masukkan no rekening baru (max 10 char) : ");
	scanf("%s",no_rekening);

	simpan_data_nasabah( no_rekening,  nama);	
	
	printf("Nilai setor awal : ");
	scanf("%d",&nilai);
	
	simpan_saldo_akhir( no_rekening,  1,  nilai,  0);
}
void transaksi(){
	int nilai,setor_kah,saldo;
	char mode;
	char no_rekening[10];

 	printf("\n\nMasukkan no rekening : ");
	scanf("%s",no_rekening);
	
	printf("Nilai transaksi : ");
	scanf("%d",&nilai);	
	
	printf("1. Tarik?\n2. Setor?");
	mode=getche();
	if(mode=='1'){
		setor_kah=0;
	}else if(mode=='2'){
		setor_kah=1;
	}
	saldo =baca_saldo_akhir(no_rekening);
	simpan_saldo_akhir( no_rekening,  setor_kah,  nilai,  saldo);
}

void searchByNoRekeningPrintNama()
{

   printf("\n\n\n\t\tINFO DATA NASABAH \n\n");
   char x, no_rekening[10];
   FILE *ptr;

   printf("\n\nMasukkan No Rekening >> ");
   gets(no_rekening);
   ptr = fopen(no_rekening, "r");
   
   if (ptr == 0)
   {
      printf("Data Tidak Di temukan \n");
      exit(1);
   }

   printf("\n\n\t\t  DATA NASABAH  \n\n");
   printf("  TRANSAKSI \t SALDO AWAL   SALDO AKHIR   NAMA\n\n");

   while((x = fgetc(ptr)) != EOF)
      printf("%c", x);

   fclose(ptr);

}



