//Status bars header file, named Status_Bars.h


#pragma once
#include "Global.h"

#ifndef status
#define status

void modifyhealth(int factor);
void modifythirst(int factor);
void modifyhunger(int factor);

void sick_counter(int, int, int);
void sick_health_counter(int sick_health);
void sick_food_counter(int sick_hunger);
void sick_water_counter(int sick_thirst);
void sick_stay_counter(int stay_counter);


#endif


