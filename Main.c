#include "Global.h"

//	Setting the values for status bars, food & water chance, and status depletion rates
int health = 100;	// Initial value is 100 for all status bars
int thirst = 100;
int hunger = 100;
int days = 14;		// Number of days to survive
double food_chance = 0.5;	// 50% food chance
double water_chance = 0.5;	// 50% water chance
int hungry_damage = -5;		// Minus 5 health when hunger is zero
int thirsty_damage = -7;	// Minus 7 health when thirst is zero
int daily_hunger = -15;		// Decrease hunger by 15 every day
int daily_thirst = -15;		// Decrease thrist by 15 every day

int main() {

	main_menu();

	printf("Welcome to Fortnight! You have awoken in a forest with no memories,");
	printf("all you know is that you must survive for 14 days before you are rescued. Can you survive?\n\n\n");
	printf("       /\\        /\\      \n");
	printf("      /  \\      /  \\    \n");
	printf("     /\\   \\    /   /\\   \n");
	printf("    /      \\__/      \\  \n");
	printf("   /   /\\    /\\    /\\ \\ \n");
	printf("  /   /  \\  /  \\  /  \\ \\ \n");
	printf(" /   /    \\/    \\/    \\ \\ \n");
	printf("/   /  /\\          /\\  \\ \\ \n");
	printf("\\  /  /  \\/\\  /\\  /  \\  /\n");
	printf(" \\/  /       \\/  \\/    \\/ \n");
	printf("  \\/   /\\    /\\    /\\   \\/\n");
	printf("   \\  /  \\  /  \\  /  \\  / \n");
	printf("    \\/    \\/    \\/    \\/  \n");
	printf("     ||    ||    ||    ||  \n");
	printf("     ||    ||    ||    ||  \n");
	printf("     ||    ||    ||    ||  \n");
	printf("     ||    ||    ||    ||  \n");


	//call main menu function
	//give background story
	
	//maybe just do one decision a day, keep it simple
	for(int i = 1; i<days; i++){
		printf("\nDay %d\n", i);
		morning_event();
		//midday_event();
		//evening_event();

		//if hunger or thirst are zero, decrement health by appropraite amounts
		if (hunger == 0) {
			modifyhealth(hungry_damage);
		}
		if (thirst == 0) {
			modifyhealth(thirsty_damage);
		}

	// Lower hunger and health every day
		modifyhunger(daily_hunger);
		modifythirst(daily_thirst);

		//If health runs out, print losing message and return
		if (health <= 0) {
			printf("\n\nUh-Oh, you died :(\n");
			printf("You survived %d days\n\n", days);
			main();
		}
		
	 }
	
	//if made it through loop, and health is above 0, user won, print win message and return
	printf("\n\nCongratulations!\nYou beat Fort Night!\n\n");

	// Return to begining of main function
	main();

	return 0;
}





