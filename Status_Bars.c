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






