/*
    Header file containing damage values and tick/turn counts

*/
#pragma warning(disable: 4996)
#pragma once

#include "Global.h"

#ifndef chance_values
#define Chance_values

//  Food and Water Chance
extern double food_chance;
extern double water_chance;
extern int hungry_damage;
extern int thirsty_damage;
extern int daily_hunger;
extern int daily_thirst;


//  Random event threshold values (Values are upper thresholds, so < is used)
extern int normal; //0-5 means no event
//extern int bear; //6-7 is Bear attack
//extern int storm; //8-10 is Storm

//  Damage values for certain event
extern int bear_damage;
extern int storm_damage;

#endif

