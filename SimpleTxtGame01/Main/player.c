//
//  player.c
//  SimpleTxtGame01
//
//  Created by Brendon on 23/6/18.
//  Copyright © 2018 FLAMEL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "simpleTxtMain.h"


void playerPrint(struct character *p);

// function which prints out the instructions for choosing a class.
void playerClass(void){
    char *c1 = "class.txt";
    char *c2 = "class2.txt";
    
    int  c;
    
    c = getchar();
    // read the story
    readFile(c1);
    c = getchar();
    readFile(c2);
    classSelect();
    
}

// Recursive function which prompts the user to choose a valid class.
void classSelect(void){
    int class;
    char c;
    
    scanf("%d", &class);
    
    switch(class){
        case JESTER :
            printf("Jester has been selected.\n");
            break;
        case WIZARD :
            printf("Wizard has been selected.\n");
            break;
        case KNIGHT :
            printf("Knight has been selected.\n");
            break;
        case RANGER :
            printf("Ranger has been selected.\n");
            break;
        default:
            if(class != '\n'){
                printf("Please enter a valid response\n");
            }
            classSelect();
    }
    scanf("%c", &c);
}



// Function which assigns all details of the character in both a struct and a .txt file
void playerDet(char *playerName){
    struct character *p = malloc(sizeof(struct character));
    strcpy(p->name, playerName);
    p->health = MAX_HEALTH;
    p->money  = STARTING_CASH;
}


// function which prints out the information of the player to ocnsole.
void playerPrint(struct character *p){
    printf("NAME:   %s\n", p->name);
    printf("HEALTH: %lf\n", p->health);
    printf("MONEY:  %d gold\n", p->money);
}

void playerAction(void){
    
}



