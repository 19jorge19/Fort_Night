#include "Status_Bars.h"

/* 
*	Function alters health based on an integer value factor
* 	When called, send in however much you want to alter health by (factor) send in negative value if you want to decrease
*/
void modifyhealth(int factor) {

	health += factor;
	

}

/*
*	Function alters thirst based on an integer value factor
*	When called, send in however much you want to alter thirst by (factor) send in negative value if you want to decrease
*/
void modifythirst(int factor) {

	thirst += factor;

}

/*
*	Function alters hunger based on an integer value factor
*	When called, send in however much you want to alter hunger by (factor) send in negative value if you want to decrease
*/
void modifyhunger(int factor) {

	hunger += factor;

}






