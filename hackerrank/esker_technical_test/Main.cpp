// 12/12/2022

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Player
{
    public:
       string Name;
       int    Score = 0;
	  
    public:
	   Player(string name)
	   {
		  Name = name;
	   }
};

class TennisGame
{
    protected:
        static const string zero;
        static const string quinze;
        static const string trente;
        static const string quarante;
        static const string egalite;
        static const string avantage;
    
    protected:
        Player**   players;
	    bool       gameOver = false;
    
    public:
    TennisGame(string player1, string player2)
    {
        players = new Player*[2];
        players[0] = new Player(player1);
        players[1] = new Player(player2);
    }
    
    virtual void   ScorePoint(int idxPlayer) = 0;
    virtual string GetDisplayScores() = 0;
    
    void   Simulate();
    
    virtual ~TennisGame()
     {
        delete players[0];
        delete players[1];
        delete [] players;
     }
};

const string TennisGame::zero = "zéro";
const string TennisGame::quinze = "quinze";
const string TennisGame::trente = "trente";
const string TennisGame::quarante = "quarante";
const string TennisGame::egalite = "égalité";
const string TennisGame::avantage = "avantage";

class   TennisGameEsker : public TennisGame
{
    private:
        string DisplayScore3LessPlayer(int idxPlayer);

    public:
        TennisGameEsker(string player1, string player2) :
                TennisGame(player1, player2 )
         {}
    
    //To Implement
    void   ScorePoint(int idxPlayer);

    //To Implement
    string GetDisplayScores();

};


void TennisGameEsker::ScorePoint(int idxPlayer)
{
    //Implement the function
    if(idxPlayer == 0 || idxPlayer == 1)
    {
        players[idxPlayer]->Score++;
    }
    else
    {
        cout << "Invalid player index" << endl;
    }
}

string TennisGameEsker::GetDisplayScores()
{
    //Implement the function
    string scoreDisplay = "";
    int score1 = this->players[0]->Score;
    int score2 = this->players[1]->Score;


    // win condition
    if(score1 >= 4 || score2 >= 4)
    {
        
        if(std::abs(score1 - score2) >= 2)
        {
            std::string winText = " a gagné le jeu. Jeu terminé";
            if(score1 > score2)
            {
                scoreDisplay = this->players[0]->Name + winText;
            }
            else
            {
                scoreDisplay = this->players[1]->Name + winText;
            }
            this->gameOver = true;
            return scoreDisplay;
        }
    }

    // equality condition
    if(score1 >= 3 && score2 >= 3 && score1 == score2)
    {
        scoreDisplay = egalite;
        return scoreDisplay;
    }

    // advantage condition
    if(score1 >= 3 && score2 >= 3 && std::abs(score1 - score2) == 1)
    {
        if(score1 > score2)
        {
            scoreDisplay = avantage + " " + this->players[0]->Name;
        }
        else
        {
            scoreDisplay = avantage + " " + this->players[1]->Name;
        }
        return scoreDisplay;
    }

    // display score otherwhise
    scoreDisplay += DisplayScore3LessPlayer(0);
    scoreDisplay += " | ";
    scoreDisplay += DisplayScore3LessPlayer(1);

    return scoreDisplay;
}

string TennisGameEsker::DisplayScore3LessPlayer(int idxPlayer)
{
    std::string result = this->players[idxPlayer]->Name + ":";
    switch(this->players[idxPlayer]->Score)
    {
        case 0:
            result += zero;
            break;
        case 1:
            result += quinze;
            break;
        case 2:
            result += trente;
            break;
        case 3:
            result += quarante;
            break;
    }
    return result;
}

int main() 
{
    TennisGameEsker game("Federer","Djokovic");
    game.Simulate();
    return 0;
}

/*
 * Take a sequence of 1 and 2 indicates the player who won the point
 111111 simulate the player 1 wins 6 times in a row
 1111112 simulate the player 1 wins 6 times and player 2 win the 7th point
 121212121 simulate players alternatively win the point
 */
void TennisGame::Simulate()
{
    string input;
    cin >> input;

    cout << GetDisplayScores() << endl;

    for (int i = 0; i < (int)input.length(); i++)
    {
        int idxPlayer = input[i] - '1'; //input is 1 or 2
        ScorePoint(idxPlayer);
        cout << GetDisplayScores() << endl;
        if (gameOver)
        {
            break;
        }
    }
}