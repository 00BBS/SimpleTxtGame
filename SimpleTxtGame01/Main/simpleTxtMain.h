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

void readFile(char *name);
void fileCreate(char *name);
void menu(void);
int  characterCreation(void);
void loadSave(void);
void loadingLoop(void);
void instruct(void);


// Name  - Corresponds with AREA in the map.txt file.
// Desc  - Description of the area, given by LOOK.
struct area{
    char   *name;
    char   *desc;
    struct area *north;
    struct area *south;
    struct area *east;
    struct area *west;
};

#endif /* simpleTxtMain_h */
