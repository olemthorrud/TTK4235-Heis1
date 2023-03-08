#pragma once
#include "elevio.h"

int buttons_pressed[N_FLOORS][N_BUTTONS] = {
    {0, 0, 0},                      //1. floor {BTN_UP, BTN_DWN, BTN_CAB}
    {0, 0, 0},
    {0, 0, 0},    
    {0, 0, 0}
    };

int CURRENT_FLOOR;

int STOP = 0;
int kukksuger = 0; 

int order_exist();

void Set_buttons_pressed();

int calculate_nxt_floor();

