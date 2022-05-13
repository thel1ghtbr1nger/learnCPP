//Basic functions such as cout/cin
#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty)
{
    if (Difficulty == 1)
    {
    std::cout << "\n----------------------------------------------------------------------------------------";
    std::cout << "\n\n    Welcome to my game!\n    Crack the 3 digit code on each level to move on!\n";
    }
    std::cout << "\n    Level: " << Difficulty << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntro(Difficulty);
    //Declaring variables for question
    int CodeA = rand()%Difficulty+Difficulty;
    int CodeB = rand()%Difficulty+Difficulty;
    int CodeC = rand()%Difficulty+Difficulty;
    int CodeSum = CodeA+CodeB+CodeC;
    int CodeProduct = CodeA*CodeB*CodeC;
    
    std::cout << "\n  The Numbers Add Up To: " << CodeSum << "\n  The Numbers Multiply Out To: " << CodeProduct;
    std::cout << "\n\n    Input Code: ";

    //Initializing Variables for user input
    int CodeInputA;
    int CodeInputB;
    int CodeInputC;

    std::cin >> CodeInputA >> CodeInputB >> CodeInputC;

    int InputSum = CodeInputA+CodeInputB+CodeInputC;
    int InputProduct = CodeInputA*CodeInputB*CodeInputC;
    
    std::cout << "\n\n    You Entered: " << CodeInputA << " " << CodeInputB << " " << CodeInputC << std::endl;

    //Check user input against code
    if (InputSum == CodeSum && InputProduct == CodeProduct)
    {
        std::cout << "\n    Good Job!\n";
        return true;
    }
    else
    {
        std::cout << "\n    Sorry, wrong input.\n    Try again? (Y/n) ";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    int MaxLevel;
    std::cout << "\n  How many levels would you like to play? ";
    std::cin >> MaxLevel;
    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears error from non-int input
        std::cin.ignore(); //Discards buffer
        
        if (bLevelComplete)
        {
            ++LevelDifficulty;
            if (LevelDifficulty == MaxLevel +1)
            std::cout << "\n  Congratulations and thank you for playing my game!\n  Feel free to reach out to @the_L1ghtbr1nger on Telegram \n  if you'd like to collaborate or study together!\n";
        }
        else
        {
            std::string Continue;
            std::cin >> Continue;
            if (Continue == "n")
            {
                LevelDifficulty = MaxLevel + 1;
            }
            else
            {

                LevelDifficulty = 1;
            }
        }
    }
    
    return 0;
}
