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
        printf("instructions here");
        main_menu();
    case 3:
        //write out credits
        printf("credits here");
        main_menu();
    default:
        printf("Please choose a valid choice.\n");
        main_menu();
    }
}








