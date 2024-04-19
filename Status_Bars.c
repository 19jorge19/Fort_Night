#include "Status_Bars.h"

/* 
* function alters health based on integer value factor
* when called, send in however much you want to alter health by (factor) send in negative value if you want to decrease
*/
void modifyhealth(int factor) {

	health += factor;
	if (health > 100) {
		health = 100;
	}
	if (health < 0) {
		health = 0;
	}

}

/*
* function alters thirst based on integer value factor
* when called, send in however much you want to alter thirst by (factor) send in negative value if you want to decrease
*/
void modifythirst(int factor) {

	thirst += factor;
	if (thirst > 100) {
		thirst = 100;
	}
	if (thirst < 0) {
		thirst = 0;
	}

}

/*
* function alters hunger based on integer value factor
* when called, send in however much you want to alter hunger by (factor) send in negative value if you want to decrease
*/
void modifyhunger(int factor) {

	hunger += factor;
	if (hunger > 100) {
		hunger = 100;
	}
	if (hunger < 0) {
		hunger = 0;
	}
}

/*
*	Checks to see if you are meant to lose health due to sickness
*	Continually decreases counter, and only decreases health if 'sick_health' value is greater than 1.
*/
void sick_health_counter(int sick_health) {
	if (sick_health > 1) {
		modifyhealth(-5);
	}
	else if (sick_health == 1) {
		printf("You are no longer losing extra health due to sickness!\n");

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
void sick_food_counter(int sick_hunger) {
	if (sick_hunger > 1) {
		modifyhunger(-5);
	}
	else if (sick_hunger == 1) {
		printf("You are no longer losing extra hunger due to sickness!\n");
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
void sick_water_counter(int sick_thirst) {
	if (sick_thirst > 1) {
		modifythirst(-5);
	}
	else if (sick_thirst == 1) {
		printf("You are no longer losing extra thrist due to sickness!\n");
	}

	if (sick_thirst > 0) {
		sick_thirst--;
	}
	else
		sick_thirst = 0;
}

/*
*	Runs the sick counters for all status bars, and checks to see if you are meant to stay sick overall
*/
void sick_counter(int sick_health, int sick_hunger, int sick_thirst) {
	int h = sick_health;
	int u = sick_hunger;
	int t = sick_thirst;
	sick_health_counter(sick_health);
	sick_food_counter(sick_hunger);
	sick_water_counter(sick_thirst);

	if (sick_health <= h && sick_hunger <= u && sick_thirst <= t) {
		if (h == 1 || u == 1 || t == 1) {
			printf("You are no longer sick!\n");
		}
	}
}

/*
*	Counts  the number of days you stay in, and makes you sick after 5 days 
*/
void sick_stay_counter(int stay_counter) {
	if (stay_counter > 5) {
		printf("You have stayed in for too long, and have gotten sick!\n");
		sick_hunger = 4;
		stay_counter = 1;
	}
	return;
}



