#include <iostream>
#include <ctime>

using namespace std;

// Intro scenario of the game 
void Intro()
{
    cout << "Welcome to the Mathmare, if you're not brillant enough...\n";
    cout << "YOU WILL DIE !\n\n";
}

bool PlayGame(int Room)
{
    // Randomizer variable
    int RandomSetting = Room * 4;

    // Declaring variables here ( srand(time(NULL)); is used to add more randomness)
    const int PuzzleA = rand() % RandomSetting;
    srand(time(NULL));

    const int PuzzleB = rand() % RandomSetting;
    srand(time(NULL));
    
    const int PuzzleC = rand() % RandomSetting;
    srand(time(NULL));

    const int PuzzleSum = PuzzleA + PuzzleB + PuzzleC;
    const int PuzzleProd = PuzzleA * PuzzleB * PuzzleC;
    
    // Intro story
    cout << "To overcome the challenge in the room "<< Room <<", you shall solve the following: \n";
    cout << "+ There are 3 numbers in this puzzle";
    cout << "\n+ United, they add-up to " << PuzzleSum;
    cout << "\n+ Fused together, their power multiplies to " << PuzzleProd << endl;
    cout << "+ Who are we?\n";
    int GuessA,GuessB,GuessC;

    //The player enter his answer
    cin >> GuessA;
    cin >> GuessB;
    cin >> GuessC;
    cout << GuessA << " " << GuessB << " " << GuessC << " are your pitiful answers !\n\n"; 
    
    // Calculation of the player's answer
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProd = GuessA * GuessB * GuessC;
    
    // Filtering the answer to see if the player guessed right
    if(PuzzleSum == GuessSum && PuzzleProd == GuessProd)
    {
        cout << "YOU MAY PROCEED!\n\n";
        return true;
    }
    else
    {
        cout << "YOU SHALL PERISH, YOU MINDLESS SCOUNDREL!\n\n";
        return false;
    }
}


int main()
{
    
    int Room = 1;
    int DeathCount = 0;
    const int FinalRoom = 25;

    while (Room <= FinalRoom)
    {
        if(Room == 1)
        {
            Intro();
        }
        bool bRoomComplete = PlayGame(Room);
        if (bRoomComplete)
        {
            // Difficulty is rising in each room that the player enters
            ++Room;
        }
        else 
        {
            // Keeps track of the player's failure
            ++DeathCount;
        }

        cin.clear(); // Clears errors
        cin.ignore(); // Discards buffer
    }
    // End game
    if (DeathCount==0)
    {
        cout << "CURSES!\n YOU HAVE SURVIVED ALL MY ENIGMAS!\n YOU DESERVE TO LIVE AND PROSPER!";
    }
    else
    {
        cout << "YOU WERE A STUBBORN ONE...\n"; 
        cout << "YOU DIED " << DeathCount << " TIMES...\n"; 
        cout << "TRY TO SURVIVE FOR REAL NEXT TIME !!! "; 
    }
    
    return 0;
}
