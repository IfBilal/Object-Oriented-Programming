#include <iostream>
using namespace std;
class Team;
class Player
{
private:
    int ID;
    string name;
    string type;
    int age;
    Team **teams;
    int noTeams;

public:
    Player(int ID = 0, string name = "", string type = "", int age = 0)
    {
        this->ID = ID;
        this->name = name;
        this->type = type;
        this->age = age;
        teams = new Team *[5];
        noTeams = 0;
    }
    void DisplayPlayer()
    {
        cout << "Player ID : " << ID << endl;
        cout << "Player name : " << name << endl;
        cout << "Player type : " << type << endl;
        cout << "Player age : " << age << endl;
    }
    void addTeam(Team &T)
    {
        if (noTeams < 5)
            teams[noTeams++] = &T;
    }
    int getTeam()
    {
        return noTeams;
    }
    void showTeams();
    int getID()
    {
        return ID;
    }
    void setTeam(int num)
    {
        noTeams = num;
    }
    void RemoveTeam(int teamID);
    ~Player()
    {
        delete[] teams; // Delete array of pointers to Team
        teams = nullptr;
    }
};
class Coach
{
private:
    int ID;
    string name;
    int experience;
    int age;
    Team **teams;
    int noTeams;

public:
    void showTeams();
    Coach(int ID = 0, string name = "", int experience = 0, int age = 0)
    {
        this->ID = ID;
        this->name = name;
        this->experience = experience;
        this->age = age;
        teams = new Team *[5];
        noTeams = 0;
    }
    void addTeam(Team &T)
    {
        if (noTeams < 5)
            teams[noTeams++] = &T;
    }
    int getTeam()
    {
        return noTeams;
    }
    void setTeam(int num)
    {
        noTeams = num;
    }
    void DisplayCoach()
    {
        cout << "Coach ID : " << ID << endl;
        cout << "Coach name : " << name << endl;
        cout << "Coach experience : " << experience << endl;
        cout << "Coach age : " << age << endl;
    }
    int getID()
    {
        return ID;
    }
    void RemoveTeam(int teamID);

    ~Coach()
    {
        delete[] teams;
        teams = nullptr;
    }
};
class Team
{
private:
    int teamID;
    string type;
    string name;
    Player **List_Of_Players;
    Coach **List_Of_Coaches;
    int noPlayers;
    int noCoaches;

public:
    Team(int teamID = 0, string type = "", string name = "")
    {
        this->teamID = teamID;
        this->type = type;
        this->name = name;
        List_Of_Players = new Player *[10];
        List_Of_Coaches = new Coach *[3];
        noPlayers = 0;
        noCoaches = 0;
    }
    void AddPlayer(Player &P)
    {
        for (int i = 0; i < noPlayers; i++)
        {
            if (List_Of_Players[i]->getID() == P.getID())
            {
                cout << "Player already in the team.\n";
                return;
            }
        }
        if (noPlayers < 10 && P.getTeam() < 5)
        {
            List_Of_Players[noPlayers++] = &P;
            P.addTeam(*this);
            cout<<"Player ADDED "<<endl;
        }
        else
        {
            cout << "Cannot add player: team full or player has too many teams.\n";
        }
    }

    int getID() const
    {
        return teamID;
    }

    int getNoPlayers()
    {
        return noPlayers;
    }
    int getNoCoach()
    {
        return noCoaches;
    }
    Player **getPlayerList()
    {
        return List_Of_Players;
    }

    string getType() const
    {
        return type;
    }

    string getName() const
    {
        return name;
    }

    void AddCoach(Coach &C)
    {
        for (int i = 0; i < noCoaches; i++)
        {
            if (List_Of_Coaches[i]->getID() == C.getID())
            {
                cout << "Coach already in the team.\n";
                return;
            }
        }
        if (noCoaches < 3 && C.getTeam() < 5)
        {
            List_Of_Coaches[noCoaches++] = &C;
            C.addTeam(*this);
            cout<<"Coach ADDED"<<endl;
        }
        else
        {
            cout << "Cannot add player: team full or Coach has too many teams.\n";
        }
    }
    void RemovePlayer(int ID)
    {
        bool check = 0;
        for (int i = 0; i < noPlayers; i++)
        {
            if (List_Of_Players[i]->getID() == ID)
            {
                check = 1;
                List_Of_Players[i]->RemoveTeam(teamID);
                for (int j = i; j < noPlayers - 1; j++)
                {
                    List_Of_Players[j] = List_Of_Players[j + 1];
                }
                noPlayers--;
                cout<<"Player removed "<<endl;
                break;
            }
        }
        if (check == 0)
        {
            cout << "Player with given ID not found " << endl;
        }
    }
    void RemoveCoach(int ID)
    {
        bool check = 0;
        for (int i = 0; i < noCoaches; i++)
        {
            if (List_Of_Coaches[i]->getID() == ID)
            {
                check = 1;
                List_Of_Coaches[i]->RemoveTeam(teamID);
                for (int j = i; j < noCoaches - 1; j++)
                {
                    List_Of_Coaches[j] = List_Of_Coaches[j + 1];
                }
                noCoaches--;
                cout<<"Coach Removed"<<endl;
                break;
            }
        }
        if (check == 0)
        {
            cout << "Coach with given ID not found " << endl;
        }
    }

    void DisplayTeam()
    {
        cout << "Team name : " << name << endl;
        cout << "Team type : " << type << endl;
        cout << "Team ID : " << teamID << endl;
        cout << "Coaches : " << endl;
        for (int i = 0; i < noCoaches; i++)
        {
            List_Of_Coaches[i]->DisplayCoach();
            cout << endl;
        }
        cout << "Players : " << endl;
        for (int i = 0; i < noPlayers; i++)
        {
            List_Of_Players[i]->DisplayPlayer();
            cout << endl;
        }
    }
    ~Team()
    {
        delete[] List_Of_Players; // Delete array of pointers
        delete[] List_Of_Coaches;
        List_Of_Players = nullptr;
        List_Of_Coaches = nullptr;
    }
};

void Player::showTeams()
{
    if (noTeams == 0)
    {
        cout << "No teams to display " << endl;
        return;
    }
    for (int i = 0; i < noTeams; i++)
    {
        cout << "Team #" << i + 1 << endl;
        cout << "Team ID : " << teams[i]->getID() << endl;
        cout << "Team Name : " << teams[i]->getName() << endl;
        cout << "Team Type : " << teams[i]->getType() << endl;
    }
}
void Coach::showTeams()
{
    if (noTeams == 0)
    {
        cout << "No teams to display " << endl;
        return;
    }
    for (int i = 0; i < noTeams; i++)
    {
        cout << "Team #" << i + 1 << endl;
        cout << "Team ID : " << teams[i]->getID() << endl;
        cout << "Team Name : " << teams[i]->getName() << endl;
        cout << "Team Type : " << teams[i]->getType() << endl;
    }
}

void Player::RemoveTeam(int teamID)
{
    bool check=0;
    for (int i = 0; i < noTeams; i++)
    {
        if (teams[i]->getID() == teamID)
        {
            check=1;
            for (int j = i; j < noTeams - 1; j++)
            {
                teams[j] = teams[j + 1];
            }
            noTeams--;
            cout<<"Team removed from Player's data"<<endl;
            break;
        }
    }
    if(check==0)
    cout<<"Player is not part of given team"<<endl;
}
void Coach::RemoveTeam(int teamID)
{
    bool check = 0;
    for (int i = 0; i < noTeams; i++)
    {
        if (teams[i]->getID() == teamID)
        {
            check = 1;
            for (int j = i; j < noTeams - 1; j++)
            {
                teams[j] = teams[j + 1];
            }
            noTeams--;
            cout<<"Team removed from Coach's data"<<endl;
            break;
        }
    }
    if (check == 0)
        cout << "Coach is not part of given team" << endl;
}

int main()
{
    Team *teams[10];
    Player *players[20];
    Coach *coaches[10];
    int teamCount = 0, playerCount = 0, coachCount = 0;
    int choice;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Team\n";
        cout << "2. Add Player\n";
        cout << "3. Add Coach\n";
        cout << "4. Assign Player to Team\n";
        cout << "5. Assign Coach to Team\n";
        cout << "6. Remove Player from Team\n";
        cout << "7. Remove Coach from Team\n";
        cout << "8. Display All Teams\n";
        cout << "9. Show Teams of a Player\n";
        cout << "10. Show Teams of a Coach\n";
        cout << "11.Remove Team\n";
        cout << "12. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (teamCount >= 10)
            {
                cout << "Limit reached\n"
                     << endl;
                continue;
            }
            int id;
            string name, type;
            cout << "Team ID: ";
            cin >> id;
            while (id < 0)
            {
                cout << "Invalid\nEnter again : ";
                cin >> id;
            }
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Type: ";
            getline(cin, type);
            bool idExists = false;
            for (int i = 0; i < teamCount; i++)
            {
                if (teams[i]->getID() == id)
                {
                    idExists = true;
                    break;
                }
            }
            if (idExists)
            {
                cout << "Team with this ID already exists.\n";
            }
            else
            {
                teams[teamCount++] = new Team(id, type, name);
            }
        }

        else if (choice == 2)
        {
            if (playerCount >= 20)
            {
                cout << "Limit reached\n"
                     << endl;
                continue;
            }
            int id, age;
            string name, type;
            cout << "Player ID: ";
            cin >> id;
            while (id < 0)
            {
                cout << "Invalid\nEnter again : ";
                cin >> id;
            }
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Type: ";
            getline(cin, type);
            cout << "Age: ";
            cin >> age;
            bool idExists = false;
            for (int i = 0; i < playerCount; i++)
            {
                if (players[i]->getID() == id)
                {
                    idExists = true;
                    break;
                }
            }

            if (idExists)
            {
                cout << "Player with this ID already exists.\n";
            }
            else
            {
                players[playerCount++] = new Player(id, name, type, age);
            }
        }

        else if (choice == 3)
        {

            if (coachCount >= 10)
            {
                cout << "Limit reached\n"
                     << endl;
                continue;
            }
            int id, exp, age;
            string name;
            cout << "Coach ID: ";
            cin >> id;
            while (id < 0)
            {
                cout << "Invalid\nEnter again : ";
                cin >> id;
            }
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Experience: ";
            cin >> exp;
            cout << "Age: ";
            cin >> age;
            bool idExists = false;
            for (int i = 0; i < coachCount; i++)
            {
                if (coaches[i]->getID() == id)
                {
                    idExists = true;
                    break;
                }
            }
            if (idExists)
            {
                cout << "Coach with this ID already exists.\n";
            }
            else
            {
                coaches[coachCount++] = new Coach(id, name, exp, age);
            }
        }

        else if (choice == 4)
        {
            bool check = 0, check2 = 0;
            int pID, tID;
            cout << "Player ID: ";
            cin >> pID;
            cout << "Team ID: ";
            cin >> tID;
            for (int i = 0; i < playerCount; i++)
                if (players[i]->getID() == pID)
                {
                    check = 1;
                    for (int j = 0; j < teamCount; j++)
                        if (teams[j]->getID() == tID)
                        {
                            check2 = 1;
                            teams[j]->AddPlayer(*players[i]);
                        }
                }
            if (check == 0)
                cout << "Player with given ID not found \n";
            if (check2 == 0)
                cout << "Team with given ID not found \n";
        }

        else if (choice == 5)
        {
            int cID, tID;
            bool check = 0, check2 = 0;
            cout << "Coach ID: ";
            cin >> cID;
            cout << "Team ID: ";
            cin >> tID;
            for (int i = 0; i < coachCount; i++)
                if (coaches[i]->getID() == cID)
                {
                    check = 1;
                    for (int j = 0; j < teamCount; j++)
                        if (teams[j]->getID() == tID)
                        {
                            check2 = 1;
                            teams[j]->AddCoach(*coaches[i]);
                        }
                }
            if (check == 0)
                cout << "Coach with given ID not found \n";
            if (check2 == 0)
                cout << "Team with given ID not found \n";
        }

        else if (choice == 6)
        {
            int pID, tID;
            bool check = 0;
            cout << "Player ID: ";
            cin >> pID;
            cout << "Team ID: ";
            cin >> tID;
            for (int i = 0; i < teamCount; i++)
                if (teams[i]->getID() == tID)
                {
                    check = 1;
                    teams[i]->RemovePlayer(pID);
                }
            if (check == 0)
            {
                cout << "Team with given ID not found " << endl;
            }
        }

        else if (choice == 7)
        {
            int cID, tID;
            bool check = 0;
            cout << "Coach ID: ";
            cin >> cID;
            cout << "Team ID: ";
            cin >> tID;
            for (int i = 0; i < teamCount; i++)
                if (teams[i]->getID() == tID)
                {
                    check = 1;
                    teams[i]->RemoveCoach(cID);
                }
            if (check == 0)
            {
                cout << "Team with given ID not found " << endl;
            }
        }

        else if (choice == 8)
        {
            if (teamCount == 0)
            {
                cout << "No teams to display.\n";
                continue;
            }
            for (int i = 0; i < teamCount; i++)
            {
                cout << "\nTeam #" << (i + 1) << ":\n";
                teams[i]->DisplayTeam();
            }
        }

        if (choice == 9)
        {
            int pID;
            bool check = 0;
            cout << "Enter ID of player to show Teams : ";
            cin >> pID;
            for (int i = 0; i < playerCount; i++)
            {
                if (players[i]->getID() == pID)
                {
                    check = 1;
                    players[i]->showTeams();
                }
            }
            if (check == 0)
                cout << "Player with given ID not found" << endl;
        }
        if (choice == 10)
        {
            int cID;
            bool check = 0;
            cout << "Enter ID of Coach to show Teams : ";
            cin >> cID;
            for (int i = 0; i < coachCount; i++)
            {
                if (coaches[i]->getID() == cID)
                {
                    check = 1;
                    coaches[i]->showTeams();
                }
            }
            if (check == 0)
                cout << "Coach with given ID not found" << endl;
        }
        if (choice == 11)
        {
            int tID;
            cout << "Enter ID of team to remove : ";
            cin >> tID;
            bool check = 0;
            for (int i = 0; i < teamCount; i++)
            {
                if (teams[i]->getID() == tID)
                {
                    check = 1;
                    for (int p = 0; p < playerCount; p++)
                        players[p]->RemoveTeam(tID);

                    for (int c = 0; c < coachCount; c++)
                        coaches[c]->RemoveTeam(tID);

                    delete teams[i];
                    for (int j = i; j < teamCount - 1; j++)
                    {
                        teams[j] = teams[j + 1];
                    }
                    teamCount--;
                    cout << "Team removed";
                    break;
                }
            }
            if (check == 0)
                cout << "Team not found \n";
        }
    } while (choice != 12);

    for (int i = 0; i < playerCount; i++)
        delete players[i];
    for (int i = 0; i < coachCount; i++)
        delete coaches[i];
    for (int i = 0; i < teamCount; i++)
        delete teams[i];

    return 0;
}
