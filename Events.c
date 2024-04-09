#include "Events.h"
#include "Status_Bars.h"

int normal = 0; 
int bear_attack = 1; 
int storm_appear = 2;
int package_drop = 3;
double food_chance = 0.5; //50%
double water_chance = 0.5; //50%
double bear_chance = 0.2; //20%
double storm_chance = 0.2; //20%
double package_chance = 0.08; //8%
double sick_chance = 60; // Threshold for random_sick to cross

bool hatchet = false;
bool water_bottle = false;
bool medkit = false;
bool backpack = false;

/*
* Function displays status bars before prompting user to make a decision for what to do in the morning
* User may search for food, search for water, or stay in
* Chance of random event happening to which function calls other functions based on user decision, and passes what random event happened
*/
void morning_event() {
	int decision;
	int random_event;

	printf("\nMorning Event %d \n", day_count);
	//print statuses
	status_show(health, hunger, thirst);

	//print to screen user decision, go find food, find water, or stay here
	choices();

	scanf("%d", &decision);
	printf("\n");
	

	//random chance of storm, other unpredictable event
	int random_sick = rand() % 100; // random number between 0-99. Any value above 'sick_chance' is sick, while below is not sick

	double r = (double)rand() / RAND_MAX;
	if (r <= bear_chance) {
		//bear attack
		random_event = 1;
	}
	else if (r <= bear_chance + storm_chance) {
		//storm
		random_event = 2;
	}
	else if (r <= bear_chance + storm_chance + package_chance) {
		//package
		random_event = 3;
	}
	else {
		//normal
		random_event = 0;
	}


	//send into different function if there is a storm or other event 
	if (decision == 0) {
		find_food(random_event, random_sick);
		return;
	}
	else if (decision == 1) {
		find_water(random_event, random_sick);
		return;
	}
	else if (decision == 2) {
		stay_count++;
		stay_in(random_event, stay_count);
		return;
	}
	else {
		printf("Please choose a decision\n");
		morning_event();
	}

}

//*
void midday_event() {
	int decision;
	int random_event;
	//print statuses
	printf("Midday Event %d \n", day_count);
	status_show(health, hunger, thirst);

	//print to screen user decision, go find food, find water, or stay here
	choices();

	scanf("%d", &decision);
	printf("\n");
	

	//random chance of storm, other unpredictable event
	int random_sick = rand() % 100; // random number between 0-99. a value above 90 is sick, below is fine

	double r = (double)rand() / RAND_MAX;
	if (r <= bear_chance) {
		//bear attack
		random_event = 1;
	}
	else if (r <= bear_chance + storm_chance) {
		//storm
		random_event = 2;
	}
	else if (r <= bear_chance + storm_chance + package_chance) {
		//package
		random_event = 3;
	}
	else {
		//normal
		random_event = 0;
	}


	//send into different function if there is a storm or other event 
	if (decision == 0) {
		find_food(random_event, random_sick);
		return;
	}
	else if (decision == 1) {
		find_water(random_event, random_sick);
		return;
	}
	else if (decision == 2) {
		stay_in(random_event, stay_count);
		return;
	}
	else {
		printf("Please choose a decision\n");
		midday_event();
	}

}
//*/


/*
* Function takes in random_event number
* If random event is in certain ranges, triggers bear or storm events
* If not, function provides user with food based on chance defined by food_chance variable
*/
void find_food(int random_event, int random_sick) {
	int food_found = 45;
	//if random number is in the bear range, 6-7, bear attack
	if (random_event == bear_attack) {
		//bear attack
		bear(false);
	}
	//if random number is in the storm range, 8-9, storm
	else if (random_event == storm_appear) {
		//storm
		storm(false);
	}
	else if (random_event == package_drop) {
		//dropped package
		dropped_package(false);
	}
	//if random number is not in those ranges, it's a normal case
	//additionally, if we want normal case to run through no matter what, we can remove else statement
	//else {
		//normal case
		double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1

		if (r <= food_chance) {
			printf("Congrats!\nYou have successfully found food!\n\n");
			modifyhunger(food_found);
			//additionally can modify food chance to decrease
			food_chance -= 0.2;
			if (random_sick >= sick_chance){
				printf("You've contracted food poisoning, and have developed a fever!\n\n");
				sick_health = 4;
				sick_hunger = 4;
			}
		}
		else {
			printf("Uh-Oh\nYou did not find any food.\n\n");
			food_chance += 0.2;
			//additionally, can decrease hunger if we want, for wasting energy not finding food
			//additionally, can modify food chance to increase
		}
	//}
	return;
}

/*
* function called if user decides to stay in
* takes in random event integer and calls bear or storm if event occurs
* if event does not occur, nothing happens
*/
void find_water(int random_event, int random_sick) {
	int water_found = 45;
	//if random number is in the bear range, 6-7, bear attack
	if (random_event == bear_attack) {
		//bear attack
		bear(false);
	}
	//if random number is in the storm range, 8-9, storm
	else if (random_event == storm_appear) {
		//storm
		storm(false); //false because not at home
	}
	else if (random_event == package_drop) {
		//dropped package
		dropped_package(false);
	}
	//if random number is not in those ranges, it's a normal case
	//additionally, if we want normal case to run through no matter what, we can remove else statement
	//else {
		//normal case
		double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1

		if (r <= water_chance) {
			printf("Congrats!\nYou have successfully found water!\n\n");
			modifythirst(water_found);
			water_chance -= 0.2;
			//additionally can modify water chance to decrease
			if (random_sick >= sick_chance){
				printf("You've drunk contaminated water, and have contracted dysentary!\n\n");
				sick_health = 4;
				sick_thirst = 4;
			}
		}
		else {
			printf("Uh-Oh\nYou did not find any water.\n\n");
			water_chance += 0.2;
			//additionally, can decrease thirst if we want, for wasting energy not finding food
			//additionally, can modify food chance to increase
		}
	//}
	return;
}

/*
* function called if user decides to stay in
* takes in random event integer and calls bear or storm if event occurs
* if event does not occur, nothing happens 
*/
void stay_in(int random_event, int stay_count) {

	//if random number is in the bear range, 6-7, bear attack
	if (random_event == bear_attack) {
		//bear attack
		bear(true);
		sick_stay_counter(stay_count);
	}
	//if random number is in the storm range, 8-9, storm
	else if (random_event == storm_appear) {
		//storm
		storm(true); //call storm function, at home so send in true for home boolean
		sick_stay_counter(stay_count);
	}
	else if (random_event == package_drop) {
		//dropped package
		dropped_package(true);
		sick_stay_counter(stay_count);
	}
	else {
		sick_stay_counter(stay_count);
		printf("You have stayed in, and nothing unexpected has happened.\n");
		
	}
	return;
}

/*
* Function is called if there is a bear attack
* gives options to run away, fight, or play dead
* constants for chances as well as damages for each case located in function
*/
void bear(bool home) {
	printf("Oh no! A bear appeared!\n\n");
	print_bear();

	if (home) {
		printf("Luckily, you were at home so nothing happened.\n");
		return;
	}

	int choice;
	printf("What would you like to do?\n");
	printf("0: Run away\n");
	printf("1: Fight it\n");
	printf("2: Play dead\n");

	scanf("%d", &choice);
	printf("\n");

	//initializing chances of success
	double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1
	double run_away = 0.3;	    //chance of runing away 30%
	double fight_hatchet = 0.5; //chance of beating with hatchet = 50%
	double fight = 0.1;         //chance of beating it in a fight 10%
	double play_dead = 0.7;    //chance of playing dead and it leaving you alone 70%

	//initializing what you get for each scenario
	int running_attack = -30;
	int fight_attack = -50;
	int play_attack = -10;
	int bear_food = 100;


	if (choice == 0) {
		if (r <= run_away) {
			//success
			printf("Congrats!\nYou successfully ran away from the bear!\n\n");
		}
		else {
			printf("Oh no!\nThe bear caught you!\n");
			printf("Health decreased by %d\n\n", abs(running_attack));
			modifyhealth(running_attack);
		}
	}
	else if (choice == 1) {
		if (hatchet == true) {
			if (r <= fight_hatchet) {
				printf("Congrats!\nYou successfully fought off the bear and took some of its food!\n");
				printf("Food increased by %d\n\n", bear_food);
				modifyhunger(bear_food);
			}
			else {
				printf("Oh no!\nThe bear beat you!\n");
				printf("Health decreased by %d\n\n", abs(fight_attack));
				modifyhealth(fight_attack);
			}
		}
		else{
			if (r <= fight) {
				//success
				printf("Congrats!\nYou successfully fought off the bear and took some of its food!\n");
				printf("Food increased by %d\n\n", bear_food);
				modifyhunger(bear_food);
			}
			else {
				printf("Oh no!\nThe bear beat you!\n");
				printf("Health decreased by %d\n\n", abs(fight_attack));
				modifyhealth(fight_attack);
			}		
		}
	}
	else if (choice == 2) {
		if (r <= play_dead) {
			//success
			printf("Congrats!\nThe bear left you alone.\n\n");
		}
		else {
			printf("Oh no!\nThe bear still attacked you!\n");
			printf("Health decreased by %d\n\n", abs(play_attack));
			modifyhealth(play_attack);
		}
	}
	else {
		printf("Please select a valid choice\n\n");
		bear(home);
	}
	return;
}

/*
* Function is called if user is caught in storm
* takes in boolean of their decision to stay home or not
* if they stayed home nothing happens, if not they make a choice to ignore the storm take shelter nearby or try to find a cave
* constants for liklihood of events as well as event damage located in function
*/
void storm(bool home) {
	printf("Oh no! A storm is rolling in!\n");
	print_storm();

	//if at home nothing happens
	if (home) {
		printf("Luckily you are at home and nothing happened.\n");
		return;
	}

	//if not at home player has to make a choice
	int choice;
	printf("What would you like to do?\n");
	printf("0: Ignore it\n");
	printf("1: Take shelter nearby\n");
	printf("2: Try to find a cave\n");

	scanf("%d", &choice);
	printf("\n");


	//initializing chances of success
	double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1
	double ignore = 0.2;	//chance of ignoring it successfully 20%
	double shelter = 0.95;		//chance of finding shelter 95%
	double cave = 0.4;  //chance of finding a cave 40%

	//initializing what you get for each scenario
	int ignore_damage = -30;
	int shelter_damage = -5;
	int storm_damage = -25;

	if (choice == 0) {
		//ignore it
		if (r <= ignore) {
			//success
			printf("Luckily the storm moved the other way, avoiding you.\n\n");
		}
		else {
			//unsuccessful
			printf("Uh oh!\nYou were caught in the storm!\n");
			printf("Health deducted by %d\n\n", abs(ignore_damage));
			modifyhealth(ignore_damage);
		}
	}
	else if (choice == 1) {
		//take shelter nearby
		if (r <= shelter) {
			//success
			printf("You find shelter in a nearby bush but still take some damage from the storm.\n");
			printf("Health deducted by %d\n\n", abs(shelter_damage));
			modifyhealth(shelter_damage);
		}
		else {
			//unsuccessful
			printf("Oh no!\nYou couldn't find shelter nearby!\n");
			printf("Health deducted by %d\n\n", abs(storm_damage));
			modifyhealth(storm_damage);
		}

	}
	else if (choice == 2) {
		//try to find a cave
		if (r <= cave) {
			//success
			printf("You manage to find shelter in a nearby cave.\n\n");
		}
		else {
			//unsuccessful
			printf("You were unable to find a cave to shelter in.\n");
			printf("Health deducted by %d\n\n", abs(storm_damage));
			modifyhealth(storm_damage);
		}
	}
	else {
		printf("Please make a valid choice.\n\n");
		storm(home);
	}

	return;

}


/*	
*	Event determining if a package has dropped, which may contain an item or food
*	Package cannot be collected if 'stay at home' option is chosen
*/ 
void dropped_package(bool home) {


	printf("A package was accidentally dropped from a plane flying by!\n\n");

	if (home) {
		printf("You stayed home, so you were unable to retrieve the package. Sadly a bear eventually got into it\n");
		print_bear();
	}
	else {
		double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1
		if (r <= 0.25) {
			if (hatchet == false) {
				printf("You found some canned food in the package!\n");
				modifyhunger(25);
			}
			else {
				hatchet = true;
				printf("You got a hatchet!\n");
			}
		}
		else if (0.25 < r <= 0.5) {
			if (backpack == false) {
				printf("You found some canned food in the package!\n");
				modifyhunger(25);
			}
			else {
				backpack = true;
				printf("You got a backpack!\n");
			}
		}
		else if (0.5 < r <= 0.75) {
			if (water_bottle == false) {
				printf("You found some canned food in the package!\n");
				modifyhunger(25);
			}
			else {
				water_bottle = true;
				printf("You got a medkit!\n");
			}
		}
		else if (0.75 < r <= 1) {
			if (medkit == false) {
				printf("You found some canned food in the package!\n");
				modifyhunger(25);
			}
			else {
				medkit = true;
				printf("You got a medkit!\n");
			}

		}
	}
	return;
}

/*
*	Checks to see if you are meant to lose health due to sickness
*	Continually decreases counter, and only decreases health if 'sick_health' value is greater than 1.
*/
void sick_health_counter(int sick_health){
	if (sick_health > 1){
		modifyhealth(-5);
	}
	else if(sick_health == 1){
		printf("You are no longer sick and losing extra health!\n");
		
	}

	if (sick_health > 0) {
		sick_health--;
	}
	else
		sick_health = 0;
}

/*
*	Checks to see if you are meant to lose hunger due to sickness
*	Continually decreases counter, and only decreases hunger if 'sick_hunger' value is greater than 1.
*/
void sick_food_counter(int sick_hunger){
	if (sick_hunger > 1){
		modifyhunger(-5);
	}
	else if(sick_hunger == 1){
		printf("You are no longer sick and losing extra hunger!\n");
	}

	if (sick_hunger > 0) {
		sick_hunger--;
	}
	else
		sick_hunger = 0;
}

/*
*	Checks to see if you are meant to lose thirst due to sickness
*	Continually decreases counter, and only decreases health if 'sick_thirst' value is greater than 1.
*/
void sick_water_counter(int sick_thirst){
	if (sick_thirst > 1){
		modifythirst(-5);
	}
	else if(sick_thirst == 1) {
		printf("You are no longer sick and losing extra thrist!\n");
	}

	if (sick_thirst > 0) {
		sick_thirst--;
	}
	else
		sick_thirst = 0;
}

void sick_stay_counter(int stay_counter) {
	if (stay_counter > 5) {
		printf("You have stayed in for too long, and have gotten sick!\n");
		sick_hunger = 4;
		stay_counter = 1;
	}
	return;
}

void print_bear() {

	printf("   :'._..---.._.'\";\n");
	printf("    `.             .'\n");
	printf("    .'    ^   ^    `.\n");
	printf("   :      a   a      :                 __....._\n");
	printf("   :     _.-0-._     :---'\"\"'\"-....--'\"        '.\n");
	printf("    :  .'   :   `.  :                          `,`.\n");
	printf("     `.: '--'--' :.'                             ; ;\n");
	printf("      : `._`-'_.'                                ;.'\n");
	printf("      `.   '\"'                                   ;\n");
	printf("       `.               '                        ;\n");
	printf("        `.     `        :           `            ;\n");
	printf("         .`.    ;       ;           :           ;\n");
	printf("       .'    `-.'      ;            :          ;`.\n");
	printf("   __.'      .'      .'              :        ;   `.\n");
	printf(" .'      __.'      .'`--..__      _._.'      ;      ;\n");
	printf(" `......'        .'         `'\"\"'`.'        ;......-'\n");
	printf("       `.......-'                 `........'\n\n");
	return;

}

void print_storm() {

	printf("   .edee...      .....       .eeec.   ..eee..\n"
		"   .d*\"  \"\"\"\"*e..d*\"\"\"\"\"\"**e..e*\"\"  \"*c.d\"\"  \"\"*e.\n"
		"  z\"           \"$          $\"\"       *F         **e.\n"
		" z\"             \"c        d\"          *.           \"$.\n"
		".F                        \"            \"            'F\n"
		"d                                                   J%%\n"
		"3         .                                        e\"\n"
		"4r       e\"              .                        d\"\n"
		" $     .d\"     .        .F             z ..zeeeeed\"\n"
		" \"*beeeP\"      P        d      e.      $**\"\"    \"\n"
		"     \"*b.     Jbc.     z*%%e.. .$**eeeeP\"\n"
		"        \"*beee* \"$eeed\"  ^$$$\"\"    \"\n"
		"                 '$$.     .$$$c\n"
		"                  \"$$$.   e$$*$$c\n"
		"                   \"$$..$$P\" '$$r\n"
		"                    \"$$$$\"    \"$$$.           .d\n"
		"        z.          .$$$\"      \"$$$.        .dP\"\n"
		"        ^*e        e$$\"         \"$$$.     .e$\"\n"
		"          *b.    .$$P\"           \"$$$.   z$\"\n"
		"           \"$c  e$$\"              \"$$$.z$*\"\n"
		"            ^*e$$P\"                \"$$$\"\n"
		"              *$$                   \"$$r\n"
		"              '$$F                 .$$P\n"
		"               $$$                z$$\"\n"
		"               4$$               d$$b.\n"
		"               .$$%%            .$$*\"*$$e.\n"
		"            e$$$*\"            z$$\"    \"*$$e.\n"
		"           4$$\"              d$P\"        \"*$$e.\n"
		"           $P              .d$$$c           \"*$$e..\n"
		"          d$\"             z$$\" *$b.            \"*$L\n"
		"         4$\"             e$P\"   \"*$c            ^$$\n"
		"         $\"            .d$\"       \"$$$.           ^$r\n"
		"        dP            z$$\"         ^*$e.          \"b\n"
		"       4$            e$P             \"$$           \"\n"
		"                    J$F               $$\n"
		"                    $$               .$F\n"
		"                   4$\"               $P\"\n\n");

	return;
}

void choices(){

	printf("Make a decision: \n");
	printf("0: Search for food ");
	printf("| 1: Search for water ");
	printf("| 2: Stay in\n");

	return;

}

void status_show(int health, int hunger, int thirst) {


printf("Health: %d\n", health);
printf("Hunger: %d\n", hunger);
printf("Thirst: %d\n\n", thirst);

	return;
}
