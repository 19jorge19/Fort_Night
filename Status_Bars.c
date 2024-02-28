#include "Status_Bars.h"

/* 
* function alters health based on integer value factor
* when called, send in however much you want to alter health by (factor) send in negative value if you want to decrease
*/
void modifyhealth(int factor) {

	health += factor;
	

}

/*
* function alters thirst based on integer value factor
* when called, send in however much you want to alter thirst by (factor) send in negative value if you want to decrease
*/
void modifythirst(int factor) {

	thirst += factor;

}

/*
* function alters hunger based on integer value factor
* when called, send in however much you want to alter hunger by (factor) send in negative value if you want to decrease
*/
void modifyhunger(int factor) {

	hunger += factor;

}






