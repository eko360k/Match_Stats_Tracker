#include <iostream>
#include<conio.h>

using namespace std;

void EnterMatchResults();
void viewtable();
void createPlayer();
void showMatchRecord();

int main() {

	do{
		system("cls");

		cout << "\tMAIN MENU" << endl;
		cout << "Select an option" << endl;
		cout << "1. Enter match results" << endl;
		cout << "2. View tornament table" << endl;
		cout << "3. View match record" << endl;
		cout << "4. Add new player" << endl;
		cout << "5. Exit." << endl;
		char op = getche();

		switch (op){
			case '1':	EnterMatchResults();
						break;

			case '2':	viewtable();
						break;
						
			case '3':	system("cls");
						showMatchRecord();
						break;

			case '4':	system("cls");
						createPlayer();
						break;

			case '5':	exit(0);	
						break;				
		}

	} while(1);
		
	
	return 0;
}
