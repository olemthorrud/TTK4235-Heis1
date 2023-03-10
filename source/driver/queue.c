#include "queue.h"
#include <stdlib.h>

int buttons_pressed[N_FLOORS][N_BUTTONS] = {
    {0, 0, 0},                      //1. floor {BTN_UP, BTN_DWN, BTN_CAB}
    {0, 0, 0},
    {0, 0, 0},    
    {0, 0, 0}
    };


int order_exist() {
    for(int i = 0; i<N_FLOORS; i++){
        for(int y = 0; y<N_BUTTONS; y++)
        if (elevio_callButton(i, y)) {
            return 1;
        }
    }
    return 0;
}


void Set_buttons_pressed() {
    for(int i = 0; i<N_FLOORS; i++){
        for(int y = 0; y<N_BUTTONS; y++)
        if (elevio_callButton(i, y)) {
            buttons_pressed[i][y] = 1;
        }
    }
}



int check_for_stops(int current_floor, int current_next, MoveState motor_dir) {

    switch (motor_dir)
    {

    //skal vi ned(-1); iterer ovenifra og ned, sjekk index 1, 2 i matrise 
    case MOVE_DOWN:
    for(int i = current_floor; i >= 0; i--) {
        if(buttons_pressed[i][BUTTON_HALL_DOWN] || buttons_pressed[i][BUTTON_CAB]){
            return i;
            }
        }   
        return current_next;
    
    //skal vi opp(1); iterer nedenifra og opp, sjekk index 0, 2 i matrise
    case MOVE_UP:
    for(int i = current_floor; i < N_FLOORS; i++){
        if(buttons_pressed[i][BUTTON_HALL_UP] || buttons_pressed[i][BUTTON_CAB]){
            return i;
            }
        }
        return current_next;


    default:
    return current_next;

    }
}


int calculate_nxt_floor(MoveState state) {

    int current_floor = elevio_floorSensor();

    if(state == IDLE){
        state = MOVE_UP;
    }

    //1. se etter ordre i state-retning med state_plassering fra nermest til lengst unna
    int max_lim = 1.5 + 2.5 * state;
    int btn_dir_idx = 0.5 - 0.5 *state;

    int i = current_floor;
    while (i != max_lim) {
        if (buttons_pressed[i][btn_dir_idx] || buttons_pressed[i][BUTTON_CAB]){
            return i;
        }
        i += state;
    }

    //2. se etter ordre i !state-retning fra langst unna til nermest
    i = max_lim - 1;
    btn_dir_idx = 0.5 + 0.5 *state;
    while (i != current_floor) {
        if (buttons_pressed[i][btn_dir_idx]){
            return i;
        }
        i += state*(-1); 
    }

    //3. se etter ordre i !state-retning fra nermest til lengst unna
    i = current_floor;
    max_lim = 1.5 - 2.5 * state; 
    while (i != max_lim){
        if(buttons_pressed[i][btn_dir_idx] || buttons_pressed[i][BUTTON_CAB]){
            return i;
        }
        i += state*(-1);
    }
   
    //4. se etter ordre i state-retning fra
    i = max_lim - 1; 
    btn_dir_idx = 0.5 - 0.5 *state;

    while (i != current_floor){
        if (buttons_pressed[i][btn_dir_idx]){
            return i;
        }
    }

    return current_floor;
}



MoveState calculate_state(int current_floor, int nxt_floor) {
    int value = current_floor - nxt_floor;

    if(value > 0) {
        return MOVE_DOWN;
    }

    else if (value < 0) {
        return MOVE_UP;
    }

    else{
        return IDLE;
    }
}


void move_elevator(MoveState state) {
    switch (state)
    {
    case MOVE_DOWN:
        elevio_motorDirection(DIRN_DOWN);
        break;

    case MOVE_UP:
        elevio_motorDirection(DIRN_UP);
        break;
    
    case IDLE:
        elevio_motorDirection(DIRN_STOP);
        break;

    default:
        break;
    }
}


void clear_btn(int floor) {
    for (int i = 0; i < N_BUTTONS; i++){
        buttons_pressed[floor][i] = 0;
    }

}
