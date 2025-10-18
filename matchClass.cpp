#include <iostream>
#include <iomanip>
using namespace std;

static int matchNo = 0;

class matchrecord{
	private:
		int matchNumb;
		int ply1Goals, ply2Goals;
		string ply1, ply2;
	public:
		matchrecord(string ply1, int ply1Goals, int ply2Goals, string ply2):matchNumb(++matchNo), ply1(ply1), ply1Goals(ply1Goals), ply2Goals(ply2Goals), ply2(ply2){
		}
		void display(){
			cout.unsetf(ios::left);
			cout << "\t     | " << setw(12) << ply1 <<"  "<< setw(2) << ply1Goals << "  :  "; cout.setf(ios::left); cout << setw(2) << ply2Goals << "  " << setw(12) << ply2 << " |" << endl;
		}
};

static matchrecord* RecList[100];



