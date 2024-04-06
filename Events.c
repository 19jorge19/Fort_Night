#include "Events.h"

int normal = 0; //0-5 nothing for random event
int bear_chance = 1; //6-7 bear
int storm_chance = 2;
//storm is if not below those two events
//int bear_damage = -25;
//int storm_damage = -25;


/*
* Function displays status bars before prompting user to make a decision for what to do in the morning
* User may search for food, search for water, or stay in
* Chance of random event happening to which function calls other functions based on user decision, and passes what random event happened
*/
void morning_event() {
	int decision;

	//print statuses
	//printf("Health: %d\n", health);
	//printf("Hunger: %d\n", hunger);
	//printf("Thirst: %d\n\n", thirst);

	//print to screen user decision, go find food, find water, or stay here
	printf("Make a decision: \n");
	printf("0: Search for food\n");
	printf("1: Search for water\n");
	printf("2: Stay in\n");

	scanf("%d", &decision);
	printf("\n");
	

	//random chance of storm, other unpredictable event
	int random_event = rand() % 3; // random number 0-2, 0 is nothing, 1 is bear, 2 is storm
	//random event = random number 0-9, 0-5 = nothing, 6-7 = bear attack, 8-9 = storm
	//when eventually adding modes, use a multiplier here to scale up for hard mode, and scale down for easy mode


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
		printf("Please choose a valid decision\n");
		morning_event();
	}

}

/*
* Function takes in random_event number
* If random event is in certain ranges, triggers bear or storm events
* If not, function provides user with food based on chance defined by food_chance variable
*/
void find_food(int random_event) {
	int food_found = 45;
	//if random number is in the bear range, 6-7, bear attack
	if (random_event == bear_chance) {
		//bear attack
		bear(false);
	}
	//if random number is in the storm range, 8-9, storm
	else if (random_event == storm_chance) {
		//storm
		storm(false);
	}
	//if random number is not in those ranges, it's a normal case
	//additionally, if we want normal case to run through no matter what, we can remove else statement
	//else {
		//normal case
		double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1

		if (r <= food_chance) {
			printf("Congratualations!\nYou have successfully found food!\n");
			modifyhunger(food_found);
			//additionally can modify food chance to decrease
			food_chance -= 0.2;
		}
		else {
			printf("Uh-Oh\nYou did not find any food.\n");
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
void find_water(int random_event) {
	int water_found = 45;
	//if random number is in the bear range, 6-7, bear attack
	if (random_event == bear_chance) {
		//bear attack
		bear(false);
	}
	//if random number is in the storm range, 8-9, storm
	else if (random_event == storm_chance) {
		//storm
		storm(false); //false because not at home
	}
	//if random number is not in those ranges, it's a normal case
	//additionally, if we want normal case to run through no matter what, we can remove else statement
	//else {
		//normal case
		double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1

		if (r <= water_chance) {
			printf("Congratualations!\nYou have successfully found water!\n");
			modifythirst(water_found);
			water_chance -= 0.2;
			//additionally can modify water chance to decrease
		}
		else {
			printf("Uh-Oh\nYou did not find any water.\n");
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
void stay_in(int random_event) {
	//if random number is in the bear range, 6-7, bear attack
	if (random_event == bear_chance) {
		//bear attack
		bear(true);
	}
	//if random number is in the storm range, 8-9, storm
	else if (random_event == storm_chance) {
		//storm
		storm(true); //call storm function, at home so send in true for home boolean
	}
	else {
		printf("You have stayed in, and nothing has happened.\n");
	}
	return;
}

/*
* Function is called if there is a bear attack
* Gives options to run away, fight, or play dead
* Constants for chances as well as damages for each case located in function
* input = true, then at home, and therefore safe from bear
* input = false, then not at home, and in danger
*/
void bear(bool home) {
	printf("Oh no! A bear!\n\n");
	
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
	int bear_food = 100;


	if (choice == 0) {
		if (r <= run_away) {
			//success
			printf("Congratulations!\nYou have successfully ran away from the bear!\n\n");
		}
		else {
			printf("Oh no!\nThe bear caught you!\n");
			printf("Health decreased by %d\n\n", abs(running_attack));
			modifyhealth(running_attack);
		}
	}
	else if (choice == 1) {
		if (r <= fight) {
			//success
			printf("Congratulations!\nYou have successfully fought off the bear and took some of its food!\n");
			printf("Food increased by %d\n\n", bear_food);
			modifyhunger(bear_food);
		}
		else {
			printf("Oh no!\nThe bear beat you!\n");
			printf("Health decreased by %d\n\n", abs(fight_attack));
			modifyhealth(fight_attack);
		}
	}
	else if (choice == 2) {
		if (r <= play_dead) {
			//success
			printf("Congratualtions!\nThe bear left you alone.\n\n");
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
	printf("Oh no! A storm is coming in!\n");
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
	printf("\n\n");


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
			printf("Luckily the storm did not affect you.\n\n");
		}
		else {
			//unsuccessful
			printf("Uh oh!\nYou could not ignore the storm!\n");
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
			printf("Oh no!\nYou can't find shelter nearby!\n");
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
			printf("You are unable to find a cave to shelter in.\n");
			printf("Health deducted by %d\n\n", abs(storm_damage));
			modifyhealth(storm_damage);
		}
	}
	else {
		printf("Please make a valid choice.\n\n");
		storm(home);
	}

	return;

	//if at home nothing happens
	if (home) {
		printf("Oh no! A storm is coming in!\n");
		printf("Luckily you are at home and nothing happened.\n");
		return;
	}

	//if not at home player has to make a choice
	int choice;
	printf("Oh no! A storm is coming in!\n");
	printf("What would you like to do?\n");
	printf("0: Ignore it\n");
	printf("1: Take shelter nearby\n");
	printf("2: Try to find a cave\n");

	scanf("%d", &choice);
	printf("\n\n");


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
			printf("Luckily the storm did not affect you.\n\n");
		}
		else {
			//unsuccessful
			printf("Uh oh!\nYou could not ignore the storm!\n");
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
			printf("Oh no!\nYou can't find shelter nearby!\n");
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
			printf("You are unable to find a cave to shelter in.\n");
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

void dropped_package(bool home) {

	printf("A package was dropped from a plane flying by!\n\n");

	if (home) {
		printf("You stayed home so you were unable to retrieve the package, a bear eventually got into it\n");
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
	}
	else {
		double r = (double)rand() / RAND_MAX; //generate random number between 0 and 1
		if (r <= 0.25) {
			if (hatchet = true) {
				printf("You found food in the package!");
				modifyhunger(25);
			}
			else {
				hatchet = true;
				printf("You got a hatchet!");
			}
		}

		if (0.25 < r <= 0.5) {
			if (backpack = true) {
				printf("You found food in the package!");
				modifyhunger(25);
			}
			else {
				backpack = true;
				printf("You got a backpack!");
			}
		}

		if (0.5 < r <= 0.75) {
			if (water_bottle = true) {
				printf("You found food in the package!");
				modifyhunger(25);
			}
			else {
				water_bottle = true;
				printf("You got a medkit!");
			}
		}
		if (0.75 < r <= 1){
			if (medkit = true) {
				printf("You found food in the package!");
				modifyhunger(25);
			}
			else {
				medkit = true;
				printf("You got a medkit!");
		}

		}
	}
	return;
}
