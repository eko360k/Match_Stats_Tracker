#include <iostream>
#include<conio.h> 
#include<sstream>
//#include "playerClass.cpp"

using namespace std;

int main();

void makeBar(char c, int x){
	for(int i=0; i<x; i++){
		cout << c;
	}
	cout << endl;
}

int getnumb(){
	string goals;
	char ch;

	do{
		
		if (ch == 27){main();}
		else if (ch=='\b'){
			if (!goals.empty()){
				goals = goals.substr(0, goals.size()-1);
				cout << "X " << goals;
			}	
		}
		else if (ch >= 48 && ch <= 57){
			cout << ch;
			goals+=ch;
		}
	}while((ch = getch()) != '\r' || goals.empty() );
	stringstream value;
	value << goals;
	int score;
	value >> score;
	return score;
}

string getname(){
	string name;
	char ch;
	cout << "\n";	
	do{
		if(ch == 27) main();
		else if(ch=='\b'){
			if (!name.empty()){
				name = name.substr(0, name.size()-1);
			}
		}
		else if(ch >= 64 && ch <= 122) {
			name += ch;
		}
	}while((ch = getche()) != '\r'||name.empty());

	return name;
}

