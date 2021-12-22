#include<iostream>
#include<unistd.h>
#include<ctime>
#include<cstdlib>
using namespace std;
string currentBatsmen,currentBowler;
class Team{
    private:
       string name;
       string playernames[3];
       int runs;
    public:
        Team(string teamName,string player1,string player2, string player3){
            this->name=teamName;
            playernames[0]=player1;
            playernames[1]=player2;
            playernames[2]=player3;
        }
    /* Display all the players in both team A and team B */
        void displayPlayers(Team teamB){
            cout << "\nPress Enter to display players: ";
            cin.get();

            cout << "Displaying players...\n";
            usleep(1000 * 1000);

            cout << "--------------------------\t\t--------------------------" << endl;
            cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
            cout << "--------------------------\t\t--------------------------" << endl;
            for (int i = 0; i < 3; i++) {
                cout << "|\t[" << i+1 << "] " << playernames[i] << "\t |";
                cout << "\t\t";
                cout << "|\t[" << i+1<< "] " << teamB.playernames[i] << "\t |";
                cout << endl;

        }
        cout << "--------------------------\t\t--------------------------" << endl << endl;
        }
  /* Start inning by displaying initial inning details */
       void inningsStart(int inning,Team bowlTeam){
            cout << "Press Enter to start inning " << inning;
            cin.get();
            usleep(1000 * 1000);
            cout << "|------------ Inning " << inning << " Starts ------------|" << endl;
            cout << "|----- " << name << " is batting and " << bowlTeam.name<< " is bowling -----|" << endl << endl;
        }
     /* Select current batsman and bowler from batting team and bowler team respectively */
        void batsmanAndBowlerSelector(Team bowlTeam){
           cout << "Press Enter to select batsman and bowler: ";
           cin.get();
            cout << "Selecting batsman and bowler...\n";
            usleep(2000 * 1000);
            currentBatsmen = playerSelector(playernames);
            currentBowler = playerSelector(bowlTeam.playernames);
        cout << "----------------------------------------------------" << endl;
        cout << "\t\t " << name << ": Batsman - " << currentBatsmen <<endl;
        cout << "\t\t " << bowlTeam.name << ": Bowler - " << currentBowler <<endl;
        cout << "----------------------------------------------------" << endl << endl;

        }
    /* Select a player among the given players randomly */
        string playerSelector(string arr[3]){
            srand(time(NULL));
            int randomValue = rand()%3;
            string selectedPlayer = arr[randomValue];
            return selectedPlayer;
        }
    /* Play one inning (6 balls) */
        void playInnings(){
            int sum=0;
            const int BALLS =6;
            for(int i=0;i<BALLS;i++){
                 cout << "Press Enter to bowl...";
                cin.get();
                cout << "Bowling..." << endl << endl;
                usleep(1000 * 1000);
                srand(time(NULL));
                int score = rand()%7;
                sum+=score;
                 cout << "----------------------------------------------------" << endl;
                 cout << "|\t\t" << currentBowler << " to " << currentBatsmen << " " << score << " runs" << endl;
                 cout << "----------------------------------------------------" << endl << endl;
            }
            this->runs = sum;
        }
    /* Display runs scored by batting team in the inning */
        void displayScore(){
             cout << "----------------------------------------------------" << endl;
            cout << "\t\t " << name << " scored " << runs << " runs." << endl;
            cout << "----------------------------------------------------" << endl << endl;
        }
        friend void winner(Team,Team);
    };
/* Decide winner by comparing final scores of both the teams */
    void winner(Team teamA, Team teamB){
        cout << "----------------------------------------------------" << endl;

        if (teamA.runs > teamB.runs) {
            cout << "\t\t Team A is the Winner" << endl;
        } else if (teamA.runs < teamB.runs) {
            cout<< "\t\t Team B is the Winner" << endl;
        } else {
            cout << "\t\t Match Draw" << endl;
        }

        cout << "----------------------------------------------------" << endl << endl;
    }

void greet(){
        cout << "---------------------------------------" << endl;
        cout << "|=========== GULLY CRICKET ===========|" << endl;
        cout << "|                                     |" << endl;
        cout << "|      Welcome to Gully Cricket       |" << endl;
        cout << "---------------------------------------" << endl;
}
int main(){
   greet();
   Team teamA("Riders","Ankit","Anjali","Tanika");
   Team teamB("Royals","Deepu","Rashu","Yash");
   teamA.displayPlayers(teamB);
   teamA.inningsStart(1,teamB);
   teamA.batsmanAndBowlerSelector(teamB);
   teamA.playInnings();
   teamA.displayScore();

   teamB.inningsStart(2,teamA);
   teamB.batsmanAndBowlerSelector(teamA);
   teamB.playInnings();
   teamB.displayScore();
   winner(teamA,teamB);
   return 0;
}
/* Greet users with a welcome message */



/*           Functional Approach        */

// #include <iostream>
// #include <cstdlib>
// #include <unistd.h>
// #include <ctime>
// using namespace std;

// class Team {

// 	public:
// 		string name;
// 		string players[3];
// 		int runs;
// };

// void welcomeUsers();
// void startInning(int, string, string);
// void displayPlayers(string[], string[]);
// void selectBatsmanAndBowler(Team, Team);
// string selectPlayer(string[]);
// int playInning();
// void displayScore(Team);
// void decideWinner(int, int);

// string currentBatsman, currentBowler;


// int main() {

// 	welcomeUsers();

// 	Team teamA;
// 	teamA.players[0] = "Virat";
// 	teamA.players[1] = "Dhawan";
// 	teamA.players[2] = "Karthik";
// 	teamA.name = "TeamA";

// 	Team teamB;
// 	teamB.players[0] =  "Rohit";
// 	teamB.players[1] =  "Pant";
// 	teamB.players[2] =  "KLRahul";
// 	teamB.name = "TeamB";

//     displayPlayers(teamA.players, teamB.players);

//     startInning(1, teamA.name, teamB.name);
//     selectBatsmanAndBowler(teamA, teamB);
//     teamA.runs = playInning();
//     displayScore(teamA);

//     cout << "\n*********** TeamB needs " << teamA.runs + 1 << " runs to win ***********" << endl << endl;

//     startInning(2, teamB.name, teamA.name);
//     selectBatsmanAndBowler(teamB, teamA);
//     teamB.runs = playInning();
//     displayScore(teamB);

//     decideWinner(teamA.runs, teamB.runs);

//     return 0;
// }

// /* Greet users with a welcome message */
// void welcomeUsers() {

//     cout << "---------------------------------------" << endl;
//     cout << "|=========== GULLY CRICKET ===========|" << endl;
//     cout << "|                                     |" << endl;
//     cout << "|      Welcome to Gully Cricket       |" << endl;
//     cout << "---------------------------------------" << endl;
// }

// /* Display all the players in both team A and team B */
// void displayPlayers(string playersA[3], string playersB[3]) {

// 	cout << "\nPress Enter to display players: ";
// 	cin.get();

//     cout << "Displaying players...\n";
//     usleep(1000 * 1000);

//     cout << "--------------------------\t\t--------------------------" << endl;
//     cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
//     cout << "--------------------------\t\t--------------------------" << endl;

//     for (int i = 0; i < 3; i++) {
//         cout << "|\t";
//         cout << "[" << i << "] " << playersA[i] << "\t |";
//         cout << "\t\t|\t";
//         cout << "[" << i << "] " << playersB[i] << "\t |";
//         cout << endl;
//     }
//     cout << "--------------------------\t\t--------------------------" << endl << endl;
// }

// /* Select current batsman and bowler from batting team and bowler team respectively */
// void selectBatsmanAndBowler(Team batTeam, Team bowlTeam) {

//     cout << "Press Enter to select batsman and bowler: ";
//     cin.get();

//     cout << "Selecting batsman and bowler...\n";
//     usleep(1000 * 1000);

//     currentBatsman = selectPlayer(batTeam.players);
//     currentBowler = selectPlayer(bowlTeam.players);

//     cout << "----------------------------------------------------" << endl;
//     cout << "\t\t " << batTeam.name << ": Batsman - " << currentBatsman <<endl;
//     cout << "\t\t " << bowlTeam.name << ": Bowler - " << currentBowler <<endl;
//     cout << "----------------------------------------------------" << endl << endl;
// }

// /* Select a player among the given players randomly */
// string selectPlayer(string players[3]) {

//     int randomValue;

//     srand(time(NULL));
//     randomValue = rand() % 3; // Generates either 0, 1, or 2

//     string selectedPlayerName = players[randomValue];
//     return selectedPlayerName;
// }

// /* Start inning by displaying initial inning details */
// void startInning(int inning, string batTeam, string bowlTeam) {

// 	cout << "Press Enter to start inning " << inning;
//     cin.get();
//     usleep(1000 * 1000);

//     cout << "|------------ Inning " << inning << " Starts ------------|" << endl;
//     cout << "|----- " << batTeam << " is batting and " << bowlTeam << " is bowling -----|" << endl << endl;
// }

// /* Play one inning (6 balls) */
// int playInning() {

//     int runs = 0;
//     const int MAX_BALLS = 6;

//     for (int i = 0; i < MAX_BALLS; i++) {

//         cout << "Press Enter to bowl...";
//         cin.get();

//         cout << "Bowling..." << endl << endl;
//         usleep(1000 * 1000);

//         int randomValue;
//         srand(time(NULL));
//         randomValue = rand() % 7;   // 0, 1, 2, 3, 4, 5, or 6
//         runs = runs + randomValue;

//         cout << "----------------------------------------------------" << endl;
//         cout << "|\t\t" << currentBowler << " to " << currentBatsman << " " << randomValue << " runs" << endl;
//         cout << "----------------------------------------------------" << endl << endl;
//     }

//     return runs;
// }

// /* Display runs scored by batting team in the inning */
// void displayScore(Team team) {

//     cout << "----------------------------------------------------" << endl;
//     cout << "\t\t " << team.name << " scored " << team.runs << " runs." << endl;
//     cout << "----------------------------------------------------" << endl << endl;
// }

// /* Decide winner by comparing final scores of both the teams */
// void decideWinner(int teamAScore, int teamBScore) {

// 	cout << "----------------------------------------------------" << endl;

//     if (teamAScore > teamBScore) {
//         cout << "\t\t Team A is the Winner" << endl;
//     } else if (teamAScore < teamBScore) {
//         cout<< "\t\t Team B is the Winner" << endl;
//     } else {
//         cout << "\t\t Match Draw" << endl;
//     }

//     cout << "----------------------------------------------------" << endl << endl;
// }
