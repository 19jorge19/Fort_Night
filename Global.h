//  Global header file, to be imported into every header file, named Global.h
//  includes global variables of health thirst and hunger

#pragma once
#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef global
#define global

extern int health;
extern int thirst;
extern int hunger;
extern int days;
//extern double food_chance;
//extern double water_chance;

#endif





