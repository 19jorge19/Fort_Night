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
void bear();
void storm(bool home);

#endif