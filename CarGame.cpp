#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define screen_width 90
#define screen_height 29
#define window_width 70

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

char car3[4][4] = { ' ','*','*',' ',
	 		   	    '*','*','*','*',
 					' ','*','*',' ',
					'*','*','*','*'};

char car4[4][4] = { ' ','#','#',' ',
	 		   	    '#','#','#','#',
 					' ','#','#',' ',
					'#','#','#','#'};

char car5[4][4] = { ' ','*','*',' ',
	 		   	    '+','+','+','+',
 					' ','*','*',' ',
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
int choosecar(){
    system("cls");
    gotoxy(10,5);cout<<"\t\t\t-------------------------- ";
	gotoxy(10,6);cout<<"\t\t\t|      Choose A Car      | ";
	gotoxy(10,7);cout<<"\t\t\t--------------------------";
    gotoxy(5,9);cout << "1."<<endl; printcar(car1,5,10);
    gotoxy(20,9);cout << "2."<<endl;printcar(car2,20,10);
    gotoxy(35,9);cout << "3."<<endl;printcar(car3,35,10);
    gotoxy(50,9);cout << "4."<<endl;printcar(car4,50,10);
    gotoxy(65,9);cout << "5."<<endl;printcar(car5,65,10);
    gotoxy(80,9);cout << "6."<<endl;printcar(car6,80,10);
    gotoxy(10,15); cout << "Select A Car: ";
    char choosen = getche();
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
    else{
        cout << endl;
        gotoxy(10,17);cout <<"Invalid choice. Choose again"<< endl;
        gotoxy(10,19);cout << "Press Any Key To Continue"<<endl;
        getch();
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
	for(int i=0; i<screen_height; i++){
		for(int j=0; j<18; j++){
			gotoxy(0+j,i);
			 cout<<"*";
			gotoxy(window_width-j,i);
			 cout<<"*";
		}
	}
	for(int i=0; i<screen_height; i++){
		gotoxy(screen_width,i);
 		cout<<"*";
	}
}

void genEnemy(int index){
	enemy_X[index] = 17 + rand()%(33);
}

void Enemy(int index){
	if( enemyFlag[index]== true ){
		gotoxy(enemy_X[index] , enemy_Y[index]);    cout<<"****";
		gotoxy(enemy_X[index] , enemy_Y[index]+1);  cout<<" ** ";
		gotoxy(enemy_X[index] , enemy_Y[index]+2);	cout<<"****";
		gotoxy(enemy_X[index] , enemy_Y[index]+3);  cout<<" ** ";

	}
}

void eraseEnemy(int index){
	if( enemyFlag[index]== true ){
		gotoxy(enemy_X[index] , enemy_Y[index]); 		cout<<"    ";
		gotoxy(enemy_X[index] , enemy_Y[index]+1);		cout<<"    ";
		gotoxy(enemy_X[index] , enemy_Y[index]+2);		cout<<"    ";
		gotoxy(enemy_X[index] , enemy_Y[index]+3);		cout<<"    ";
		gotoxy(window_width -40, 0);  cout<<"     ||     ";
		gotoxy(window_width -40, 5);  cout<<"     ||     ";
		gotoxy(window_width -40, 10); cout<<"     ||     ";
		gotoxy(window_width -40, 15); cout<<"     ||     ";
		gotoxy(window_width -40, 20); cout<<"     ||     ";
		gotoxy(window_width -40, 25); cout<<"     ||     ";
	}
}

void resetEnemy(int index){
	eraseEnemy(index);
	enemy_Y[index] = 1;
	genEnemy(index);
}

void Car(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carposition, i+22);  cout<<car[i][j];
		}
	}
}

void eraseCar(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carposition, i+22);  cout<<" ";
		}
	}
}

int collision(){
	if( enemy_Y[0] + 4 >=23){
		if(enemy_X[0] + 4 -carposition >=0 && enemy_X[0] + 4 -carposition <8){
			return 1;
		}
	}
	if(enemy_Y[1] + 4 >=23){
        if(enemy_X[1] + 4 -carposition >=0 && enemy_X[1] + 4 -carposition <8)
            return 1;
	}
	return 0;
}

void gameover(){
	system("cls");
	cout<<endl;
	cout<<"\t\t\t----------------------------"<<endl;
	cout<<"\t\t\t--------- Game Over --------"<<endl;
	cout<<"\t\t\t----------------------------"<<endl<<endl;
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
	cout<<"Score: "<<score<<endl;
}

void instructions(){
	system("cls");
	cout<<"Instructions";
	cout<<"\n-----------------";
	cout<<"\n Avoid car by moving left or right.";
	cout<<"\n\n Press 'Arrow Keys' or 'A and D' to move the Car";
	cout<<"\n\n Press 'x' to Exit";
	cout<<"\n\n Press any Key to go back to the menu";
	getch();
}

void play(){
	carposition = -1 + window_width/2;
	score = 0;
	enemyFlag[0] = 1;
	enemyFlag[1] = 0;
	enemy_Y[0] = enemy_Y[1] = 1;

	system("cls");
	Border();
	updateScore();
	genEnemy(0);
	genEnemy(1);

	gotoxy(window_width +7, 2); cout<<"Car Game";
	gotoxy(window_width +6, 4); cout<<"----------";
	gotoxy(window_width +6, 6); cout<<"----------";
	gotoxy(window_width +2, 7); cout<<"Highest Score: "<<highest_score<<endl;
	gotoxy(window_width +7, 12); cout<<"Control ";
	gotoxy(window_width +7, 13); cout<<"-------- ";
	gotoxy(window_width +2, 14); cout<<"A Key - Left";
	gotoxy(window_width +2, 15); cout<<"D Key - Left";
	gotoxy(window_width +2, 15); cout<<"Left Arrow";
	gotoxy(window_width +2, 14); cout<<"Right Ket";

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
				if( carposition < 50 )
					carposition += 4;
			}
			if(ch=='x' || ch=='X'){
				break;
			}
		}

		Car();
		Enemy(0);
		Enemy(1);
		if( collision() ==1 ){
			gameover();
			return ;
		}
		Sleep(50);
		eraseCar();
		eraseEnemy(0);
		eraseEnemy(1);

		if( enemy_Y[0] == 10 )
			if( enemyFlag[1] == 0 )
				enemyFlag[1] = 1;

		if( enemyFlag[0] == 1 )
			enemy_Y[0] += 1;

		if( enemyFlag[1] == 1 )
			enemy_Y[1] += 1;

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
	}
}


int main(){
	setcursor(0,0);
	srand( (unsigned)time(NULL));

	do{
		system("cls");
		gotoxy(10,5); cout<<" -------------------------- ";
		gotoxy(10,6); cout<<" |        Car Game        | ";
		gotoxy(10,7); cout<<" --------------------------";
		gotoxy(10,9); cout<<"1. Start Game";
		gotoxy(10,10); cout<<"2. Instructions";
		gotoxy(10,11); cout<<"3. Quit";
		gotoxy(10,13); cout<<"Select option: ";
		char option = getche();

		if( option == '1'){
        if(choosecar())
			play();
		}
		else if( option =='2'){
			instructions();
		}
		else if( option == '3'){
			exit(0);
		}

	}while(1);

	return 0;
}
