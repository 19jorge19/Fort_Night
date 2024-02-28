/*
    Header file containing damage values and tick/turn counts

*/
#pragma warning(disable: 4996)
#pragma once

#include "Global.h"

#ifndef chance_values
#define Chance_values

//  Food and Water Chance
extern double food_chance = 0.5;
extern double water_chance = 0.5;
extern int hungry_damage = -5;
extern int thirsty_damage = -7;
extern int daily_hunger = 5;
extern int daily_thirst = 5;


//  Random event threshold values (Values are upper thresholds, so < is used)
extern int normal = 6; //0-5 means no event
extern int bear = 8; //6-7 is Bear attack
extern int storm = 11; //8-10 is Storm

//  Damage values for certain event
extern int bear_damage = -25;
extern int storm_damage = -25;

#endif

