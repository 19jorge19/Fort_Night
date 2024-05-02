#include "Global.h"
#include "Events.h"

int health = 100;	//	Value of health
int thirst = 100;	//	Value of thirst
int hunger = 100;	//	Value of hunger

//	Values that store if player is sick, and which stat to decrease. Only decrease values is greater than 1
int sick_hunger = 0;
int sick_thirst = 0;
int sick_health = 0;
int stay_count = 1;
int day_count = 0;

int days = 14;	//	Days required to beat the game

int hungry_damage = -15;	//	Decrease in health if hunger is zero
int thirsty_damage = -20;	//	Decrease in health if thirst is zero
int daily_hunger = -15;		//	Decrease in hunger after every day
int daily_thirst = -15;		//	Decrease in thirst after every day

int main() {

	main_menu();

	health = 100;
	thirst = 100;
	hunger = 100;

	printf("Welcome to Fortnight! You have awoken in a forest with no memories, \nall you know is that you must survive for 14 days before you are rescued. Can you survive?\n\n\n");
	printf("       /\\        /\\      \n");
	printf("      /  \\      /  \\    \n");
	printf("     /\\   \\    /   /\\   \n");
	printf("    /      \\__/      \\  \n");
	printf("   /   /\\    /\\    /\\ \\ \n");
	printf("  /   / /\\  /  \\  /  \\ \\ \n");
	printf(" /   /    \\/   /\\/    \\ \\ \n");
	printf("/   / /\\          /\\  /  \\ \n");
	printf("\\  / /  \\/\\  /\\  /  \\/	 /\n");
	printf(" \\/ /      \\/  \\/    \\  / \n");
	printf("  \\/   /\\    /\\    /\\ \\/\\ \n");
	printf("   \\  /  \\  /  \\  /  \\  / \n");
	printf("    \\/    \\/    \\/    \\/  \n");
	printf("    ||    ||    ||    ||  \n");
	printf("    ||    ||    ||    ||  \n");
	printf("    ||    ||    ||    ||  \n");
	//printf("    ||    ||    ||    ||  \n");


	//call main menu function
	//give background story
	
	//maybe just do one decision a day, keep it simple
	for(int i = 1; i<days; i++){
		day_count = i;
		printf("\n| Day #%d | \n", i);
		//status_show(health, hunger, thirst);

		morning_event();
		midday_event();
		//evening_event();

		//daily hunger and thirst decrements
		modifyhunger(daily_hunger);
		modifythirst(daily_thirst);
		sick_counter(sick_health, sick_hunger, sick_thirst);

		//if hungry or thirsty, decrement health by appropraite amounts
		if (hunger == 0) {
			modifyhealth(hungry_damage);
		}
		if (thirst == 0) {
			modifyhealth(thirsty_damage);
		}
		//return_items();

		//If health runs out, print losing message and return
		if (health <= 0) {
			if (check_totem() == true) {
				printf("The totem disappears in a flash of light, and you are saved from death!\n");
				modifyhealth(50);
			}
			else {
				printf("\n---------\nUh-Oh, you died :(\n");
				printf("You survived for %d days\n---------\n\n", i);
				main();
			}
		}
		
	 }
	
	//if made it through loop, and health is above 0, user won, print win message and return
	printf("\n\nCongratulations!\nYou beat Fortnight!\n\n");

	main();

	return 0;
}





