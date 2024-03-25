#pragma once

#include "Global.h"
#include <stdbool.h>

#ifndef event
#define event


void morning_event();
//void midday_event();
//void evening_event();
void find_food(int random_event);
void find_water(int random_event);
void stay_in(int random_event);
void bear(bool home);
void storm(bool home);
void fever_sick(int random_sick);
void dysentary_sick(int random_sick);
void sick_health_counter(int sick_health);
void sick_food_counter(int sick_hunger);
void sick_water_counter(int sick_thirst);

#endif