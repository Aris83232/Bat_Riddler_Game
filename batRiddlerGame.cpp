#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{

  std::cout << "\n\nRiddler:  Riddle me this, riddle me that, who's afraid of the big, black bat?\n";
  std::cout << "\nRiddler:  'I knew youd come Batman', There is no other way out, There are multiple doors to open, let's test your Intelligence....\n";
  std::cout << "\nEnter the correct code to open the door: "<< Difficulty <<"...\n\n";
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);

 //Declaring the codes
  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;

 //Declaring code sum & product
  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

 //Giving Hints
  std::cout << "\n+ The There are 3 numbers in the code.";
  std::cout << "\n+ The codes add uo to: " << CodeSum;
  std::cout << "\n+ The multiply to give: " << CodeProduct <<"\n";

 // Taking Player Input of player Guess
  int GuessA, GuessB, GuessC;
  std::cin >> GuessA >> GuessB >> GuessC;

 // Calculation PlayerGuess
  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC ;

 // Checking Player Answer
  if (GuessSum == CodeSum && GuessProduct == CodeProduct)
  {
    std::cout << "So you managed to open the door, HUH\n";
    return true;
  }
  else
  {
    std::cout << "You need to exercise your Brain Baty! Try Again \"Ha HA\" \n";
    return false;
  }
}

int main()
{
  srand(time(NULL));  // Create new random sequence based on time of day

  int LevelDifficulty = 1;
  const int FinalDoor = 5;

  while (LevelDifficulty <= FinalDoor) // Loop the game until all doors are open.
  {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear();  // Clears the errors.
    std::cin.ignore(); //Discards the Buffer.

    if (bLevelComplete)
    {
      ++LevelDifficulty;
    }
  }

  std::cout << "You win this time Batman, See you until next time";
  return 0;
}
