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

// need to implement class selection
// Function which assigns all details of the character in both a struct and a .txt file
void playerDet(char *playerName){
    struct character *p = malloc(sizeof(struct character));
    strcpy(p->name, playerName);
    p->health = MAX_HEALTH;
    p->money  = STARTING_CASH;
}

void playerPrint(struct character *p){
    printf("NAME:   %s\n", p->name);
    printf("HEALTH: %lf\n", p->health);
    printf("MONEY:  %dn", p->money);
    
}


void playerAction(void){
    
}



