#include <iostream>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
using namespace std;

void roundOf16();
void quaterFinals();
void semiFinals();
void final();
void remTeam();
string randTeam();
string winner();
void gameOver();

class Team {
public:
    static string teamName;

    vector<string> allTeams{ "Manchester United", "Manchester City", "Chelsea", "Arsenal", "Spurs", "Liverpool",
    "Real Madrid", "FC Barcelona", "Athletico Madrid", "Bayern Munich", "Borussia Dortmund", "PSG", "Inter Milan", "AC Milan",
    "Juventus", "Porto" };

    static vector<string> teamsRemaining;

    void selectTeam() {
        int choice;

        // user will select a team
        cout << "        Welcome to The Champions League simulator" << endl << endl;
        cout << "    Select team: " << endl << endl;
        cout << "    Press 1 for Manchester United" << endl;
        cout << "    Press 2 for Manchester City" << endl;
        cout << "    Press 3 for Chelsea" << endl;
        cout << "    Press 4 for Arsenal" << endl;
        cout << "    Press 5 for Spurs" << endl;
        cout << "    Press 6 for Liverpool" << endl;
        cout << "    Press 7 for Real Madrid" << endl;
        cout << "    Press 8 for FC Barcelona" << endl;
        cout << "    Press 9 for Athletico Madrid" << endl;
        cout << "    Press 10 for Bayern Munich" << endl;
        cout << "    Press 11 for Borussia Dortmund" << endl;
        cout << "    Press 12 for PSG" << endl;
        cout << "    Press 13 for Inter Milan" << endl;
        cout << "    Press 14 for AC Milan" << endl;
        cout << "    Press 15 for Juventus" << endl;
        cout << "    Press 16 for Porto" << endl;

        m:
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            teamName = "Manchester United";
            cout << "You have selected Manchester United as your team." << endl << endl;
            break;
        case 2:
            teamName = "Manchester City";
            cout << "You have selected Manchester City as your team." << endl << endl;;
            break;
        case 3:
            teamName = "Chelsea";
            cout << "You have selected Chelsea as your team." << endl << endl;;
            break;
        case 4:
            teamName = "Arsenal";
            cout << "You have selected Arsenal as your team." << endl << endl;;
            break;
        case 5:
            teamName = "Spurs";
            cout << "You have selected Spurs as your team." << endl << endl;;
            break;
        case 6:
            teamName = "Liverpool";
            cout << "You have selected Liverpool as your team." << endl << endl;;
            break;
        case 7:
            teamName = "Real Madrid";
            cout << "You have selected Real Madrid as your team." << endl << endl;;
            break;
        case 8:
            teamName = "FC Barcelona";
            cout << "You have selected FC Barcelona as your team." << endl << endl;;
            break;
        case 9:
            teamName = "Athletico Madrid";
            cout << "You have selected Athletico Madrid as your team." << endl << endl;;
            break;
        case 10:
            teamName = "Bayern Munich";
            cout << "You have selected Bayern Munich as your team." << endl << endl;;
            break;
        case 11:
            teamName = "Borussia Dortmund";
            cout << "You have selected Borussia Dortmund as your team." << endl << endl;;
            break;
        case 12:
            teamName = "PSG";
            cout << "You have selected PSG as your team." << endl << endl;;
            break;
        case 13:
            teamName = "Inter Milan";
            cout << "You have selected Inter Milan as your team." << endl << endl;;
            break;
        case 14:
            teamName = "AC Milan";
            cout << "You have selected AC Milan as your team." << endl << endl;;
            break;
        case 15:
            teamName = "Juventus";
            cout << "You have selected Juventus as your team." << endl << endl;;
            break;
        case 16:
            teamName = "Porto";
            cout << "You have selected Porto as your team." << endl << endl;;
            break;
        default:
            cout << "Invalid option. Please try again." << endl << endl;
            goto m;
        }

        // push all teams into teamsRemaining apart from the selected team
        for (auto team : allTeams) {
            if (team == teamName) {
            }
            else {
                teamsRemaining.push_back(team);
            }
        }

        roundOf16();
    }
};

string Team::teamName;
vector<string> Team::teamsRemaining;

// remove selected team from vector
void remTeam(string teamRem) {
    vector<string> temp;

    for (string team : Team::teamsRemaining) {
        if (team == teamRem) {
        }
        else {
            temp.push_back(team);
        }
    }
    Team::teamsRemaining = temp;
}

// random team is selected to assign to fixtures
string randTeam() {
    srand(time(NULL));
    int num = rand() % Team::teamsRemaining.size();
    string randTeam = Team::teamsRemaining[num];

    return randTeam;
}

// winner is selected from the match
string winner(string teamA, string teamB, int num) {
    vector<int> v{ 'w','l' };
    string winner;

    char result = v[num];

    if (result == 'w') {
        winner = teamA;
    }
    else if (result == 'l') {
        winner = teamB;
    }

    return winner;  
}

int team1Goals;
int team2Goals;
int team3Goals;
int team4Goals;
int team5Goals;
int team6Goals;
int team7Goals;
int team8Goals;
int team9Goals;
int team10Goals;
int team11Goals;
int team12Goals;
int team13Goals;
int team14Goals;
int team15Goals;
int team16Goals;

// this method is ran if the user loses a match 
void gameOver(string team1, string team2) {
    int choice;

    cout << endl;
    cout << "        You have been knocked out by " << team2 << " losing " << team1Goals << " - " << team2Goals << " on aggregate" << endl << endl;

    m:
    cout << "      Press 1 to PLAY AGAIN" << endl;
    cout << "      Press 2 to EXIT" << endl;
    cin >> choice;

    if (choice == 1) {
        system("cls");
        Team t;
        t.selectTeam();
    }
    else if (choice == 2) {
        exit(0);
    }
    else {
        goto m;
    }
}

void roundOf16() {
    vector<string> winners; 

    cout << "        You have qualified for the Champions League knock-out stages" << endl << endl;
    cout << "        ROUND OF 16" << endl << endl;

    // make selected team upper case
    string upperName;
    for (char c : Team::teamName) {
        upperName += toupper(c);
    }
    Team::teamName = upperName;

    // setting up matches
    // match 1
    string team1 = Team::teamName;
    string team2 = randTeam();
    remTeam(team2);

    // match 2
    string team3 = randTeam(); // random team is selected 
    remTeam(team3); // selected team is removed from vector
    string team4 = randTeam();
    remTeam(team4);

    // match 3
    string team5 = randTeam();
    remTeam(team5);
    string team6 = randTeam();
    remTeam(team6);

    // match 4
    string team7 = randTeam();
    remTeam(team7);
    string team8 = randTeam();
    remTeam(team8);

    // match 5
    string team9 = randTeam();
    remTeam(team9);
    string team10 = randTeam();
    remTeam(team10);

    // match 6
    string team11 = randTeam();
    remTeam(team11);
    string team12 = randTeam();
    remTeam(team12);
    
    // match 7 
    string team13 = randTeam();
    remTeam(team13);
    string team14 = randTeam();
    remTeam(team14);

    // match 8
    string team15 = randTeam();
    remTeam(team15);
    string team16 = randTeam();
    remTeam(team16);
    
    cout << "    Upcoming fixtures: " << endl << endl;
    cout << "    " + team1 + " vs " + team2 << endl;
    cout << "    " + team3 + " vs " + team4 << endl;
    cout << "    " + team5 + " vs " + team6 << endl;
    cout << "    " + team7 + " vs " + team8 << endl;
    cout << "    " + team9 + " vs " + team10 << endl;
    cout << "    " + team11 + " vs " + team12 << endl;
    cout << "    " + team13 + " vs " + team14 << endl;
    cout << "    " + team15 + " vs " + team16 << endl;

    vector<int> v{ 'w','l' };
    srand(time(NULL));

    // random number is generated to produce a random result (w or l)
    int num1 = rand() % v.size();
    int num2 = rand() % v.size();
    int num3 = rand() % v.size();
    int num4 = rand() % v.size();
    int num5 = rand() % v.size();
    int num6 = rand() % v.size();
    int num7 = rand() % v.size();
    int num8 = rand() % v.size();

    // if user wins, they are not pushed into the vector (can't have them playing themselves e.g. PSG vs PSG)
    if (winner(team1, team2, num1) == team1 ) {
    }
    else {
        winners.push_back(winner(team1, team2, num1));
    }
    
    // winners are pushed back
    winners.push_back(winner(team3, team4,num2));
    winners.push_back(winner(team5, team6,num3));
    winners.push_back(winner(team7, team8,num4));
    winners.push_back(winner(team9, team10,num5));
    winners.push_back(winner(team11, team12,num6));
    winners.push_back(winner(team13, team14,num7));
    winners.push_back(winner(team15, team16,num8));
    
    Team::teamsRemaining = winners;

    // random number of goals scored per team depending on who won/loss
    if (winner(team1, team2, num1) == team1) {
        team1Goals = rand() % 8 + 1;
        team2Goals = rand() % team1Goals;
    }
    else {
        team2Goals = rand() % 8 + 1;
        team1Goals = rand() % team2Goals;
    } 

    if (winner(team3, team4, num2) == team3) {
        team3Goals = rand() % 8 + 1;
        team4Goals = rand() % team3Goals;
    }
    else {
        team4Goals = rand() % 8 + 1;
        team3Goals = rand() % team4Goals;
    }

    if (winner(team5, team6, num3) == team5) {
        team5Goals = rand() % 8 + 1;
        team6Goals = rand() % team5Goals;
    }
    else {
        team6Goals = rand() % 8 + 1;
        team5Goals = rand() % team6Goals;
    }

    if (winner(team7, team8, num4) == team7) {
        team7Goals = rand() % 8 + 1;
        team8Goals = rand() % team7Goals;
    }
    else {
        team8Goals = rand() % 8 + 1;
        team7Goals = rand() % team8Goals;
    }

    if (winner(team9, team10, num5) == team9) {
        team9Goals = rand() % 8 + 1;
        team10Goals = rand() % team9Goals;
    }
    else {
        team10Goals = rand() % 8 + 1;
        team9Goals = rand() % team10Goals;
    }

    if (winner(team11, team12, num6) == team11) {
        team11Goals = rand() % 8 + 1;
        team12Goals = rand() % team11Goals;
    }
    else {
        team12Goals = rand() % 8 + 1;
        team11Goals = rand() % team12Goals;
    }

    if (winner(team13, team14, num7) == team13) {
        team13Goals = rand() % 8 + 1;
        team14Goals = rand() % team13Goals;
    }
    else {
        team14Goals = rand() % 8 + 1;
        team13Goals = rand() % team14Goals;
    }

    if (winner(team15, team16, num8) == team15) {
        team15Goals = rand() % 8 + 1;
        team16Goals = rand() % team15Goals;
    }
    else {
        team16Goals = rand() % 8 + 1;
        team15Goals = rand() % team16Goals;
    }
    
    int c;

    x:
    cout << endl;
    cout << "    Press 1 to simulate results" << endl;
    cout << "    Press 2 to start again" << endl;
    cout << "    Press 3 to EXIT" << endl;
    cin >> c;

    if (c == 1) {
        cout << endl;
        cout << "    AGGREGATE SCORES (2 legs):" << endl << endl;
        cout << "    " << team1 << " " << team1Goals << " - " << team2Goals << " " << team2 << endl;
        cout << "    " << team3 << " " << team3Goals << " - " << team4Goals << " " << team4 << endl;
        cout << "    " << team5 << " " << team5Goals << " - " << team6Goals << " " << team6 << endl;
        cout << "    " << team7 << " " << team7Goals << " - " << team8Goals << " " << team8 << endl;
        cout << "    " << team9 << " " << team9Goals << " - " << team10Goals << " " << team10 << endl;
        cout << "    " << team11 << " " << team11Goals << " - " << team12Goals << " " << team12 << endl;
        cout << "    " << team13 << " " << team13Goals << " - " << team14Goals << " " << team14 << endl;
        cout << "    " << team15 << " " << team15Goals << " - " << team16Goals << " " << team16 << endl;

        // game is over if you get knocked out
        if (team1Goals < team2Goals) {
            gameOver(team1, team2);
        }
        else {
            quaterFinals();
        }
    }
    else if (c == 2) {
        system("cls");
        Team t;
        t.selectTeam();
    } else if (c == 3) {
        exit(0);
    }
    else {
        goto x;
    }
}


void quaterFinals() {
    cout << endl;
    cout << "        You have qualified for the quater finals" << endl << endl;
    cout << "        QUATER FINALS" << endl << endl;

    vector<string> winners;

    string upperName;
    for (char c : Team::teamName) {
        upperName += toupper(c);
    }
    Team::teamName = upperName;

    // setting up matches
    // match 1
    string team1 = Team::teamName;
    string team2 = randTeam();
    remTeam(team2);

    // match 2
    string team3 = randTeam();
    remTeam(team3);
    string team4 = randTeam();
    remTeam(team4);

    // match 3
    string team5 = randTeam();
    remTeam(team5);
    string team6 = randTeam();
    remTeam(team6);

    // match 4
    string team7 = randTeam();
    remTeam(team7);
    string team8 = randTeam();
    remTeam(team8);

    cout << "    Upcoming fixtures: " << endl << endl;
    cout << "    " + team1 + " vs " + team2 << endl;
    cout << "    " + team3 + " vs " + team4 << endl;
    cout << "    " + team5 + " vs " + team6 << endl;
    cout << "    " + team7 + " vs " + team8 << endl;
    
    vector<int> v{ 'w','l' };
    srand(time(NULL));

    int num1 = rand() % v.size();
    int num2 = rand() % v.size();
    int num3 = rand() % v.size();
    int num4 = rand() % v.size();
    
    if (winner(team1, team2, num1) == team1) {
    }
    else {
        winners.push_back(winner(team1, team2, num1));
    }

    winners.push_back(winner(team3, team4, num2));
    winners.push_back(winner(team5, team6, num3));
    winners.push_back(winner(team7, team8, num4));
    
    Team::teamsRemaining = winners;

    if (winner(team1, team2, num1) == team1) {
        team1Goals = rand() % 8 + 1;
        team2Goals = rand() % team1Goals;
    }
    else {
        team2Goals = rand() % 8 + 1;
        team1Goals = rand() % team2Goals;
    }

    if (winner(team3, team4, num2) == team3) {
        team3Goals = rand() % 8 + 1;
        team4Goals = rand() % team3Goals;
    }
    else {
        team4Goals = rand() % 8 + 1;
        team3Goals = rand() % team4Goals;
    }

    if (winner(team5, team6, num3) == team5) {
        team5Goals = rand() % 8 + 1;
        team6Goals = rand() % team5Goals;
    }
    else {
        team6Goals = rand() % 8 + 1;
        team5Goals = rand() % team6Goals;
    }

    if (winner(team7, team8, num4) == team7) {
        team7Goals = rand() % 8 + 1;
        team8Goals = rand() % team7Goals;
    }
    else {
        team8Goals = rand() % 8 + 1;
        team7Goals = rand() % team8Goals;
    }

    int c;

    x:
    cout << endl;
    cout << "    Press 1 to simulate results" << endl;
    cout << "    Press 2 to start again" << endl;
    cout << "    Press 3 to EXIT" << endl;
    cin >> c;

    if (c == 1) {
        cout << "    AGGREGATE SCORES (2 legs):" << endl << endl;
        cout << "    " << team1 << " " << team1Goals << " - " << team2Goals << " " << team2 << endl;
        cout << "    " << team3 << " " << team3Goals << " - " << team4Goals << " " << team4 << endl;
        cout << "    " << team5 << " " << team5Goals << " - " << team6Goals << " " << team6 << endl;
        cout << "    " << team7 << " " << team7Goals << " - " << team8Goals << " " << team8 << endl;
       
        // game is over if you get knocked out
        if (team1Goals < team2Goals) {
            gameOver(team1, team2);
        }
        else {
            semiFinals();
        }
    }
    else if (c == 2) {
        system("cls");
        Team t;
        t.selectTeam();
    }
    else if (c == 3) {
        exit(0);
    }
    else {
        goto x;
    }


}
void semiFinals() {
    cout << endl;
    cout << "        You have qualified for the semi finals" << endl << endl;
    cout << "        SEMI FINALS" << endl << endl;

    vector<string> winners;

    string upperName;
    for (char c : Team::teamName) {
        upperName += toupper(c);
    }
    Team::teamName = upperName;

    // setting up matches
    // match 1
    string team1 = Team::teamName;
    string team2 = randTeam();
    remTeam(team2);

    // match 2
    string team3 = randTeam();
    remTeam(team3);
    string team4 = randTeam();
    remTeam(team4);

    cout << "    Upcoming fixtures: " << endl << endl;
    cout << "    " + team1 + " vs " + team2 << endl;
    cout << "    " + team3 + " vs " + team4 << endl;
  
    vector<int> v{ 'w','l' };
    srand(time(NULL));

    int num1 = rand() % v.size();
    int num2 = rand() % v.size();

    if (winner(team1, team2, num1) == team1) {
    }
    else {
        winners.push_back(winner(team1, team2, num1));
    }

    winners.push_back(winner(team3, team4, num2));

    Team::teamsRemaining = winners;

    if (winner(team1, team2, num1) == team1) {
        team1Goals = rand() % 8 + 1;
        team2Goals = rand() % team1Goals;
    }
    else {
        team2Goals = rand() % 8 + 1;
        team1Goals = rand() % team2Goals;
    }

    if (winner(team3, team4, num2) == team3) {
        team3Goals = rand() % 8 + 1;
        team4Goals = rand() % team3Goals;
    }
    else {
        team4Goals = rand() % 8 + 1;
        team3Goals = rand() % team4Goals;
    }

    int c;

    x:
    cout << endl;
    cout << "    Press 1 to simulate results" << endl;
    cout << "    Press 2 to start again" << endl;
    cout << "    Press 3 to EXIT" << endl;
    cin >> c;

    if (c == 1) {
        cout << "    AGGREGATE SCORES (2 legs):" << endl << endl;
        cout << "    " << team1 << " " << team1Goals << " - " << team2Goals << " " << team2 << endl;
        cout << "    " << team3 << " " << team3Goals << " - " << team4Goals << " " << team4 << endl;

        // game is over if you get knocked out
        if (team1Goals < team2Goals) {
            gameOver(team1, team2);
        }
        else {
            final();
        }
    }
    else if (c == 2) {
        system("cls");
        Team t;
        t.selectTeam();
    }
    else if (c == 3) {
        exit(0);
    }
    else {
        goto x;
    }

}
void final() {
    cout << endl;
    cout << "        You have qualified for the semi finals" << endl << endl;
    cout << "        SEMI FINALS" << endl << endl;

    vector<string> winners;

    string upperName;
    for (char c : Team::teamName) {
        upperName += toupper(c);
    }
    Team::teamName = upperName;

    string team1 = Team::teamName;
    string team2 = randTeam();
    remTeam(team2);

    cout << "    Upcoming fixtures: " << endl << endl;
    cout << "    " + team1 + " vs " + team2 << endl;

    vector<int> v{ 'w','l' };
    srand(time(NULL));

    int num1 = rand() % v.size();

    winners.push_back(winner(team1, team2, num1));

    Team::teamsRemaining = winners;

    if (winner(team1, team2, num1) == team1) {
        team1Goals = rand() % 8 + 1;
        team2Goals = rand() % team1Goals;
    }
    else {
        team2Goals = rand() % 8 + 1;
        team1Goals = rand() % team2Goals;
    }

    int c;

    x:
    cout << endl;
    cout << "    Press 1 to simulate results" << endl;
    cout << "    Press 2 to start again" << endl;
    cout << "    Press 3 to EXIT" << endl;
    cin >> c;

    if (c == 1) {
        cout << "    FINAL SCORE" << endl << endl;
        cout << "    " << team1 << " " << team1Goals << " - " << team2Goals << " " << team2 << endl;
        
        // game is over if you get knocked out
        if (team1Goals < team2Goals) {
            gameOver(team1, team2);
        }
        else {
            cout << "    CONGRATULATIONS you have won this years Champions league" << endl << endl;
            cout << "    " + Team::teamName + " CHAMPIONS" << endl << endl;
        }
    }
    else if (c == 2) {
        system("cls");
        Team t;
        t.selectTeam();
    }
    else if (c == 3) {
        exit(0);
    }
    else {
        goto x;
    }
}

int main() {
    
    Team t;
    t.selectTeam();
    
}

