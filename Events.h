#pragma once

#include "Global.h"
#include <stdbool.h>

#ifndef event
#define event


void morning_event();
//void midday_event();
//void evening_event();
void find_food(int, int);
void find_water(int, int);
void stay_in(int, int);
void bear(bool home);
void storm(bool home);
void fever_sick(int random_sick);
void dysentary_sick(int random_sick);
void dropped_package(bool home);
void sick_health_counter(int sick_health);
void sick_food_counter(int sick_hunger);
void sick_water_counter(int sick_thirst);
void sick_stay_counter(int stay_counter);
void print_bear();
void print_storm();
void choices();
void status_show(int health, int hunger, int thirst);
int random_event_set(int r);

#endif