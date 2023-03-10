#include "queue.h"


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




int calculate_nxt_floor(int current_floor, MoveState motor_dir) {

    int next_floor = current_floor;

    switch (motor_dir)
    {

    //skal vi ned(-1); iterer ovenifra og ned, sjekk index 1, 2 i matrise 
    case MOVE_DOWN:
    for(int i = current_floor; i >= 0; i--) {
        if(buttons_pressed[i][BUTTON_HALL_DOWN] || buttons_pressed[i][BUTTON_CAB]){
            next_floor = i;
            return next_floor;
            }
        }   

        if (buttons_pressed[0][BUTTON_HALL_UP]){
            return 0;
        }
        break;
    
    //skal vi opp(1); iterer nedenifra og opp, sjekk index 0, 2 i matrise
    case MOVE_UP:
    for(int i = current_floor; i < N_FLOORS; i++){
        if(buttons_pressed[i][BUTTON_HALL_UP] || buttons_pressed[i][BUTTON_CAB]){
            next_floor = i;
            return next_floor;
        }
    }
    if (buttons_pressed[N_FLOORS-1][BUTTON_HALL_DOWN]){
            return 3;
        }
        break;

    //iterer gjennom alle etasjer
    case IDLE:
    for (int i = 0; i < N_FLOORS; i++) {
        for (int y = 0; i < N_BUTTONS; y++)
            {
            if(buttons_pressed[i][y]){
                next_floor = i;
                return next_floor;
            }
        }        
    }
    break;

    default:
    return next_floor;
}
}

MoveState calculate_state(int current_floor, int target_floor,MoveState state) {
    
}

/* MoveState calculate_move_state(int current_floor, int nxt_floor) {
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
 */

void clear_btn(int floor) {
    for (int i = 0; i < N_BUTTONS; i++){
        buttons_pressed[floor][i] = 0;
    }

}
