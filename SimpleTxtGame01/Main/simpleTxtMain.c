
/**************************************** SIMPLE TEXT GAME ****************************************/
/* Created By:   BrennyS (Brendon)                                                                */
/* Date Created: 20/06/18                                                                         */
/* Version: v0.0.2                                                                                */
/* Version notes:                                                                                 */
/* - Added a loadSave function which reads a txt file based on the players name.                  */
/* Planned Updates:                                                                               */
/* - Game will function completely on reading writing .txt files                                  */
/* - Game will also implement structs and linked lists to replicate "movement" between dungeons   */
/****************************************      FLAMEL      ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpleTxtMain.h"
#include "player.h"

int main(int argc, const char * argv[]) {
    
    menu();
    
    return 0;
}

// Function which reads the contents of a .txt file until EOF and prints it out in console.
void readFile(char *name){
    FILE *fp;
    int c = 0;
    
    fp = fopen(name, "r");
    while(1){
        c = fgetc(fp);
        if(feof(fp)){
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
}

// Function that checks for player information at the beginning of the game.
// If the player has a save file, search for the file and read it to continue the game.
// Otherwise send the player to the character creation menu.
void menu(void){
    int  newGame = 0;
    
    char start[YES_NO];
    char *fileName = "intro.txt";
    
    readFile(fileName);
    
    // Ask if the user is willing to start a new game, otherwise ask them to enter the name of their save file
    while(newGame == 0){
        scanf("%s", start);
        
        // If the player responds with Y or y, we will create a new character and game file.
        if(strcmp(start,"Y") == 0 || strcmp(start,"y") == 0){
            newGame = 1;
            printf("You will be taken to the character creation menu. \n");
            loadingLoop();
            characterCreation();
        }
        // As of v0.0.1 we will not read in a file just yet (e.g. N will be unavailable until v0.0.2)
        else if(strcmp(start,"N") == 0 || strcmp(start,"n") == 0){
            loadSave();
        }
        // If the player input is not a proper value, continue asking.
        else{
            printf("Please enter a valid input.\n");
        }
    }
}

// Function reads a file name given by the player and opens it using "r".
// If the file does not exist, player will be asked if they want to create a new character or re-enter the file name.
void loadSave(void){
    char name[MAX_NAME_LENGTH];
    char save[MAX_NAME_LENGTH];
    char start[YES_NO];
    int  saveCheck = 0;
    
    FILE *fp;
    // ask the player to enter their character name to open the save file
    printf("Please enter your character name.\n");
    while(saveCheck == 0){
        scanf("%s", name);
        strcpy(save,name);
        strcat(save,".txt");
        fp = fopen(save,"r");
        
        if(NULL == fp){
            printf("File does not exist.\nDo you want to try again (Y) or return to the main menu (N)?\n");
            scanf("%s", start);
            if(strcmp(start,"N") == 0 || strcmp(start,"n") == 0){
                menu();
            }
            else if(strcmp(start,"Y") == 0 || strcmp(start,"y") == 0){
                loadSave();
            }
        }
        else{
            saveCheck = 1;
            loadingLoop();
            printf("Welcome back %s.\nWe will continue from your save file.\n", name);
            // print out the contents of the file (TEST).
            readFile(save);
            instruct();
        }
    }
}


// Function which allows the player to create their character
// Will create a text file with their character name
int characterCreation(void){
    char name[MAX_NAME_LENGTH];
    char save[MAX_NAME_LENGTH];
    char *charCreation = "charCreation.txt";
   
    char genderQ[YES_NO];
    char gender[] = "placeholder";
    char honorific[] = "placeholder";
    
    int health = MAX_HEALTH;
    int qFlag = 0;
    char c;
    
    FILE *fp;
    
    readFile(charCreation);

    // create a function for gender check
    while(qFlag == 0){
        scanf("%s", genderQ);
        // Check if the player is a boy or a girl
        if(strcmp(genderQ,"G") == 0 || strcmp(genderQ,"g") == 0){
            strcpy(gender, "girl");
            strcpy(honorific,"madam");
            qFlag = 1;
        }
        else if(strcmp(genderQ,"B") == 0 || strcmp(genderQ,"b") == 0){
            strcpy(gender, "boy");
            strcpy(honorific,"sir");
            qFlag = 1;
        }
        else{
            printf("Please enter a valid input.\n");
        }
    }
    
    // change the honorific depending on gender.
    printf("Ah... a %s, I see! Sorry for such a silly question.\n", gender);
    printf("Now then %s, could I also get your name?\n", honorific);
    
    // scan the players name into a string, and append the name with ".txt" to create a text file.
    scanf("%s", name);
    strcpy(save,name);
    strcat(save,".txt");
    fp = fopen(save,"w");
    
    // save the players name within the file.
    fprintf(fp,"NAME: %s\n", name);
    fprintf(fp,"HEALTH: %d\n", health);
    scanf("%c", &c);
    
    playerDet(name);
    
    printf("Well %s, are you ready to step into the STG world?\nToo late.... you don't have a choice.\n",name);
    printf("Actually you could probably just type QUIT but oh well.\nPress any key to continue...");
    scanf("%c", &c);
    
    // close the file and continue onto the next phase of the game
    fclose(fp);
    
    loadingLoop();
    instruct();
    
    return 0;
}

// instructions phase of the game
void instruct(void){
    char *instructions = "instructions.txt";
    readFile(instructions);
}


// function which prints out from a loop to clear the screen between game phases.
void loadingLoop(void){
    int i = 0;
    
    while(i < LOADING_LOOP){
        printf("Loading...\n");
        i++;
    }
    printf("\n");
}
