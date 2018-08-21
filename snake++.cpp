#include <iostream>
using namespace std;
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

bool GameOver;
const int width=20;
const int height=20;
int tailX[50],tailY[50];
int nTail=0;


int x,y,fruitX,fruitY,score;
enum eDirection{STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setting(){
	GameOver=false;
	dir = STOP;
	x=width/2;
	y=height/2;
	fruitX = rand()%width;
	fruitY = rand()%height;
	score = 0; 
}

void Visual(){

	system("cls");
	
	for(int i=0;i<width+2;i++){
		cout<<"#";
	}
	cout<<endl;
	
	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){
			
			if(j==0)
				cout<<"#";
			
			if(i==y && j==x)
				cout<<"O";

			else if(i == fruitY && j==fruitX)
				cout<<"*";
			
			else{

				bool printTail = false;

				for(int k=0;k<nTail;k++){
					if(tailX[k]==j && tailY[k]== i){
						cout<<"o";
						printTail = true;
					}
				}
				if(!printTail) 
				cout<<" ";

			}


			if(j==width-1)
				cout<<"#";

		}
		cout<<endl;
	}	

	for(int i=0;i<width+2;i++){
		cout<<"#";
	}
	cout<<endl;
	cout<<"SCORE : "<<score<<endl;
}



void Logic(){

	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X,prev2Y;

	tailX[0] = x;
	tailY[0] = y;

	for(int i=1;i<nTail;i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}


  switch(dir)
  {
  	 case LEFT :
  	 	x--;
  	 	break;

  	 case RIGHT:
  	 	x++;
  	 	break; 

  	 case UP:
  	 	y--;
  	 	break;

  	 case DOWN:
  	 	y++;
  	 	break;

  	 default:
  	 	break;
  }

  if(x >= width)
  	x=0;
  else if( x < 0)
  	x=width-1;
 
  if(y >= width)
  	y=0;
  else if(y < 0)
  	y=width-1;

  for(int i=0;i<nTail;i++){
  	if(tailX[i] == x && tailY[i] == y)
  		GameOver = true;
  }

  if(y== fruitY && x==fruitX){
  	score++;
  	fruitX = rand()%width;
	fruitY = rand()%height;
	nTail++;
  }

}





void Input(){
	if(_kbhit()){
		switch(_getch()){
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				GameOver = true;
				break;	
		}
	}
}





int main(){
	setting();
	while(!GameOver){
		Visual();
		Input();
		Logic();
		Sleep(40);
	}

	return 0;
}