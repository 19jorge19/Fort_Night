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
        return;
    case 2:
        //write out instructions
        printf("Welcome to Fort Night the decision making survival game.\n");
        printf("To start playing please select the play option once in.\n");
        printf("You will be given options every day.\n"); //change to three a day if we change that
        printf("Each one of these options will impact your likelyhood of\n");
        printf("surviving so be careful. Additionally there will be special events you \n");
        printf("must react to to survive\nGood Luck!\n\n");
        main_menu();
    case 3:
        //write out credits
        printf("Developers:\n");
        printf("Dylan\nJorge\nJosh\nMax\nXavier\n\n");
        main_menu();
    default:
        printf("Please choose a valid choice.\n");
        main_menu();
    }
}








