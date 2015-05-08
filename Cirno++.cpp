// Cirno++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <time.h>

// CirnoAnswer should check wheter the right answer has been given.
bool CirnoAnswer();

// Cirno() prints the question on screen to be answered, returns 'left' (0) or 'right' (1)
bool Cirno();

// Menu for restarting
void boot();

// Main game loop
void Game();

// Changes numbers to proper Touhou numbers
void Transcriber(int nAnswer, int nWrong, bool bDirection);

std::string Touhoufy(int n);

int main()
{
	std::cout << "Rules:\n1) You have 5 seconds to answer\n2) Use the arrow keys on the keyboard to answer\n3) Use right shift to exit\n\n";
	std::cout << "Press [Enter] to play\n\n";
	boot();
	return 0;
}

void boot()
{
	int nPressed = 0;
	while (nPressed == 0)
	{
		while (GetAsyncKeyState(VK_RETURN))
			nPressed = 1;

		while (GetAsyncKeyState(VK_RSHIFT))
			nPressed = -1;
	}

	if (nPressed == -1)
		return;

	if (nPressed == 1)
		Game();

	boot();
}

void Game()
{
	bool gameEnd = false;
	int highscore = -1;

	while (!gameEnd)
	{
		highscore++;
		gameEnd = CirnoAnswer();
		Sleep(500);
	}
	std::cout << "Game Over!\n\nCombo: " << highscore << "\n\nPress [Enter] to play again!\n\n";
}

bool CirnoAnswer()
{
	// If answered correctly
	bool foo = Cirno();
	bool answerGiven = false;

	while (!answerGiven)
	{
		while(GetAsyncKeyState(VK_LEFT))
		{
			if (foo)
			{
				//std::cout << "\nRIGHT ANSWER\n";
				return false;
			}
			if (!foo)
			{
				//std::cout << "\nWRONG ANSWER\n";
				return true;
			}
		}
		while(GetAsyncKeyState(VK_RIGHT))
		{
			if (!foo)
			{
				//std::cout << "\nRIGHT ANSWER\n";
				return false;
			}
			if (foo)
			{
				//std::cout << "\nWRONG ANSWER\n";
				return true;
			}
		}
	}
	return true;
}

bool Cirno()
{
	srand(time(NULL));
	auto x = rand() % 8 + 1;
	auto y = rand() % (9 - x) + 1;

	std::cout << "Solve: " << x << " + " << y << " is?" << std::endl;

	auto z = rand() % 2 + 1;

	int c = (x + y);
	
	do
	{
		c = rand() % 8 + 1;
	} while (c == (x + y));

	if (z == 1)
	{
		//std::cout << "\nLeft Side is correct\n";
		// Left side is the right answer
		Transcriber((x + y), c, true);
		return true;
	}
	else
	{
		//std::cout << "\nRight Side is correct\n";
		// Right side is the right answer
		Transcriber((x + y), c, false);
		return false;
	}
}

void Transcriber(int nAnswer, int nWrong, bool bDirection)
{
	//std::string sAnswer;
	//std::string sWrong;

	//sAnswer = Touhoufy(nAnswer);
	//sWrong = Touhoufy(nWrong);

	// Correct answer is LEFT
	if (bDirection)
	{
		if (nAnswer == 9)
			std::cout << "\t" << nAnswer << " || " << nWrong << "\n\n";
		else
			std::cout << "\t" << nWrong << " || " << nAnswer << "\n\n";
	}

	// Correct answer is RIGHT
	if (!bDirection)
	{
		if (nAnswer == 9)
			std::cout << "\t" << nWrong << " || " << nAnswer << "\n\n";
		else
			std::cout << "\t" << nAnswer << " || " << nWrong << "\n\n";
	}
}

//RIP
std::string Touhoufy(int n)
{
	if (n == 1)
		return "①";
	else if (n == 2)
		return "②";
	else if (n == 3)
		return "③";
	else if (n == 4)
		return "④";
	else if (n == 5)
		return "⑤";
	else if (n == 6)
		return "⑥";
	else if (n == 7)
		return "⑦";
	else if (n == 8)
		return "⑧";
	else if (n == 9)
		return "⑨";
}
