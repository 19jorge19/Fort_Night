#include "Global.h"

int health = 100;
int thirst = 100;
int hunger = 100;
int days = 14;
double food_chance = 0.5; //50%
double water_chance = 0.5; //50%
int hungry_damage = -5;
int thirsty_damage = -7;
int daily_hunger = -15;
int daily_thirst = -15;

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

		//if hungry or thirsty, decrement health by appropraite amounts
		if (hunger == 0) {
			modifyhealth(hungry_damage);
		}
		if (thirst == 0) {
			modifyhealth(thirsty_damage);
		}

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

	main();

	return 0;
}





