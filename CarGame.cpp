#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define screen_width 120
#define screen_height 33
#define window_width 100

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemy_X[3];
int enemy_Y[3];
int enemyFlag[3];
char car1[4][4] = { ' ','+','+',' ',
	 		   	    '+','+','+','+',
 					' ','+','+',' ',
					'+','+','+','+'};

char car2[4][4] = { ' ','-','-',' ',
	 		   	    '-','-','-','-',
 					' ','-','-',' ',
					'-','-','-','-'};

char car3[4][4] = { ' ','|','|',' ',
	 		   	    '|','|','|','|',
 					' ','|','|',' ',
					'|','|','|','|'};

char car4[4][4] = { ' ','#','#',' ',
	 		   	    '#','#','#','#',
 					' ','#','#',' ',
					'#','#','#','#'};

char car5[4][4] = { ' ','|','|',' ',
	 		   	    '+','+','+','+',
 					' ','|','|',' ',
					'+','+','+','+'};

char car6[4][4] = { ' ','#','#',' ',
	 		   	    '+','+','+','+',
 					' ','#','#',' ',
					'+','+','+','+'};
char car[4][4];

int carposition = window_width/2;
int score = 0;
int highest_score = 0;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition( console, CursorPosition );
}
void printcar(char car[4][4],int x, int y) {
    for(int i = 0; i < 4; i++) {
            int p = x;
        for(int j = 0; j < 4; j++) {
            gotoxy(p,y);cout << car[i][j];
            p++;
        }
    cout<<endl;
    y++;

    }
}
int choosecar(char choosen){
    if (choosen =='1'){
        for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            car[i][j] = car1[i][j];
        }
    }
    return 1;
    }
    else if (choosen =='2'){
        for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            car[i][j] = car2[i][j];
        }
    }
    return 1;
    }
    else if (choosen =='3'){
        for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            car[i][j] = car3[i][j];
        }
    }
    return 1;
    }
    else if (choosen =='4'){
        for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            car[i][j] = car4[i][j];
        }
    }
    return 1;
    }
    else if (choosen =='5'){
        for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            car[i][j] = car5[i][j];
        }
    }
    return 1;
    }
    else if (choosen =='6'){
        for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            car[i][j] = car6[i][j];
        }
    }
    return 1;
    }
    return 0;
	
}

void setcursor(bool visible, DWORD size) {
	if(size ==0)
	size  = 50;

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void Border(){
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for(int i=0; i<screen_height; i++){
		for(int j=0; j<18; j++){
			gotoxy(0+j,i);
			 cout<<"*";
			gotoxy(window_width-j,i);
			 cout<<"*";
		}
	}
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
	
void genEnemy(int index){
	enemy_X[index] = 17 + rand()%(54);
}

void Enemy(int index){
	if( enemyFlag[index]== true ){
		if(index == 0){
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
		gotoxy(enemy_X[index] , enemy_Y[index]);    cout<<"####";
		gotoxy(enemy_X[index] , enemy_Y[index]+1);  cout<<" ## ";
		gotoxy(enemy_X[index] , enemy_Y[index]+2);	cout<<"####";
		gotoxy(enemy_X[index] , enemy_Y[index]+3);  cout<<" ## ";
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else if(index == 1){
		SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		gotoxy(enemy_X[index] , enemy_Y[index]);    cout<<"++++";
		gotoxy(enemy_X[index] , enemy_Y[index]+1);  cout<<" || ";
		gotoxy(enemy_X[index] , enemy_Y[index]+2);	cout<<"++++";
		gotoxy(enemy_X[index] , enemy_Y[index]+3);  cout<<" || ";
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}

        else{
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		gotoxy(enemy_X[index] , enemy_Y[index]);    cout<<"++++";
		gotoxy(enemy_X[index] , enemy_Y[index]+1);  cout<<" ** ";
		gotoxy(enemy_X[index] , enemy_Y[index]+2);	cout<<"++++";
		gotoxy(enemy_X[index] , enemy_Y[index]+3);  cout<<" ** ";
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
}

void eraseEnemy(int index){
	if( enemyFlag[index]== true ){
		gotoxy(enemy_X[index] , enemy_Y[index]); 		cout<<"    ";
		gotoxy(enemy_X[index] , enemy_Y[index]+1);		cout<<"    ";
		gotoxy(enemy_X[index] , enemy_Y[index]+2);		cout<<"    ";
		gotoxy(enemy_X[index] , enemy_Y[index]+3);		cout<<"    ";
		gotoxy(window_width -37, 0);  cout<<"     ||     ";
		gotoxy(window_width -37, 5);  cout<<"     ||     ";
		gotoxy(window_width -37, 10); cout<<"     ||     ";
		gotoxy(window_width -37 , 15); cout<<"     ||     ";
		gotoxy(window_width -37, 20); cout<<"     ||     ";
		gotoxy(window_width -37, 25); cout<<"     ||     ";
		gotoxy(window_width -37, 30); cout<<"     ||     ";
        gotoxy(window_width -72, 0);  cout<<"     ||     ";
		gotoxy(window_width -72, 5);  cout<<"     ||     ";
		gotoxy(window_width -72, 10); cout<<"     ||     ";
		gotoxy(window_width -72, 15); cout<<"     ||     ";
		gotoxy(window_width -72, 20); cout<<"     ||     ";
		gotoxy(window_width -72, 25); cout<<"     ||     ";
		gotoxy(window_width -72, 30); cout<<"     ||     ";
	}
}

void resetEnemy(int index){
	eraseEnemy(index);
	enemy_Y[index] = 1;
	genEnemy(index);
}

void Car(){
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carposition, i+26);  cout<<car[i][j];
		}
	}
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void eraseCar(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carposition, i+26);  cout<<" ";
		}
	}
}

int collision(){
	if( enemy_Y[0] + 4 >=27){
		if(enemy_X[0] + 4 -carposition >=0 && enemy_X[0] + 4 -carposition <8){
			return 1;
		}
	}
	if(enemy_Y[1] + 4 >=27){
        if(enemy_X[1] + 4 -carposition >=0 && enemy_X[1] + 4 -carposition <8)
            return 1;
	}
    if(enemy_Y[2] + 4 >=27){
        if(enemy_X[2] + 4 -carposition >=0 && enemy_X[2] + 4 -carposition <8)
            return 1;
	}
	return 0;
}

void gameover(){
	system("cls");
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout <<"\t #####     #    #     # #######    ####### #     # ####### ######     ###\n"; 
    cout <<"\t#     #   # #   ##   ## #          #     # #     # #       #     #    ###\n"; 
    cout <<"\t#        #   #  # # # # #          #     # #     # #       #     #    ###\n"; 
    cout <<"\t#  #### #     # #  #  # #####      #     # #     # #####   ######      #\n"; 
    cout <<"\t#     # ####### #     # #          #     #  #   #  #       #   #          \n"; 
    cout <<"\t#     # #     # #     # #          #     #   # #   #       #    #     ### \n";
    cout <<"\t #####  #     # #     # #######    #######    #    ####### #     #    ###\n";
	cout<<endl;
	cout<<endl;
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	
	if(score>highest_score){
        highest_score = score;
        cout<<"\t\tCongratulations! You Created A New High Score!"<<endl<<endl;
	}
	cout<<"\t\t\t\t  Score : "<<score<<endl<<endl;
	cout<<"\t\t      Press any Key to go back to menu.";
	getch();
}

void updateScore(){
	gotoxy(window_width +7, 5);
	cout<<"\tScore: "<<score<<endl;
}

void play(int n){
	carposition = -1 + window_width/2;
	score = 0;
	enemyFlag[0] = 1;
	enemyFlag[1] = 0;
    enemyFlag[2] = 0;
	enemy_Y[0] = enemy_Y[1] = enemy_Y[2] = 1;

	system("cls");
	Border();
	updateScore();
	genEnemy(0);
	genEnemy(1);
    genEnemy(2);
	gotoxy(window_width +4, 7); cout<<"\tHighest Score: "<<highest_score<<endl;

	gotoxy(18, 5);cout<<"Press any key to start";
	getch();
	gotoxy(18, 5);cout<<"                      ";

	while(1){
		if(kbhit()){
			char ch = getch();
			if( ch=='a' || ch=='A' || ch == 75 ){
				if( carposition > 18 )
					carposition -= 4;
			}
			if( ch=='d' || ch=='D' || ch== 77 ){
				if( carposition < 77 )
					carposition += 4;
			}
			if(ch=='x' || ch=='X'){
				break;
			}
		}

		Car();
		Enemy(0);
		Enemy(1);
        Enemy(2);
		if( collision() ==1 ){
			gameover();
			return ;
		}
		Sleep(n);
		eraseCar();
		eraseEnemy(0);
		eraseEnemy(1);
        eraseEnemy(2);

		if( enemy_Y[0] == 10 ){
			if( enemyFlag[1] == 0 )
				enemyFlag[1] = 1;
        }
        if( enemy_Y[1] == 10 ){
			if( enemyFlag[2] == 0 )
				enemyFlag[2] = 1;
        }

		if( enemyFlag[0] == 1 )
			enemy_Y[0] += 1;

		if( enemyFlag[1] == 1 )
			enemy_Y[1] += 1;

        if( enemyFlag[2] == 1 )
			enemy_Y[2] += 1;

		if( enemy_Y[0] > screen_height-4 ){
			resetEnemy(0);
			score++;
			updateScore();
		}
		if( enemy_Y[1] > screen_height-4 ){
			resetEnemy(1);
			score++;
			updateScore();
		}
        if( enemy_Y[2] > screen_height-4 ){
			resetEnemy(2);
			score++;
			updateScore();
        }
	}
}

void diff(int n){
    system("cls");
gotoxy(10,10); cout<<"\t\t    Please Choose a Car Below to Continue";
		gotoxy(5,15);cout << "    1."<<endl; 
		{SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printcar(car1,9,16);
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);}
		gotoxy(20,15);cout << "    2."<<endl;{
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printcar(car2,24,16);
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);}
		gotoxy(35,15);cout << "    3."<<endl;{
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printcar(car3,39,16);
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);}
		gotoxy(50,15);cout << "    4."<<endl;{
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printcar(car4,54,16);
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);}
		gotoxy(65,15);cout << "    5."<<endl;{
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printcar(car5,69,16);
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);}
		gotoxy(80,15);cout << "    6."<<endl;{
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printcar(car6,84,16);
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);}
		gotoxy(5,21); cout << "Select A Car: ";
        char choosen = getche();
        if(choosecar(choosen))
			play(n);
        else{cout << endl;
        gotoxy(10,25);cout <<"Invalid choice. Choose again"<< endl;
        gotoxy(10,26);cout << "Press Any Key To Continue"<<endl;
        getch();
        }
}


void drawLogo() {
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<endl;
	cout<<"\t #####     #    ######     ######     #     #####  ### #     #  #####       #####     ###### \n"; 
	cout<<"\t#     #   # #   #     #    #     #   # #   #     #  #  ##    # #     #     #     #    #     #\n"; 
	cout<<"\t#        #   #  #     #    #     #  #   #  #        #  # #   # #                 #    #     #\n"; 
	cout<<"\t#       #     # ######     ######  #     # #        #  #  #  # #  ####      #####     #     #\n"; 
	cout<<"\t#       ####### #   #      #   #   ####### #        #  #   # # #     #     #          #     #\n"; 
	cout<<"\t#     # #     # #    #     #    #  #     # #     #  #  #    ## #     #     #          #     #\n"; 
 	cout<<"\t #####  #     # #     #    #     # #     #  #####  ### #     #  #####      ####### ## ###### \n";
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main(){
	setcursor(0,0);
	srand( (unsigned)time(NULL));

	do{
		system("cls");
 		drawLogo();
        gotoxy(10,10);cout<<"\t\t    Select Level";
        gotoxy(10,12);cout<<"\t\t1. Easy";
        gotoxy(10,13);cout<<"\t\t2. Medium";
        gotoxy(10,14);cout<<"\t\t3. Hard";
        gotoxy(32,30); cout<<"-----Press X to Quit-----";
        char ch = getche();

		if(ch == '1'){
			diff(50);
		}
		else if(ch == '2'){
            diff(40);
        }
        else if(ch == '3'){
            diff(30);
        }
        else if(ch == 'x' || ch == 'X'){
            system("cls");
            exit(0);
        }

	}while(1);

	return 0;
}
