//this is our first project and the name of this game is "HANGMAN GAME"
//this game is developed by Md.Sadman Ahmmed Chowdhuri and Nawreen islam.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void gamesfun(char *wordforfun, char *wordforuser, int letter);   //Function for checking the letter, incrementing counters etc.
void printword(char * userword,int letter);			        //Function for printing the array of user
void printgamefig(int fig);						      //Function for printing the hangman figure

int main()
{

printf("HELP:- In this game firstly you have to select level and category.\nThen you have to guess a correct letter by your own because this game will not give you any hint to make the correct word.\n");
printf("You will get 9 chance here to be a winner .\nFor your kind information in this game the easy level is SIX letter word game medium is SEVEN letter game\n");

	FILE *fptr;     //First, program reads from file
	fptr = fopen("words.txt", "r");

	if(fptr== NULL)
	{
		printf("file is not found and dose not excised ");
		return 0;
	}
	char readthefile[300];

	while(!feof(fptr))
	{
		fgets(readthefile, 300, fptr);
	}

	fclose(fptr);

	srand(time(NULL));  //Seeding for random choices

	int againplay= -1; //At the end, that variable's value can change so the game terminates
	while(againplay==-1)
	{
		int gamelevel;   //Program asks user to select his level
		 printf("\n\n\n\t !!WELLCOME TO HANGMAN GAME!!\n");
      printf("-------------------------------------------------");
      printf("\n\n select your level \n\n 1. EASY\n 2. MEDIUM\n");
		scanf("%d", &gamelevel);

		while(gamelevel != 1 && gamelevel != 2 )
		{
			system("cls");
			 printf("\n\n\n\t !!WELLCOME TO HANGMAN GAME!!\n");
      printf("-------------------------------------------------");
      printf("\n\n select your level \n\n 1. EASY\n 2. MEDIUM\n");


			scanf("%d", &gamelevel);




		}

		system("cls");


		int category; //Program asks user to category type
printf(" CHOOSE A CATAGORY OF WORD WHICH YOU WANT TO GUESS\n\n 1.Fish\t 2.Animal\t 3.Bird\t 4.Food\n\n\n");

		scanf("%d", &category);

		while(category != 1 && category != 2 && category != 3 && category!= 4 )
		{
			system("cls");

printf(" CHOOSE A CATAGORY OF WORD WHICH YOU WANT TO GUESS\n\n 1.Fish\t 2.Animal\t 3.Bird\t 4.Food\n\n\n");
			scanf("%d", &category);

		}

	//	if(category== 5)
	//	{
	//		category= rand() % 4 + 1;
	//	}

		char askword[8];									//Array for holding the word
		char userWord[8]= {'_','_','_','_','_','_','_'};    //Array for user's true letters

		int random_genatate = rand()% 5;              //Program writes appropriate random word to askedWord array from readed file
          int i;
		if(category == 1)      //Category for Fruits and Vegetables
		{
			if(gamelevel== 1)
			{
				for( i= 0; i< 7; i++)
				{
					askword[i]= readthefile[(35* 0)+ (random_genatate * 7)+ i]; // 0-35 care count and randomly word cho.
				}                                                                  //7 WARD ER JNNO 7  //

			}

			else
			{
				for( i= 0; i< 7; i++)
				{
					askword[i]= readthefile[(35* 1)+ (random_genatate* 7)+ i];
				}

			}
		}

		else if(category == 2) //Category for Sports
		{
			if(gamelevel==1)
			{
				for(i= 0; i< 7; i++)
				{
					askword[i]= readthefile[(35* 2)+ (random_genatate * 7)+ i];
				}

			}

			else
			{
				for(i= 0; i< 7; i++)
				{
					askword[i]= readthefile[(35* 3)+ (random_genatate * 7)+ i];
				}

			}
		}

		else if(category == 3) //Category for Technological Devices
		{
			if(gamelevel==1)
			{
				for(i= 0; i< 7; i++)
				{
					askword[i]= readthefile[(35* 4)+ (random_genatate * 7)+ i];
				}

			}

			else
			{
				for( i= 0; i< 7; i++)
				{
					askword[i]= readthefile[(35* 5)+ (random_genatate * 7)+ i];
				}

			}
		}

		else			        //Category for Countries
		{
			if(gamelevel==1)
			{
				for( i= 0; i< 7; i++)
				{
					askword[i]= readthefile[(35* 6)+ (random_genatate * 7)+ i];
				}

			}

			else
			{
				for(i= 0; i< 7; i++)
				{
					askword[i]= readthefile[(35* 7)+ (random_genatate * 7)+ i];
				}

			}
		}

		gamesfun(askword, userWord, (gamelevel+5));    //Program goes to gameFunction with neccessary arrays and lettter size
        printf("\n \nDO YOU WANT TO PLAY AGAIN!!??\n");
		printf("\n\n Enter -1 to play again\n");    //At the end of the game program asks user to replay or not
		scanf(" %d", &againplay);
		system("cls");
	}
}

void gamesfun(char *wordforfun, char *wordforuser, int letter)      //Function for checking the letter, incrementing counters etc.
{
	int correct= 0;			//Total number of true entered letters -if equals to letterNumber game is over-
	int incorrect= 0;			//Total number of fails -must be less than 9 or game is over-
	char scanword;
    int i;
	while(incorrect< 9)
	{
		printgamefig(incorrect);		//Program goes function to print the corresponding figure to fail
		printf("\n\n\n");
		printword(wordforuser, letter);     //Program goes function to print the user's array
		printf("ENTER A CHARECTER:_ ");
		scanf(" %c", &scanword);
		scanword= toupper(scanword);

		int usedletter= 1;			//Program checks whether the inputted letter is already found or not//
		while(usedletter== 1)
		{
			for(i=  0; i< letter; i++)
			{
				if(wordforuser[i]!= scanword)
				{
					usedletter= 0;
				}

				else
				{
					usedletter= 1;
					printgamefig(incorrect);
					printf("\n\n\n");
					printword(wordforuser, letter);
					printf("\nLetter already found!\nEnter a new character: ");
					scanf(" %c", &scanword);
					scanword= toupper(scanword);
					break;
				}
			}

		}

		int correctletter= 0;                        //This part checks every valid letter in order to understand...
		for( i= 0; i< letter; i++)			   //... it is a part of askedWord or not with counters
		{
			if(scanword== wordforfun[i])		   //This part means that user entered a correct character
			{
				wordforuser[i]= wordforfun[i];
				correctletter++;
				correct++;
			}
		}

		if(correctletter== 0)						//This part means that user entered a wrong character
		{
			incorrect++;
		}

		if(correct== letter)                //This if statement works if you win the game and returns to main
		{
			printgamefig(incorrect);
			printf("\n\n\n\n\n");
			printword(wordforuser, letter);
			printf("\n\n!!!!!!!HERRAH!!!!!!\nYOU WON THE GAME :-D");
			printf("THANK YOU FOR PLAYING WITH US  :-)");
			return;
		}
	}

	printgamefig(incorrect);	                         //This part works if you loose the game and returns to main
	printf("\n\n\n");
	for( i= 0; i< letter; i++)
	{
		printf("%c ", wordforfun[i]);
	}
	 printf("\n !!!WE ARE SORRY!!!\nYOU LOSE THE GAMES :'-( \nBETTER LUCK NEXT TIME :-D\n");
	 printf("THANK YOU FOR PLAYING WITH US :-)");
	return;

}

void printword(char *userword,int letter)    //This function basicly prints the array of user
{   int i;
	for( i= 0; i< letter; i++)
	{
		printf("%c ", userword[i]);
	}
}

void printgamefig(int fig)    //This function clears the screen and prints the corresponding fail figure
{
	system("cls");

	switch(fig)
	{
		case 0:
			printf(" _ _ _  \n|     \n|     \n|    \n|     \n|     \n|     \n|      \n|\n|_");
			break;
		case 1:
			printf(" _ _ _  \n|     |\n|     \n|    \n|     \n|     \n|     \n|      \n|\n|_");
			break;
		case 2:
			printf(" _ _ _  \n|     |\n|     |\n|    \n|     \n|     \n|     \n|      \n|\n|_");
			break;
		case 3:
			printf(" _ _ _  \n|     |\n|     |\n|    ( )\n|     \n|     \n|     \n|      \n|\n|_");
			break;
		case 4:
			printf(" _ _ _  \n|     |\n|     |\n|    ( )\n|     |\n|     |\n|     \n|      \n|\n|_");
			break;
		case 5:
			printf(" _ _ _  \n|     |\n|     |\n|    ( )\n|    /| \n|     |\n|     \n|      \n|\n|_");
			break;
		case 6:
			printf(" _ _ _  \n|     |\n|     |\n|    ( )\n|    /|\\ \n|     |\n|     \n|      \n|\n|_");
			break;
		case 7:
			printf(" _ _ _  \n|     |\n|     |\n|    ( )\n|    /|\\ \n|     |\n|     |\n|      \n|\n|_");
			break;
		case 8:
			printf(" _ _ _  \n|     |\n|     |\n|    ( )\n|    /|\\ \n|     |\n|     |\n|    /  \n|\n|_");
			break;
		case 9:
			printf(" _ _ _  \n|     |\n|     |\n|    ( )\n|    /|\\ \n|     |\n|     |\n|    / \\ \n|\n|_");
			break;
	}

	return;

}
