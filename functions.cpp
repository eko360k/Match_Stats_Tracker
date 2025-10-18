#include <iostream>
#include <iomanip>
#include <cstring>
#include<conio.h> 
#include<sstream>
#include "playerClass.cpp"
#include "matchClass.cpp"
#include "tables.cpp"

using namespace std;

int main();
string getname();
int getnumb();
void makeBar(char c, int x);
void EnterMatchResults();
void viewtable();
void getplayersthenplay();
void ReferenceTable();

void addMatchRec(string ply1, int ply1Goals, int ply2Goals, string ply2){
	RecList[matchNo-1] = new matchrecord(ply1, ply1Goals, ply2Goals, ply2);
}

void showMatchRecord(){
	if (matchNo < 1){
		cout << "\n\t\tNo match played yet!\n" << endl;
		system("PAUSE");
		main();
	}
	else{
		cout << "\t     "; makeBar('-', 41);
		cout << "\t     |             Match Records             |" << endl;
		cout << "\t     "; makeBar('-', 41);
		for(int i = matchNo; i>=0; i--){
			if(RecList[i]!=NULL){
				RecList[i]->display();
			}
		}
		cout << "\t     "; makeBar('-', 41);
	}
	
	char c;
	cout << endl;
	cout << "\nPress Esc to return to main menu; ";
	do{
			c = getch();
		}
		while (c!=27);
		main();
}

void player::playmatch(player *Pone, player *Ptwo){
	List[20];
	int goalsP1, goalsP2;
	
	cout << "\n\n\t\t\tOngoing Match" << endl;
	cout <<"\t\t     "<< Pone->getPname() << " verses " << Ptwo->getPname();
	
	cout << "\n\t     Enter goals scored by "<< Pone->getPname() << "  ";			goalsP1=getnumb();
	
	if (goalsP1 > 100){
		do {
			cout << "Enter a valid score: ";	goalsP1=getnumb();
		}while(goalsP1 > 100);
	}

	cout << "\n\t     Enter goals scored by "<< Ptwo->getPname() << "  ";			goalsP2=getnumb();
	
	if (goalsP2 > 100){
		do {
			cout << "Enter a valid score: ";	goalsP1=getnumb();
		}while(goalsP2 > 100);
	}
	
	Pone->match();
	Ptwo->match();
	
	Pone->getgoalsScored(goalsP1);
	Ptwo->getgoalsScored(goalsP2);
	
	Pone->getgoalsConceeded(goalsP2);
	Ptwo->getgoalsConceeded(goalsP1);
	
	if(goalsP1 > goalsP2){
		Pone->getwin();
		Ptwo->getloss();
	}
	else if(goalsP2 > goalsP1){
		Ptwo->getwin();
		Pone->getloss();
	}
	else {
		Pone->getdraw();
		Ptwo->getdraw();
	}
	
	addMatchRec(Pone->getPname(), goalsP1, goalsP2, Ptwo->getPname());
	char c;
	cout << endl;
	cout << "\n\t     Press 1 to enter next match results \n\t           2 to view tornament table \n\t           Esc to return to main menu ";

	do{
		c = getch();
		if (c==27) main();
		else if (c=='1') {
			cout << "\n\n\t           Next match..." << endl;
			getplayersthenplay();
		}
		else if (c=='2') viewtable();
	}
	while (c!='1'&&c!='2'&&c!=27);
}

void getplayersthenplay(){
	int ply1, ply2;
	if(playerID==3){
		ply1 = 1;
		ply2 = 2;
	}
	else {
		cout << "\t\tEnter ID of player1 ";		ply1 = getnumb();
		if(ply1>=playerID){
			cout << "\n\t\tEnter a valid playerID for player1 ";
			do {
				cout << "\n\t\tTry again  ";
				ply1 = getnumb();
			}while(playerID < ply1);	
		}
		cout << "\n\t\tEnter ID of player2 ";	ply2 = getnumb();
		if(ply2>=playerID || ply2 == ply1){
			do {
				if(ply2 == ply1){
					cout << "\n\t\tThis player has already been selected!";
				}
				else{
					cout << "\n\t\tEnter a valid playerID for player2 ";
				}
				cout << "\n\t\tTry again  ";
				ply2 = getnumb();
			}while(playerID < ply2 || ply2==ply1);
		}
	}			
		player::playmatch(List[ply1], List[ply2]);
}

void bsort(player** pp, int n){
	void order(player**, player**);
	int j,k;
	for(j=0; j<n-1; j++)
		for(k=j+1; k<n; k++)
			order(pp+j, pp+k);
}

//Point, wins, matchesPlayed, avewins, goalDifference

void order(player** pp1, player** pp2){
	if(*pp1==NULL || *pp2==NULL){}
	else if( (*pp1)->getPoints() == (*pp2)->getPoints() ){
		if( (*pp1)->getWins() == (*pp2)->getWins() ){
			if(  (*pp1)->getMatches() == (*pp2)->getMatches() ){
				if( (*pp1)->getAvrwins() == (*pp2)->getAvrwins() ){
					if( (*pp1)->goaldiff() < (*pp2)->goaldiff() ){
						player* tempptr = *pp1;
						*pp1 = *pp2;
						*pp2 = tempptr;
					}
				}
				else if( (*pp1)->getAvrwins() < (*pp2)->getAvrwins() ){
					player* tempptr = *pp1;
					*pp1 = *pp2;
					*pp2 = tempptr;
				}
			}
			else if(  (*pp1)->getMatches() < (*pp2)->getMatches() ){
				player* tempptr = *pp1;
				*pp1 = *pp2;
				*pp2 = tempptr;
			}	
		}
		else if( (*pp1)->getWins() < (*pp2)->getWins() ){
			player* tempptr = *pp1;
			*pp1 = *pp2;
			*pp2 = tempptr;
		}
	}	
	else if( (*pp1)->getPoints() < (*pp2)->getPoints() ){
		player* tempptr = *pp1;
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
	
}

void createPlayer(){
	bool stay = true;
		
	system("cls");
	
	cout << "\n\tADDING A NEW PLAYER" << endl;
	while(stay){
		string name;
		int id = playerID;
		cout << "Enter player name: ";		
		bool next = true;
		do{
			name = getname();
			cout << endl;
			for(int i=0; i<playerID; i++){
				if(List[i]!=NULL){
					if(List[i]->getPname()==name){
						cout << "\nName already exist. Enter a different name: ";
						next = false;
					}	
				}
				else(next = true);
			}
		}while(!next);
		
		List[id] = new player(name);
		cout << "\nPress 1 to add another player \n      Esc to return to main menu ";
		char c;
		do{
			c = getch();
			if (c=='1'||c==27){
				if(c=='1'){
					stay = true;
					cout <<"\n"<< endl;
				}
				else if (c==27)	{stay = false;}
						
			}							
		} while	(c!='1'&&c!=27);
	}
	main();
}


void viewtable(){
	system("cls");
	char c;
	cout << "\n\t\t\tTOURNAMENT STANDINGS" << endl;
	makeBar('-', 87);
	
	if (playerID < 2){
		cout << "\t\tThere are no players registered yet." << endl;
		makeBar('_', 87);
		cout << "\n    Press 1 to add a new player or Press Esc to return to main menu ";
		
		do{
			c = getch();
			if (c=='1'||c==27){
				if(c=='1'){
					createPlayer();
				}
				else if (c==27){
					main();
				}
			}	
		}while(c!='1'||c!=27);
	}

	else {
		player* Pos[20];
		for(int i=0;i<20;i++){
			Pos[i]=List[i];
		}
		cout.setf(ios::left);
		cout <<setw(16) << "| Players      |"; 
		cout.unsetf(ios::left);
		cout << setw(7)<< "  PM  |" << setw(6) << "  W  |" << setw(6) << "  D  |" << setw(6) << "  L  |" << setw(7)  << "  GF  |" << setw(7) << "  GA  |" << setw(7) << "  GD  |" << setw(7) << "  W%  |" << setw(11) << " AvgGoals |" << setw(7)<< "  PTS |" << endl;
	
		makeBar('_', 87);
		
		bsort(Pos, playerID);
		
		for(int i=0; i < 20; i++){
			while(i<20 && Pos[i]!=NULL){
				Pos[i]->displaystat();
				i++;
			}
		}
		makeBar('_', 87);
		cout << endl;
		cout << "\nPress 1 to enter match result " << endl;
		cout << "      Esc to return to main menu ";
		do{
			c = getch();
			if(c==27) main();
			else if(c=='1') EnterMatchResults();
		}
		while (c!=27||c!=1);
		
	}		
}

void ReferenceTable(){
	cout << "\n\t     Reference for current players" << endl;
	cout << "\t\t";
	makeBar('-', 23);
	cout.setf(ios::left);
	cout << "\t\t" << setw(16) << "| Players      |";
	cout.unsetf(ios::left);
	cout << setw(7)<< "  ID  |" <<endl;
	cout << "\t\t";
	makeBar('-', 23);

	for(int i=0; i<20; i++){
		if(List[i]!=NULL){
				cout.setf(ios::left); 
				cout << "\t\t| " << setw(12) << List[i]->getPname() << " | ";
				cout.unsetf(ios::left);
				cout << setw(4) << List[i]->getID() << " |" << endl;
		}	
	}
	cout << "\t\t";
	makeBar('-', 23);
	cout << endl;
}

void EnterMatchResults(){
	system("cls");
	cout << "\t\t\tNEW GAME" << endl;
	if(playerID<2){
		cout << "Not enough players are registered to play!" << endl;
		cout << "Returning to the main menu" << endl;
		system("PAUSE");
		main();
		}

	ReferenceTable();		
	getplayersthenplay();		
}
