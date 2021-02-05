#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Modular
void DisplayPlayerMenu();
void DisplayAbout();
void DisplayHelp();
void PlayerVSComputer();
void PlayerVSPlayer();

//Variabel Global
int PlayerOption, LevelOption, GridOption;
char NamePlayer1[10], NamePlayer2[10];
char Symbol[8][8] = {
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					};

//Program Utama
int main(){
	int MainOption;
	
	puts("Selamat Datang di Permainan Tic Tac Toe");
	do{
		puts("Menu :");
		puts("[1] Main");
		puts("[2] Tentang");
		puts("[3] Bantuan");
		puts("[4] Keluar");
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
		puts("[1] 1 Player");
		puts("[2] 2 Player");
		printf("Masukkan pilihan : ");
		scanf("%d", &PlayerOption);
		
		if(PlayerOption == 1){
			PlayerVSComputer();
		}else if(PlayerOption == 2){
			PlayerVSPlayer();
		}else{
			system("cls");
			puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while((PlayerOption < 1) || (PlayerOption > 2));
}

//Modul untuk Program Player VS Komputer
void PlayerVSComputer(){
	system("cls");
	
	int i, Player = 1, Choice;
	
	//Memanggil Modul Pilihan Level
	DisplayLevelMenu();
	
	//Memanggil Modul Pilihan Grid
	DisplayGridMenu();
	
	//Memasukkan Nama Player 1
	DisplayNamePlayerInput();
	
	//Algoritma Permainan Dimulai
}

//Modul untuk Program Player VS Player
void PlayerVSPlayer(){
	system("cls");
	
	int i, Player = 1, Choice;
	
	//Memanggil Modul Pilihan Grid
	DisplayGridMenu();
	
	//Memasukkan Nama Player 2
	DisplayNamePlayerInput();
	
	//Algoritma Permainan Dimulai
	switch(GridOption){
		case 1:
			//Algoritma untuk Pilihan Kisi 3x3
			break;
		case 2:
			//Algoritma untuk Pilihan Kisi 5x5
			Grid5();
			break;
		case 3:
			//Algoritma untuk Pilihan Kisi 7x7
			break;
	}
}

//Modul untuk Tampilan Pilihan Level pada Player VS Komputer
int DisplayLevelMenu(){
	system("cls");
	
	do{
		puts("Level");
		puts("[1] Mudah");
		puts("[2] Normal");
		puts("[3] Sulit");
		printf("Masukkan pilihan : ");
		scanf("%d", &LevelOption);
		
		if((LevelOption < 1) || (LevelOption > 3)){
			system("cls");
			puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while((LevelOption < 1) || (LevelOption > 3));
}

//Modul untuk Tampilan Pilihan Kisi
int DisplayGridMenu(){
	system("cls");
	
	do{
		puts("Kisi :");
		puts("[1] 3x3");
		puts("[2] 5x5");
		puts("[3] 7x7");
		printf("Masukkan pilihan : ");
		scanf("%d", &GridOption);
		
		if((GridOption < 1) || (GridOption > 3)){
			system("cls");
			puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while((GridOption < 1) || (GridOption > 3));
}

//Modul untuk Input Nama Player
int DisplayNamePlayerInput(){
	system("cls");
	
	if(PlayerOption == 1){
		printf("Masukkan nama player 1 : ");
		scanf("%s", NamePlayer1);
	}
	else{
		printf("Masukkan nama player 1 : ");
		scanf("%s", NamePlayer1);
		printf("Masukkan nama player 2 : ");
		scanf("%s", NamePlayer2);
	}
}

//Modul untuk Tampilan Kisi 5x5
void Grid5(){
	system("cls");
	
	int i;
	
	puts("====== Tic Tac Toe 5x5 ======");
	
	printf("Player 1 (X) \t\t Player 2 (O)\n");
	printf("%s \t\t\t %s\n\n", NamePlayer1, NamePlayer2);
	
	printf("    ");
	for(i = 1; i <= 5; i++){
		printf("  %d   ", i);
	}
	printf("\n");
	puts("    _____ _____ _____ _____ _____ ");
	for(i = 0; i < 5; i++){
		printf("   |     |     |     |     |     |\n");
		printf("%d  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", i+1, Symbol[i][0], Symbol[i][1], Symbol[i][2], Symbol[i][3], Symbol[i][4]);
		printf("   |_____|_____|_____|_____|_____|\n");
	}
}


//Modul untuk Tampilan Tentang
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
	
	printf("\n");
	puts("[1] Kembali");
	puts("[2] Keluar");
	
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

//Modul untuk Tampilan Bantuan
void DisplayHelp(){
	system("cls");
	char teks[150];
	
	FILE * FBantuan;
	
	FBantuan = fopen("bantuan.txt","r");
	
	while(!feof(FBantuan)){
		fgets(teks, 150, FBantuan);
		puts(teks);
	}
	
	fclose(FBantuan);
	
	int HelpOption;
	
	printf("\n");
	puts("[1] Kembali");
	puts("[2] Keluar");
	
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
