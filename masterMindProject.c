#include "masterMindProject.h" // include header file in project


// The Main Function
int main()
{
	int iChoice;

	logoDesign();

	system("Pause");

	do
	{
		switch( iChoice = showMenu() )
		{
			case 1:
				{
					easyMode();
					break;
				}
			case 2:
				{
					mediumMode();
					break;
				}
			case 3:
				{
					hardMode();
					break;
				}
			case 4:
				{
					system("cls");
					highScoreReadContents();
					break;
				}
			case 5:
				{
					exit;
					break;
				}
			default:
				{
					printf("Please Enter a valid Selection");
					break;
				}
		}
		
	}while( iChoice != 5 ); // End of do while showMenu()

	printf("\n\n\n\n\n");
	system("Pause");

	return(0);

} //  End of Main


// Start of showMenu Function
int showMenu()
{
	int iChoice;

	do
	{
		system("cls");
		printf("\n\n\n");
		printf("\t\t           MASTERMIND GAME MENU             \n");
		printf("\t\t __________________________________________ \n");
		printf("\t\t|                                          |\n");
		printf("\t\t|       Press 1 to Play on Easy            |\n");
		printf("\t\t|                                          |\n");
		printf("\t\t|       Press 2 to Play on Medium          |\n");
		printf("\t\t|                                          |\n");
		printf("\t\t|       Press 3 to Play on Hard            |\n");
		printf("\t\t|                                          |\n");
		printf("\t\t|       Press 4 to View High Scores        |\n");
		printf("\t\t|                                          |\n");
		printf("\t\t|       Press 5 to Exit                    |\n");
		printf("\t\t|__________________________________________|\n");

		fflush(stdin);
		scanf("%d", &iChoice );

	}while( ( iChoice < 0 ) || ( iChoice > 5 ) ); // End of do/while

	return( iChoice );
	

} //  End of showMenu Function