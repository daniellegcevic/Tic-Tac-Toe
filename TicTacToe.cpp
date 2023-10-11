#include <iostream>
#include <string>
using namespace std;

class TicTacToe
{
private:

	//Game pieces
	const string x = "X", o = "O";

	string playerTurn = x;

	int squaresLeft = 8; //Keeps track of how many squares are left

	const static int arraySize = 3;
	string s[arraySize][arraySize];

public:

	TicTacToe()
	{
		playerTurn = x;

		squaresLeft = 8;

		for (int i = 0; i < arraySize; i++)
		{
			for(int j = 0; j < arraySize; j++)
			{
				s[i][j] = " ";
			}
		}
	}

	//Allows users to choose what to do
	void displayMenu()
	{
		cout << "------------------------ MENU SELECTION ------------------------" << endl << endl;
		cout << "   (1) Play" << endl;
		cout << "   (2) Instructions" << endl;
		cout << "   (3) Exit" << endl << endl << endl;
	}

	string makeChoice()
	{
		string choice;

		bool validInput = false;

		//Get valid choice
		while (!validInput)
		{
			//Get user's choice
			cout << "--------------------------------------------- Enter a number:  ";
			getline(cin, choice);

			//Validate user's choice
			if (choice == "1" || choice == "2" || choice == "3")
			{
				validInput = true;
			}
			else
			{
				printErrorMessage();
			}
		}

		return choice;
	}

	// Show rules for the user
	bool displayRules()
	{
		cout << endl << "------------------------- INSTRUCTIONS -------------------------" << endl << endl;
		cout << "   The game is played on a grid that's 3 squares by 3 squares." << endl << endl;
		cout << "   You are X, and your friend is O." << endl << endl;
		cout << "   Players take turns putting their marks in empty squares." << endl << endl;
		cout << "   Enter your move by typing a row and a column (example: 12)." << endl << endl;
		cout << "   The first player to get 3 marks in a row is the winner." << endl << endl;
		cout << "   If all 9 squares are full, the game is over." << endl << endl << endl;

		string input;
		bool validInput = false;
		
		while (!validInput)
		{
			cout << "----------------------------- Enter (1) to exit instructions:  ";
			getline(cin, input);

			if (input == "1")
			{
				validInput = true;
			}
			else
			{
				printErrorMessage();
			}
		}

		return true;
	}

	void printErrorMessage()
	{
		cout << endl << "------------------- INVALID INPUT, TRY AGAIN -------------------" << endl << endl;
	}

	// Output dashes and lines for the gameboard
	void createGameboard()
	{
		cout << endl;

		for (int i = 0; i < arraySize; i++)
		{
			cout << "                           ";

			for (int j = 0; j < arraySize; j++)
			{
				cout << s[i][j];

				if (j != 2)
				{
					cout << " | ";
				}
			}

			cout << endl;

			if (i != 2)
			{
				printDashes();
			}
		}
	}

	void printDashes()
	{
		cout << "                          -----------" << endl;
	}

	// Prompt user and get value for move
	void playerMove()
	{
		string location; //Where the player wants to move

		if (playerTurn == x)
		{
			cout << endl << "-- Player 1 ------------------------------- Enter your move:  ";
		}
		else
		{
			cout << endl << "-- Player 2 ------------------------------- Enter your move:  ";
		}

		getline(cin, location);

		while (!processMove(location))
		{
			cout << "------------------------------------------- Enter your move:  ";
			getline(cin, location);
		}
	}

	//Determine if it can be placed and place if available
	bool processMove(string location)
	{
		bool validMove = true;

		if (location == "11" && s[0][0] == " ") //Checks input for row 1
		{
			s[0][0] = playerTurn;
		}
		else if (location == "12" && s[0][1] == " ")
		{
			s[0][1] = playerTurn;
		}
		else if (location == "13" && s[0][2] == " ")
		{
			s[0][2] = playerTurn;
		}
		else if (location == "21" && s[1][0] == " ") //Checks input for row 2
		{
			s[1][0] = playerTurn;
		}
		else if (location == "22" && s[1][1] == " ")
		{
			s[1][1] = playerTurn;
		}
		else if (location == "23" && s[1][2] == " ")
		{
			s[1][2] = playerTurn;
		}
		else if (location == "31" && s[2][0] == " ") //Checks input for row 3
		{
			s[2][0] = playerTurn;
		}
		else if (location == "32" && s[2][1] == " ")
		{
			s[2][1] = playerTurn;
		}
		else if (location == "33" && s[2][2] == " ")
		{
			s[2][2] = playerTurn;
		}
		else
		{
			validMove = false;

			printErrorMessage();
		}

		return validMove;
	}

	bool determineGameOver()
	{
		bool gameOver = false;

		if (s[0][0] == playerTurn && s[0][1] == playerTurn && s[0][2] == playerTurn) //Row 1
		{
			gameOver = true;
		}
		else if (s[1][0] == playerTurn && s[1][1] == playerTurn && s[1][2] == playerTurn) //Row 2
		{
			gameOver = true;
		}
		else if (s[2][0] == playerTurn && s[2][1] == playerTurn && s[2][2] == playerTurn) //Row 3
		{
			gameOver = true;
		}
		else if (s[0][0] == playerTurn && s[1][0] == playerTurn && s[2][0] == playerTurn) //Column 1
		{
			gameOver = true;
		}
		else if (s[0][1] == playerTurn && s[1][1] == playerTurn && s[2][1] == playerTurn) //Column 2
		{
			gameOver = true;
		}
		else if (s[0][2] == playerTurn && s[1][2] == playerTurn && s[2][2] == playerTurn) //Column 3
		{
			gameOver = true;
		}
		else if (s[0][0] == playerTurn && s[1][1] == playerTurn && s[2][2] == playerTurn) //Diagonal 1
		{
			gameOver = true;
		}
		else if (s[2][0] == playerTurn && s[1][1] == playerTurn && s[0][2] == playerTurn) //Diagonal 2
		{
			gameOver = true;
		}
		else if (squaresLeft == 0)
		{
			gameOver = true;
		}
		else
		{
			gameOver = false;
		}

		return gameOver;
	}

	//Print the result of the game
	void printOutcome(bool end)
	{
		if (end && squaresLeft == 0)
		{
			cout << endl << "-------------------------- IT'S A TIE --------------------------" << endl;
		}
		else if (end)
		{
			if (playerTurn == x)
			{
				cout << endl << "------------------------ PLAYER 1 WINS -------------------------" << endl;
			}
			else
			{
				cout << endl << "------------------------ PLAYER 2 WINS -------------------------" << endl;
			}
		}
	}

	// Alternate between the players
	void changeTurns()
	{
		squaresLeft--;

		if (playerTurn == x)
		{
			playerTurn = o;
		}
		else
		{
			playerTurn = x;
		}
	}
};

void StartNewGame()
{
	TicTacToe temp;

	temp.displayMenu();

	string answer = temp.makeChoice();

	if (answer == "1") //Play game
	{
		bool gameOver = false;

		do
		{
			temp.createGameboard();

			temp.playerMove(); //user chooses an input

			gameOver = temp.determineGameOver();

			if (gameOver)
			{
				temp.createGameboard();
			}

			temp.printOutcome(gameOver);

			if (!gameOver)
			{
				temp.changeTurns();
			}

		} while (!gameOver);
	}
	else if (answer == "2") //Display instructions
	{
		if (temp.displayRules())
		{
			cout << endl;
			StartNewGame();
		}
	}
	else if (answer == "3") //Exit
	{
		//No code to execute to exit
	}
}

int main()
{
	StartNewGame();

	return 0;
}