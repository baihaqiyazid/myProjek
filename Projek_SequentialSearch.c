#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void seqSearchTanpaSentinel(int array[], int N, int searchkey);
void seqSearchDenganSentinel(int array[],int N, int searchkey);
void seqSearchDenganBoolean(int array[], int N, int searchkey);
void getRandomArrayOfInteger(int **a,long n);

void getRandomArrayOfInteger(int **a,long n){
	int * array= (int *) malloc(sizeof(int)*n);	
	long i;
    time_t t;     
    /* Intializes random number generator */
    srand((unsigned) time(&t));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < n ; i++ ) {
      array[i]= rand()%10000;
   }
   *a=array;
}

int main(int argc, char *argv[]) {
	int *a ;
	long n=1000*1000*1000;
	
	getRandomArrayOfInteger(&a,n);

	printf("\nSeq search no sentinel\n");	
	seqSearchTanpaSentinel(a,n,3);
	seqSearchTanpaSentinel(a,n,99);
			
	printf("\nSeq search with sentinel\n");
	seqSearchDenganSentinel(a,n,3);
	seqSearchDenganSentinel(a,n,99);
	
	printf("\nSeq search with boolean\n");	
	seqSearchDenganBoolean(a,n,3);
	seqSearchDenganBoolean(a,n,99);
	
	return 0;
}

void seqSearchTanpaSentinel(int array[], int N, int searchkey){
	int i=0;
	
	while( (array[i] != searchkey) && (i<N)){
		i++;
	}
	
	if(array[i]==searchkey)
	{
		printf("Data %d ditemukan di index %d\n", searchkey, i);
	}
	else
	{
		printf("Data %d tidak ditemukan\n", searchkey);
	}
}

void seqSearchDenganSentinel(int array[], int N, int searchkey){
	array[N]=searchkey;
	int i = 0;
	
//	array[maks_array+1] = searchkey;
	while((array[i] != searchkey)){
		i++;
	}
	if (i < N){
	
		printf("Data %d ditemukan pada index %d\n", searchkey,i);
	}
	else{
		
		printf("Data %d tidak ditemukan\n", searchkey);
	}
}

void seqSearchDenganBoolean(int array[], int N, int searchkey){

	int i = 0;
	int found = 0;
	
	while ( !found && i <= N){
		if (array[i] == searchkey){
			found = 1;
		}
		else{
			i++;
		}
		
	} 
	
	if(found==1){
	
		printf("Data %d ditemukan pada index %d\n", searchkey,i);
	}
	else{
	
	printf("Data %d tidak ditemukan\n", searchkey);
	}
}

