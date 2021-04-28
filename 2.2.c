#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
	int NO;
	char Nama[30];
	int Nilai;
} siswa;

void menu(siswa Data[]);
void tampil(siswa Data[]);

int pilihan, n;

int main(){
	siswa Data[MAX], Data2[MAX];
	
	printf("%-25s", "Panjang Array"); printf(": ");
	scanf("%d", &n);
	fflush(stdin);
	
	alokasi(Data2);
	
	do {
		copyData(Data2, Data);
		printf("%-25s", "Data array awal"); printf(": ");
		tampil(Data);
		menu(Data);
		printf("%-25s", "Data array terurut"); printf(": ");
		tampil(Data);
	} while(pilihan != 3);
}

int copyData(siswa Data2[], siswa Data[]){
	int i;
	
	for(i=0; i<n; i++){
		Data[i].NO = Data2[i].NO;
		strcpy(Data[i].Nama, Data2[i].Nama);
		Data[i].Nilai = Data2[i].Nilai;
	}
}

int alokasi(siswa Data2[]){
	int i;
	
	for(i=0; i<n; i++){
		printf("Data Array ke %d \n", i+1);
		printf("%-10s", "NO"); printf(": ");
		scanf("%d", &Data2[i].NO);
		fflush(stdin);
		printf("%-10s", "Nama"); printf(": ");
		scanf("%s", &Data2[i].Nama);
		fflush(stdin);
		printf("%-10s", "Nilai"); printf(": ");
		scanf("%d", &Data2[i].Nilai);
		fflush(stdin);
	}
}

void menu(siswa Data[]){
	int ascDesc;
	printf("========================\n");
	printf(" MENU METODE SORTING\n");
	printf("========================\n");
	printf("1. Insertion Sort\n");
	printf("2. Selection Sort\n");
	printf("3. Keluar\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &pilihan);
	fflush(stdin);
	
	if(pilihan == 3)
		exit(0);
		
	ascDesc = modeUrut();
		
	switch(pilihan){
		case 1:
			insertion(Data, ascDesc);
			break;
		case 2:
			selection(Data, ascDesc);
			break;
	}
}

int modeUrut(){
	int ascDesc;
	printf("========================\n");
	printf(" MENU MODE SORTING\n");
	printf("========================\n");
	printf("1. Ascending\n");
	printf("2. Descending\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &ascDesc);
	fflush(stdin);
	
	return(ascDesc);
}

int insertion(siswa Data[], int ascDesc){
	
	int i, j;
	siswa key;
	
	for(i=1; i<n; i++){
		key = Data[i];
		j = i - 1;
		while(j >= 0 && (Data[j].NO > key.NO && ascDesc == 1 || Data[j].NO < key.NO && ascDesc == 2)){
			Data[j+1] = Data[j];
			j = j - 1;
		}
		Data[j+1] = key;
	}
}

int selection(siswa Data[], int ascDesc){
	
	int i,j, x, kondisi;
    for(i=0; i<n-1; i++){
        x = i;
    
        for(j = i+1; j<n; j++){
        	if(ascDesc == 1)
        		kondisi = Data[j].NO < Data[x].NO;
			else 
				kondisi = Data[j].NO > Data[x].NO;

        	if(kondisi){
        		x = j;
			}
		}
        tukar(&Data[i], &Data[x]);
    }
	
}

int tukar(siswa *a, siswa *b){
	siswa temp;
	
    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(siswa Data[]){
	int i;
	printf("\n");
	printf("%-5s", "NO"); printf("%-15s", "Nama"); printf("%-10s", "Nilai");
	for(i=0; i<n; i++){
		printf("\n");
		printf("%-5d ", Data[i].NO); printf("%-15s ", Data[i].Nama); printf("%-10d ", Data[i].Nilai);
	}
	printf("\n\n");
}
