#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

#define WIDTH 61
#define HEIGHT 21
#define OFFSET_X 29
#define OFFSET_Y 3

//#define KEY_UP 72
//#define KEY_DOWN 80
//#define KEY_LEFT 75
//#define KEY_RIGHT 77
#define ENTER 13

#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

int dataPlayer = 0;
int lives;

struct playerData{
	int score;
	char name[100];
} list[100];

int readFile(){
	FILE* f = fopen("data.txt", "r");
	
	if(f == NULL) return 0;
	
	while(!feof(f)){
		fscanf(f, "%[^#]#%d\n", &list[dataPlayer].name, &list[dataPlayer].score);
		dataPlayer++;
	}
		
	fclose(f);
	
	return dataPlayer;
}

void saveFile(){
	if(dataPlayer == 0) return;
	
	FILE* f2 = fopen("data.txt", "w");
	
	for(int i = 0; i < dataPlayer; i++){
		fprintf(f2, "%s#%d\n", list[i].name, list[i].score);
	}
	
	fclose(f2);
}

void openingMenu(){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	
	printf("\n\n\n");
	puts("\t\t  888    d8P  d8b                   d8b              8888888b.  d8b                   ");
	puts("\t\t  888   d8P   Y8P                   88P              888   Y88b Y8P                   ");
	puts("\t\t  888  d8P                          8P               888    888                       ");
	puts("\t\t  888d88K     888 88888b.   .d88b.  '   .d8888b      888   d88P 888 88888b.   .d88b.  ");
	puts("\t\t  8888888b    888 888 '88b d88P'88b     88K          8888888P'  888 888 '88b d88P'88b ");
	SetConsoleTextAttribute(hConsole, 14);
	puts("\t\t  888  Y88b   888 888  888 888  888     'Y8888b.     888 T88b   888 888  888 888  888 ");
	puts("\t\t  888   Y88b  888 888  888 Y88b 888          X88     888  T88b  888 888  888 Y88b 888 ");
	puts("\t\t  888    Y88b 888 888  888  'Y88888      88888P'     888   T88b 888 888  888  'Y88888 ");
	puts("\t\t                                888                                               888 ");
	puts("\t\t                           Y8b d88P                                          Y8b d88P ");
	puts("\t\t                            'Y88P'                                            'Y88P'  \n");
}

void menu1(HANDLE hConsole, int a){
	SetConsoleTextAttribute(hConsole, a);
	
	printf("\n\n\t\t\t\t\t\t%c", 201);
	for(int i = 0; i < 15; i++){
		printf("%c", 205);
	}
	printf("%c\n\t\t\t\t\t\t", 187);
	
	for(int i = 0; i < 17; i++){
		if(i == 0 || i == 16) printf("%c", 186);
		else if(i == 4) printf("Play Game");
		else if(i > 4 && i < 13) continue;
		else printf(" ");
	}
	
	printf("\n\t\t\t\t\t\t%c", 200);
	for(int i = 0; i < 15; i++){
		printf("%c", 205);
	}
	printf("%c", 188);
}

void menu2(HANDLE hConsole, int a){
	SetConsoleTextAttribute(hConsole, a);
	
	printf("\n\t\t\t\t\t\t%c", 201);
	for(int i = 0; i < 15; i++){
		printf("%c", 205);
	}
	printf("%c\n\t\t\t\t\t\t", 187);
	
	for(int i = 0; i < 17; i++){
		if(i == 0 || i == 16) printf("%c", 186);
		else if(i == 4) printf("High Score");
		else if(i > 4 && i < 14) continue;
		else printf(" ");
	}
	
	printf("\n\t\t\t\t\t\t%c", 200);
	for(int i = 0; i < 15; i++){
		printf("%c", 205);
	}
	printf("%c", 188);
}

void menu3(HANDLE hConsole, int a){
	SetConsoleTextAttribute(hConsole, a);
	
	printf("\n\t\t\t\t\t\t%c", 201);
	for(int i = 0; i < 15; i++){
		printf("%c", 205);
	}
	printf("%c\n\t\t\t\t\t\t", 187);
	
	for(int i = 0; i < 17; i++){
		if(i == 0 || i == 16) printf("%c", 186);
		else if(i == 4) printf("Exit Game");
		else if(i > 4 && i < 13) continue;
		else printf(" ");
	}
	
	printf("\n\t\t\t\t\t\t%c", 200);
	for(int i = 0; i < 15; i++){
		printf("%c", 205);
	}
	printf("%c\n\n", 188);
}

void menuEnding(char temp[], int count){
	printf("\n\n");
	
	if(count == 0){
		for(int i = 0; i < 120; i++){
			printf("%c", 205);
		}
		printf("\n\n");
		for(int x = 0; x < 534; x++){
			Sleep(10);
			printf("%c", temp[x]);
			if(temp[x] == '\n') Sleep(500);
		}
	}else{
		for(int i = 0; i < 120; i++){
			printf("%c", 205);
		}
		printf("\n\n");
		for(int x = 0; x < 534; x++){
			printf("%c", temp[x]);
		}
	}
}

void leaderboard(HANDLE hConsole){
	
	SetConsoleTextAttribute(hConsole, 7);
	
	puts("\t\t\t    _                   _             ___                     _ ");
	puts("\t\t\t   | |    ___  __ _  __| | ___  _ _  | _ ) ___  __ _  _ _  __| |");
	puts("\t\t\t   | |__ / -_)/ _` |/ _` |/ -_)| '_| | _ \\/ _ \\/ _` || '_|/ _` |");
	puts("\t\t\t   |____|\\___|\\__,_|\\__,_|\\___||_|   |___/\\___/\\__,_||_|  \\__,_|");

	printf("\n\n\t\t\t\t\t  %c", 201);
	for(int i = 0; i < 30; i++){
		printf("%c", 205);
	}
	printf("%c\n", 187);
	
	printf("\t\t\t\t\t  %c %-20s %-7s %c\n", 186, "Player Name", "Score", 186);
	printf("\t\t\t\t\t  %c ---------------------------- %c\n", 186, 186);
	
	if(dataPlayer == 0){
		printf("\t\t\t\t\t  %c ", 186);
		SetConsoleTextAttribute(hConsole, 6);
		printf("%-28s ", "    Make Your High Score!");
		SetConsoleTextAttribute(hConsole, 7);
		printf("%c\n", 186);
	}else{
		for(int i = 0; i < dataPlayer; i++){
			if(i == 10) break;
			printf("\t\t\t\t\t  %c %-20s %-7d %c\n", 186, list[i].name, list[i].score, 186);
		}
	}
	
	printf("\t\t\t\t\t  %c", 200);
	for(int i = 0; i < 30; i++){
		printf("%c", 205);
	}
	printf("%c", 188);
}

void savePlayerData(HANDLE hConsole){
	system("cls");
	SetConsoleTextAttribute(hConsole, 12);
	
	puts("\n\n\n\t\t\t    ____     _     __  __  _____    ___  __     __ _____  ____  ");
	puts("\t\t\t   / ___|   / \\   |  \\/  || ____|  / _ \\ \\ \\   / /| ____||  _ \\ ");
	puts("\t\t\t  | |  _   / _ \\  | |\\/| ||  _|   | | | | \\ \\ / / |  _|  | |_) |");
	puts("\t\t\t  | |_| | / ___ \\ | |  | || |___  | |_| |  \\ V /  | |___ |  _ < ");
	puts("\t\t\t   \\____|/_/   \\_\\|_|  |_||_____|  \\___/    \\_/   |_____||_| \\_\\");
	
	SetConsoleTextAttribute(hConsole, 7);
	printf("\n\n\n\t\t\t\t\t  %c", 201);
	for(int i = 0; i < 30; i++){
		printf("%c", 205);
	}
	printf("%c\n\t\t\t\t\t  ", 187);
	
	int x = 0;
	while(x < 3){
		for(int i = 0; i < 31; i++){
			if(i == 0 || i == 30) printf("%c", 186);
			if(x == 1){
				printf("\t  YOUR SCORE: %-10d %c", list[dataPlayer].score, 186);
				break;
			}
			else printf(" ");
		}
		printf("\n\t\t\t\t\t  ");
		x++;
	}
	
	printf("%c", 200);
	for(int i = 0; i < 30; i++){
		printf("%c", 205);
	}
	printf("%c\n\n", 188);
	
	do{
		printf("\t\t\t\t\t       Player Name: ");
		scanf("%[^\n]", &list[dataPlayer].name);
		fflush(stdin);
	}while(strlen(list[dataPlayer].name) == 0);
		
	dataPlayer++;
	
	if(dataPlayer > 1){
		for(int i = 0; i < dataPlayer; i++){
			for(int j = dataPlayer; j > i; j--){
				if(list[j].score > list[j-1].score){
					playerData temp = list[j];
					list[j] = list[j-1];
					list[j-1] = temp;
				}
			}
		}
	}
	system("cls");
	printf("\n\n\n");
	leaderboard(hConsole);		
}

int story(HANDLE hConsole, char temp[], bool idx){
	int input;
	int choose = 1;
	if(idx == 0){
		for(int i = 0; i < 120; i++){
			printf("%c", 205);
		}
		printf("\n\n");
		for(int x = 0; x < 363; x++){
			Sleep(50);
			printf("%c", temp[x]);
			if(temp[x] == '\n') Sleep(500);
		}
		printf("\n\n");
		for(int i = 0; i < 120; i++){
			printf("%c", 205);
		}
		getch();
	
		system("cls");
		openingMenu();
		SetConsoleTextAttribute(hConsole, 15);
		for(int i = 0; i < 120; i++){
			printf("%c", 205);
		}
		printf("\n\n");
		for(int x = 363; temp[x] != NULL; x++){
			Sleep(50);
			printf("%c", temp[x]);
			if(temp[x] == '\n') Sleep(500);
		}
		printf("\n\n");
		for(int i = 0; i < 120; i++){
			printf("%c", 205);
		}
		getch(); fflush(stdin);
	}else{
		int a = 15;
		int b = 8;
		int count = 0;
		
		do{
			system("cls");
			SetConsoleTextAttribute(hConsole, 15);
			menuEnding(temp, count);
			SetConsoleTextAttribute(hConsole, a);
			printf("\n\n\n\n\t\t\t\t\t\t%c", 201);
			for(int i = 0; i < 15; i++){
				printf("%c", 205);
			}
			printf("%c\n\t\t\t\t\t\t", 187);
			
			for(int i = 0; i < 17; i++){
				if(i == 0 || i == 16) printf("%c", 186);
				else if(i == 2) printf("Continue Game");
				else if(i > 2 && i < 15) continue;
				else printf(" ");
			}
			
			printf("\n\t\t\t\t\t\t%c", 200);
			for(int i = 0; i < 15; i++){
				printf("%c", 205);
			}
			printf("%c\n\n", 188);
			
			SetConsoleTextAttribute(hConsole, b);
			printf("\n\t\t\t\t\t\t%c", 201);
			for(int i = 0; i < 15; i++){
				printf("%c", 205);
			}
			printf("%c\n\t\t\t\t\t\t", 187);
			
			for(int i = 0; i < 17; i++){
				if(i == 0 || i == 16) printf("%c", 186);
				else if(i == 5) printf("End Game");
				else if(i > 4 && i < 13) continue;
				else printf(" ");
			}
			
			printf("\n\t\t\t\t\t\t%c", 200);
			for(int i = 0; i < 15; i++){
				printf("%c", 205);
			}
			printf("%c\n\n", 188);
			
			printf("\n\n");
			for(int i = 0; i < 120; i++){
				printf("%c", 205);
			}
			
			input = getch();
			count++;
			if(input == ENTER) break;
			if(input == 'w'){
				a = 15;
				b = 8;
				choose = 1;
			}else if(input == 's'){
				a = 8;
				b = 15;
				choose = 2;
			}else continue;
		}while(input != ENTER);
		return choose;
	}
	return 0;
}

using namespace std;

int map[HEIGHT][WIDTH];

enum mapCode{
	WALL = 0,
	PATH
};

struct coor{
	int x,y;
};

char getChar(int code){
	switch(code){
		case WALL: return 219;
		case PATH: return ' ';
	}
	return ' ';
}

void gotoxy(int x, int y){
	COORD coor;
	coor.X = x;
	coor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coor);
}

void printBorder(){
	for(int y =0; y < HEIGHT; y++){
		for(int x =0; x < WIDTH; x++){
			if(y == 0 || x == 0 || x == WIDTH-1 || y == HEIGHT-1){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", getChar(map[y][x]));
			}
			else printf(" ");
		}
		puts("");
	}
}

int neighbour[4][2]={
	{0,-1},
	{0,+1},
	{-1,0},
	{+1,0}
};

void changeParent(int y, int x, int currParent, int min){
	if(currParent == min) return;
	
	map[y][x] = min;
	
	for(int i = 0; i<4; i++){
		int x1 = x + neighbour[i][0];
		int y1 = y + neighbour[i][1];
		if(map[y1][x1] != WALL){
			for(int i = 0; i<4; i++){
				int x2 = x1 + neighbour[i][0];
				int y2 = y1 + neighbour[i][1];
				if(map[y2][x2] != WALL){
					changeParent(y2, x2, map[y2][x2], min);
				}
			}
		}
	}
}

void generateMaze(){
	int n=2; 
	for(int i=1; i < HEIGHT-1; i+=2){ 
		for(int j=1; j < WIDTH-1; j+=2){
			map[i][j] = n++; 
		}
	}
	
	vector<coor> walls; 
	for(int y= 1; y<HEIGHT-1; y++){
		for(int x =1; x<WIDTH-1; x++){
			if(map[y][x] != WALL) continue; 
			if(x % 2 && y % 2) continue;
			if(!(x % 2) && !(y % 2)) continue;
			
			coor c;
			c.x = x;
			c.y = y;
			walls.push_back(c);
		}
	}
	
	vector<int> parents;
	while(walls.size()){
		parents.clear();
		
		int r = rand()%walls.size();
		coor w = walls[r];
		walls.erase(walls.begin() + r); 
		
		int min = INT_MAX;
		for(int i = 0; i<4; i++){ 
			int x = w.x + neighbour[i][0];
			int y = w.y + neighbour[i][1];
			if(map[y][x] == WALL) continue;
			parents.push_back(map[y][x]);
			if(min > map[y][x]) min = map[y][x];
		}
		
		bool isDup = false;
		for(int i =0; i<parents.size();i++){
			for(int j = i+1; j < parents.size(); j++){
				if(parents[i] == parents[j]){
					isDup = true;
					break;
				}
			}
			if(isDup) break;
		}
		if(isDup) continue;
		map[w.y][w.x] = PATH;
		
		for(int i = 0; i<4; i++){
			int x = w.x + neighbour[i][0];
			int y = w.y + neighbour[i][1];
			if(map[y][x] == WALL) continue;
			
			int currParent = map[y][x]; 
			
			changeParent(y, x, currParent, min);
		}	
	}
}

vector <coor> visited;
vector <coor> branch;

coor bot;
void initBot(){
	do{
	bot.x = rand()%((WIDTH-1)/3-2) + 2;
	bot.y = rand()%(HEIGHT-2) + 2;
	}while(map[bot.y][bot.x] == WALL);
	
	visited.push_back(bot);
	
	gotoxy(bot.x+OFFSET_X, bot.y+OFFSET_Y);
	printf("%c", 225);
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
}

int checkNeighbour(){
	coor lastPost = visited.back();
	
	coor c;
	for(int i = 0; i<4; i++){
		c.x = lastPost.x + neighbour[i][0];
		c.y = lastPost.y + neighbour[i][1];
		
		coor temp;
		int size = visited.size();
		for(int i=0; i<size; i++){
			temp = visited[i];
			if(c.x == temp.x && c.y == temp.y) break;
		}
		
		if(c.x == temp.x && c.y == temp.y) continue;
		
		if(map[c.y][c.x] != WALL) branch.push_back(c);
	}
}

int branchCount(int y, int x){
	int count=0;

	for(int i = 0; i<4; i++){
		int x1 = x + neighbour[i][0];
		int y1 = y + neighbour[i][1];
		
		coor temp;
		int size = visited.size();
		for(int i=0; i<size; i++){
			temp = visited[i];
			if(x1 == temp.x && y1 == temp.y) break;
		}
		
		if(x1 == temp.x && y1 == temp.y) continue;
		
		if(map[y1][x1] == WALL) continue;
		count++;
	}
	return count;
}

void moveBot(){
	checkNeighbour();
	
	bot = branch.back();
	branch.pop_back();
		
	coor lastPost = visited.back();
	gotoxy(lastPost.x+OFFSET_X, lastPost.y+OFFSET_Y);
	printf(" ");
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
	
	gotoxy(bot.x+OFFSET_X, bot.y+OFFSET_Y);
	printf("%c", 225);
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
	
	visited.push_back(bot);
	
	if(!branch.size() && !branchCount(bot.y,bot.x)){
		Sleep(800);
		gotoxy(bot.x+OFFSET_X, bot.y+OFFSET_Y);
	    printf(" ");
		visited.clear();
		initBot();
	}
}

vector <coor> visited2;
vector <coor> branch2;

coor bot2;
void initBot2(){
	do{
	bot2.x = rand()%((WIDTH-1)/3) + (WIDTH-1)/3;
	bot2.y = rand()%(HEIGHT-2) + 2;
	}while(map[bot2.y][bot2.x] == WALL);
	
	visited2.push_back(bot2);
	
	gotoxy(bot2.x+OFFSET_X, bot2.y+OFFSET_Y);
	printf("B");
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
}

int checkNeighbour2(){
	coor lastPost2 = visited2.back();
	
	coor c2;
	for(int i = 0; i<4; i++){
		c2.x = lastPost2.x + neighbour[i][0];
		c2.y = lastPost2.y + neighbour[i][1];
		
		coor temp2;
		int size2 = visited2.size();
		for(int i=0; i<size2; i++){
			temp2 = visited2[i];
			if(c2.x == temp2.x && c2.y == temp2.y) break;
		}
		
		if(c2.x == temp2.x && c2.y == temp2.y) continue;
		
		if(map[c2.y][c2.x] != WALL) branch2.push_back(c2);
	}
}

int branchCount2(int y, int x){
	int count2=0;

	for(int i = 0; i<4; i++){
		int x2 = x + neighbour[i][0];
		int y2 = y + neighbour[i][1];
		
		coor temp2;
		int size2 = visited2.size();
		for(int i=0; i<size2; i++){
			temp2 = visited2[i];
			if(x2 == temp2.x && y2 == temp2.y) break;
		}
		
		if(x2 == temp2.x && y2 == temp2.y) continue;
		
		if(map[y2][x2] == WALL) continue;
		count2++;
	}
	return count2;
}

void moveBot2(){
	checkNeighbour2();
	
	bot2 = branch2.back();
	branch2.pop_back();
		
	coor lastPost2 = visited2.back();
	gotoxy(lastPost2.x+OFFSET_X, lastPost2.y+OFFSET_Y);
	printf(" ");
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
	
	gotoxy(bot2.x+OFFSET_X, bot2.y+OFFSET_Y);
	printf("B");
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
	
	visited2.push_back(bot2);
	
	if(!branch2.size() && !branchCount2(bot2.y,bot2.x)){
		Sleep(800);
		gotoxy(bot2.x+OFFSET_X, bot2.y+OFFSET_Y);
	    printf(" ");
		visited2.clear();
		initBot2();
	}
}

vector <coor> visited3;
vector <coor> branch3;

coor bot3;
void initBot3(){
	do{
	bot3.x = rand()%((WIDTH-1)/3-2) + 2*(WIDTH-1)/3; 
	bot3.y = rand()%((HEIGHT-1)-3+1) + 3;
	}while(map[bot3.y][bot3.x] == WALL); 
	
	visited3.push_back(bot3);
	
	gotoxy(bot3.x+OFFSET_X, bot3.y+OFFSET_Y);
	printf("b");
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
}

int checkNeighbour3(){
	coor lastPost3 = visited3.back();
	
	coor c3;
	for(int i = 0; i<4; i++){
		c3.x = lastPost3.x + neighbour[i][0];
		c3.y = lastPost3.y + neighbour[i][1];
		
		coor temp3;
		int size3 = visited3.size();
		for(int i=0; i<size3; i++){
			temp3 = visited3[i];
			if(c3.x == temp3.x && c3.y == temp3.y) break;
		}
		
		if(c3.x == temp3.x && c3.y == temp3.y) continue;
		
		if(map[c3.y][c3.x] != WALL) branch3.push_back(c3);
	}
}

int branchCount3(int y, int x){
	int count3=0;

	for(int i = 0; i<4; i++){
		int x3 = x + neighbour[i][0];
		int y3 = y + neighbour[i][1];
		
		coor temp3;
		int size3 = visited3.size();
		for(int i=0; i<size3; i++){
			temp3 = visited3[i];
			if(x3 == temp3.x && y3 == temp3.y) break;
		}
		
		if(x3 == temp3.x && y3 == temp3.y) continue;
		
		if(map[y3][x3] == WALL) continue;
		count3++;
	}
	return count3;
}

void moveBot3(){
	checkNeighbour3();
	
	bot3 = branch3.back();
	branch3.pop_back();
		
	coor lastPost3 = visited3.back();
	gotoxy(lastPost3.x+OFFSET_X, lastPost3.y+OFFSET_Y);
	printf(" ");
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
	
	gotoxy(bot3.x+OFFSET_X, bot3.y+OFFSET_Y);
	printf("b");
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
	
	visited3.push_back(bot3);
	
	if(!branch3.size() && !branchCount3(bot3.y,bot3.x)){
		Sleep(800);
		gotoxy(bot3.x+OFFSET_X, bot3.y+OFFSET_Y);
	    printf(" ");
		visited3.clear();
		initBot3(); 
	}
}

coor hero;
void initHero(){
	hero.x = 1;
	hero.y = 1;
	
	gotoxy(hero.x+OFFSET_X, hero.y+OFFSET_Y);
	puts("H");
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
}

void printMap(){
	coor currPost = hero;
	int x1,x2,y1,y2,i;
	bool isPrinted[6];
	if((currPost.x > 0 && currPost.x <= WIDTH/3) && (currPost.y > 0 && currPost.y <= HEIGHT/2)){ //kiri atas
		i=1;
		x1 = 0;
		x2 = WIDTH/3;
		y1 = 0;
		y2 = HEIGHT/2;

	}
	else if((currPost.x > WIDTH/3 && currPost.x <= 2*WIDTH/3) && (currPost.y > 0 && currPost.y <= HEIGHT/2)){ //tengah atas
		i=2;
		x1 = WIDTH/3;
		x2 = 2*WIDTH/3;
		y1 = 0;
		y2 = HEIGHT/2;

	}
	else if((currPost.x > 2*WIDTH/3 && currPost.x <= WIDTH) && (currPost.y > 0 && currPost.y <= HEIGHT/2)){ //kanan atas
		i=3;
		x1 = 2*WIDTH/3;
		x2 = WIDTH;
		y1 = 0;
		y2 = HEIGHT/2;
	}
	else if((currPost.x > 0 && currPost.x <= WIDTH/3) && (currPost.y > HEIGHT/2 && currPost.y <= HEIGHT)){ //kiri bwh
		i=4;
		x1 = 0;
		x2 = WIDTH/3;
		y1 = HEIGHT/2;
		y2 = HEIGHT;
	}
	else if((currPost.x > WIDTH/3 && currPost.x <= 2*WIDTH/3) && (currPost.y > HEIGHT/2 && currPost.y <= HEIGHT)){ //tengah bwh
		i=5;
		x1 = WIDTH/3;
		x2 = 2*WIDTH/3;
		y1 = HEIGHT/2;
		y2 = HEIGHT;
	}
	else if((currPost.x > 2*WIDTH/3 && currPost.x <= WIDTH) && (currPost.y > HEIGHT/2 && currPost.y <= HEIGHT)){ //kanan bwh
		i=6;
		x1 = 2*WIDTH/3;
		x2 = WIDTH;
		y1 = HEIGHT/2;
		y2 = HEIGHT;
	}
	
	if(isPrinted[i] == false){
		for(int y = y1; y < y2; y++){
			for(int x =x1; x < x2; x++){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", getChar(map[y][x]));
			}
			puts("");
		}
		isPrinted[i] = true;
	}
}

coor Key;
void generateKey(){
	do{
		Key.x = rand()%((WIDTH-1)-2+1) + 2;
		Key.y = rand()%((HEIGHT-1)-2+1) + 2;
	}while(map[Key.y][Key.x] == WALL || (Key.y == bot.y && Key.x == bot.x) || 
		  (Key.y == bot2.y && Key.x == bot2.x) || (Key.y == bot3.y && Key.x == bot3.x));
	
	gotoxy(Key.x+OFFSET_X, Key.y+OFFSET_Y);
	printf("K");
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
}

void respawnKey(){
	gotoxy(Key.x+OFFSET_X, Key.y+OFFSET_Y);
	printf("K");
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
}

void moveHero(char key){
	coor temp = hero;
	
	switch(key){
		case KEY_UP: hero.y--; break;
		case KEY_LEFT: hero.x--; break;
		case KEY_DOWN: hero.y++; break;
		case KEY_RIGHT: hero.x++; break;
//		case ENTER: 
//				hero.x = bot.x;
//				hero.y = bot.y;
//				break;
	}
	if(map[hero.y][hero.x] == WALL) hero = temp;
	
	gotoxy(temp.x+OFFSET_X, temp.y+OFFSET_Y);
	printf(" ");
	
	gotoxy(hero.x+OFFSET_X, hero.y+OFFSET_Y);
	printf("H");
	
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
}

openWall(){
	int Y;
	do{
		Y = rand()%HEIGHT;
	}while(map[Y][WIDTH-2] == WALL);
	
	map[Y][WIDTH-1] = PATH;
	gotoxy(WIDTH-1+OFFSET_X,Y+OFFSET_Y);
	printf(" ");
}

void closeWall(){
	int Y;
	for(Y=0; Y<HEIGHT;Y++){
		map[Y][WIDTH-1] = WALL;
		gotoxy(WIDTH-1+OFFSET_X,Y+OFFSET_Y);
		printf("%c", 219);
	}
}

bool checkKeyRetrieval(){
	if(hero.x == Key.x && hero.y == Key.y){
		openWall();
		return true;
	}
	return false;
}

void printLives(int lives, int totalScore, HANDLE hConsole){
	gotoxy(OFFSET_X, 25);
	printf("LIVES %d: ",lives);
	if(lives == 5 || lives == 4)SetConsoleTextAttribute(hConsole, 10);
	else if(lives == 3 || lives == 2) SetConsoleTextAttribute(hConsole, 14);
	else SetConsoleTextAttribute(hConsole, 12);
	for(int j=0; j<lives; j++){
		printf("%c%c", 219, 219);
	}
	for(int i=0; i<5-lives; i++){
		printf("  ");
	}
	gotoxy(OFFSET_X, 26);
	SetConsoleTextAttribute(hConsole, 15);
	printf("SCORE: %d", totalScore);
	gotoxy(WIDTH+OFFSET_X, HEIGHT+OFFSET_Y);
}

void nextLevel(int lvl, HANDLE hConsole){
	SetConsoleTextAttribute(hConsole, 6);
	for(int y = 5; y <= 15; y++){
		for(int x = 20; x <= 40; x++){
			if(y == 5 && x == 20){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 201);
			}else if((y == 5 && (x > 20 && x < 40)) || (y == 15 && (x > 20 && x < 40))){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 205);
			}else if(y == 5 && x == 40){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 187);
			}else if(y > 5 && y < 15 && (x == 20 || x == 40)){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 186);
			}else if(y == 8 && x == 22){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("Level %d Completed", lvl-1);
			}else if(y == 12 && x == 22){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf(">>   Level %d   <<", lvl);
			}
			else if(y == 15 && x == 20){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 200);
			}else if(y == 15 && x == 40){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 188);
			}else if((y == 8 && x < 22) || (y == 8 && x > 38)){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf(" ");
			}else if((y == 12 && x < 22) || (y == 12 && x > 38)){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf(" ");
			}else if(y != 8 && y != 12){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf(" ");
			}
		}
		printf("\n");	
	}
	SetConsoleTextAttribute(hConsole, 15);
	getch();
}

void finish(HANDLE hConsole){
	SetConsoleTextAttribute(hConsole, 14);
	for(int y = 2; y <= 18; y++){
		for(int x = 20; x <= 40; x++){
			if(y == 2 && x == 20){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 201);
			}else if((y == 2 && (x > 20 && x < 40)) || (y == 18 && (x > 20 && x < 40))){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 205);
			}else if(y == 2 && x == 40){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 187);
			}else if(y > 2 && y < 18 && (x == 20 || x == 40)){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 186);
			}else if(y == 18 && x == 20){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 200);
			}else if(y == 18 && x == 40){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf("%c", 188);
			}else{
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				printf(" ");
			}
		}
		printf("\n");	
	}
	for(int y = 2; y < 18; y++){
		for(int x = 20; x < 40; x++){
			if(y == 4 && x == 21){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("      .-===-.");	
				break;
			}else if(y == 5 && x == 21){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("      \\'-=-'/");
				break;
			}else if(y == 6 && x == 21){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("        \\Y/");
				break;
			}else if(y == 7 && x == 21){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("     .-''^''-.");
				break;
			}else if(y == 8 && x == 21){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("    /'.''^''.'\\");
				break;
			}else if(y == 9 && x == 21){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("   | /       \\ |");
				break;
			}else if(y == 10 && x == 21){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("   | |       | |");
				break;
			}else if(y == 11 && x == 21){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("   \\ \\       / /");
				break;
			}else if(y == 12 && x == 21){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("    '.''---''.'");
				break;
			}else if(y == 13 && x == 21){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("      ''---''");
				break;
			}else if(y == 16 && x == 20){
				gotoxy(x+OFFSET_X,y+OFFSET_Y);
				puts("YOU'VE FOUND THE RING");
			}
		}
	}
	SetConsoleTextAttribute(hConsole, 15);
	getch();
}

void clearMap(){
 	for(int y=0; y<HEIGHT; y++){
  		for(int x=0; x<WIDTH; x++){
   			map[y][x] = WALL;
  		}
 	}
}

void caption(int a){
	int keyFound = 0;
	int bye = 0;
	gotoxy(OFFSET_X, 28);
	if(a == 1){
		printf("Go get the key!                                           ");
	}else if(a == 2){
		//dapet key
		keyFound = 1;
		printf("Go to the exit!                                           "); Sleep(500);
	}else if(a == 3){
		//kena bot
		printf("Ouch! Blood drained!"); Sleep(500);
	}else if(a == 4){
		//sekarat
		printf("OMG! This is your last chance, be careful!"); Sleep(500);
	}else if(a == 5){
		printf("Oh no! Good bye!                                          "); Sleep(500);
		bye = 1;
	}
	gotoxy(OFFSET_X, 28);
	if(bye == 1) printf("Oh no! Good bye!                                          ");
	else if(keyFound == 0) printf("Go get the key!                                           ");	
	else printf("Go to the exit!                                           ");
	
}

int mainGame(HANDLE hConsole, int totalScore, char closing[]){
	int choose;
	int lvl = 1;
	int interval = 460;
	
	while(lives > 0){
		srand(time(NULL));
		gotoxy(OFFSET_X,0);
		printf("\n\t\t\t\t\t\t     << LEVEL %-2d >>", lvl);
		printLives(lives, totalScore, hConsole);
		caption(1);
		generateMaze();
		printBorder();
		initHero();
		initBot();
		if(lvl > 3) initBot2();
		if(lvl > 6) initBot3();
		generateKey();
		bool isRetrieved = false; 
		char key = tolower(getch());
		while(hero.x != WIDTH-1 && lives > 0){ 
			Sleep(interval);
			if(kbhit()){
				char newKey = tolower(getch());
				key = newKey;
			}
			printMap();
			moveBot();
			if(lvl > 3) moveBot2();
			if(lvl > 6) moveBot3();
			
			if((hero.x == bot.x && hero.y == bot.y) || (hero.x == bot2.x && hero.y == bot2.y) || (hero.x == bot3.x && hero.y == bot3.y)){
				lives--;
				gotoxy(hero.x+OFFSET_X,hero.y+OFFSET_Y);
				printf("X");
				Sleep(500);
				gotoxy(WIDTH+OFFSET_X,HEIGHT+OFFSET_Y);
				printLives(lives, totalScore, hConsole);
				if(lives != 1 && lives != 0) caption(3);
				else if(lives == 1) caption(4);
				else caption(5);
			}
			
			moveHero(key);
			
			if((hero.x == bot.x && hero.y == bot.y) || (hero.x == bot2.x && hero.y == bot2.y) || (hero.x == bot3.x && hero.y == bot3.y)){
				lives--;
				gotoxy(hero.x+OFFSET_X,hero.y+OFFSET_Y);
				printf("X");
				Sleep(500);
				gotoxy(WIDTH+OFFSET_X,HEIGHT+OFFSET_Y);
				printLives(lives, totalScore, hConsole);
				if(lives != 1 && lives != 0) caption(3);
				else if(lives == 1) caption(4);
				else caption(5);
			}
			
			if(isRetrieved == false){ 
				respawnKey(); 
				isRetrieved = checkKeyRetrieval();
				if(isRetrieved == true){
					totalScore += 10;
					printLives(lives, totalScore, hConsole);
					caption(2);
				}
			}
		}
		totalScore = totalScore + (lvl*lives*10);
		lvl++;
		if(interval > 100) interval-=40;
		else interval-=50;
		if(lvl == 11 && lives != 0){
			finish(hConsole);
			system("cls");
			choose = story(hConsole, closing, 1);
			if(choose == 2) lives = 0;
		}
		if(choose == 1 && lvl == 11) system("cls");
		if(lives > 0) nextLevel(lvl, hConsole);
		clearMap();
		closeWall();
	}
	return totalScore;
}

int main(){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	dataPlayer = readFile();
	
	int x;
	int menu;
	int totalScore = 0;
	char opening[] = {
   "\t\t\t\t  One day, an Evil Sorcerer steals King's precious ring.\n\t\t\tThe ring holds enermous power that keeps the kingdom safe from any danger.\n\t It is really valuable, that the King decided to send his best Knight on a mission to take the ring back.\n    However, it is not an easy task as the Evil Sorcerer hide the ring in a maze full of tricks to confuse the Knight.\t\t\t\t        The maze consists of 10 dangerous stages.\n\t\t     To pass each of them, the Knight needs to find 10 keys hidden by the Evil Sorcerer.\n     The key is needed to unlock the door to the next stage and each stage is harder to pass than the previous stage.\n\n\n\t\t\t\t   And that's when the Knight's journey begin..."
	};
	char closing[] = {
   "\t\t\t\t\t\tAfter a long journey...\n     The Knight is finally succeeded to complete each of the 10 stages of the maze and steal the King's ring back.\n\tThe King is very happy with the news and present the Knight with tremendous gifts of diamonds and golds.\n\t\t  The King also offer an important job to the Knight to be the Kingdom's guardian.\n\t\t\tThe job is to continue to protect the Kingdom from the Evil Sorcerer.\n\t\t      However, the Knight can choose to decline the King's offer if he wish so.\n\t\t\t\t\tWhat will be the Knight decision ?"
	};
	
	while(1){
		system("cls");
		
		menu = 1;
		openingMenu();
		menu1(hConsole, 7);
		menu2(hConsole, 8);
		menu3(hConsole, 8);
		fflush(stdin);
		
		do{
			do{
				x = getch();
			}while(x != KEY_UP && x != KEY_DOWN && x != ENTER);
			
			if(x == ENTER) break;
			
			system("cls");
			openingMenu();
			
			if((x == KEY_UP && menu == 2) || (x == KEY_UP && menu == 1)){
				menu1(hConsole, 15);
				menu2(hConsole, 8);
				menu3(hConsole, 8);
				menu = 1;
			}else if((x == KEY_DOWN && menu == 1) || (x == KEY_UP && menu == 3)){
				menu1(hConsole, 8);
				menu2(hConsole, 15);
				menu3(hConsole, 8);
				menu = 2;
			}else if((x == KEY_DOWN && menu == 2) || (x == KEY_DOWN && menu == 3)){
				menu1(hConsole, 8);
				menu2(hConsole, 8);
				menu3(hConsole, 15);
				menu = 3;
			}
		}while(x != ENTER);
		
		switch(menu){
			case 1:
				lives = 5;
				totalScore = 0;
				system("cls");
				openingMenu();
				SetConsoleTextAttribute(hConsole, 15);
				story(hConsole, opening, 0);
				system("cls");
				totalScore = mainGame(hConsole, totalScore, closing);
				if(lives == 0){
					list[dataPlayer].score = totalScore;
					savePlayerData(hConsole);
					getch();
				}
				break;
			case 2:
				system("cls");
				openingMenu();
				leaderboard(hConsole);
				getch();
				break;
			case 3:
				system("cls");
				printf("\n\n\n\n\n\n\n");
				SetConsoleTextAttribute(hConsole, 11);  
				puts("\t\t\t\t  ______ _______ _______    _     _ _______ _     _    _ "); Sleep(50);
				puts("\t\t\t\t / _____|_______|_______)  | |   | (_______|_)   (_)  | |"); Sleep(50);
				puts("\t\t\t\t( (____  _____   _____     | |___| |_     _ _     _   | |"); Sleep(50);
				puts("\t\t\t\t \\____ \\|  ___) |  ___)    |_____  | |   | | |   | |  |_|"); Sleep(50);
				puts("\t\t\t\t _____) ) |_____| |_____    _____| | |___| | |___| |   _ "); Sleep(50);
				puts("\t\t\t\t(______/|_______)_______)  (_______|\\_____/ \\_____/   |_|"); Sleep(50);
				printf("\n\n\n\n\n\n\n");
				saveFile();
				getch();
				
				break;
		}
		if(menu == 3) break;
	}
	
	return 0;
}
