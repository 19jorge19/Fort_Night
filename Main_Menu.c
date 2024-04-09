#include "Global.h"

/*
*   Main Menu function:
*   Menu has options to exit the program, play the game, show instructions on how to play the game, or to show the credits.
*/

void main_menu()
{
    printf("Welcome to Fortnight: \n");
    printf("0: Quit\n1: Play Game\n");
    printf("2: Instructions\n");
    printf("3: Credits\n");

    int choice;
    scanf("%d", &choice);

    /*
    if (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9) {
        exit(0);
    }
    */
    
    if (choice == 0) {
        printf("Thanks for playing\n");
        exit(0);
    }
    else if (choice == 1) {
        return;
    }
    else if (choice == 2) {
        //write out instructions
        printf("Welcome to Fortnight the decision-making survival game.\n");
        printf("To start playing, please select the play option.\n");
        printf("You will be given options every day to choose from.\n"); //change to three a day if we change that
        printf("Each one of these options will impact your likelyhood of\n");
        printf("survival, so be careful. Additionally there will be special events you \n");
        printf("must react to in order to survive!\nGood Luck!\n\n");
        main_menu();
    }
    else if (choice == 3) {
        //write out credits
        printf("Developers:\n");
        printf("Dylan\nJorge\nJosh\nMax\nXavier\n\n");
        main_menu();
    }
    else {
        printf("Please choose a valid choice.\n");
        main_menu();
    }
    

    /*
    switch (choice)
    {
    case 0:
        printf("Thanks for playing\n");
        exit(0);
    case 1:
        return;
        break;
    case 2:
        //write out instructions
        printf("Welcome to Fortnight the decision-making survival game.\n");
        printf("To start playing, please select the play option.\n");
        printf("You will be given options every day to choose from.\n"); //change to three a day if we change that
        printf("Each one of these options will impact your likelyhood of\n");
        printf("survival, so be careful. Additionally there will be special events you \n");
        printf("must react to in order to survive!\nGood Luck!\n\n");
        main_menu();
        break;
    case 3:
        //write out credits
        printf("Developers:\n");
        printf("Dylan\nJorge\nJosh\nMax\nXavier\n\n");
        main_menu();
        break;
    default:
        printf("Please choose a valid choice.\n");
        main_menu();
        break;
    }
   */

}








