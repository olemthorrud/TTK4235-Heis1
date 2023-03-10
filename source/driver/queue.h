#pragma once
#include "elevio.h"




typedef enum { 
    MOVE_DOWN   = -1,
    IDLE        = 0,
    MOVE_UP     = 1
} MoveState;


int order_exist();

void Set_buttons_pressed();

int calculate_nxt_floor();

void clear_btn(int floor);

MoveState calculate_state(int current_floor, int nxt_floor);

void move_elevator(MoveState state);

