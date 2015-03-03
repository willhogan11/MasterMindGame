#include "masterMindProject.h"


///////  EASY MODE  //////////////////////////////////////////
void easyMode()
{
	// Declaration of Function Variables & Arrays
	int i, j, y, iTmpCnt;
	int num = 0;
	int blackPegCounter = 0;
	int whitePegCounter = 0;
	int attempts = 15;
	int completedAttempts = 0;

	char name[MAX_LENGTH + 1];
	char emptyArray[FOURARRAY + 1];
	char randomEmptyArray[FOURARRAY + 1];

	char easyCols[7] = { 'R', 'O', 'Y', 'G', 'B', 'I', 'V' };
	char temp = ' ';
	int	n = 7;
	FILE *fptr;
	j = 0;


	// initialize random seed:
	srand(time(NULL));
	system("cls");


	// Easy Mode Header
	printf("E A S Y   M O D E\n");
	printf("_________________\n");

	srand(time(NULL));

	// Using the Fisher Yates Shuffle to Eliminate Duplicate Values in the Random Array
	for (i = (n - 1); i > 0; i--)
	{
		j = rand() % (i + 1);
		temp = easyCols[j];
		easyCols[j] = easyCols[i];
		easyCols[i] = temp;

	} // End for (i = (n - 1); i > 0; i--)


	for (iTmpCnt = 0; i < 4; ++i)
	{
		randomEmptyArray[i] = easyCols[i];
		randomEmptyArray[4] = '\0';

	} // End for (iTmpCnt = 0; i < 4; ++i)

#ifdef DEBUG
	printf("%4s", randomEmptyArray);
#endif

	playGame(attempts, emptyArray, randomEmptyArray, name);

	printf("\n\n\n");
	system("Pause");

}
/////// END EASY MODE  ///////////////////////////////////////



///////  MEDIUM MODE  ////////////////////////////////////////
void mediumMode()
{
	// Declaration of Function Variables & Arrays
	int i, j, y;
	int k;
	int num = 0;
	int iResultCnt = 0;
	int n = 0;
	int blackPegCounter = 0;
	int whitePegCounter = 0;
	int attempts = 15;
	int completedAttempts = 0;

	char temp;
	char name[MAX_LENGTH + 1];
	char colour[NUMCOLS + 1];
	char emptyArray[FOURARRAY + 1];
	char randomEmptyArray[FOURARRAY + 1];

	FILE *fptr;

	// Initialise Character Array
	colour[0] = 'R';
	colour[1] = 'O';
	colour[2] = 'Y';
	colour[3] = 'G';
	colour[4] = 'B';
	colour[5] = 'I';
	colour[6] = 'V';


	// Initialize random seed
	srand((int)time(NULL));
	system("cls");


	// Medium Mode Header
	printf("M E D I U M   M O D E\n");
	printf("_________________\n");


	// Randomly Shuffle the 'colour[]' array and Store the result in the randomEmptyArray[]
	for (i = 0; i<FOURARRAY; i++)
	{
		randomEmptyArray[i] = colour[randFunc()];
		#ifdef DEBUG
			printf("%c", randomEmptyArray[i]);
		#endif

	} // End for loop

	randomEmptyArray[i] = '\0';

	playGame(attempts, emptyArray, randomEmptyArray, name);

	printf("\n\n\n");
	system("Pause");
}
/////// END MEDIUM MODE  /////////////////////////////////////



/////// HARD MODE  ///////////////////////////////////////////
void hardMode()
{
	// Declaration of Function Variables & Arrays
	int i;
	int score = 0;
	int blackPegCounter = 0;
	int whitePegCounter = 0;
	int attempts = 15;

	char name[MAX_LENGTH + 1];
	char colour[NUMHARDCOLS + 1];
	char emptyArray[FOURARRAY + 1];
	char randomEmptyArray[FOURARRAY + 1];

	FILE *fptr;

	// Initialise Character Array
	colour[0] = 'R';
	colour[1] = 'O';
	colour[2] = 'Y';
	colour[3] = 'G';
	colour[4] = 'B';
	colour[5] = 'I';
	colour[6] = 'V';
	colour[7] = ' ';

	// initialize random seed:
	srand(time(NULL));
	system("cls");


	// Easy Mode Header
	printf("H A R D   M O D E\n");
	printf("_________________\n");


	// Randomly Shuffle the 'colour[]' array 
	for (i = 0; i<FOURARRAY; i++)
	{
		randomEmptyArray[i] = colour[randFuncWithSpaces()];
		#ifdef DEBUG
			printf("%c", randomEmptyArray[i]);
		#endif

	} // End for loop

	randomEmptyArray[i] = '\0';

	playGame(attempts, emptyArray, randomEmptyArray, name);

	printf("\n\n\n");
	system("Pause");
}
/////// END HARD MODE  ///////////////////////////////////////



// This is the Actual Game Function used throughout all 3 Game Modes
void playGame(int attempts, char *emptyArray, char *randomEmptyArray, char *name)
{
	int blackPegCounter,
		whitePegCounter = 0,
		completedAttempts = 0;

	// If Invalid Character is entered, user will be returned to here. 
	START: printf("\nHere are the Colours, Please Enter Capital letters only, no spaces: \nR O Y G B I V\n");

	do
	{
		blackPegCounter = 0;

		// User enters Values
		printf("\nEnter any 4 from the Above, you have %d Attempts Remaining\n", attempts);
		fflush(stdin);
		gets(emptyArray);
		printf("\n", emptyArray);

		// Validation
		if ((emptyArray[0] == 'R' || emptyArray[0] == 'O' || emptyArray[0] == 'Y' || emptyArray[0] == 'G' || emptyArray[0] == 'B' || emptyArray[0] == 'I' || emptyArray[0] == 'V') ||
			(emptyArray[1] == 'R' || emptyArray[1] == 'O' || emptyArray[1] == 'Y' || emptyArray[1] == 'G' || emptyArray[1] == 'B' || emptyArray[1] == 'I' || emptyArray[1] == 'V') ||
			(emptyArray[2] == 'R' || emptyArray[2] == 'O' || emptyArray[2] == 'Y' || emptyArray[2] == 'G' || emptyArray[2] == 'B' || emptyArray[2] == 'I' || emptyArray[2] == 'V') ||
			(emptyArray[3] == 'R' || emptyArray[3] == 'O' || emptyArray[3] == 'Y' || emptyArray[3] == 'G' || emptyArray[3] == 'B' || emptyArray[3] == 'I' || emptyArray[3] == 'V'))
		{
			printf("\nYou Have chosen correct Colours...");
		}
		else
		{
			printf("Please Enter Valid Characters from the List R O Y G B I V\n");
			goto START;
		} // End of Validation if/else

		printf("\nYou Entered: %s\n", emptyArray);

		if (4 == checkPrintRoundChoices(emptyArray, randomEmptyArray, blackPegCounter))
			break;

		attempts--;
		completedAttempts++;

	} while (attempts != 0); // End do/while


	if (completedAttempts != 15)
	{
		printf("\n\nYou Guessed the Sequence and won the Game in %d Attempts", completedAttempts + 1);
	}
	else
	{
		printf("\nG A M E   O V E R");
		printf("\nYou have no more Chances");
	}

	// User won the game
	printf("\n\nPlease Enter your Intials: ");
	scanf("%s", &name);

	// Results printed using this Function. 
	printResults(&name, completedAttempts);

} 
// End void playGame(int attempts, char *emptyArray, char *randomEmptyArray, char *name)



// This Function Prints the game Results to FILENAME (HighScore.txt)
void printResults(char *name, int completedAttempts)
{
	FILE *fptr = fopen(FILENAME, "a");
	
	// Time/Date Stamp Associations plus conversion.  
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	// If no File Found, throws an error
	if (fptr == NULL)
	{
		printf("\n Could not open the file %s.", FILENAME);
		system("Pause");
		exit(0);

	} //  End of if ( fptr == NULL )

	fprintf(fptr, "\nNAME: %s: Completed in %d Attempt(s), at %s", name, (completedAttempts + 1), asctime(timeinfo));
	fclose(fptr);
}
// End void printResults(char *name, int completedAttempts)



// This Function Checks Which BlackPeg / Whitepeg Values have been Found in the Users Input. 
int checkPrintRoundChoices(char *UserChoices, char *ComputerChoices, int bPegCounter)
{
	int i, y, iResultCnt = 0, result, wpCounter = 0;

	for (i = 0; i < 4; i++)
	{
		if (UserChoices[i] == ComputerChoices[i])
		{
			bPegCounter++;
		}
		else
		{
			for (y = 0; y < 4; y++)
			{
				if (UserChoices[y] == ComputerChoices[i])
				{
					wpCounter++;

				} // End if (UserChoices[y] == ComputerChoices[i])

			} // End for (y = 0; y < 4; y++)

		} // End if (UserChoices[i] == ComputerChoices[i])

	} // End for (i = 0; i < 4; i++)


	if (bPegCounter == 4)
		puts("\nYou Won!\n");

	result = bPegCounter;

	while ((bPegCounter)-- > 0)
	{
		printf("Black Peg | ");
		iResultCnt++;
	}
	while ((wpCounter)-- > 0)
	{
		printf("White Peg | ");
		iResultCnt++;
	}

	while ((iResultCnt)++ != 4)
	{
		printf("----------| ");
	}

	return result;
}
// End int checkPrintRoundChoices(char *UserChoices, char *ComputerChoices, int bPegCounter)



///////  Random Function Generator ///////////////////////////
int randFunc()
{
	return rand() % 6;
}
//////// End of Random Function Generator ////////////////////



///////  Random Function with Spaces Generator ///////////////
int randFuncWithSpaces()
{
	return rand() % 8;
}
//////// End of Random Function Generator ////////////////////



/////// HIGH SCORE FUNCTION  /////////////////////////////////
void highScoreReadContents()
{
	FILE *fptr;
	int i = 0;
	char strBuffer[MAX_COUNT + 1]; 

	fptr = fopen(FILENAME, "r"); // "r" = READMODE

	// If there is an issue with opening the file or it doesn'y exist, throws the below error. 
	if( fptr == NULL )
	{
		printf("\nCould not open the file %s\n", FILENAME);
		system("Pause");
		exit(0);

	} //  End of if ( fptr == NULL )

	fprintf(stdout, "------------------ S C O R E   B O A R D ------------------------");
	
	do
	{
		// Read the contents
		fgets(strBuffer, MAX_COUNT, fptr); // Gets a number of characters from a filepointer. 
		printf("%s", strBuffer);
	}
	while( !feof(fptr) ); //  Haven't reached the end of file (eof)

	fclose(fptr);

	printf("\n\n");
	system("Pause");
	
}
/////// END highScoreReadContents() FUNCTION  ////////////////