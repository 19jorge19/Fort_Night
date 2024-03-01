#include "Events.h"
#include "Status_Bars.h"
#include "Chance_Values.h"
//#include "SettingChance.c"

int normal = 6; //0-5 nothing for random event
int bear_chance = 8; //6-7 bear

//storm is if not below those two events
int storm_damage = -25;

double food_chance = 0.5;
double water_chance = 0.5;
int hungry_damage = -5;
int thirsty_damage = -7;
int daily_hunger = 5;
int daily_thirst = 5;
int bear_damage = -25;

/*
* Function displays status bars before prompting user to make a decision for what to do in the morning
* User may search for food, search for water, or stay in
* Chance of random event happening to which function calls other functions based on user decision, and passes what random event happened
*/
void morning_event() {
	int decision;

	//print statuses
	printf("Health: %d\n", health);
	printf("Hunger: %d\n", hunger);
	printf("Thirst: %d\n\n", thirst);

	//print to screen user decision, go find food, find water, or stay here
	printf("Make a decision: \n");
	printf("0: Search for food\n");
	printf("1: Search for water\n");
	printf("2: Stay in\n");

	scanf("%d", &decision);
	
	printf("\n\n");

	//random chance of storm, other unpredictable event
	int random_event = rand() % 10;
	//random event = random number 0-9, 0-5 = nothing, 6-7 = bear attack, 8-9 = storm
	//when adding modes, use multiplier here to scale up hard mode, scale down easy mode


	//send into different function if there is a storm or other event 
	if (decision == 0) {
		find_food(random_event);
		return;
	}
	else if (decision == 1) {
		find_water(random_event);
		return;
	}
	else if (decision == 2) {
		stay_in(random_event);
		return;
	}
	else {
		printf("Please choose a decision\n");
		morning_event();
	}

}

/*
* Function takes in random_event number
* If random event is in certain ranges, triggers bear or storm events
* If not, function provides user with food based on chance defined by food_chance variable
*/
void find_food(int random_event) {
	//if random number is in the bear range, 6-7, bear attack
	if (random_event >= normal && random_event < bear_chance) {
		//bear attack
		bear();
	}
	//if random number is in the storm range, 8-9, storm
	else if (random_event >= bear_chance) {
		//storm
		printf("While out searching for food, you ran into a storm!\n");
		printf("Health decreased by: %d\n", abs(storm_damage));
		modifyhealth(storm_damage);
	}
	//if random number is not in those ranges, it's a normal case
	//additionally, if we want normal case to run through no matter what, we can remove else statement
	else {
		//normal case
		double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1

		if (r <= food_chance) {
			printf("Congratualations!\nYou have successfully found food!\n");
			modifyhunger(10);
			//additionally can modify food chance to decrease
		}
		else {
			printf("Uh-Oh\nYou did not find any food.\n");
			//additionally, can decrease hunger if we want, for wasting energy not finding food
			//additionally, can modify food chance to increase
		}
	}
	return;
}

void find_water(int random_event) {
	//if random number is in the bear range, 6-7, bear attack
	if (random_event >= normal && random_event < bear) {
		//bear attack
		bear();
	}
	//if random number is in the storm range, 8-9, storm
	else if (random_event >= bear) {
		//storm
		printf("While out searching for water, you ran into a storm!\n");
		printf("Health decreased by: %d\n", abs(storm_damage));
		modifyhealth(storm_damage);
	}
	//if random number is not in those ranges, it's a normal case
	//additionally, if we want normal case to run through no matter what, we can remove else statement
	else {
		//normal case
		double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1

		if (r <= water_chance) {
			printf("Congratualations!\nYou have successfully found water!\n");
			modifythirst(10);
			//additionally can modify water chance to decrease
		}
		else {
			printf("Uh-Oh\nYou did not find any water.\n");
			//additionally, can decrease thirst if we want, for wasting energy not finding food
			//additionally, can modify food chance to increase
		}
	}
	return;
}

void stay_in(int random_event) {
	//if random number is in the bear range, 6-7, bear attack
	if (random_event >= normal && random_event < bear) {
		//bear attack
		bear();
	}
	//if random number is in the storm range, 8-9, storm
	else if (random_event >= bear) {
		//storm
		printf("A storm came in, but you stayed in so nothing happened.\n");
	}
	else {
		printf("You have stayed in, and nothing has happened.\n");
	}
	return;
}

/*
* Function is called if there is a bear attack
* gives options to run away, fight, or play dead
* constants for chances as well as damages for each case located in function
*/
void bear() {
	int choice;
	printf("Oh no! You ran into a bear!\n");
	printf("What would you like to do?\n");
	printf("0: Run away\n");
	printf("1: Fight it\n");
	printf("2: Play dead\n");

	scanf("%d", &choice);
	printf("\n\n");

	//initializing chances of success
	double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1
	double run_away = 0.3;	//chance of runing away 30%
	double fight = 0.1;		//chance of beating it in a fight 10%
	double play_dead = 0.7;  //chance of playing dead and it leaving you alone 70%

	//initializing what you get for each scenario
	int running_attack = -30;
	int fight_attack = -50;
	int play_attack = -10;
	int bear_food = 30;


	if (choice == 0) {
		if (r <= run_away) {
			//success
			printf("Congratualtions!\nYou have successfully ran away from the bear!\n");
		}
		else {
			printf("Oh no!\nThe bear caught you!\n");
			printf("Health decreased by %d\n", abs(running_attack));
			modifyhealth(running_attack);
		}
	}
	else if (choice == 1) {
		if (r <= fight) {
			//success
			printf("Congratulations!\nYou have successfully fought off the bear and took some of its food!\n");
			printf("Food increased by %d", bear_food);
			modifyhunger(bear_food);
		}
		else {
			printf("Oh no!\nThe bear beat you!\n");
			printf("Health decreased by %d\n", abs(fight_attack));
			modifyhealth(fight_attack);
		}
	}
	else if (choice == 2) {
		if (r <= play_dead) {
			//success
			printf("Congratualtions!\nThe bear left you alone.\n");
		}
		else {
			printf("Oh no!\nThe bear still attacked you!\n");
			printf("Health decreased by %d", abs(play_attack));
			modifyhealth(play_attack);
		}
	}
	else {
		printf("Please select a valid choice\n");
		bear();
	}
	return;
}

void storm(bool home) {

}
