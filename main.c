#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Deklarasi Modular
void DisplayPlayerMenu();
void DisplayHighscore();
void DisplayAbout();
void DisplayHelp();
void PlayerVSComputer();
void PlayerVSPlayer();
void Grid3();
void Grid5();
void Grid7();
void PlayGame3PVP();
void PlayGame5PVP();
void PlayGame7PVP();
int CheckWin3();
int CheckWin5();
int CheckWin7();
int Score(int InitialScore, int ActionCount, float AverageTime);
void SaveHighscore(int Highscore, int player, int ActionCount, float AverageTime);
int *Timer(unsigned int sec);

//Variabel Global
int PlayerOption, LevelOption, GridOption;
char Symbol[7][7] = {
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					 	{' ', ' ', ' ', ' ', ' ', ' ', ' '},
					};

typedef struct{
	char Name[20];
	int InitialScore;
	int ActionCount;
	float AverageTime;
	int Highscore;
}Player;					

Player Player1, Player2, PlayerComputer;

//Program Utama
int main(){
	system("cls");
	int MainOption;
	
	puts("Selamat Datang di Permainan Tic Tac Toe");
	do{
		puts("Menu");
		puts("[1] Mulai");
		puts("[2] Riwayat Skor");
		puts("[3] Tentang");
		puts("[4] Bantuan");
		puts("[5] Keluar");
		printf("Masukkan pilihan : ");
		scanf("%d", &MainOption);
		
		switch(MainOption){
			case 1:
				DisplayPlayerMenu();
				break;
			case 2:
				DisplayHighscore();
				break;
			case 3:
				DisplayAbout();
				break;
			case 4:
				DisplayHelp();
				break;
			case 5:
				system("cls");
				printf("Terima Kasih");
				exit(0);
			default:
				system("cls");
				puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
				break;
		}
	}while((MainOption < 1) || (MainOption > 5));
	
	return 0;
}

//Modul untuk Tampilan Pilihan Jumlah Player
void DisplayPlayerMenu(){
	system("cls");
	do{
		puts("Mode Permainan");
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
		puts("Kisi");
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
	
	printf("Nama Player\n");
	if(PlayerOption == 1){
		PlayerComputer.Name = "Komputer";
		printf("Masukkan nama player 1 : ");
		scanf("%s", Player1.Name);
	}
	else{
		printf("Masukkan nama player 1 : ");
		scanf("%s", Player1.Name);
		printf("Masukkan nama player 2 : ");
		scanf("%s", Player2.Name);
	}
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
	
	//Memanggil Modul Pilihan Grid
	DisplayGridMenu();
	
	//Memasukkan Nama Player 2
	DisplayNamePlayerInput();
	
	//Algoritma Permainan Dimulai
	if(GridOption == 1){
		Player1.InitialScore = Player2.InitialScore = 9;
		PlayGame3PVP();
	}else if(GridOption == 2){
		Player1.InitialScore = Player2.InitialScore = 25;
		PlayGame5PVP();
	}else{
		Player1.InitialScore = Player2.InitialScore = 49;
		PlayGame7PVP();
	}
}

/*======================================================
		MODUL-MODUL UNTUK SAAT PERMAINAN DIMULAI		
========================================================*/
//Modul untuk Program Player VS Player 3x3 saat dimulai
void PlayGame3PVP(){
	int column, row, player=1, Done=-1;
	char mark;
	int *ch, remain_time;
	
	do {
		system("cls");
		Grid3();
		player = (player % 2) ? 1 : 2;
		
		if(player == 1){
        	printf(" Giliran Player %d [%s] \n", player, Player1.Name);
		}else{
			printf(" Giliran Player %d [%s] \n", player, Player2.Name);
		}
		printf(" NOTE : Masukan hanya angka tanpa koma dan tanda kurung\n");
		
		//Inputan dari Pemain dengan Timer
		if ((ch = Timer(10)) != 0){
        	row = ch[0]-48;
			column = ch[1]-48;
			remain_time = ch[2];
        }
	    else{
	        printf("Waktu Habis");
			player++;
			continue;
	    }
		
        mark = (player == 1) ? 'X' : 'O';
        
        if((Symbol[row-1][column-1] != 'X') && (Symbol[row-1][column-1] != 'O')){
        	if((row > 0) && (row < 4) && (column > 0) && (column < 4)){
        		Symbol[row-1][column-1] = mark;
				if(player == 1){
        			Player1.InitialScore--;
        			Player1.ActionCount++;
        			Player1.AverageTime += remain_time;
				}else{
					Player2.InitialScore--;
					Player2.ActionCount++;
        			Player2.AverageTime += remain_time;
				}
			}
		}
		else {
			printf("Masukan tidak valid, Silahkan coba lagi.");

            player--;
            getch();
		}
		Done=CheckWin3();
		
		player++;
	}while (Done==-1);
	
	Grid3();
	
	if(Done == 1){
		printf("Player %d Menang\n", --player);
		if(player == 1){
			Player1.Highscore = Score(Player1.InitialScore, Player1.ActionCount, Player1.AverageTime);
			printf("Highscore : %d", Player1.Highscore);
			
			SaveHighscore(Player1.Highscore, player, Player1.ActionCount, Player1.AverageTime);
		}else{
			Player2.Highscore = Score(Player2.InitialScore, Player2.ActionCount, Player2.AverageTime);
			printf("Highscore : %d", Player2.Highscore);
			
			SaveHighscore(Player1.Highscore, player, Player1.ActionCount, Player1.AverageTime);
		}
	}
	else{
		printf("Game Seri\n");
	}
	
	getch();
	exit(0);
}

//Modul untuk Program Player VS Player 5x5 saat dimulai
void PlayGame5PVP(){
	int column, row, player = 1, Done = -1;
	char mark;
	int *ch, remain_time;
	
	do{
		system("cls");
		Grid5();
		player = (player % 2) ? 1 : 2;
		
        if(player == 1){
        	printf(" Giliran Player %d [%s] \n", player, Player1.Name);
		}else{
			printf(" Giliran Player %d [%s] \n", player, Player2.Name);
		}
		printf(" NOTE : Masukan hanya angka tanpa koma dan tanda kurung\n");
		
		//Inputan dari Pemain dengan Timer
		if ((ch = Timer(10)) != 0){
        	row = ch[0]-48;
			column = ch[1]-48;
			remain_time = ch[2];
        }
	    else{
	        printf("Waktu Habis");
			player++;
			continue;
	    }
		
        mark = (player == 1) ? 'X' : 'O';
                
        if((Symbol[row-1][column-1] != 'X') && (Symbol[row-1][column-1] != 'O')){
        	if((row > 0) && (row < 6) && (column > 0) && (column < 6)){
        		Symbol[row-1][column-1] = mark;
				if(player == 1){
        			Player1.InitialScore--;
        			Player1.ActionCount++;
        			Player1.AverageTime += remain_time;
				}else{
					Player2.InitialScore--;
					Player2.ActionCount++;
        			Player2.AverageTime += remain_time;
				}
			}
		}
		else {
			printf("Masukan tidak valid, Silahkan coba lagi.");

            player--;
            getch();
		}
		Done = CheckWin5();
		
		player++;
	}while(Done == -1);
	
	Grid5();
	
	if(Done == 1){
		printf("Player %d Menang\n", --player);
		if(player == 1){
			Player1.Highscore = Score(Player1.InitialScore, Player1.ActionCount, Player1.AverageTime);
			printf("Highscore : %d", Player1.Highscore);
			
			SaveHighscore(Player1.Highscore, player, Player1.ActionCount, Player1.AverageTime);
		}else{
			Player2.Highscore = Score(Player2.InitialScore, Player2.ActionCount, Player2.AverageTime);
			printf("Highscore : %d", Player2.Highscore);
			
			SaveHighscore(Player1.Highscore, player, Player1.ActionCount, Player1.AverageTime);
		}
	}
	else{
		printf("Game Seri\n");
	}
	
	getch();
	exit(0);
}

//Modul untuk Program Player VS Player 7x7 saat dimulai
void PlayGame7PVP(){
	int column, row, player = 1, Done = -1;
	char mark;
	int *ch, remain_time;
	
	do{
		system("cls");
		Grid7();
		player = (player % 2) ? 1 : 2;
		
        if(player == 1){
        	printf(" Player %d [%s], Masukkan Angka (Baris, Kolom) tanpa Tanda Kurung :  ", player, Player1.Name);
		}else{
			printf(" Player %d [%s], Masukkan Angka (Baris, Kolom) tanpa Tanda Kurung :  ", player, Player2.Name);
		}
		
        if(player == 1){
        	printf(" Giliran Player %d [%s] \n", player, Player1.Name);
		}else{
			printf(" Giliran Player %d [%s] \n", player, Player2.Name);
		}
		printf(" NOTE : Masukan hanya angka tanpa koma dan tanda kurung\n");
		
		//Inputan dari Pemain dengan Timer
		if ((ch = Timer(10)) != 0){
        	row = ch[0]-48;
			column = ch[1]-48;
			remain_time = ch[2];
        }
	    else{
	        printf("Waktu Habis");
			player++;
			continue;
	    }
		
        mark = (player == 1) ? 'X' : 'O';
                
        if((Symbol[row-1][column-1] != 'X') && (Symbol[row-1][column-1] != 'O')){
        	if((row > 0) && (row < 8) && (column > 0) && (column < 8)){
        		Symbol[row-1][column-1] = mark;
				if(player == 1){
        			Player1.InitialScore--;
        			Player1.ActionCount++;
        			Player1.AverageTime += remain_time;
				}else{
					Player2.InitialScore--;
					Player2.ActionCount++;
        			Player2.AverageTime += remain_time;
				}
			}
		}
		else {
			printf("Masukan tidak valid, Silahkan coba lagi.");

            player--;
            getch();
		}
		Done = CheckWin7();
		
		player++;
	}while(Done == -1);
	
	Grid7();
	
	if(Done == 1){
		printf("Player %d Menang\n", --player);
		if(player == 1){
			Player1.Highscore = Score(Player1.InitialScore, Player1.ActionCount, Player1.AverageTime);
			printf("Highscore : %d", Player1.Highscore);
			
			SaveHighscore(Player1.Highscore, player, Player1.ActionCount, Player1.AverageTime);
		}else{
			Player2.Highscore = Score(Player2.InitialScore, Player2.ActionCount, Player2.AverageTime);
			printf("Highscore : %d", Player2.Highscore);
			
			SaveHighscore(Player1.Highscore, player, Player1.ActionCount, Player1.AverageTime);
		}
	}
	else{
		printf("Game Seri\n");
	}
	
	getch();
	exit(0);
}

/*=============================================================
		MODUL-MODUL UNTUK TAMPILAN KISI/PAPAN PERMAINAN		   
===============================================================*/
//Modul untuk Tampilan Kisi 3x3
void Grid3(){
	system("cls");
	
	int i;
	
	puts(" ===================================");
	puts("          TIC TAC TOE 3X3           ");
	puts(" ===================================");
	
	printf("Player 1 (X) \t\t Player 2 (O)\n");
	printf("%s \t\t\t %s\n\n", Player1.Name, Player2.Name);
	
	printf("    ");
	for(i = 1; i <= 3; i++){
		printf("  %d   ", i);
	}
	printf("\n");
	puts("    _____ _____ _____  ");
	for(i = 0; i < 3; i++){
		printf("   |     |     |     |\n");
		printf("%d  |  %c  |  %c  |  %c  |\n", i+1, Symbol[i][0], Symbol[i][1], Symbol[i][2]);
		printf("   |_____|_____|_____|\n");
	}
}

//Modul untuk Tampilan Kisi 5x5
void Grid5(){
	system("cls");
	
	int i;
	
	puts(" ===================================");
	puts("          TIC TAC TOE 5X5           ");
	puts(" ===================================");
	
	printf(" Player 1 (X) \t\t Player 2 (O)\n");
	printf(" %s \t\t\t %s\n\n", Player1.Name, Player2.Name);
	
	printf("     ");
	for(i = 1; i <= 5; i++){
		printf("  %d   ", i);
	}
	printf("\n");
	puts("     _____ _____ _____ _____ _____ ");
	for(i = 0; i < 5; i++){
		printf("    |     |     |     |     |     |\n");
		printf(" %d  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", i+1, Symbol[i][0], Symbol[i][1], Symbol[i][2], Symbol[i][3], Symbol[i][4]);
		printf("    |_____|_____|_____|_____|_____|\n");
	}
	printf("\n");
}

//Modul untuk Tampilan Kisi 7x7
void Grid7(){
	system("cls");
	
	int i;
	
	puts(" ==============================================");
	puts("                TIC TAC TOE 7X7                ");
	puts(" ==============================================");
	
	printf(" Player 1 (X) \t\t Player 2 (O)\n");
	printf(" %s \t\t\t %s\n\n", Player1.Name, Player2.Name);
	
	printf("     ");
	for(i = 1; i <= 7; i++){
		printf("  %d   ", i);
	}
	printf("\n");
	puts("     _____ _____ _____ _____ _____ _____ _____ ");
	for(i = 0; i < 7; i++){
		printf("    |     |     |     |     |     |     |     |\n");
		printf(" %d  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", i+1, Symbol[i][0], Symbol[i][1], Symbol[i][2], Symbol[i][3], Symbol[i][4], Symbol[i][5], Symbol[i][6]);
		printf("    |_____|_____|_____|_____|_____|_____|_____|\n");
	}
	printf("\n");
}

//Modul untuk Timer
int *Timer(unsigned int sec){
	int count = 0;
	int set[3];
	
	while(sec > 0){
		printf("\r [Sisa Waktu : %2d] Masukkan Angka (Baris, Kolom): ", sec);
		if(kbhit()){
			if(count==0){
				set[0] = getch();
				printf("%c,", set[0]);
			}else{
				set[1] = getch();
				printf("%c,%c", set[0], set[1]);
				set[2] = sec;
				return set;
			}
			count++;
		}
		sec--;
		Sleep(1000);
	}
}

/*========================================================
	MODUL-MODUL UNTUK MENGECEK KEMENANGAN
	Fungsi untuk mengembalikan status permainan, dengan kondisi :
	1, maka permainan berakhir dengan salah satu pemain menang;
	0, maka game berakhir dengan kedua pemain seri; atau
	-1, maka permainan masih berlanjut. 
==========================================================*/
//Modul untuk Memeriksa Kemenangan pad Kisi 3x3
int CheckWin3(){
	int i=0, j=0, seri=0;
	
	//Kondisi Menang
	/*Untuk Horizontal*/
	for (i=0; i<3; i++){
		if ( (Symbol[i][j] == Symbol[i][j+1]) && (Symbol[i][j+1]==Symbol[i][j+2]) ){
			if ((Symbol[i][j]!=' ') && (Symbol[i][j+1]!=' ') && (Symbol[i][j+2]!=' ')){
				return 1;
			}
		}
	}	
	/*Untuk Vertikal*/
	for (i=0; i<3; i++){
		if ( (Symbol[j][i] == Symbol[j+1][i]) && (Symbol[j+1][i] == Symbol[j+2][i]) ){
			if ((Symbol[i][j]!=' ')&&(Symbol[j+1][i]!=' ')&&(Symbol[j+2][i]!=' ')){
				return 1;
			}
		}
	}	
	/*Untuk Diagonal*/
	i=0;
	j=0;
	if ((Symbol[j][i]==Symbol[j+1][i+1])&&(Symbol[j+1][i+1]==Symbol[j+2][i+2])){
		if (Symbol[j][i]!=' '){
			return 1;
		}
	}
	else if ((Symbol[j][i+2]==Symbol[j+1][i+1])&&(Symbol[j+1][i+1]==Symbol[j+2][i])){
		if (Symbol[j+1][i+1]!=' '){
			return 1;
		}
	}	
	
	//Kondisi Seri
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			if ((Symbol[i][j]=='X') || (Symbol[i][j]=='O')){
				seri++;
			}
		}
	}
	if (seri==9){
		return 0;
	}
	else return -1;
}

//Modul untuk Memeriksa Kemenangan pada Kisi 5x5
int CheckWin5(){
	int i, j;
	//Kondisi Menang
	/*Horizontal*/
	for(i = 0; i < 5; i++){
		for(j = 0; j < 2; j++){
			if((Symbol[i][j] == Symbol[i][j+1]) && (Symbol[i][j] == Symbol[i][j+2]) && (Symbol[i][j] == Symbol[i][j+3])){
				if((Symbol[i][j] != ' ') && (Symbol[i][j+1] != ' ') && (Symbol[i][j+2] != ' ') && (Symbol[i][j+3] != ' ')){
					return 1;
				}
			}
		}
	}	
	/*Vertikal*/
	for(j = 0; j < 5; j++){
		for(i = 0; i < 2; i++){
			if((Symbol[i][j]) == (Symbol[i+1][j]) && (Symbol[i][j]) == (Symbol[i+2][j]) && (Symbol[i][j]) == (Symbol[i+3][j])){
				if((Symbol[i][j] != ' ') && (Symbol[i+1][j] != ' ') && (Symbol[i+2][j] != ' ') && (Symbol[i+3][j] != ' ')){
					return 1;
				}
			}
		}
	}	
	/*Untuk Diagonal*/
	i=0;
	j=0;
	/*0,0 - 3,3*/
	if((Symbol[i][j] == Symbol[i+1][j+1]) && (Symbol[i+1][j+1] == Symbol[i+2][j+2]) && (Symbol[i+2][j+2] == Symbol[i+3][j+3])){
		if(Symbol[j][i] != ' '){
			return 1;
		}
	}
	/*Diagonal Utama*/
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			if((Symbol[i][j]) == (Symbol[i+1][j+1]) && (Symbol[i][j]) == (Symbol[i+2][j+2]) && (Symbol[i][j]) == (Symbol[i+3][j+3])){
				if((Symbol[i][j] != ' ') && (Symbol[i+1][j+1] != ' ') && (Symbol[i+2][j+2] != ' ') && (Symbol[i+3][j+3] != ' ')){
					return 1;
				}
			}
		}
	}
	/*Diagonal Sekunder*/
	for(i = 0; i < 3; i++){
		for(j = 3; j < 5; j++){
			if((Symbol[i][j]) == (Symbol[i+1][j-1]) && (Symbol[i][j]) == (Symbol[i+2][j-2]) && (Symbol[i][j]) == (Symbol[i+3][j-3])){
				if((Symbol[i][j] != ' ') && (Symbol[i+1][j-1] != ' ') && (Symbol[i+2][j-2] != ' ') && (Symbol[i+3][j-3] != ' ')){
					return 1;
				}
			}
		}
	}
	
	//Kondisi Seri
	if((Symbol[0][0] != ' ') && (Symbol[0][1] != ' ') && (Symbol[0][2] != ' ') && (Symbol[0][3] != ' ') && (Symbol[0][4] != ' ') &&
	(Symbol[1][0] != ' ') && (Symbol[1][1] != ' ') && (Symbol[1][2] != ' ') && (Symbol[1][3] != ' ') && (Symbol[1][4] != ' ') &&
	(Symbol[2][0] != ' ') && (Symbol[2][1] != ' ') && (Symbol[2][2] != ' ') && (Symbol[2][3] != ' ') && (Symbol[2][4] != ' ') &&
	(Symbol[3][0] != ' ') && (Symbol[3][1] != ' ') && (Symbol[3][2] != ' ') && (Symbol[3][3] != ' ') && (Symbol[3][4] != ' ') &&
	(Symbol[4][0] != ' ') && (Symbol[4][1] != ' ') && (Symbol[4][2] != ' ') && (Symbol[4][3] != ' ') && (Symbol[4][4] != ' ')){
		return 0;
	}
	else{
		return -1;
	}
}

//Modul untuk Memeriksa Kemenangan pada Kisi 7x7
int CheckWin7(){
	int i, j;
	//Kondisi Menang
	/*Horizontal*/
	for(i = 0; i < 7; i++){
		for(j = 0; j < 4; j++){
			if((Symbol[i][j] == Symbol[i][j+1]) && (Symbol[i][j] == Symbol[i][j+2]) && (Symbol[i][j] == Symbol[i][j+3]) && (Symbol[i][j] == Symbol[i][j+4])){
				if((Symbol[i][j] != ' ') && (Symbol[i][j+1] != ' ') && (Symbol[i][j+2] != ' ') && (Symbol[i][j+3] != ' ') && (Symbol[i][j+4] != ' ')){
					return 1;
				}
			}
		}
	}	
	/*Vertikal*/
	for(j = 0; j < 7; j++){
		for(i = 0; i < 4; i++){
			if((Symbol[i][j]) == (Symbol[i+1][j]) && (Symbol[i][j]) == (Symbol[i+2][j]) && (Symbol[i][j]) == (Symbol[i+3][j]) && (Symbol[i][j]) == (Symbol[i+4][j])){
				if((Symbol[i][j] != ' ') && (Symbol[i+1][j] != ' ') && (Symbol[i+2][j] != ' ') && (Symbol[i+3][j] != ' ') && (Symbol[i+4][j] != ' ')){
					return 1;
				}
			}
		}
	}	
	/*Diagonal Utama*/
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if((Symbol[i][j]) == (Symbol[i+1][j+1]) && (Symbol[i][j]) == (Symbol[i+2][j+2]) && (Symbol[i][j]) == (Symbol[i+3][j+3]) && (Symbol[i][j]) == (Symbol[i+4][j+4])){
				if((Symbol[i][j] != ' ') && (Symbol[i+1][j+1] != ' ') && (Symbol[i+2][j+2] != ' ') && (Symbol[i+3][j+3] != ' ') && (Symbol[i+4][j+4] != ' ')){
					return 1;
				}
			}
		}
	}
	/*Diagonal Sekunder*/
	for(i = 0; i < 3; i++){
		for(j = 4; j < 7; j++){
			if((Symbol[i][j]) == (Symbol[i+1][j-1]) && (Symbol[i][j]) == (Symbol[i+2][j-2]) && (Symbol[i][j]) == (Symbol[i+3][j-3]) && (Symbol[i][j]) == (Symbol[i+4][j-4])){
				if((Symbol[i][j] != ' ') && (Symbol[i+1][j-1] != ' ') && (Symbol[i+2][j-2] != ' ') && (Symbol[i+3][j-3] != ' ') && (Symbol[i+4][j-4] != ' ')){
					return 1;
				}
			}
		}
	}
	
	//Kondisi Seri
	if((Symbol[0][0] != ' ') && (Symbol[0][1] != ' ') && (Symbol[0][2] != ' ') && (Symbol[0][3] != ' ') && (Symbol[0][4] != ' ') && (Symbol[0][5] != ' ') && (Symbol[0][6] != ' ') &&
	(Symbol[1][0] != ' ') && (Symbol[1][1] != ' ') && (Symbol[1][2] != ' ') && (Symbol[1][3] != ' ') && (Symbol[1][4] != ' ') && (Symbol[1][5] != ' ') && (Symbol[1][6] != ' ') &&
	(Symbol[2][0] != ' ') && (Symbol[2][1] != ' ') && (Symbol[2][2] != ' ') && (Symbol[2][3] != ' ') && (Symbol[2][4] != ' ') && (Symbol[2][5] != ' ') && (Symbol[2][6] != ' ') &&
	(Symbol[3][0] != ' ') && (Symbol[3][1] != ' ') && (Symbol[3][2] != ' ') && (Symbol[3][3] != ' ') && (Symbol[3][4] != ' ') && (Symbol[3][5] != ' ') && (Symbol[3][6] != ' ') &&
	(Symbol[4][0] != ' ') && (Symbol[4][1] != ' ') && (Symbol[4][2] != ' ') && (Symbol[4][3] != ' ') && (Symbol[4][4] != ' ') && (Symbol[4][5] != ' ') && (Symbol[4][6] != ' ') &&
	(Symbol[5][0] != ' ') && (Symbol[5][1] != ' ') && (Symbol[5][2] != ' ') && (Symbol[5][3] != ' ') && (Symbol[5][4] != ' ') && (Symbol[5][5] != ' ') && (Symbol[5][6] != ' ') &&
	(Symbol[6][0] != ' ') && (Symbol[6][1] != ' ') && (Symbol[6][2] != ' ') && (Symbol[6][3] != ' ') && (Symbol[6][4] != ' ') && (Symbol[6][5] != ' ') && (Symbol[6][6] != ' ')){
		return 0;
	}
	else{
		return -1;
	}
}

//Modul untuk Menghitung Skor Akhir Pemenang
int Score(int InitialScore, int ActionCount, float AverageTime){
	int Result = InitialScore * ((int)AverageTime/ActionCount) * 4;
	
	return Result;
}

//Modul untuk Menyimpan Data Pemain yang Menang
void SaveHighscore(int Highscore, int player, int ActionCount, float AverageTime){
	FILE * FHighscore = fopen("highscore.txt", "a");
	
	if(GridOption == 1){
		if(PlayerOption == 1){
		
		}else{
			if(player == 1){
				fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t3x3", Player1.Name, player, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
			}else{
				fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t3x3", Player2.Name, player, Player2.Highscore, Player2.ActionCount, Player2.AverageTime/(float)Player2.ActionCount);
			}
		}
	}else if(GridOption == 2){
		if(PlayerOption == 1){
		
		}else{
			if(player == 1){
				fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t5x5", Player1.Name, player, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
			}else{
				fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t5x5", Player2.Name, player, Player2.Highscore, Player2.ActionCount, Player2.AverageTime/(float)Player2.ActionCount);
			}
		}
	}else{
		if(PlayerOption == 1){
		
		}else{
			if(player == 1){
				fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t7x7", Player1.Name, player, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
			}else{
				fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t7x7", Player2.Name, player, Player2.Highscore, Player2.ActionCount, Player2.AverageTime/(float)Player2.ActionCount);
			}
		}
	}
	
    fclose(FHighscore);
}

void DisplayHighscore(){
	system("cls");
	int HighscoreListOption;
	char teks[150];
	
	FILE * FHighscore;
	
	printf("NAMA\t\t\tPLAYER\t\tHIGHSCORE\tAKSI\t\tRATA-RATA WAKTU");
	
	if ((FHighscore = fopen("highscore.txt","r")) == NULL){
        printf("Error: File tidak ada!");
    }else{
    	while(!feof(FHighscore)){
			fgets(teks, 150, FHighscore);
			printf(teks);
		}
	}
	
    fclose(FHighscore);
    
    printf("\n\n");
	puts("[1] Kembali");
	puts("[2] Keluar");
	do{
		printf("Masukkan pilihan : ");
		scanf("%d", &HighscoreListOption);
		
		switch(HighscoreListOption){
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
	}while((HighscoreOption < 1) || (HighscoreOption > 2));
}

//Modul untuk Tampilan Tentang
void DisplayAbout(){
	system("cls");
	char teks[150];
	
	FILE * FTentang;
	
	if((FTentang = fopen("tentang.txt","r")) == NULL){
        printf("Error: File tidak ada!");
    }else{
    	while(!feof(FTentang)){
			fgets(teks, 150, FTentang);
			puts(teks);
		}
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
	
	if((FBantuan = fopen("bantuan.txt","r")) == NULL){
        printf("Error: File tidak ada!");
    }else{
    	while(!feof(FBantuan)){
			fgets(teks, 150, FBantuan);
			puts(teks);
		}
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
