#include "Global.h"

int health = 100;
int thirst = 100;
int hunger = 100;
bool hatchet = false;
bool water_bottle = false;
bool medkit = false;
bool backpack = false;
int days = 14;
double food_chance = 0.5; //50%
double water_chance = 0.5; //50%
double bear_chance = 0.2; //20%
double storm_chance = 0.2; //20%
double package_chance = 0.08; //8%
int hungry_damage = -15;
int thirsty_damage = -20;
int daily_hunger = -15;
int daily_thirst = -15;

int main() {
	health = 100;
	thirst = 100;
	hunger = 100;

	main_menu();

	printf("Welcome to Fortnight! You have awoken in a forest with no memories, all you know is that you must survive for 14 days before you are rescued. Can you survive?\n\n\n");
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
		printf("Health: %d\n", health);
		printf("Hunger: %d\n", hunger);
		printf("Thirst: %d\n\n", thirst);
		
		//daily hunger and thirst decrements
		modifyhunger(daily_hunger);
		modifythirst(daily_thirst);

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


		//If health runs out, print losing message and return
		if (health <= 0) {
			printf("\n\nUh-Oh, you died :(\n");
			printf("You survived %d days\n\n", i);
			main();
		}
		
	 }
	
	//if made it through loop, and health is above 0, user won, print win message and return
	printf("\n\nCongratulations!\nYou beat Fortnight!\n\n");

	main();

	return 0;
}





