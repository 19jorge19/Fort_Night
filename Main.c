#include "Global.h"

int health = 100;
int thirst = 100;
int hunger = 100;
int days = 14;
double food_chance = 0.5;
double water_chance = 0.5;
int hungry_damage = -5;
int thirsty_damage = -7;
int daily_hunger = 5;
int daily_thirst = 5;

int main() {

	//call main menu function
	//give background story
	
	//maybe just do one decision a day, keep it simple
	for(int i = 1; i<days; i++){
		printf("Day %d\n\n", i);
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

		hunger -= daily_hunger;
		thirst -= daily_thirst;

		//If health runs out, print losing message and return
		if (health <= 0) {
			printf("Uh-Oh, you died :(\n");
			printf("You survived %d days", days);
			return 0;
		}
		
	 }
	
	//if made it through loop, and health is above 0, user won, print win message and return
	printf("\n\nCongratulations!\nYou beat Fortnight!\n\n");

	return 0;
}





