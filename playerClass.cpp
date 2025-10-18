#include <iostream>
#include <iomanip>
using namespace std;

static int playerID=1;


class player{
	private:
		string Pname;
		unsigned int Pmatches, Pwins, Pdraws, Ploss, goalsfor, goalsagainst, Points;
		int PID;
	public:
		
		player(string name):Pname(name),Pmatches(0),Pwins(0),Pdraws(0),Ploss(0),goalsfor(0),goalsagainst(0),Points(0),PID(playerID++){
			
			
			
			cout << "\nNew player created with name: " << Pname << "\nAssigned ID: " << PID << endl;
		}
		
		void displaystat(){
			cout.setf(ios::left);
			cout << "| " << setw(12) << Pname << " | ";
			cout.unsetf(ios::left);
			cout << setw(4) << Pmatches << " | " << setw(3) << Pwins << " | "<< setw(3) << Pdraws << " | " << setw(3) << Ploss << " | " <<  setw(4) << goalsfor << " | " << setw(4) << goalsagainst << " | " << setw(4) << goaldiff() << " | "; getavrwins();
			cout << " | "; getavrgoals(); cout << " | " << setw(4) << Points << " | "  << endl;
		}
		
		void getavrgoals(){
			
			if (Pmatches == 0||goalsfor==0) {cout << setw(6) << 0 << ".0";}
			else{
				
				double gf = static_cast<double>(goalsfor);
				double pm = static_cast<double>(Pmatches);
				double avegoals = gf/pm;
				int intavegoals = gf/pm;
				if(avegoals-intavegoals==0){
					cout << setw(6) << intavegoals << ".0";
				}
				else{
					cout << setiosflags(ios::fixed) << setprecision(1) << setw(8) << (gf/pm);
				}	
			}	
		}
		
		int goaldiff(){
			return goalsfor - goalsagainst;
		}
		
		int getPlyPoints(){
			return Points;
		}
		double getAvrwins(){
			if(Pmatches== 0){
				return 0;
			}
			return Pwins/Pmatches;
		}
		void getavrwins(){
			if (Pmatches == 0||Pwins==0) {cout << setw(4) << 0;}
			else{
				double pw = static_cast<double>(Pwins);
				double pm = static_cast<double>(Pmatches);
				double avewins = (pw/pm)*100;
				int intavewins = (pw/pm)*100;
				if (avewins==100) cout << setw(4) << 100;
				else if (avewins-intavewins==0){
					cout << setw(4) << intavewins;
				}
				else{
					cout << setiosflags(ios::fixed) <<  setprecision(1) << setw(4) << avewins;
				}		
			}	
		}
		
		string getPname(){
			return Pname;
		}
		
		int getID(){
			return PID;
		}
		
		int getPoints(){
			return Points;
		}
		
		int getWins(){
			return Pwins;
		}
		
		int getMatches(){
			return Pmatches;
		}
		
		void getgoalsScored(int goals){
			goalsfor += goals;	
		}
		
		void getgoalsConceeded(int goals){
			goalsagainst += goals;
		}
		
		void match(){Pmatches++;}
		
		void getwin(){
			++Pwins;
			Points += 3; 
		}
		
		void getloss(){++Ploss;}
		
		void getdraw(){
			++Pdraws;
			Points += 1;
		}
		
		static void playmatch(player *Pone, player *Ptwo);
		
		void createPlayer();
};

static player* List[20];
