#ifndef __masterMindProject_h
	
	// Definition Declarations
	#define __masterMindProject_h
	#define MenuItems 5
	#define NUMCOLS 7
	#define NUMHARDCOLS 8
	#define FOURARRAY 4
	#define FILENAME "HighScores.txt"
	#define WRITEMODE "w"
	#define READMODE "r"
	#define APPENDMODE "a"
	#define MAX_LENGTH 200
	#define MAX_COUNT 2000

	// Uncomment this for Debug mode to Display the Randonly Generated Values in Each Game Mode. 
	// #define DEBUG

	// Include Declarations
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <string.h>
	#include <dos.h>
	#include <conio.h>

	// Function Declarations
	int showMenu();
	int randFunc();
	int randFuncWithSpaces();
	void easyMode();
	void newPattern(char colours[]);
	void mediumMode();
	void hardMode();
	void highScoreReadContents();
	void timestamp();
	void logoDesign();
	int checkPrintRoundChoices(char *, char *, int);
	void printResults(char *, int);
	void playGame(int attempts, char *emptyArray, char *randomEmptyArray, char *name);

#endif // End if masterMindProject