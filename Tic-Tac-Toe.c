#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Modular
void DisplayPlayerMenu();
void DisplayAbout();
void DisplayHelp();

//Variabel Global
int PlayerOption;

//Program Utama
int main(){
	int MainOption;
	
	puts("Selamat Datang di Permainan Tic Tac Toe");
	do{
		puts("Menu :");
		puts("1. Main");
		puts("2. Tentang");
		puts("3. Bantuan");
		puts("4. Keluar");
		printf("Masukkan pilihan : ");
		scanf("%d", &MainOption);
		
		if(MainOption == 1){
			DisplayPlayerMenu();
		}else if(MainOption == 2){
			DisplayAbout();
		}else if(MainOption == 3){
			DisplayHelp();
		}else if(MainOption == 4){
			system("cls");
			printf("Terima Kasih");
			exit(0);
		}else{
			system("cls");
			puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while((MainOption < 1) || (MainOption > 4));
	
	return 0;
}

//Tampilan Pilihan Jumlah Player
void DisplayPlayerMenu(){
	system("cls");
	do{
		puts("Jumlah Player");
		puts("1. 1 Player");
		puts("2. 2 Player");
		printf("Masukkan pilihan : ");
		scanf("%d", &PlayerOption);
		
		if(PlayerOption == 1){

		}else if(PlayerOption == 2){
			
		}else{
			system("cls");
			puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while((PlayerOption < 1) || (PlayerOption > 2));
}

//Tampilan Tentang
void DisplayAbout(){
	system("cls");
	char teks[150];
	FILE * FTentang;
	
	FTentang = fopen("tentang.txt","r");
	
	while(!feof(FTentang)){
		fgets(teks, 150, FTentang);
		puts(teks);
	}
	
	fclose(FTentang);
	
	int AboutOption;
	
	puts("1. Kembali");
	puts("2. Keluar");
	
	do{
		printf("Masukkan pilihan : ");
		scanf("%d", &AboutOption);
		
		switch(AboutOption){
			case 1:
				system("cls");
				main();
				break;
			case 2:
				exit(0);
				break;
			default:
				puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while((AboutOption < 1) || (AboutOption > 2));
}

//Tampilan Bantuan
void DisplayHelp(){
	system("cls");
	int HelpOption;
	puts("1. Kembali");
	puts("2. Keluar");
	
	do{
		printf("Masukkan pilihan : ");
		scanf("%d", &HelpOption);
		
		switch(HelpOption){
			case 1:
				system("cls");
				main();
				break;
			case 2:
				exit(0);
				break;
			default:
				puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while((HelpOption < 1) || (HelpOption > 2));
}
