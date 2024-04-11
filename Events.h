#pragma once

#include "Global.h"
#include <stdbool.h>

#ifndef event
#define event


void morning_event();
void midday_event();
void evening_event();
void find_food(int, int);
void find_water(int, int);
void stay_in(int, int);
int random_event_set(float);

void bear(bool home);
void storm(bool home);
void ants(bool home);

void fever_sick(int random_sick);
void dysentary_sick(int random_sick);

void dropped_package(bool home);

void sick_item_check(bool);

void print_bear();
void print_storm();
void print_ant();
void choices();
void status_show(int, int, int);

bool check_totem();


#endif