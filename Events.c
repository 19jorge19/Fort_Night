#include "Events.h"

int normal = 6; //0-5 nothing for random event
int bear = 8; //6-7 bear
//storm is if not below those two events
int bear_damage = -25;
int storm_damage = -25;


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
	if (random_event >= normal && random_event < bear) {
		//bear attack
		printf("While out searching for food, you ran into a bear!\n");
		printf("Health decreased by: %d\n", abs(bear_damage));
		modifyhealth(bear_damage);
	}
	//if random number is in the storm range, 8-9, storm
	else if (random_event >= bear) {
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

		if (r < food_chance) {
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
		printf("While out searching for water, you ran into a bear!\n");
		printf("Health decreased by: %d\n", abs(bear_damage));
		modifyhealth(bear_damage);
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

		if (r < water_chance) {
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
		printf("Oh no! A bear has found you!\n");
		printf("Health decreased by: %d\n", abs(bear_damage));
		modifyhealth(bear_damage);
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

