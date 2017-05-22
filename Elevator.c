// Title: Elevator.c
// Date: 05/22/2017
// Copyleft: Dryicefox 2017
// For use and distribution related to education and restricted rights to distributed selling of code.

#include <stdio.h>
#include <unistd.h>

void printBuilding(int space)
{
	//This is subproblem 2.1 printing a floor for every run through
	/// local floors
	if (space>0)
	{
		printf("on||");
	//This is subproblem 2.2 printing n *'s until n is so low that it cannot run in printStars
	printBuilding(space-1);

	}
	else
	{
		if (space == 0)
		{
			printf("\n");
		}

	}
}

void printElevator(int level, int floors, int space)
{
	//This is subproblem 2.1 printing a floor for every run through
	/// local floors
	if (floors>0 && floors != level)
	{
		printf("|   |");
		printBuilding(space);
	//This is subproblem 2.2 printing n *'s until n is so low that it cannot run in printStars
	printElevator(level, floors-1, space);

	}
	else
	{
		if  (floors == level && floors>0)
		{
			printf("|| ||");
			printBuilding(space);
			//This is subproblem 2.2 printing n *'s until n is so low that it cannot run in printStars
			printElevator(level, floors-1, space);
		}

	}
}

void printMovement(int level, int floors, int n, int on, int space)
	{
		if (on < 1)
		{
			n = level;
			level = 1;
			on++;
		}
		if (n >= level)
		{
			sleep(1);
			printf("\n\n\n\n\n\n\n\n");
			printElevator(level, floors, space);
			level++;
			if (level < floors)
			{
				printMovement(level, floors, n, on, space);
			}
		}
	}

int main(void)
{
	
	//for every level print a floor.
	int level, space, number, floors, n;
	floors = 15;
	level = 1;
	n = 1;
	printf("Please make the building.\nThe building has this many floors: ");
	scanf("%d", &floors);
	if (floors == 0)
	{
		do
		{	
			printf("That's not a building at all if it has %d floors!\n\tTry again. \n", floors);
			scanf("%d", &floors);
		}while(level > floors);		
	}
	printf("Please make the building.\nThe building has this many rooms: ");
	scanf("%d", &space);

	printf("Please put in the floor you wish to go to and the elevator will take you there.\nFloor number: ");
	scanf("%d", &level);

	if (level > floors)
	{
		do
		{	
			printf("Sorry, it doesn't seem that the floor selected in inside the building. Your building has %d floors.\n\tTry again. \n", floors);
			scanf("%d", &level);
		}while(level > floors);
	}

	int on = 0;
	printMovement(level, floors, n, on, space);
}3