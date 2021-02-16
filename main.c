/*
	Author			: Algi Fari Ramdhani & Mochammad Lutfi Faturachman
	Program			: Tic Tac Toe
	Tanggal Dibuat	: 01 Februari 2020
	Compiler		: DevC++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Deklarasi Modular
void DisplayPlayerMenu();
void DisplayHighscoreMenu();
void DisplayHighscore1Player();
void DisplayHighscore2Player();
void DisplayLevelMenu();
void DisplayGridMenu();
void DisplayNamePlayerInput();
void DisplayAbout();
void DisplayHelp();
void PlayerVSComputer();
void PlayerVSPlayer();
void GridBoard();
void PlayGamePVC();
void PlayGamePVP();
void PlayerMove();
void ComputerMoveEasy();
void ComputerMoveNormal();
void ComputerMoveHard();
int CheckWin();
int Score(int Done, int InitialScore, int ActionCount, float AverageTime);
void SaveHighscore(int Highscore, int Result, int ActionCount, float AverageTime);
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
Player Player1, Player2;
int PlayerRow, PlayerColumn;

//Program Utama
int main(){
	system("cls");
	int MainOption;
	
	puts("Selamat Datang di Permainan Tic Tac Toe");
	do{
		puts("Menu Utama");
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
				DisplayHighscoreMenu();
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
				getch();
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
void DisplayLevelMenu(){
	system("cls");
	
	do{
		puts("Level");
		puts("[1] Mudah");
		puts("[2] Normal");
		puts("[3] Sulit");
		printf("Masukkan pilihan : ");
		scanf("%d", &LevelOption);
		
		if(LevelOption > 3){
			system("cls");
			puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while((LevelOption < 1) || (LevelOption > 3));
}

//Modul untuk Tampilan Pilihan Kisi
void DisplayGridMenu(){
	system("cls");
	
	do{
		puts("Kisi");
		puts("[1] 3x3");
		puts("[2] 5x5");
		puts("[3] 7x7");
		printf("Masukkan pilihan : ");
		scanf("%d", &GridOption);
		
		if(GridOption == 1){
			Player1.InitialScore = Player2.InitialScore = 9;
		}else if(GridOption == 2){
			Player1.InitialScore = Player2.InitialScore = 25;
		}else if(GridOption == 3){
			Player1.InitialScore = Player2.InitialScore = 49;
		}else{
			system("cls");
			puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while((GridOption < 1) || (GridOption > 3));
}

//Modul untuk Input Nama Player
void DisplayNamePlayerInput(){
	system("cls");
	
	printf("Nama Player\n");
	if(PlayerOption == 1){
		printf("Masukkan nama player 1 : ");
		scanf("%s", Player1.Name);
		strcpy(Player2.Name, "Komputer");
	}
	else{
		printf("Masukkan nama player 1 : ");
		scanf("%s", Player1.Name);
		printf("Masukkan nama player 2 : ");
		scanf("%s", Player2.Name);
	}
}

//Modul untuk Algoritma / Linimasa dari Program Player VS Komputer
void PlayerVSComputer(){
	system("cls");
	
	int i, Player = 1, Choice;
	
	//Memanggil Modul Pilihan Level
	DisplayLevelMenu();
	
	//Memanggil Modul Pilihan Grid
	DisplayGridMenu();
	
	//Memasukkan Nama Player
	DisplayNamePlayerInput();
	
	//Algoritma Permainan Dimulai
	PlayGamePVC();
}

//Modul untuk Algoritma/Linimasa dari Program Player VS Player
void PlayerVSPlayer(){
	system("cls");
	
	//Memanggil Modul Pilihan Grid
	DisplayGridMenu();
	
	//Memasukkan Nama Player
	DisplayNamePlayerInput();
	
	//Algoritma Permainan Dimulai
	PlayGamePVP();
}

//Modul untuk Program Player VS Komputer saat Permainan Dimulai
void PlayGamePVC(){
	int done=-1, winner=0;
	do{
		GridBoard(); 
		//Giliran Player Utama
		PlayerMove();
		done = CheckWin(); 	/* see if winner */ 
		if (done==1) {
			winner=1;
			break;
		} 				  	/* winner!*/ 
		
		//Giliran Player Bot
		switch(LevelOption){
			case 1:
				ComputerMoveEasy();
				break;
			case 2:
				ComputerMoveNormal();
				break;
			case 3:
				ComputerMoveHard();
				break;
		}
		done = CheckWin(); 	/* see if winner */ 
		if (done==1) {
			winner=2;
			break;
		}
	} while(done == -1);
	
	GridBoard();
	
	if(winner == 1){ //Jika Player 1 Menang
		printf("Player 1 Menang\n");
		Player1.Highscore = Score(1, Player1.InitialScore, Player1.ActionCount, Player1.AverageTime);
		printf("Highscore : %d", Player1.Highscore);
			
		SaveHighscore(Player1.Highscore, winner, Player1.ActionCount, Player1.AverageTime);
	}
	else if(winner==2){
		printf("Pemenangnya adalah Komputer, Anda kalah");
		Player1.Highscore = Score(1, Player1.InitialScore, Player1.ActionCount, Player1.AverageTime);
		SaveHighscore(Player1.Highscore, winner, Player1.ActionCount, Player1.AverageTime);
	}
	else if(done == 0){
		printf("Game seri\n");
		Player1.Highscore = Score(1, Player1.InitialScore, Player1.ActionCount, Player1.AverageTime);
		SaveHighscore(Player1.Highscore, done, Player1.ActionCount, Player1.AverageTime);
	}
	getch();
}

void PlayerMove(){
	int row, column, i=1, limit;
	int *ch, remain_time;
	do{
		system("cls");
		GridBoard();
		printf(" Giliran Player 1 [%s] \n", Player1.Name);
		printf(" NOTE : Masukan hanya angka tanpa koma dan tanda kurung\n");
		
		//Inputan dari Pemain dengan Timer
		if ((ch = Timer(10)) != 0){
        	row = ch[0]-48;
			column = ch[1]-48;
			remain_time = ch[2];
        }
	    else{
	        printf("Waktu Habis");
	        break;
	    }
		
		switch(GridOption){
    		case 1: //Batasan input untuk Kisi 3x3
    			limit = 4;
    			break;
    		case 2: //Batasan input untuk Kisi 5x5
    			limit = 6;
    			break;
    		case 3: //Batasan input untuk Kisi 7x7
    			limit = 8;
    			break;
		}
		
		if((Symbol[row-1][column-1] != 'X') && (Symbol[row-1][column-1] != 'O')){
        	if((row > 0) && (row < limit) && (column > 0) && (column < limit)){
        		Symbol[row-1][column-1] = 'X';
        		PlayerRow=row;
        		PlayerColumn=column;
        		Player1.InitialScore--;
       			Player1.ActionCount++;
       			Player1.AverageTime += remain_time;
        		i=0;
        		break;
			}
		}else{
			printf("Masukan tidak valid, Silahkan coba lagi.");
            getch();
		}
	}while(i==1);
}

void ComputerMoveEasy(){
	int i, j, box = 1;
	if(GridOption == 1){ //Kisi 3x3 
		for (i=0; i<3; i++){
			for (j=0; j<3; j++){
			if (Symbol[i][j] == ' '){
					Symbol[i][j] = 'O';
					i = 3;
					j = 3;
				}
			}
		}
	}else if(GridOption == 2){ //Kisi 5x5
		for (i=0; i<5; i++){
			for (j=0; j<5; j++){
			if (Symbol[i][j] == ' '){
					Symbol[i][j] = 'O';
					i = 5;
					j = 5;
				}
			}
		}
	}else{ //Kisi 7x7
		for (i=0; i<7; i++){
			for (j=0; j<7; j++){
			if (Symbol[i][j] == ' '){
					Symbol[i][j] = 'O';
					i = 7;
					j = 7;
				}
			}
		}
	}
}

void ComputerMoveNormal(){
	int i, j, box=1; 
	for (i=PlayerRow-2; i<PlayerRow+1; i++){
			for (j=PlayerColumn-2; j<PlayerColumn+1; j++){
				if (box%2==1){
					if (Symbol[i][j]=='X' && ((i!=PlayerRow-1) && (j!=PlayerColumn-1))){
					box--;
					i=100;
					j=100;
					}
				}
				else {
					if (Symbol[i][j]=='X' && ((i!=PlayerRow-1) ^ (j!=PlayerColumn-1))){
					box--;
					i=100;
					j=100;
					}
				}
				box++;
			}
		}
	
	switch(box){
		case 1 :
			if (Symbol[PlayerRow][PlayerColumn]==' '){
				if ((PlayerRow>=0 && PlayerRow <=GridOption*2) && (PlayerColumn>=0 && PlayerColumn<=GridOption*2)){
					Symbol[PlayerRow][PlayerColumn]='O';
					break;
				}
			}
			if (Symbol[PlayerRow-3][PlayerColumn-3]==' '){
				if ((PlayerRow-3>=0 && PlayerRow-3 <=GridOption*2) && (PlayerColumn-3>=0 && PlayerColumn-3<=GridOption*2)){
					Symbol[PlayerRow-3][PlayerColumn-3]='O';
					break;
				}
			}else{
				ComputerMoveEasy();
				break;	
			}
		case 2 :
			if (Symbol[PlayerRow][PlayerColumn-1]==' '){
				if ((PlayerRow>=0 && PlayerRow<=GridOption*2) && (PlayerColumn-1 >=0 && PlayerColumn-1 <=GridOption*2)){
					Symbol[PlayerRow][PlayerColumn-1]='O';
					break;
				}
			}
			if (Symbol[PlayerRow-3][PlayerColumn-1]==' '){
				if ((PlayerRow-3>=0 && PlayerRow-3<=GridOption*2) && (PlayerColumn-1 >=0 && PlayerColumn-2 <=GridOption*2)){
					Symbol[PlayerRow-3][PlayerColumn-1]='O';
					break;
				}
			}else{
				ComputerMoveEasy();
				break;	
			}
		case 3 :
			if (Symbol[PlayerRow][PlayerColumn-2]==' '){
				if ((PlayerRow >= 0 && PlayerRow <= GridOption*2) && (PlayerColumn-2 >= 0 && PlayerColumn-2 <= GridOption*2)){
					Symbol[PlayerRow][PlayerColumn-2]='O';
					break;
				}
			}
			if (Symbol[PlayerRow-3][PlayerColumn+1]==' '){
				if ((PlayerRow-3 >= 0 && PlayerRow-3 <= GridOption*2) && (PlayerColumn+1 >= 0 && PlayerColumn+1 <=GridOption*2)){
					Symbol[PlayerRow-3][PlayerColumn+1]='O';
					break;
				}
			}
			else {
				ComputerMoveEasy();
				break;	
			}
		case 4 :
			if (Symbol[PlayerRow-1][PlayerColumn]==' '){
				if ((PlayerRow-1 >= 0 && PlayerRow-1 <=GridOption*2) && (PlayerColumn >= 0 && PlayerColumn <=GridOption*2)){
					Symbol[PlayerRow-1][PlayerColumn]='O';
					break;
				}
			}
			if (Symbol[PlayerRow-1][PlayerColumn-3]==' '){
				if ((PlayerRow-1 >= 0 && PlayerRow-1 <=GridOption*2) && (PlayerColumn-3 >= 0 && PlayerColumn-3 <=GridOption*2)){
					Symbol[PlayerRow-1][PlayerColumn-3]='O';
					break;
				}
			}
			else {
				ComputerMoveEasy();
				break;	
			}
		case 6 :
			if (Symbol[PlayerRow-1][PlayerColumn-2]==' '){
				if ((PlayerRow-1 >= 0 && PlayerRow-1 <= GridOption*2) && (PlayerColumn-2 >= 0 && PlayerColumn-2 <= GridOption*2)){
					Symbol[PlayerRow-1][PlayerColumn-2]='O';
					break;
				}
			}
			if (Symbol[PlayerRow-1][PlayerColumn+1]==' '){
				if ((PlayerRow-1 >= 0 && PlayerRow-1 <= GridOption*2) && (PlayerColumn+1 >= 0 && PlayerColumn+1 <= GridOption*2)){
					Symbol[PlayerRow-1][PlayerColumn+1]='O';
					break;
				}
			}
			else {
				ComputerMoveEasy();
				break;	
			}
		case 7 :
			if(Symbol[PlayerRow-2][PlayerColumn]==' '){
				if ((PlayerRow-2 >= 0 && PlayerRow-2 <= GridOption*2) && (PlayerColumn >= 0 && PlayerColumn <=GridOption*2)){
					Symbol[PlayerRow-2][PlayerColumn]='O';
					break;
				}
			}
			if(Symbol[PlayerRow+1][PlayerColumn-3]==' '){
				if ((PlayerRow+1 >= 0 && PlayerRow+1 <= GridOption*2) && (PlayerColumn-3 >= 0 && PlayerColumn-3 <=GridOption*2)){
					Symbol[PlayerRow+1][PlayerColumn-3]='O';
					break;
				}
			}
			else{
				ComputerMoveEasy();
				break;	
			}
		case 8 :
			if (Symbol[PlayerRow-2][PlayerColumn-1]==' '){
				if ((PlayerRow-2 >= 0 && PlayerRow-2 <= GridOption*2) && (PlayerColumn-1 >= 0 && PlayerColumn-1 <= GridOption*2)){
					Symbol[PlayerRow-2][PlayerColumn-1]='O';
					break;
				}
			}
			if(Symbol[PlayerRow+1][PlayerColumn-1]==' '){
				if ((PlayerRow+1 >= 0 && PlayerRow+1 <= GridOption*2) && (PlayerColumn-1 >= 0 && PlayerColumn-1 <= GridOption*2)){
					Symbol[PlayerRow+1][PlayerColumn-1]='O';
					break;
				}
			}
			else{
				ComputerMoveEasy();
				break;	
			}
		case 9 :
			if(Symbol[PlayerRow-2][PlayerColumn-2]==' '){
				if ((PlayerRow-2>= 0 && PlayerRow-2 <= GridOption*2) && (PlayerColumn-2 >= 0 && PlayerColumn-2 <= GridOption*2)){
					Symbol[PlayerRow-2][PlayerColumn-2]='O';
					break;
				}
			}
			if(Symbol[PlayerRow+1][PlayerColumn+1]==' '){
				if ((PlayerRow+1>= 0 && PlayerRow+1 <= GridOption*2) && (PlayerColumn+1 >= 0 && PlayerColumn+1 <= GridOption*2)){
					Symbol[PlayerRow+1][PlayerColumn+1]='O';
					break;
				}
			}
			else{
				ComputerMoveEasy();
				break;	
			}
		case 10 :
			ComputerMoveEasy();
			break;
	}
}

void ComputerMoveHard(){
	int i, j, box=1;
	for (i=PlayerRow-3; i<PlayerRow+2; i=i+2){
			for (j=PlayerColumn-3; j<PlayerColumn+2; j=j+2){
				if (box%2==1){
					if (Symbol[i][j]=='X' && ((i!=PlayerRow-1) && (j!=PlayerColumn-1))){
					box--;
					i=100;
					j=100;
					}
				}
				else {
					if (Symbol[i][j]=='X' && ((i!=PlayerRow-1) ^ (j!=PlayerColumn-1))){
					box--;
					i=100;
					j=100;
					}
				}
				box++;
			}
		}
	
	switch (box){
		case 1 :
			if (Symbol[PlayerRow-2][PlayerColumn-2]==' '){
				if ((PlayerRow-2 >=0 && PlayerRow-2 <= GridOption*2) &&(PlayerColumn-2 >=0 && PlayerColumn-2 <= GridOption*2)){
					Symbol[PlayerRow-2][PlayerColumn-2]='O';
					break;
				}
			}
			else ComputerMoveNormal();
		case 2 :
			if (Symbol[PlayerRow-2][PlayerColumn-1]==' '){
				if ((PlayerRow-2 >=0 && PlayerRow-2 <= GridOption*2) && (PlayerColumn-1 >=0 && PlayerColumn-1 <= GridOption*2 )){
					Symbol[PlayerRow-2][PlayerColumn-1]='O';
					break;
				}
			}
			else ComputerMoveNormal();
		case 3 :
			if (Symbol[PlayerRow-2][PlayerColumn]==' '){
				if ((PlayerRow-2 >=0 && PlayerRow-2 <= GridOption*2) && (PlayerColumn >=0 && PlayerColumn <= GridOption*2 )){
					Symbol[PlayerRow-2][PlayerColumn]='O';
					break;
				}
			}
			else ComputerMoveNormal();
		case 4 :
			if (Symbol[PlayerRow-1][PlayerColumn-2]==' '){
				if ((PlayerRow-1 >=0 && PlayerRow-1 <= GridOption*2) && (PlayerColumn-2 >=0 && PlayerColumn-2 <= GridOption*2)){
					Symbol[PlayerRow-1][PlayerColumn-2]='O';
					break;
				}
			}
			else ComputerMoveNormal();
		case 6 :
			if (Symbol[PlayerRow-1][PlayerColumn]==' '){
				if ((PlayerRow-1 >=0 && PlayerRow-1 <= GridOption*2) && (PlayerColumn >=0 && PlayerColumn <= GridOption*2)){
					Symbol[PlayerRow-1][PlayerColumn]='O';
					break;
				}
			}
			else ComputerMoveNormal();
		case 7 :
			if (Symbol[PlayerRow][PlayerColumn-2]==' '){
				if ((PlayerRow >=0 && PlayerRow <= GridOption*2 ) && (PlayerColumn-2 >=0 && PlayerColumn-2 <= GridOption*2)){
					Symbol[PlayerRow][PlayerColumn-2]='O';
					break;
				}
			}
			else ComputerMoveNormal();
		case 8 :
			if (Symbol[PlayerRow][PlayerColumn-1]==' '){
				if ((PlayerRow >=0 && PlayerRow <= GridOption*2 ) && (PlayerColumn-1 >=0 && PlayerColumn-1 <= GridOption*2)){
					Symbol[PlayerRow][PlayerColumn-1]='O';
					break;
				}
			}
			else ComputerMoveNormal();
		case 9 :
			if (Symbol[PlayerRow][PlayerColumn]==' '){
				if ((PlayerRow >=0 && PlayerRow <= GridOption*2) && (PlayerColumn >=0 && PlayerColumn <= GridOption*2)){
					Symbol[PlayerRow][PlayerColumn-1]='O';
					break;
				}
			}
			else ComputerMoveNormal();
		case 10 :
			ComputerMoveNormal();
			break;
	}
}

//Modul untuk Program Player VS Player saat Permainan Dimulai
void PlayGamePVP(){
	int column, row, player=1, Done=-1, limit;
	char mark;
	int *ch, remain_time;
	
	do{
		system("cls");
		GridBoard();
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
                
    	switch(GridOption){
    		case 1: //Batasan input untuk Kisi 3x3
    			limit = 4;
    			break;
    		case 2: //Batasan input untuk Kisi 5x5
    			limit = 6;
    			break;
    		case 3: //Batasan input untuk Kisi 7x7
    			limit = 8;
    			break;
		}
		
		if((Symbol[row-1][column-1] != 'X') && (Symbol[row-1][column-1] != 'O')){
        	if((row > 0) && (row < limit) && (column > 0) && (column < limit)){
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
		}else{
			printf("Masukan tidak valid, Silahkan coba lagi.");

            player--;
            getch();
		}
		
		Done=CheckWin();
		
		player++;
	}while(Done==-1);
	
	GridBoard();
	
	if(Done == 1){
		printf("Player %d Menang\n", --player);
		if(player == 1){
			Player1.Highscore = Score(Done, Player1.InitialScore, Player1.ActionCount, Player1.AverageTime);
			printf("Highscore : %d", Player1.Highscore);
			
			SaveHighscore(Player1.Highscore, player, Player1.ActionCount, Player1.AverageTime);
		}else{
			Player2.Highscore = Score(Done, Player2.InitialScore, Player2.ActionCount, Player2.AverageTime);
			printf("Highscore : %d", Player2.Highscore);
			
			SaveHighscore(Player2.Highscore, player, Player2.ActionCount, Player2.AverageTime);
		}
	}
	else{
		Player1.Highscore = Score(Done, Player1.InitialScore, Player1.ActionCount, Player1.AverageTime);
		Player2.Highscore = Score(Done, Player2.InitialScore, Player2.ActionCount, Player2.AverageTime);
		printf("Game Seri\n");
		printf("Skor Akhir Player 1 : %d\n", Player1.Highscore);
		printf("Skor Akhir Player 2 : %d", Player2.Highscore);
	}
	
	getch();
	exit(0);
}

//Modul untuk Tampilan Papan
void GridBoard(){
	system("cls");
	int i;
	
	if(GridOption == 1){
		puts(" ===============================");
		puts("         TIC TAC TOE 3x3        ");
		puts(" ===============================");
		
		printf(" Player 1 (X)  VS  Player 2 (O)\n");
		printf(" %s                %s\n", Player1.Name, Player2.Name);
		
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
	}else if(GridOption == 2){
		puts(" ====================================");
		puts("           TIC TAC TOE 5X5           ");
		puts(" ====================================");
		
		printf(" Player 1 (X)    VS    Player 2 (O)\n");
		printf(" %s                    %s\n", Player1.Name, Player2.Name);
		
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
	}else{
		puts(" ==============================================");
		puts("                TIC TAC TOE 7X7                ");
		puts(" ==============================================");
		
		printf(" Player 1 (X)          VS          Player 2 (O)\n");
		printf(" %s                                %s\n\n", Player1.Name, Player2.Name);
		
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
	}
	
	printf("\n");
}

//Modul untuk Timer
int* Timer(unsigned int sec){
	int count = 0;
	static int set[3];
	
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
int CheckWin(){
	int i=0, j=0, seri=0;
	
	switch(GridOption){
		case 1: //CheckWin untuk Kisi 3x3
			//Kondisi Menang
			/*Untuk Horizontal*/
			for (i=0; i<3; i++){
				if ((Symbol[i][j] == Symbol[i][j+1]) && (Symbol[i][j+1]==Symbol[i][j+2]) ){
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
			break;
		case 2: //CheckWin untuk Kisi 5x5
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
			break;
		case 3: //CheckWin untuk Kisi 7x7
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
			break;
	}
}

//Modul untuk Menghitung Skor Akhir Pemenang
int Score(int Done, int InitialScore, int ActionCount, float AverageTime){
	int Result;
	if(Done == 1){
		Result = InitialScore * ((int)AverageTime/ActionCount) * 4;
	}else{
		Result = InitialScore * ((int)AverageTime/ActionCount) * 1;
	}
	return Result;
}

//Modul untuk Menyimpan Data Pemain yang Menang
void SaveHighscore(int Highscore, int Result, int ActionCount, float AverageTime){
	if(PlayerOption == 1){ //Menyimpan data permainan 1 player
		FILE * FHighscore = fopen("highscore1player.txt", "a");
		switch(GridOption){
			case 1:
				if(Result == 0){
					fprintf(FHighscore, "\n%s\t\t\tSeri\t\t%d\t\t%d\t\t%.2f\t\t\t3x3", Player1.Name, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}else if(Result == 1){
					fprintf(FHighscore, "\n%s\t\t\tMenang\t\t%d\t\t%d\t\t%.2f\t\t\t3x3", Player1.Name, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}else{
					fprintf(FHighscore, "\n%s\t\t\tKalah\t\t%d\t\t%d\t\t%.2f\t\t\t3x3", Player1.Name, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}
				break;
			case 2:
				if(Result == 0){
					fprintf(FHighscore, "\n%s\t\t\tSeri\t\t%d\t\t%d\t\t%.2f\t\t\t5x5", Player1.Name, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}else if(Result == 1){
					fprintf(FHighscore, "\n%s\t\t\tMenang\t\t%d\t\t%d\t\t%.2f\t\t\t5x5", Player1.Name, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}else{
					fprintf(FHighscore, "\n%s\t\t\tKalah\t\t%d\t\t%d\t\t%.2f\t\t\t5x5", Player1.Name, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}
				break;
			case 3:
				if(Result == 0){
					fprintf(FHighscore, "\n%s\t\t\tSeri\t\t%d\t\t%d\t\t%.2f\t\t\t7x7", Player1.Name, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}else if(Result == 1){
					fprintf(FHighscore, "\n%s\t\t\tMenang\t\t%d\t\t%d\t\t%.2f\t\t\t7x7", Player1.Name, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}else{
					fprintf(FHighscore, "\n%s\t\t\tKalah\t\t%d\t\t%d\t\t%.2f\t\t\t7x7", Player1.Name, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}
				break;
		}
	    fclose(FHighscore);
	}else{ //Menyimpan data permainan 2 player
		FILE * FHighscore = fopen("highscore2player.txt", "a");
		switch(GridOption){
			case 1:
				if(Result == 1){
					fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t3x3", Player1.Name, Result, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}else{
					fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t3x3", Player2.Name, Result, Player2.Highscore, Player2.ActionCount, Player2.AverageTime/(float)Player2.ActionCount);
				}
				break;
			case 2:
				if(Result == 1){
					fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t5x5", Player1.Name, Result, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}else{
					fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t5x5", Player2.Name, Result, Player2.Highscore, Player2.ActionCount, Player2.AverageTime/(float)Player2.ActionCount);
				}
				break;
			case 3:
				if(Result == 1){
					fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t7x7", Player1.Name, Result, Player1.Highscore, Player1.ActionCount, Player1.AverageTime/(float)Player1.ActionCount);
				}else{
					fprintf(FHighscore, "\n%s\t\t\t%d\t\t%d\t\t%d\t\t%.2f\t\t\t7x7", Player2.Name, Result, Player2.Highscore, Player2.ActionCount, Player2.AverageTime/(float)Player2.ActionCount);
				}
				break;
		}
	    fclose(FHighscore);
	}
	
}

//Modul untuk Tampilan Menu Highscore
void DisplayHighscoreMenu(){
	system("cls");
	
	int HighscoreOption;
	do{
		puts("Riwayat Skor");
		puts("[1] 1 Player");
		puts("[2] 2 Player");
		printf("Masukkan pilihan : ");
		scanf("%d", &HighscoreOption);
		
		switch(HighscoreOption){
			case 1:
				DisplayHighscore1Player();
				break;
			case 2:
				DisplayHighscore2Player();
				break;
			default:
				system("cls");
				puts("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
				break;
		}
	}while((HighscoreOption < 1) || (HighscoreOption > 2));
}

void DisplayHighscore1Player(){
	system("cls");
	int HighscoreListOption;
	char teks[150];
	
	FILE * FHighscore;
	
	printf("NAMA\t\t\tHASIL AKHIR\tHIGHSCORE\tAKSI\t\tRATA-RATA WAKTU\t\tKISI");
	
	if ((FHighscore = fopen("highscore1player.txt","r")) == NULL){
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
	}while((HighscoreListOption < 1) || (HighscoreListOption > 2));
}

void DisplayHighscore2Player(){
	system("cls");
	int HighscoreListOption;
	char teks[150];
	
	FILE * FHighscore;
	
	printf("NAMA\t\t\tPLAYER\t\tHIGHSCORE\tAKSI\t\tRATA-RATA WAKTU\t\tKISI");
	
	if ((FHighscore = fopen("highscore2player.txt","r")) == NULL){
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
	}while((HighscoreListOption < 1) || (HighscoreListOption > 2));
}

//Modul untuk Tampilan Tentang
void DisplayAbout(){
	system("cls");
	char teks[150];
	
	FILE * FTentang;
	
	if ((FTentang = fopen("tentang.txt","r")) == NULL){
        printf("Error: File tidak ada!");
    }else{
    	while(!feof(FTentang)){
			fgets(teks, 150, FTentang);
			printf(teks);
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
	}while(AboutOption < 1 || AboutOption > 2);
}

//Modul untuk Tampilan Bantuan
void DisplayHelp(){
	system("cls");
	char teks[150];
	
	FILE * FBantuan;
	
	if ((FBantuan = fopen("bantuan.txt","r")) == NULL){
        printf("Error: File tidak ada!");
    }else{
    	while(!feof(FBantuan)){
			fgets(teks, 150, FBantuan);
			printf(teks);
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
	}while(HelpOption < 1 || HelpOption > 2);
}
