//
//  player.h
//  SimpleTxtGame01
//
//  Created by Brendon on 23/6/18.
//  Copyright © 2018 FLAMEL. All rights reserved.
//

#ifndef player_h
#define player_h

#include <stdio.h>

#define MAX_NAME_LENGTH 64
#define MAX_HEALTH      100



void playerDet(char *name);


// Health - The amount of health the player has left. Cannot be less than 0.
// Money  - The total amount of money the player has left, which they can use to purchase various items.
// Area   - The current location of the player.
struct character {
    char   *name;
    float  health;
    int    money;
    struct inventory *inventory;
    struct area *area;
};


struct inventory{
    
};


#endif /* player_h */
