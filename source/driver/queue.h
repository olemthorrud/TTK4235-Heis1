#pragma once
#include "elevio.h"


int buttons_pressed[N_FLOORS][N_BUTTONS]; 


typedef enum { 
    MOVE_DOWN   = -1,
    IDLE        = 0,
    MOVE_UP     = 1
} MoveState;



int order_exist();

void Set_buttons_pressed();

int check_for_stops(int current_floor, int current_next, MoveState motor_dir);

void clear_btn(int floor);

MoveState calculate_state(int current_floor, int nxt_floor, int prev_floor, MoveState prev_state);

void move_elevator(MoveState state);

int calculate_nxt_floor(MoveState state, int remember_floor, int remember_state, int has_stopped);

void print_buttons();

void clear_orders(); 

int find_previous_floor(); 

int calculate_floor_after_stop(int prev_floor, MoveState prev_state); 
