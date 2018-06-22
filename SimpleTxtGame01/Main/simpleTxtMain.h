//
//  simpleTxtMain.h
//  SimpleTxtGame01
//
//  Created by Brendon on 21/6/18.
//  Copyright © 2018 FLAMEL. All rights reserved.
//

#ifndef simpleTxtMain_h
#define simpleTxtMain_h

#define MAX_NAME_LENGTH 64
#define YES_NO          1
#define LOADING_LOOP    25
#define MAX_HEALTH      100


// Health - The amount of health the player has left. Cannot be less than 0.
// Money  - The total amount of money the player has left, which they can use to purchase various items.
// Area   - The current location of the player.
struct player {
    float  health;
    int    money;
    struct area *area;
};

struct inventory{
    
};

struct area{
    
};

#endif /* simpleTxtMain_h */
