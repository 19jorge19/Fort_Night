#include "Global.h"

void main_menu()
{
    printf("Welcome to Fortnight: \n");
    printf("0: Quit\n1: Play Game\n");
    printf("2: Instructions\n");
    printf("3: Credits\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
        printf("Thanks for playing\n");
        exit(0);
    case 1:
        printf("You're playing\n");
        return;
    case 2:
        //write out instructions
        printf("Welcome to Fort Night the decision makeing survival game.\n");
        printf("To start playing please select the play option once in\n");
        printf("You will bw givwn option every morning, evening, and night.\n");
        printf("Each one of these options will impact your likely hood of.\n");
        printf("surviving so be careful. Additionally during special event and \n");
        printf("each senerio will give you additional options on hhow to react.\n");
        main_menu();
    case 3:
        //write out credits
        printf("Josh");
        printf("Dylan");
        printf("Max");
        printf("Xavier");
        printf("Jorge");
        main_menu();
    default:
        printf("Please choose a valid choice.\n");
        main_menu();
    }
}








