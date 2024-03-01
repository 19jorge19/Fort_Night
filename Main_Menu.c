#include "Global.h"

void main_menu()
{
    printf("Welcome to Fort Night: \n");
    printf("0: Quit\n1: Play Game\n");
    printf("2: Instructions\n");
    printf("3: Credits\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 0:
        printf("Thank you for playing\n");
        exit(0);
    case 1:
        return;
    case 2:
        //write out instructions
        printf("Welcome to Fort Night: the decision making survival game.\n");
        printf("To start playing, select the 'Play' option in the Main Menu.\n");
        printf("You will be given [one] option every day.\n"); //change to three options a day if we decide to change that
        printf("Each option will impact the likelyhood of\n");
        printf("surviving, so be planful. Additionally, there may be special events that \n");
        printf("require you to react appropriately in order to survive\nGood Luck!\n\n");
        main_menu();
    case 3:
        //write out credits
        printf("Developers:\n");
        printf("Dylan Mingo\nJorge Torres\nJosh Nordan\nMax Gamble\nXavier Mejia\n\n");
        main_menu();
    default:
        printf("Please input a valid choice.\n");
        main_menu();
    }
}








