//  Setting the Chance Values

#pragma warning(disable: 4996)
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Chance_Values.h"

void setValues(void){

//  Food and Water Chance
    double food_chance = 0.5;
    double water_chance = 0.5;
    int hungry_damage = -5;
    int thirsty_damage = -7;
    int daily_hunger = 5;
    int daily_thirst = 5;


//  Random event threshold values (Values are upper thresholds, so < is used)
    int normal = 6; //0-5 means no event
    int bear = 8; //6-7 is Bear attack
    int storm = 11; //8-10 is Storm

//  Damage values for certain event
    int bear_damage = -25;
    int storm_damage = -25;

}
