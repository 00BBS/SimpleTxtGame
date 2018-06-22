
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

void gameStart(void);
void intro(char start[]);
int characterCreation(void);
void fileCreate(void);
void loadSave(void);
void loadingLoop(void);

int main(int argc, const char * argv[]) {
    
    // Check if the game has a saved file.
    // If there exists a saved file and the user wishes to use it, open the file and proceed.
    // Otherwise we create a new game
    
    int gameSave = 0;
    if(gameSave == 0){
        gameStart();
    }
    
    return 0;
}

// Function that checks for player information at the beginning of the game.
// If the player has a save file, search for the file and read it to continue the game.
// Otherwise send the player to the character creation menu.
void gameStart(void){
    int  newGame = 0;
    int c;
    
    char start[YES_NO];
    
    FILE *fp;
    fp = fopen("intro.txt", "r");
    
    // Ask if the user is willing to start a new game, otherwise ask them to enter the name of their save file
    while(1){
        c = fgetc(fp);
        if(feof(fp)){
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
    
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
    int  saveCheck = 0;
    
    FILE *fp;
    
    while(saveCheck == 0){
        printf("Please enter your character name.\n");
        scanf("%s", name);
        strcpy(save,name);
        strcat(save,".txt");
        fp = fopen(save,"r");
        
        if(fp == NULL){
            printf("File does not exist.\n");
        }
        else{
            printf("Welcome back %s.\n", name);
            saveCheck = 1;
        }
    }
}


// Function which allows the player to create their character
// Will create a text file with their character name
int characterCreation(void){
    char name[MAX_NAME_LENGTH];
    char save[MAX_NAME_LENGTH];
    char genderQ[YES_NO];
    char gender[] = "placeholder";
    char honorific[] = "placeholder";
    
    int qFlag = 0;
    int c;
    
    FILE *fp;
    fp = fopen("charCreation.txt", "r");
    
    //Read the character creation file
    while(1){
        c = fgetc(fp);
        if(feof(fp)){
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
 
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
    
    // change the honorific depending on gender
    printf("Ah... a %s, I see! Sorry for such a silly question.\n", gender);
    printf("Now then %s, could I also get your name?\n", honorific);
    
    scanf("%s", name);
    strcpy(save,name);
    strcat(save,".txt");
    fp = fopen(save,"w");
    
    printf("Well %s, are you ready to step into the STG world? Too late. You don't have a choice :)\n", name);
    
    return 0;
}


// function which prints out from a loop to clear the screen between game phases.
void loadingLoop(void){
    int i = 0;
    
    while(i < LOADING_LOOP){
        printf("Loading...\n");
        i++;
    }
}
